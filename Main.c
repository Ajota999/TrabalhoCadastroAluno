#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//numero maximo de estudantes
#define MAX 20
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
int isalpha();
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
					printf("Numero maximo de alunos cadastrado\n");
					break;
				}
				cadastrar(aluno, idPont);
				idPont++;
				break;
			case '2':
				listar(aluno, idPont);
				break;
			case '3':
				pesquisar(aluno, idPont);
				break;
			case '4':
				atualizar(aluno);
				break;
			case '5':
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
		char welcome[25] = "CADASTRO DE ALUNOS";
		printf("\n");
		printf("+===========================================+\n");
		printf("§                                           §\n");
		printf("§");
		for (int i = 0; i < (43-strlen(welcome))/2; i++) printf(" ");
		fputs(welcome, stdout);
		for (int i = 0; i < (43-strlen(welcome))/2; i++) printf(" ");
		if ((43-strlen(welcome))%2 > 0) printf(" ");
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
		scanf(" %c", &esc);
		if(esc != '1' && esc != '2' && esc != '3' && esc != '4' && esc != '5' && esc != '6'){
			printf("comando invalido!\n");
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
		printf("Nome do aluno: ");
		gets(A[pont].nome);
		veri = nomeVer(A[pont].nome);
		if (veri == '0'){
			printf("Nome invalido! (verificar se nao foi digitado algum numero ou caracter especial)\n");
		}
	}while(veri == '0');

	//pegar a data de nascimento
	do{
		printf("Data de Nascimento(dd/mm/aaaa): ");
		scanf("%d/%d/%d", &A[pont].nasc.dia, &A[pont].nasc.mes, &A[pont].nasc.ano);
		veri = dataVer(A[pont].nasc.dia, A[pont].nasc.mes, A[pont].nasc.ano);
		if (veri == '0'){
			printf("Data de nascimento invalida! (verificar se a data foi digitada de maneira correta)\n");
		}
	}while(veri == '0');

	//pegar o CPF
	scanf("%c", &resto);
	do{
		printf("Digite o CPF(Ex.: 123.456.789-00): ");
		gets(A[pont].cpf);
		veri = cpfVer(A[pont].cpf);
		if (veri == '0'){
			printf("CPF invalido! (verfica se digitado de maneira correta - 123.456.789-00)\n");
		}
	}while(veri == '0');

	A[pont].situacao = 1;

	return;
}

void listar(est A[], int pont){
	for(i = 0; i < pont; i++){
		if(A[i].situacao == 1){
				printf("Nome: ");
				puts(A[i].nome);
				printf("Data de nascimento: ");
				printf("%d/%d/%d\n", A[i].nasc.dia, A[i].nasc.mes, A[i].nasc.ano);
				printf("CPF: ");
				puts(A[i].cpf);
				printf("\n");
		}
	}
	return;
}

void pesquisar(est A[], int pont){
	char pesq[NOME];
	
	scanf("%c ", &resto);
	do {
		printf("Insira o nome para pesquisa: ");	
		gets(pesq);
		if (nomeVer(pesq) == '0'){
			printf("Nome inválido. Verificar o uso de caracteres especiais e números.\n\n");
		}
	} while (nomeVer(pesq) == '0');

	for (int i = 0; i <= pont; i++){
		if (strncmp(A[i].nome, pesq, strlen(pesq)) == 0){
			printf("Nome: ");
			puts(A[i].nome);
			printf("Data de nascimento: ");
			printf("%d/%d/%d\n", A[i].nasc.dia, A[i].nasc.mes, A[i].nasc.ano);
			printf("CPF: ");
			puts(A[i].cpf);
			printf("\n");
		}
	}
	return;
}

void atualizar(est A[]){
	int ID;
	printf("Iforme o ID do cadastro do aluno que se deseja atualizar: ");
	scanf("%d", &ID);

	cadastrar(A, ID);

	printf("Informacoes atualizadas!\n");

	return;
}

void remover(est A[]){
	int ID;
	printf("Iforme o ID do cadastro do aluno que se deseja remover: ");
	scanf("%d", &ID);

	A[ID].situacao = 0;

	printf("Situacao do cadastro do aluno agora inativa!\n");

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
		if (isalpha(nome[i]) || nome[i] == ' '){
			if (i < tam - 1){
				continue;
			} else {
				return '1';
			}
		} else {
			return '0';
		}
	}
}

char dataVer(int d, int m, int a){
	if (d > 30) return '0';
	if (m > 12) return '0';
	if (a > 2019) return '0';
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