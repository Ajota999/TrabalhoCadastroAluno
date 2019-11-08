#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//numero maximo de estudantes
#define MAX 100
//numero maximo de caracteres no nome
#define NOME 50
//numero de caracteres no CPF (123.456.789-00)
#define CPF 14

struct Data{
	int dia;
	int mes;
	int ano;
};

typedef struct Data data;

struct Estudante{
	int id;
	char nome[NOME];
	data nasc;
	char cpf[CPF];
	int situacao;
};

typedef struct Estudante est;

//funcao de cadastro do aluno
void cadastrar(est A[], int pont);

//verificacao do nome
char nomeVer(char nome[]);

//verificacao da data
char dataVer(int d, int m, int a);

//verificacao do CPF
char cpfVer(char c[]);

//funcao de listar todos os alunos
void listar(est A[], int pont);

//funcao de pesquisar pelo aluno
void pesquisar(est A[], int pont);

//funcao que atualiza os dados do aluno
void atualizar(est A[]);

//funcao que invalida o cadastro do aluno
void remover(est A[]);

//funcao do menu do usuario
char menu();

//funcao de sair do programa
void sair();

//declaracao de funcoes pra remover warnings
void gets();
int isdigit();
int ispunct();
int strncmp();

int i;
char resto;

int main(){
	//ponteiro do ID
	int idPont = 0;
	est aluno[MAX];
	char escolha;

	do{
	    escolha = menu();

		switch(escolha){
			case '1':
				if(idPont == MAX){
					printf("\n\033[31m~x~ ERRO: Número máximo de alunos cadastrados. ~x~\033[0m\n\n"); 
					break;
				}
				printf("\n~x~ Cadastro de aluno. ~x~\n\n"); 
				cadastrar(aluno, idPont);
				printf("\n\033[32m~x~ Cadastro concluído! ~x~\033[0m\n\n");
				idPont++;
				break;
			case '2':
				listar(aluno, idPont);
				break;
			case '3':
				printf("\n~x~ Pesquisa por alunos. ~x~\n\n"); 
				pesquisar(aluno, idPont);
				break;
			case '4':
				printf("\n~x~ Atualização de cadastro. ~x~\n\n"); 
				atualizar(aluno);
				break;
			case '5':
				printf("\n~x~ Remoção de cadastro. ~x~\n\n"); 
				remover(aluno);
				break;
			case '6':
				sair();
				break;
		}
	}while(escolha != '6');

	return 0;
}

char menu(){
	char esc;

	do{
		char welcome[47] = "\033[1;5mCADASTRO DE ESTUDANTES\033[0m";
		printf("\n");
		printf("+===========================================+\n");
		printf("§                                           §\n");
		printf("§");
		for (int i = 0; i < ((43-strlen(welcome))+10)/2; i++) printf(" ");
		fputs(welcome, stdout);
		for (int i = 0; i < ((43-strlen(welcome))+10)/2; i++) printf(" ");
		if (((43-strlen(welcome))+10)%2 > 0) printf(" ");
		printf("§\n");
		printf("§                                           §\n");
		printf("+===========================================+\n");
		printf("§                                           §\n");
		printf("§  Escolha uma opção:                       §\n");
		printf("§                                           §\n");
		printf("§  1. Cadastrar.                            §\n");
		printf("§  2. Listar.                               §\n");
		printf("§  3. Pesquisar.                            §\n");
		printf("§  4. Atualizar.                            §\n");
		printf("§  5. Remover.                              §\n");
		printf("§  6. Sair.                                 §\n");
		printf("§                                           §\n");
		printf("+===========================================+\n");
		printf("\033[10A");
		printf("\033[22C");
		scanf(" %c", &esc);
		printf("\033[10B");
		printf("\033[22D");
		if(esc != '1' && esc != '2' && esc != '3' && esc != '4' && esc != '5' && esc != '6'){
			printf("\n\033[31m~x~ ERRO: Comando inválido. ~x~\033[0m\n\n"); 
		}
	}while(esc != '1' && esc != '2' && esc != '3' && esc != '4' && esc != '5' && esc != '6');

	return esc;
}

void cadastrar(est A[], int pont){
	//char de verificacao
	char veri;
	A[pont].id = pont;

	scanf("%c", &resto);
	//pegar o nome
	do{
		printf("Nome do Aluno: ");
		gets(A[pont].nome);
		veri = nomeVer(A[pont].nome);
		if (veri == '0'){
			printf("\n\033[31m~x~ ERRO: Formato inválido (Verifique o uso de caracteres especiais). ~x~\033[0m\n\n");
		}
	}while(veri == '0');

	//pegar a data de nascimento
	do{
		printf("Data de Nascimento (dd/mm/aaaa): ");
		scanf("%d/%d/%d", &A[pont].nasc.dia, &A[pont].nasc.mes, &A[pont].nasc.ano);
		veri = dataVer(A[pont].nasc.dia, A[pont].nasc.mes, A[pont].nasc.ano);
		if (veri == '0'){
			printf("\n\033[31m~x~ ERRO: Data inválida (Verifique formato de entrada e os dados inseridos). ~x~\033[0m\n\n");
		}
	}while(veri == '0');

	//pegar o CPF
	scanf("%c", &resto);
	do{
		printf("CPF (Ex.: 123.456.789-00): ");
		gets(A[pont].cpf);
		veri = cpfVer(A[pont].cpf);
		if (veri == '0'){
			printf("\n\033[31m~x~ ERRO: Formato inválido (Verifique o uso correto dos pontos e traço). ~x~\033[0m\n\n");
		}
	}while(veri == '0');

	A[pont].situacao = 1;
	return;
}

