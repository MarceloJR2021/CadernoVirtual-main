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
    printf("**           3. Ver Financas                                             **\n");
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
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------- Adicionar Financas --------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("             Valor(R$ 00.00): R$ ");
	do{
		scanf("%[^\n]",fin->ultEntrada);
		getchar();
		if(!entradaFinanca(fin->ultEntrada)){
			printf("	   Entrada Invalida!\n	   Digite NovamenteR$(00.00): R$ ");
		}
	}while(!entradaFinanca(fin->ultEntrada));
	fi = atof(fin->ultEntrada);
	fin->financa = fi;
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
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
	if(fd != NULL){
		fread(fi, sizeof(Financas), 1, fd);
		financaArq = fi->financa;
		financaNova = atof(fin->ultSaida);
		sub = financaArq - financaNova;
		fin->financa = sub;
		strcpy(fin->ultEntrada,fi->ultEntrada);
		fclose(fd);
		free(fi);
		return fin;
	}

}

//Gravar Financa em Arquivo
void gravarFinanca(Financas* fin){
	FILE* cd;
	cd = fopen("Financas.dat","wb");
 	fwrite(fin, sizeof(Financas), 1, cd);
	fclose(cd);
}

//Funcao ver Financa
void exibirFinancas(void) {
	FILE* cd;
	Financas* fin;
	fin = (Financas*) malloc(sizeof(Financas));
	cd = fopen("Financas.dat", "rb");
	fread(fin, sizeof(Financas), 1, cd);
	if (cd == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar este programa...\n");
		exit(1);
	}
	printf("		Financa:  R$ %.2f \n", fin->financa);
	printf("		ultEntrada:  R$ %s \n", fin->ultEntrada);
	printf("		ultSaida:  R$ %s \n", fin->ultSaida);
	fclose(cd);
	free(fin);
		
}

//Função para Remover Finanças
void removerFinancas(void) {
    system("cls");
	Financas* fin;
	fin = (Financas*) malloc(sizeof(Financas));

	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Remover Financas ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Valor(R$ 00.00): R$ ");
	do{
		scanf("%[^\n]",fin->ultSaida);
		getchar();
		if(!entradaFinanca(fin->ultSaida)){
			printf("	   Entrada Invalida!\n	   Digite NovamenteR$(00.00): R$ ");
		}
	}while(!entradaFinanca(fin->ultSaida));
	fin = deletarFinancas(fin);
	gravarFinanca(fin);
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	printf("\n");
	printf("				Financa Removida!!");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	free(fin);
}

//Função para Ver as Finanças

void verFinancas(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           --------------   Ver Financas  ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	exibirFinancas();
	printf("\n");
	printf("\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}