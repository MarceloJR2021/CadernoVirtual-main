#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Estoque.h"

typedef struct estoque Estoque;
//Função para mostrar o menu do Estoque
char menuEstoque(void) {
	char op;
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ---------------  Menu Estoque   ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           1. Adicionar Estoque                                        **\n");
	printf("**           2. Remover Estoque                                          **\n");
	printf("**           3. Ver Estoque                                              **\n");
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

//Função para adicionar o estoque
void adicionarEstoque(void){
	Estoque* est;
	est = telaAdicionarEstoque();
	gravarEstoque(est);
	free(est);
}

//Tela para adicionar Estoque

Estoque* telaAdicionarEstoque(void) {
	Estoque* est;
	est = (Estoque*)malloc(sizeof(Estoque));

    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------- Adicionar Estoque ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("             Item:  ");
	scanf("%[^\n]", est->item);
	getchar();
	printf("             Quantidade:   ");
	do{
		scanf("%[^\n]",est->quantidade);
		getchar();
		if(!entradaInt(est->quantidade)){
			printf("	     Entrada Invalida!\n	     Digite Novamente: ");
		}
	}while(!entradaInt(est->quantidade));
	printf("	     Entre com a medida:(kg,litro,g,unidade): ");
	do{
		scanf("%[^\n]",est->medida);
		getchar();
		if(!entradaMedida(est->medida)){
			printf("	     Entrada Invalida!\n	     Digite Novamente: ");
		}
	}while(!entradaMedida(est->medida));
	printf("             Valor Gasto R$(00.00):    ");
	do{
		scanf("%[^\n]",est->preco);
		getchar();
		if(!entradaFinanca(est->preco)){
			printf("	   Entrada Invalida!\n	     Digite NovamenteR$(00.00): R$ ");
		}
	}while(!entradaFinanca(est->preco));
	est->status = 'a';
	printf("**                                                                       **\n");	
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return est;
}

//Gravar Estoque em Arquivo
void gravarEstoque(Estoque* est){
	FILE* cd;
	cd = fopen("Estoque.dat","ab");
	if (cd == NULL) {
		cd = fopen("Estoque.dat","wb");
  	}
  	fwrite(est, sizeof(Estoque), 1, cd);
  	fclose(cd);
}

void regravarEstoque(Estoque* est) {
	FILE* cd;
	Estoque* nest;
	nest = (Estoque*) malloc(sizeof(Estoque));
	cd = fopen("Estoque.dat", "r+b");
	if (cd == NULL) {
		printf("Arquivo nao encontrado!");
	}
	// while(!feof(fp)) {
	while(fread(nest, sizeof(Estoque), 1, cd)) {
		if (strcmp(nest->item, est->item) == 0) {
			fseek(cd, -1*sizeof(Estoque), SEEK_CUR);
        	fwrite(est, sizeof(Estoque), 1, cd);
			break;
		}
	}
	fclose(cd);
	free(nest);
}


Estoque* procurarEstoque(char* nome) {
	FILE* cd;
	Estoque* est;
	est = (Estoque*) malloc(sizeof(Estoque));
	cd = fopen("Estoque.dat", "rb");
	if (cd == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar este programa...\n");
		exit(1);
	}
	while(!feof(cd)) {
		fread(est, sizeof(Estoque), 1, cd);
		if (strcmp(est->item, nome) == 0 && est->status == 'a') {
		fclose(cd);
		return est;
		}
		else {
			return NULL;
		}
	}
	fclose(cd);	
}



//Função para ver o que tem no Estoque
void exibirEstoque(void) {
    system("cls");
	Estoque* est;
	char nome[15];
	printf("\n");
	printf(" -----------------------------------------------  \n");
	printf(" -----------  Procurar no Estoque  -------------  \n");
	printf(" -----------------------------------------------  \n");
	printf("                                                  \n");
	printf("Entre com o nome do Item para encontrar:");
	scanf("%[^\n]", nome);
	est = procurarEstoque(nome);
	if (est != NULL){
		printf("       %s - %s - %s	 \n",est->item,est->quantidade,est->medida);
	}
	getchar();		
	printf("\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

//Função para Remover Estoque
void removerEstoque(void) {
    system("cls");
	Estoque* est;
	est = (Estoque*)malloc(sizeof(Estoque));
	char item[15];
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Remover Estoque ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("             Item:  ");
	scanf("%[^\n]", item);
	getchar();
	est = procurarEstoque(item);
	if (est == NULL) {
    	printf("\n\n Item não encontrado!\n\n");
  	} else {
		  est->status = 'd';
		  regravarEstoque(est);
		  free(est);
	}
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	printf("\n");
	printf("				ITEM REMOVIDO DO ESTOQUE!!");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

