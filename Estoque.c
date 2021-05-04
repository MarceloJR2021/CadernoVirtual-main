#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Estoque.h"

typedef struct estoque Estoque;
typedef struct financas Financas;
//Função para mostrar o menu do Estoque
char menuEstoque(void) {
	char op;
	do{
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
	printf("**           3. Procurar Estoque                                         **\n");	
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
	}while(op != '1' && op != '2' && op != '3' && op != '0');
	return op;
}

//Função para adicionar o estoque
void adicionarEstoque(void){
	Estoque* est;
	Estoque* est2;
	Financas* fin;
	est2 = (Estoque*)malloc(sizeof(Estoque));
	est = telaAdicionarEstoque();
	est2 = aberturaFinancas(est);
	if(est2 != NULL){
		gravarEstoque(est2);
		fin = deletarFinancasest(est2);
		gravarFinancaest(fin);
	}
	free(est);
	free(est2);
}

//Gravar Financa do estoque em Arquivo
void gravarFinancaest(Financas* fin){
	FILE* cd;
	cd = fopen("Financas.dat","wb");
 	fwrite(fin, sizeof(Financas), 1, cd);
	fclose(cd);
}

//Gravar financa removida
Financas* deletarFinancasest(Estoque* est){
	Financas* fi;
	Financas* fin;
	FILE* fd;
	float sub;
	float financaArq;
	float financaNova;
	fi = (Financas*) malloc(sizeof(Financas));
	fin = (Financas*) malloc(sizeof(Financas));
	fd = fopen("Financas.dat","rb");
	fread(fi, sizeof(Financas), 1, fd);
	financaArq = fi->financa;
	financaNova = atof(est->preco);
	sub = financaArq - financaNova;
	fin->financa = sub;
	strcpy(fin->ultEntrada,fi->ultEntrada);
	strcpy(fin->ultSaida,est->preco);
	fclose(fd);
	free(fi);
	return fin;
}




//Abertura de Arquivo de Financas
Estoque* aberturaFinancas(Estoque* est){
	FILE* cd;
	Financas* fin;
	float financasNova;
	fin = (Financas*) malloc(sizeof(Financas));
	cd = fopen("Financas.dat", "rb");
	if (cd == NULL){
		system("cls");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("	Sem Financas Para Adicionar Itens ao Estoque!");
		printf("\n");
		printf("\n");
		printf("\n");
    	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
		return NULL;
	}
	if (cd != NULL) {
		fread(fin, sizeof(Financas), 1, cd);
		financasNova = atof(est->preco);
		if(fin->financa <= financasNova){
			system("cls");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("	Financa Insuficiente Para Adicionar o Item ao Estoque!");
			printf("\n");
			printf("\n");
			printf("\n");
    		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
			getchar();
			fclose(cd);
			free(fin);
			return NULL;
		}
	}
	fclose(cd);
	free(fin);
	return est;
}

//Tela para adicionar Estoque
Estoque* telaAdicionarEstoque(void) {
	Estoque* est;
	est = (Estoque*)malloc(sizeof(Estoque));
	int m;
	int n;
	int i;
	char comp[30];
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------- Adicionar Estoque ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("\t\tItem:  ");
	do{
		strcpy(est->item,"");
		scanf("%[^\n]", est->item);
		getchar();
		m = strlen(est->item);
		if(m == 0){
			system("cls");
			printf("\n");
			printf("\t\tNenhuma Entrada!\n\t\tEntre com o Item:");
		}
	}while(m == 0);
	strcpy(comp,est->item);
	n = strlen(comp);
    	for(i = 0;i < m;i++){
        comp[i] = toupper(comp[i]);
    }
	strcpy(est->item,comp);
	printf("\t\tQuantidade: ");
	do{
		strcpy(est->quantidade,"");
		scanf("%[^\n]",est->quantidade);
		getchar();
		m = strlen(est->quantidade);
		if(!entradaInt(est->quantidade) || m == 0){
			system("cls");
			printf("\n");
			printf("\t\tItem: %s\n\n",est->item);
			printf("\t\tEntrada Invalida!\n\t\tDigite a Quantidade novamente: ");
		}
	}while(!entradaInt(est->quantidade) || m == 0);
	printf("\t\tEntre com a medida:(kg,litro,g,unidade): ");
	do{
		scanf("%[^\n]",est->medida);
		getchar();
		if(!entradaMedida(est->medida)){
			system("cls");
			printf("\n");
			printf("\t\tItem: %s\n",est->item);
			printf("\t\tQuantidade: %s\n\n",est->quantidade);
			printf("\t\tEntrada Invalida!\n\t\tDigite Novamente(kg,litro,g,unidade): ");
		}
	}while(!entradaMedida(est->medida));
	printf("\n");
	printf("\t\tValor Gasto R$(00.00): R$ ");
	do{
		strcpy(est->preco,"");
		scanf("%[^\n]",est->preco);
		getchar();
		m = strlen(est->preco);
		if(!entradaFinanca(est->preco) || m <= 2){
			system("cls");
			printf("\n");
			printf("\t\tItem: %s\n",est->item);
			printf("\t\tQuantidade: %s\n",est->quantidade);
			printf("\t\tMedida: %s\n\n",est->medida);
			printf("\t\tEntrada Invalida!\n\t\tDigite Novamente R$(00.00): R$ ");
		}
	}while(!entradaFinanca(est->preco) || m <= 2);
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
	int m;
	int n;
	int i;
	char comp[30];
	est = (Estoque*) malloc(sizeof(Estoque));
	cd = fopen("Estoque.dat", "rb");
	if (cd == NULL) {
		return NULL;
	}
	while(!feof(cd)) {
		fread(est, sizeof(Estoque), 1, cd);
		strcpy(comp,est->item);
		m = strlen(comp);
    	for(i = 0;i < m;i++){
        comp[i] = toupper(comp[i]);
    	}
		n = strlen(nome);
    	for(i = 0;i < m;i++){
        nome[i] = toupper(nome[i]);
    	}
		if (strcmp(comp, nome) == 0 && est->status == 'a') {
		fclose(cd);
		return est;
		}
	}
	fclose(cd);	
	return NULL;
}



//Função para ver o que tem no Estoque
void exibirEstoque(void) {
    system("cls");
	Estoque* est;
	char nome[30];
	printf("\n");
	printf(" -----------------------------------------------  \n");
	printf(" -----------  Procurar no Estoque  -------------  \n");
	printf(" -----------------------------------------------  \n");
	printf("                                                  \n");
	printf("Entre com o nome do Item para encontrar:");
	scanf("%[^\n]", nome);
	getchar();
	est = procurarEstoque(nome);
	if(est == NULL){
		printf("Item nao encontrado!");
	}
	else{
		printf("\t%s\t%s %s	 \n",est->item,est->quantidade,est->medida);
	}
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
    	printf("\n\n Item nao encontrado!\n\n");
		printf("**                                                                       **\n");
		printf("***************************************************************************\n");
		printf("\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
  	} else {
		est->status = 'd';
		regravarEstoque(est);
		free(est);
		system("cls");
		printf("\n");
		printf("				ITEM REMOVIDO DO ESTOQUE!!");
		printf("\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	}
	
	
}


