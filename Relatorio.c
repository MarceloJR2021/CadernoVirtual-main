#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Receitas.h"
#include "Estoque.h"


char menuRelatorio(void) {
	char op;
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ---------------  Menu Relatorio  --------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           1. Relatorio de Receitas                                    **\n");
	printf("**           2. Relatorio de Estoque                                     **\n");
	printf("**           3. Relatorio de Financas                                    **\n");
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




//Contar Receitas
int quantReceitas(void){
	FILE* cd;
	Receita* rec;
	int cont = 0;
	rec = (Receita*) malloc(sizeof(Receita));
	cd = fopen("Receitas.dat", "rb");
	if (cd == NULL) {
		return cont;
	}
	while(!feof(cd)) {
		fread(rec, sizeof(Receita), 1, cd);
		if (rec->status == 'a' && !feof(cd)) {
		cont++;
		}
	}
	fclose(cd);	
	free(rec);
	return cont;
}

//Contar Estoque
int quantEstoque(void){
	FILE* cd;
	Estoque* est;
	int cont = 0;
	est = (Estoque*) malloc(sizeof(Estoque));
	cd = fopen("Estoque.dat", "rb");
	if (cd == NULL) {
		return cont;
	}
	while(!feof(cd)) {
		fread(est, sizeof(Estoque), 1, cd);
		if (est->status == 'a' && !feof(cd)) {
		cont++;
		}
	}
	fclose(cd);	
	free(est);
	return cont;
}

//exibir Receitas ordenadas
void exibirrecOrdenada(Receita* rec){
	system("cls");
	printf("\n");
	 while (rec != NULL){
        printf("\n= = = Receita = = =\n");
		printf("Codigo da Receita: %s\n", rec->codReceita);
		printf("Nome: %s\n", rec->nome);
		printf("Origem: %s\n", rec->origem);
		printf("Obtencao: %s\n", rec->obtencao);
		printf("Tempo de Preparo: %s minutos\n", rec->tempo);
		printf("Dificuldade de Preparo: %s\n", rec->dificuldade);
		printf("Status da Receita: %c\n", rec->status);
        rec = rec->prox;
    }
	printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////////////////////////\n\n");
    printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
	system("cls");

}

//Apagar lista
void apagarLista(Receita **lista){
    Receita *rec;
    
    while (*lista != NULL){
   	    rec = *lista;
        *lista = (*lista)->prox;
        free(rec);
    }   
}


//Ordenar
void ordenarrecReceitas(Receita **rect){
	FILE* cd;
	Receita* rec;
	
	apagarLista(&(*rect));
    *rect = NULL;
	cd = fopen("Receitas.dat","rb");

	if(cd == NULL){
		printf("Arquivo nao encontrado!");
	}
	else{
		rec = (Receita*) malloc(sizeof(Receita));
		while(fread(rec,sizeof(Receita),1,cd)){
			if(*rect == NULL || strcmp(rec->nome,(*rect)->nome) < 0){
				rec->prox = *rect;
				*rect = rec;
			}
			else{
				Receita* ant = *rect;
				Receita* atu = (*rect)->prox;
				while((atu != NULL) && (strcmp(atu->nome,rec->nome) < 0)){
					ant = atu;
					atu = atu->prox;
				}
				ant->prox = rec;
				rec->prox = atu;

			}
			rec = (Receita*) malloc(sizeof(Receita));
		}
	free(rec);
	fclose(cd);
	}
}




//ordenar Estoque
void ordenarEstoque(void){
	FILE* cd;
	Estoque* est;
	Estoque* menor;
	int m = 0;
	int n = 0;
	est = (Estoque*) malloc(sizeof(Estoque));
	menor = (Estoque*) malloc(sizeof(Estoque));
	cd = fopen("Estoque.dat", "rb");
	m = quantEstoque();
	printf("\n");
	printf("\n");
	if (cd == NULL) {
		printf("Arquivo de Estoque nao encontrado!");
	}
	else{
		do{
			fread(menor, sizeof(Estoque), 1, cd);
			while(!feof(cd) && menor->status == 'a'){
				fread(est, sizeof(Estoque), 1, cd);
				if(est->status == 'a' && strcmp(est->item,menor->item) < 0){
					menor = est;
					break;
				}
				if(est->status == 'a' && strcmp(est->item,menor->item) == 0){
					fclose(cd);
					cd = fopen("Estoque.dat", "rb");
					break;
				}
			}
			printf("  %s ",menor->item);
			printf("\t\t\t %s",menor->quantidade);
			printf("\t\t\t %s\n",menor->medida);
			n++;
		}while(n < m);

	}
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	fclose(cd);
	free(est);
	free(menor);

}



//Funcao para exibir Receitas
void exibirtodas(void){
	FILE* cd;
	Receita* rec;
	Preparo* prep;
	Ingredientes* ing;
	ing = (Ingredientes*) malloc(sizeof(Ingredientes));
	prep = (Preparo*) malloc(sizeof(Preparo));
	rec = (Receita*) malloc(sizeof(Receita));
	cd = fopen("Receitas.dat", "rb");
	if (cd == NULL) {
		printf("Arquivos de Receitas nao Existe!");
	}
	else{
		while(!feof(cd)) {
			fread(rec, sizeof(Receita), 1, cd);
			if ( rec->status == 'a' && !feof(cd)) {
			printf("\t\t\t***RECEITAS***");
			exibirReceita(rec);
			prep = buscaPreparo(rec->codReceita);
			exibirPreparo(prep);
			exibirIngredientes(rec->codReceita);
			printf("\n");
			printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
			getchar();
			system("cls");
			}
		}
	}
		free(rec);
		free(prep);
		free(ing);
}

//Exibir todo Estoque
void exibirtodoEstoque(void){
		FILE* cd;
	Estoque* est;
	int m;
	est = (Estoque*) malloc(sizeof(Estoque));
	cd = fopen("Estoque.dat", "rb");
	if (cd == NULL) {
		printf("Arquivo de Estoque nao encontrado!");
	}
	else{
		while(!feof(cd)) {
			fread(est, sizeof(Estoque), 1, cd);
			if (est == NULL) {
					printf("\n Nao Existem Ingredientes para Exibir \n");
			}
			if(est->status == 'a' && !feof(cd)) {
				m = strlen(est->item);
				if(m >= 13 && m <= 20){
					printf("  %s \t",est->item);
					printf("\t\t %s",est->quantidade);
					printf("\t\t %s\n",est->medida);

				}	
				if(m >= 5 && m < 13){
					printf("  %s \t\t",est->item);
					printf("\t\t %s",est->quantidade);
					printf("\t\t %s\n",est->medida);

				}
				if(m > 20){
					printf("  %s \t",est->item);
					printf("\t %s",est->quantidade);
					printf("\t\t %s\n",est->medida);
				}
				}
		}
	}
	fclose(cd);	
	free(est);
}
	




void relatorioReceitas(void) {
	int cont;
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------  Relatorio de Receitas -----------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	cont = quantReceitas();
	printf("             Quantidade de Receitas: %d                                    \n",cont);
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	exibirtodas();
}

//Tela exibir estoque
void relatorioEstoque(void){
	int contest;
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------------ Estoque --------------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	contest = quantEstoque();
	printf("             Quantidade de Itens no Estoque: %d                           \n", contest);
	printf("\n");
	printf("\n");
	printf("  \tNome\t\t\t|| Quantidade ||\tMedida");
	printf("\n");
	printf("\n");
	exibirtodoEstoque();
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();

}

//Funcao ver Financa
void exibirFinancas(void) {
	FILE* cd;
	Financas* fin;
	fin = (Financas*) malloc(sizeof(Financas));
	cd = fopen("Financas.dat", "rb");
	if (cd == NULL){
		printf("\t\tArquivo nao encontrado!\n");
	}
	if (cd != NULL) {
		fread(fin, sizeof(Financas), 1, cd);
		printf("\tR$ %.2f", fin->financa);
		printf("\t\tR$ %s",fin->ultEntrada);
		printf("\t\tR$ %s",fin->ultSaida);
	}
	fclose(cd);
	free(fin);
		
}



void relatorioFinancas(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------  Relatorio de Financas -----------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("\tFINANCAS\t|| ULTIMA ENTRADA\t|| ULTIMA SAIDA\n");
	exibirFinancas();
	printf("\n");
	printf("\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}