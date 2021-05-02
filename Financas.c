#include "Validacoes.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Financas.h"



typedef struct financas Financas;

//Função para mostrar o menu das finanças

char menuFinancas(void) {
	char op;
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ---------------  Menu Financas  ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           1. Adicionar Financas                                       **\n");
	printf("**           2. Remover   Financas                                       **\n");
	printf("**           0. Voltar                                                   **\n");
	printf("**                                                                       **\n");
	printf("             Escolha a opcao desejada:  ");
	scanf("%c", &op);
	getchar();
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return op;
}

//Função para adicionar Finanças
void adicionarFinancas(void){
	Financas* fin;
	fin = telaAdicionarFinancas();
	fin = somaFinancas(fin);
	gravarFinanca(fin);
	free(fin);
}


//Tela para adicionar a Financa
Financas* telaAdicionarFinancas(void) {
	Financas* fin;
	fin = (Financas*) malloc(sizeof(Financas));
	float fi;
	int m;
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------- Adicionar Financas --------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("\t\tValor(R$ 00.00): R$ ");
	do{
		strcpy(fin->ultEntrada,"");
		scanf("%[^\n]",fin->ultEntrada);
		getchar();
		m = strlen(fin->ultEntrada);
		if(!entradaFinanca(fin->ultEntrada) || m <= 2){
			system("cls");
			printf("\n");
			printf("\t\tEntrada Invalida!\n\t\tDigite NovamenteR$(00.00): R$ ");
		}
	}while(!entradaFinanca(fin->ultEntrada) || m <= 2);
	fi = atof(fin->ultEntrada);
	fin->financa = fi;
	strcpy(fin->ultSaida ,"00.00");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("				Financa Adicionada!!");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
		printf("\n");
	return fin;
}


//soma Financas
Financas* somaFinancas(Financas* fin){
	Financas* fi;
	FILE* fd;
	float soma;
	float financaArq;
	float financaNova;
	fi = (Financas*) malloc(sizeof(Financas));
	fd = fopen("Financas.dat","rb");
	if (fd != NULL){
		fread(fi, sizeof(Financas), 1, fd);
		financaArq = fi->financa;
		financaNova = atof(fin->ultEntrada);
		soma = financaArq + financaNova;
		fin->financa = soma;
		strcpy(fin->ultSaida ,fi->ultSaida);
		fclose(fd);
		free(fi);
		return fin;
	}
	free(fi);
	fclose(fd);
	return fin;
	

}

//Remover Financas
Financas* deletarFinancas(Financas* fin){
	Financas* fi;
	FILE* fd;
	float sub;
	float financaArq;
	float financaNova;
	fi = (Financas*) malloc(sizeof(Financas));
	fd = fopen("Financas.dat","rb");
	if(fd == NULL){
		return NULL;
	}
	if(fd != NULL){
		fread(fi, sizeof(Financas), 1, fd);
		financaArq = fi->financa;
		financaNova = atof(fin->ultSaida);
		if(financaNova <= financaArq){
			sub = financaArq - financaNova;
			fin->financa = sub;
			strcpy(fin->ultEntrada,fi->ultEntrada);
		}
		if(financaNova > financaArq){
			sub = financaNova - financaArq;
			system("cls");
			printf("\n");
			printf("\n");
			printf("\t\tSem financas suficiente para remover!\n");
			printf("\n");
			printf("\t\tFaltam %.2f nas Financas!",sub);
			printf("\n");
			printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
			getchar();
			fclose(fd);
			free(fi);
			return fin;
		}
		fclose(fd);
		free(fi);
		system("cls");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("				Financa Removida!!");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
		printf("\n");
		return fin;
	}

}

//Gravar Financa em Arquivo
void gravarFinanca(Financas* fin){
	FILE* cd;
	cd = fopen("Financas.dat","w+b");
 	fwrite(fin, sizeof(Financas), 1, cd);
	fclose(cd);
}



//Função para Remover Finanças
void removerFinancas(void) {
    system("cls");
	Financas* fin;
	fin = (Financas*) malloc(sizeof(Financas));
	int m;
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Remover Financas ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**\t\tValor(R$ 00.00): R$ ");
	do{
		strcpy(fin->ultSaida,"");
		scanf("%[^\n]",fin->ultSaida);
		getchar();
		m = strlen(fin->ultSaida);
		if(!entradaFinanca(fin->ultSaida) || m <= 2){
			system("cls");
			printf("\n");
			printf("\t\tEntrada Invalida!\n\t\tDigite NovamenteR$(00.00): R$ ");
		}
	}while(!entradaFinanca(fin->ultSaida) || m <= 2);
	fin = deletarFinancas(fin);
	if (fin != NULL){
		gravarFinanca(fin);
		printf("**                                                                       **\n");
		printf("***************************************************************************\n");
		printf("\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
		
	}
	if (fin == NULL){
		system("cls");
		printf("\n");
		printf("\n");
		exibirFinancas();
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	}
	free(fin);
}

