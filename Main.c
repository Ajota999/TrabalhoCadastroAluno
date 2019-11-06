#include <stdio.h>
#include <string.h>

//numero maximo de estudantes
#define	MAX 20
//numero maximo de caracteres no nome
#define NOME 50

//numero de caracteres no CPF (123.456.789-00)
#define CPF 14

char resto;

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

//funcao do menu do usuario (por enquanto temporario)
char menu();

//funcao de sair do programa
void sair();

int i;

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
				break;
			case '4':
				break;
			case '5':
				break;
			case '6':
				break;
		}
	}while(escolha != '6');

	return 0;
}

char menu(){
	char esc;

	do{
		printf("Cadastro de Alunos\n");
		printf("1- Cadastrar\n");
		printf("2- Listar\n");
		printf("3- Pesquisar\n");
		printf("4- Atualizar\n");
		printf("5- Remover\n");
		printf("6- Sair\n");

		scanf(" %c", &esc);
		if(esc != '1' && esc != '2' && esc != '3' && esc != '4' && esc != '5' && esc != '6'){
			printf("comando invalido!\n");
		}
	}while(esc != '1' && esc != '2' && esc != '3' && esc != '4' && esc != '5' && esc != '6');

	return esc;
}

void cadastrar(est A[], int pont){
	/*
	Pedir pelo:
	(feito)Nome
	(feito)Data de nascimento
	(feito)CPF
	(feito)Deixar situacao do cadastro como valido (=1)
	(feito)Caso pont == MAX informar usuario e nao chamar essa funcao
	*/

	//char de verificacao
	char veri;
	A[pont].id = pont;

	scanf("%c", &resto);
	//pegar o nome
	do{
		printf("Nome do aluno: ");
		gets(A[pont].nome);
//		puts(A[pont].nome);
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
//		printf("%d/%d/%d\n", A[pont].nasc.dia, A[pont].nasc.mes, A[pont].nasc.ano);
		if (veri == '0'){
			printf("Data de nascimento invalida! (verificar se a data foi digitada de maneira correta)\n");
		}
	}while(veri == '0');

	//pegar o CPF
	scanf("%c", &resto);
	do{
		printf("Digite o CPF(Ex.: 123.456.789-00): ");
		gets(A[pont].cpf);
//		puts(A[pont].cpf);
		veri = cpfVer(A[pont].cpf);
		if (veri == '0'){
			printf("CPF invalido! (verfica se digitado de maneira correta - 123.456.789-00)\n");
		}
	}while(veri == '0');

	A[pont].situacao = 1;

	return;
}

void listar(est A[], int pont){
	/*
	Imprir todas as informacoes de
	todos os cadastros validos
	*/

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
	/*
	Pedir o nome do aluno
	Pesquisar atraves de todos os
	cadastros validos, o nome
	Mostrar todas as informacoes
	sobre o cadastro 
	*/
	return;
}

void atualizar(est A[]){
	/*
	Pedir o ID do aluno
	Pedir pelo:
	Nome
	Data de nascimento
	CPF
	mudar todas as informacoes
	*/

	int ID;
	printf("Iforme o ID do cadastro do aluno que se deseja atualizar: ");
	scanf("%d", &ID);

	cadastrar(A[], ID);

	printf("Informacoes atualizadas!\n")

	return;
}

void remover(est A[]){
	/*
	Solicitar o ID do aluno
	Deixar invalido a sua
	situacao de cadastro (=0)
	*/

	int ID;
	printf("Iforme o ID do cadastro do aluno que se deseja remover: ");
	scanf("%d", &ID);

	A[ID].situacao = 0;

	printf("Situacao do cadastro do aluno agora inativa!\n");

	return;
}

void sair(){
	/*
	escrever sair bonitinho
	*/
	return;
}

char nomeVer(char nome[]){
	/*
	verificar se o nome contem apenas letras 
	e nenhum caracter especial
	*/

	int tam = strlen(nome) - 1;


	for(i = 0; i < tam; i++){
		if(nome[i] == 'a' || nome[i] == 'b' || nome[i] == 'c' || nome[i] == 'd' || nome[i] == 'e' || nome[i] == 'f' || nome[i] == 'g' || nome[i] == 'h' || nome[i] == 'i' || nome[i] == 'j' || nome[i] == 'k' || nome[i] == 'l' || nome[i] == 'm' || nome[i] == 'n' || nome[i] == 'o' || nome[i] == 'p' || nome[i] == 'q' || nome[i] == 'r' || nome[i] == 's' || nome[i] == 't' || nome[i] == 'u' || nome[i] == 'v' || nome[i] == 'w' || nome[i] == 'x' || nome[i] == 'y' || nome[i] == 'z' || nome[i] == ' '){
			if (i < tam - 1) continue;
			else{
			    return '1';
			}
		}
		else if(nome[i] == 'A' || nome[i] == 'B' || nome[i] == 'C' || nome[i] == 'D' || nome[i] == 'E' || nome[i] == 'F' || nome[i] == 'G' || nome[i] == 'H' || nome[i] == 'I' || nome[i] == 'J' || nome[i] == 'K' || nome[i] == 'L' || nome[i] == 'M' || nome[i] == 'N' || nome[i] == 'O' || nome[i] == 'P' || nome[i] == 'Q' || nome[i] == 'R' || nome[i] == 'S' || nome[i] == 'T' || nome[i] == 'U' || nome[i] == 'V' || nome[i] == 'W' || nome[i] == 'X' || nome[i] == 'Y' || nome[i] == 'Z'){
			if (i < tam - 1) continue;
			else return '1';
		}
		else return '0';
	}

}

char dataVer(int d, int m, int a){
	/*
	verificar se a data faz sentido
	*/

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
	/*
	123.456.789-00
	verificar se o CPF tem 14 caracteres
	verificar se possui pontos e tracos nas posicoes corretas
	e verificar se eh apenas numeros
	*/

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
