#include <stdio.h>
#include <string.h>

//numero maximo de estudantes
#define	MAX 20
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
				//puts(aluno[idPont].nome);
				//printf("%d/%d/%d\n\n", aluno[idPont].nasc.dia, aluno[idPont].nasc.mes, aluno[idPont].nasc.ano);
				idPont++;
				break;
			case '2':
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
	CPF
	Deixar situacao do cadastro como valido (=1)
	(feito) Caso pont == MAX informar usuario e nao chamar essa funcao
	*/

	//char de verificacao
	char veri;
	A[pont].id = pont;

	//pegar o nome
	do{
		printf("Nome do aluno: ");
		fgets(A[pont].nome, NOME +1 , stdin);
		veri = nomeVer(A[pont].nome);
		if (veri == '0'){
			printf("Nome invalido! (verificar se nao foi digitado algum numero ou caracter especial)\n");
		}
	}while(veri == '0');

	//pegar a data de nascimento
	do{
		printf("Data de Nascimento(dd/mm/aaaa): ");
		scanf("%d/%d/%d", &A[pont].nasc.dia, &A[pont].nasc.mes, &A[pont].nasc.ano);
		veri = nascVer(A[pont].nasc.dia, A[pont].nasc.mes, A[pont].nasc.ano);
		if (veri == '0'){
			printf("Data de nascimento invalida! (verificar se a data foi digitada de maneira correta)\n");
		}
	}while(veri == '0');

	return;
}

void listar(est A[], int cad){
	/*
	Imprir todas as informacoes de
	todos os cadastros validos
	*/
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
	return;
}

void remover(est A[]){
	/*
	Solicitar o ID do aluno
	Deixar invalido a sua
	situacao de cadastro (=0)
	*/
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

	int i;
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