#include <stdio.h>

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
void cadastro(est A[], int pont);

//funcao de listar todos os alunos
void listar(est A[], int pont);

//funcao de pesquisar pelo aluno
void pesquisar(est A[], int pont);

//funcao que atualiza os dados do aluno
void atualizar(est A[]);

//funcao que invalida o cadastro do aluno
void remover(est A[]);

int main(){
	//ponteiro do ID
	int idPont = 0;
	
	est aluno[MAX];

	return 0;
}

void cadastro(est A[], int pont){
	/*
	Pedir pelo:
	Nome
	Data de nascimento
	CPF
	Deixar situacao do cadastro como valido (=1)
	Caso pont = MAX informar usuario
	e nao chamar essa funcao
	*/
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
