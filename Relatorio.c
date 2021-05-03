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
	int cont;
	cont = quantReceitas();
	Preparo* prep;
	prep = (Preparo*) malloc(sizeof(Preparo));
	printf("\n");
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
	 while (rec != NULL){
        printf("\n= = = Receita = = =\n");
		printf("Codigo da Receita: %s\n", rec->codReceita);
		printf("Nome: %s\n", rec->nome);
		printf("Origem: %s\n", rec->origem);
		printf("Obtencao: %s\n", rec->obtencao);
		printf("Tempo de Preparo: %s minutos\n", rec->tempo);
		printf("Dificuldade de Preparo: %s\n", rec->dificuldade);
		printf("Status da Receita: %c\n", rec->status);
		prep = buscaPreparo(rec->codReceita);
		exibirPreparo(prep);
		exibirIngredientes(rec->codReceita);
        rec = rec->prox;
		printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
    	getchar();
		system("cls");
	}
	printf("\n");
 	printf("\t\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
	free(prep);
	system("cls");

}
//exibir Estoque Ordenado
void exibirestOrdenada(Estoque* est){
	system("cls");
	int m;
	int contest;
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
	printf("\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("   Nome\t\t\t|| Quantidade ||\tMedida");
	printf("\n");
	printf("\n");
	while(est != NULL){
		m = strlen(est->item);
		if(m < 5){
			printf("  %s \t",est->item);
			printf("\t\t\t %s",est->quantidade);
			printf("\t\t %s\n",est->medida);
			est = est->prox;

		}
		else{
			printf("  %s \t",est->item);
			printf("\t\t %s",est->quantidade);
			printf("\t\t %s\n",est->medida);
			est = est->prox;
		}
		
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();


}

//Apagar lista Estoque
void apagarListaest(Estoque **listaest){
    Estoque *est;
    
    while (*listaest != NULL){
   	    est = *listaest;
        *listaest = (*listaest)->prox;
        free(est);
    }   
}

//Apagar lista Receita
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
		system("cls");
		printf("\n");
		printf("\n");
		printf("\tArquivo nao encontrado!");
		printf("\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	}
	else{
		rec = (Receita*) malloc(sizeof(Receita));
		while(fread(rec,sizeof(Receita),1,cd)){
			if(rec->status == 'a'){
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
			}
			rec = (Receita*) malloc(sizeof(Receita));
		}
	free(rec);
	fclose(cd);
	}
}




//ordenar Estoque
void ordenarestEstoque(Estoque **estc){
	FILE* cd;
	Estoque* est;
	
	apagarListaest(&(*estc));
    *estc = NULL;
	cd = fopen("Estoque.dat","rb");

	if(cd == NULL){
		system("cls");
		printf("\n");
		printf("\n");
		printf("\tArquivo nao encontrado!");
		printf("\n");
		printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
		getchar();
	}
	else{
		est = (Estoque*) malloc(sizeof(Estoque));
		while(fread(est,sizeof(Estoque),1,cd)){
			if(est->status == 'a'){
				if(*estc == NULL || strcmp(est->item,(*estc)->item) < 0){
					est->prox = *estc;
					*estc = est;
				}
				else{
					Estoque* ante = *estc;
					Estoque* atuc = (*estc)->prox;
					while((atuc != NULL) && (strcmp(atuc->item,est->item) < 0) && (atuc->status = 'a')){
						ante = atuc;
						atuc = atuc->prox;
					}
					ante->prox = est;
					est->prox = atuc;

				}
			}
				est = (Estoque*) malloc(sizeof(Estoque));
			
		}
	free(est);
	fclose(cd);

	}
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