void listar(est A[], int pont){
	short int j = 0;
	for(i = 0; i < pont; i++){
		if(A[i].situacao == 1){
			if (j == 0){
				char welcome[47] = "\033[1mCADASTROS ATIVOS\033[0m";
				printf("\n");
				printf("+===========================================+\n");
				printf("§                                           §\n");
				printf("§");
				for (int i = 0; i < ((43-strlen(welcome))+8)/2; i++) printf(" ");
				fputs(welcome, stdout);
				for (int i = 0; i < ((43-strlen(welcome))+8)/2; i++) printf(" ");
				if (((43-strlen(welcome))+8)%2 > 0) printf(" ");
				printf("§\n");
				printf("§                                           §\n");
				printf("+===========================================+\n\n");
			}				
				printf(" %03d.	", i);
				printf("Nome: ");
				puts(A[i].nome);
				printf("    	Data de Nascimento: ");
				printf("%02d/%02d/%04d\n", A[i].nasc.dia, A[i].nasc.mes, A[i].nasc.ano);
				printf("    	CPF: ");
				puts(A[i].cpf);
				printf("\n");
				j++;
		}
	}
	if (j == 0){
		printf("\n\033[93m~x~ Não há cadastros ativos. ~x~\033[0m\n\n");
	} else {
		printf("+===========================================+\n\n");
	}
	return;
}

void pesquisar(est A[], int pont){
	char pesq[NOME];
	
	scanf("%c", &resto);
	do {
		printf("Nome: ");
		gets(pesq);
		if (nomeVer(pesq) == '0'){
			printf("\n\033[31m~x~ ERRO: Formato inválido (Verifique o uso de caracteres especiais). ~x~\033[0m\n\n");
		}
	} while (nomeVer(pesq) == '0');

	short int j = 0;
	for (int i = 0; i <= pont; i++){
		short int k = 0;
		if (pont != 0){
			for (int a = 0; a < strlen(A[i].nome); a++){
				for (int b = a, c = 0; c < strlen(pesq); b++, c++){
					if (A[i].nome[b] != pesq[c]){
						break;
					} else {
						if (c == strlen(pesq)-1){
							if(A[i].situacao == 1){
								if (j == 0){
									char welcome[47] = "\033[1mCADASTROS ATIVOS\033[0m";
									printf("\n");
									printf("+===========================================+\n");
									printf("§                                           §\n");
									printf("§");
									for (int i = 0; i < ((43-strlen(welcome))+8)/2; i++) printf(" ");
									fputs(welcome, stdout);
									for (int i = 0; i < ((43-strlen(welcome))+8)/2; i++) printf(" ");
									if (((43-strlen(welcome))+8)%2 > 0) printf(" ");
									printf("§\n");
									printf("§                                           §\n");
									printf("+===========================================+\n\n");
								}				
								printf(" %03d.	", i);
								printf("Nome: ");
								puts(A[i].nome);
								printf("    	Data de Nascimento: ");
								printf("%02d/%02d/%04d\n", A[i].nasc.dia, A[i].nasc.mes, A[i].nasc.ano);
								printf("    	CPF: ");
								puts(A[i].cpf);
								printf("\n");
								j++;
								k++;
							}
						}
					}
				}
				if (k != 0) break;
			}
		}
	}
	if (j == 0){
		printf("\n\033[93m~x~ Não há cadastros ativos correspondentes. ~x~\033[0m\n\n");
	} else {
		printf("+===========================================+\n\n");
	}
	return;
}

void atualizar(est A[]){
	int ID;
	printf("Insira o ID: ");
	scanf("%d", &ID);

	cadastrar(A, ID);
	printf("\n\033[32m~x~ Informações atualizadas com sucesso! ~x~\033[0m\n\n");

	return;
}

void remover(est A[]){
	int ID;
	printf("Insira o ID: ");
	scanf("%d", &ID);

	A[ID].situacao = 0;

	printf("\n\033[32m~x~ Situação atualizada com sucesso! ~x~\033[0m\n");
	printf("	>Cadastro de \033[31m");
	fputs(A[ID].nome, stdout);
	printf("\033[0m inativo.\n\n");

	return;
}

void sair(){
	printf("\nEncerrando o programa");
			for (int i = 0; i < 3; i++){
				printf(".");
				fflush(stdout);
				system("sleep 0.5");
			}
			printf(" ^-^\n\n");
	return;
}

char nomeVer(char nome[]){
	int tam = strlen(nome);

	for(i = 0; i < tam; i++){
		if (isdigit(nome[i]) || ispunct(nome[i])){
			return '0';
		}
	}
		return '1';
}

char dataVer(int d, int m, int a){
	if (m > 12) return '0';
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
		if (d > 31) return '0';
	}
	if (m == 4 || m == 6 || m == 9 || m == 11){
		if (d > 30) return '0';
	} else {
		if (a%4 == 0){
			if (d > 29) return '0';
		} else {
			if (d > 28) return '0';
		}
	}
	if (a > 2019 || a < 1900) return '0';
	else if (a == 2019){
		if (m > 11) return '0';
		else if(m == 11){
			if (d > 8) return '0';
		}
	}
	return '1';
}

char cpfVer(char c[]){
	if (strlen(c) != CPF) return '0';

	for (i = 0; i < CPF; i++){
		if (i == 3 || i == 7){
			if (c[i] != '.') return '0';
		}
		else if (i == 11){
			if (c[i] != '-') return '0';
		}
		else{
			if (c[i] != '0' && c[i] != '1' && c[i] != '2' && c[i] != '3' && c[i] != '4' && c[i] != '5' && c[i] != '6' && c[i] != '7' && c[i] != '8' && c[i] != '9') return '0';
		}

	}
	return '1';
}
