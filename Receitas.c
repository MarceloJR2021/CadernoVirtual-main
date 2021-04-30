#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacoes.h"
#include <ctype.h>
#include "Receitas.h"
#include "Estoque.h"


typedef struct receitas Receita;
typedef struct preparo Preparo;
typedef struct ingredientes Ingredientes;

//Função para mostrar o menu das Receiats

char menuReceitas(void) {
	char op;
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ---------------  Menu Receitas  ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           1. Cadastrar Receitas                                       **\n");
	printf("**           2. Encontrar Receitas                                       **\n");
	printf("**           3. Atualizar Receitas                                       **\n");
    printf("**           4. Deletar receitas                                         **\n");
	printf("**           5. Ver Receitas                                             **\n");
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

//Função para Cadastrar Receitas
void CadastrarReceitas(void) {
	Receita* rec;
	Ingredientes* ing;
	Preparo* prep;
	char escolha[2];
	int m;
	rec = telaPreencherReceita();
	prep = telaPreencherPreparo();
	strcpy(prep->codReceita,rec->codReceita);
	do{
		ing = telaPreencherIngredientes();
		strcpy(ing->codReceita,rec->codReceita);
		gravarIngredientes(ing);
		free(ing);
		system("cls");
		printf("	   Deseja Adicionar mais Ingredientes(S/N) :");
		do{
			strcpy(escolha,"");
			scanf("%[^\n]",escolha);
			getchar();
			m = strlen(escolha);
			if(m == 0 || strcmp(escolha,"N") != 0 && strcmp(escolha,"S") != 0){
			system("cls");
			printf("\n");
			printf("	Entrada Invalida!\n	Entre Novamente(S/N):");
			}
		}while(m == 0 || strcmp(escolha,"N") != 0 && strcmp(escolha,"S") != 0);
	}while(strcmp(escolha,"S") == 0);
	gravarReceita(rec);
	gravarPreparo(prep);
	free(rec);
	free(prep);
}

//Tela de preencher Ingredientes
Ingredientes* telaPreencherIngredientes(void){
	system("cls");
	Ingredientes* ing;
	int m;
	ing = (Ingredientes*)malloc(sizeof(Ingredientes));
	ing->status = 'a';
	printf("***************************************************************************\n");
	printf("           Ingredientes: \n");
	printf("           Entre com o nome do Ingrediente: ");
		do{
			strcpy(ing->ingredientes,""),
			scanf("%[^\n]",ing->ingredientes);
			getchar();
			m = strlen(ing->ingredientes);
			printf("\n");
			if(m == 0){
				system("cls");
				printf("\n");
				printf("\t\tIngredientes: \n");
				printf("\tNenhuma Entrada!\n\tEntre com o nome do Ingrediente:");
			}
		}while(m == 0);
		printf("	   Entre com a medida:(kg,litro,g,unidade): ");
		do{
			scanf("%[^\n]", ing->medida);
			getchar();
			if(!entradaMedida(ing->medida)){
				printf("	   Entrada Invalida!\n	   Digite Novamente: ");
			}
		}while(!entradaMedida(ing->medida));
		printf("           Entre com a Quantidade do Ingrediente(So Numero): ");
		do{
			strcpy(ing->quantidade,"");
			scanf("%[^\n]",ing->quantidade);
			getchar();
			m = strlen(ing->quantidade);
			if(!entradaInt(ing->quantidade) || m == 0){
				printf("	   Entrada Invalida!\n	   Digite Novamente: ");
			}
		}while(!entradaInt(ing->quantidade) || m == 0);
		
		system("cls");
		printf("\n");
	return ing;
	
}

//Tela de Preencher Preparo da Receita
Preparo* telaPreencherPreparo(void){
	Preparo* prep;
	prep = (Preparo*) malloc(sizeof(Preparo));
	int m;
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------  Cadastrar Preparo  --------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("\n");
	printf("           Entre com o Preparo da Receita: ");
	do{
		strcpy(prep->preparo,"");
		scanf("%[^\n]", prep->preparo);
		getchar();
		m = strlen(prep->preparo);
		printf("\n");
		if(m == 0){
			system("cls");
			printf("\n");
			printf("\tNenhuma Entrada!\n\tEntre Novamente com o Preparo:\n\t");
		}
	}while(m == 0);
	system("cls");
	prep->status = 'a';
	return prep;

}



//Tela de Preencher Receita
Receita* telaPreencherReceita(void){
	Receita* rec;
	rec = (Receita*) malloc(sizeof(Receita));
	char escolha[2];
	int m;

    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------  Cadastrar Receitas  -------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("\n");
	printf("           Codigo da Receita(Ex:A1,B2,C3..): ");
	do{
		strcpy(rec->codReceita,"");
		scanf("%[^\n]", rec->codReceita);
		getchar();
		m = strlen(rec->codReceita);
		printf("\n");
		if(m == 0){
			system("cls");
			printf("\n");
			printf("	Nenhuma Entrada!\n	Entre Novamente(Ex:A1,B2,C3..):");
		}
	}while(m == 0);
	system("cls");
	printf("***************************************************************************\n");
	printf("           Nome da Receita: ");
	do{
		strcpy(rec->nome,"");
		scanf("%[^\n]", rec->nome);
		getchar();
		m = strlen(rec->nome);
		printf("\n");
		if(m == 0){
			system("cls");
			printf("\n");
			printf("	Entre com algum Nome:");
		}
	}while(m == 0);
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Origem da Receita(Pais ou Regiao): ");
	do{
		strcpy(rec->origem,"");
		scanf("%[^\n]",rec->origem);
		getchar();
		m = strlen(rec->origem);
		printf("\n");
		if(m == 0){
			system("cls");
			printf("\n");
			printf("	Entre com alguma Origem:");
		}
		
	}while(m == 0);
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Local de Obtencao da Receita(Site,Livro,Revista): ");
	do{
		strcpy(rec->obtencao,"");
		scanf("%[^\n]",rec->obtencao);
		getchar();
		m = strlen(rec->obtencao);
		printf("\n");
		if(m == 0){
			system("cls");
			printf("\n");
			printf("	Entre com algum Local de Obtencao da Receita:");
		}
	}while(m == 0);
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Tempo de Preparo em minutos(Somente numeros) : ");
	do{
			scanf("%[^\n]",rec->tempo);
			getchar();
			if(!entradaInt(rec->tempo)){
				printf("	   Entrada Invalida!\n	   Digite Novamente: ");
			}
	}while(!entradaInt(rec->tempo));
	printf("\n");
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Dificuldade de preparo,primeira letra(F[facil],M[medio] OU D[dificil]): ");
	do{
		scanf("%[^\n]",rec->dificuldade);
		getchar();
		strcpy(escolha,rec->dificuldade);
		if(strcmp(escolha,"F") != 0 && strcmp(escolha,"M") != 0 && strcmp(escolha,"D") != 0){
			printf("\n");
			printf("	Entrada Invalida!\n	Entre Novamente(F,M ou D):");
		}
	}while(strcmp(escolha,"F") != 0 && strcmp(escolha,"M") != 0 && strcmp(escolha,"D") != 0);
	printf("\n");
	rec->status = 'a';
	printf("***************************************************************************\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return rec;
}


//Gravar Receita em arquivo
void gravarReceita(Receita* rec){
	FILE* cd;
	cd = fopen("Receitas.dat","ab");
	if (cd == NULL) {
		cd = fopen("Receitas.dat","wb");
  }
  fwrite(rec, sizeof(Receita), 1, cd);
  fclose(cd);
}

//Gravar Preparo em arquivo
void gravarPreparo(Preparo* prep){
	FILE* pr;
	pr = fopen("Preparo.dat","ab");
	if (pr == NULL) {
		pr = fopen("Preparo.dat","wb");
  }
  fwrite(prep, sizeof(Preparo), 1, pr);
  fclose(pr);
}

//Gravar Ingredientes em arquivo
void gravarIngredientes(Ingredientes* ing){
	FILE* in;
	in = fopen("Ingredientes.dat","ab");
	if (in == NULL) {
		in = fopen("Ingredientes.dat","wb");
  }
  fwrite(ing, sizeof(Ingredientes), 1, in);
  fclose(in);
}

//Regravar Receita
void regravarReceita(Receita* rec) {
	FILE* cd;
	Receita* nrec;

	nrec = (Receita*) malloc(sizeof(Receita));
	cd = fopen("Receitas.dat", "r+b");
	if (cd == NULL) {
		printf("Arquivo nao encontrado!");
	}
	while(fread(nrec, sizeof(Receita), 1, cd)) {
		if (strcmp(nrec->codReceita, rec->codReceita) == 0) {
			fseek(cd, -1*sizeof(Receita), SEEK_CUR);
        	fwrite(rec, sizeof(Receita), 1, cd);
			break;
		}
	}
	fclose(cd);
	free(nrec);
}

//Regravar Preparo
void regravarPreparo(Preparo* prep) {
	FILE* cd;
	Preparo* nprep;

	nprep = (Preparo*) malloc(sizeof(Preparo));
	cd = fopen("Preparo.dat", "r+b");
	if (cd == NULL) {
		printf("Arquivo nao encontrado!");
	}
	while(fread(nprep, sizeof(Preparo), 1, cd)) {
		if (strcmp(nprep->codReceita, prep->codReceita) == 0) {
			fseek(cd, -1*sizeof(Preparo), SEEK_CUR);
        	fwrite(prep, sizeof(Preparo), 1, cd);
			break;
		}
	}
	fclose(cd);
	free(nprep);
}

//Regravar Ingredientes
void regravarIngredientes(Ingredientes* ing) {
	FILE* cd;
	Ingredientes* ning;
	ning = (Ingredientes*) malloc(sizeof(Ingredientes));
	cd = fopen("Ingredientes.dat", "r+b");
	if (cd == NULL) {
		printf("Arquivo nao encontrado!");
	}
	while(fread(ning, sizeof(Ingredientes), 1, cd)) {
			if (strcmp(ning->codReceita, ing->codReceita) == 0) {
				fseek(cd, -1*sizeof(Ingredientes), SEEK_CUR);
				fwrite(ing, sizeof(Ingredientes), 1, cd);
				break;
			}
		}
	fclose(cd);
	free(ning);
}


//Buscar Receita
Receita* buscarReceita(char* cod) {
	FILE* cd;
	Receita* rec;
	rec = (Receita*) malloc(sizeof(Receita));
	cd = fopen("Receitas.dat", "rb");
	if (cd == NULL) {
		return NULL;
	}
	while(!feof(cd)) {
		fread(rec, sizeof(Receita), 1, cd);
		if (strcmp(rec->codReceita, cod) == 0 && rec->status == 'a') {
		fclose(cd);
		return rec;
		}
	}
	fclose(cd);	
	return NULL;
}


//busca de preparo da receita
Preparo* buscaPreparo(char* cod){
	FILE* cd;
	Preparo* prep;
	prep = (Preparo*) malloc(sizeof(Preparo));
	cd = fopen("Preparo.dat", "rb");
	if (cd == NULL) {
		return NULL;
	}
	while(!feof(cd)) {
		fread(prep, sizeof(Preparo), 1, cd);
		if (strcmp(prep->codReceita, cod) == 0 && prep->status == 'a') {
		fclose(cd);
		return prep;
		}
	}
	fclose(cd);	
	return NULL;
}

//busca de Ingredientes da Receita
Ingredientes* buscaIngredientes(char* cod){
	FILE* cd;
	Ingredientes* ing;
	ing = (Ingredientes*) malloc(sizeof(Ingredientes));
	cd = fopen("Ingredientes.dat", "rb");
	if (cd == NULL) {
		return NULL;
	}
	while(!feof(cd)) {
		fread(ing, sizeof(Ingredientes), 1, cd);
		if (strcmp(ing->codReceita, cod) == 0 && ing->status == 'a') {
		fclose(cd);
		return ing;
		}
	}
	fclose(cd);	
	return NULL;
}

//exibe conteudo do arquivo
void exibirReceita(Receita* rec) {

  if (rec == NULL) {
    printf("\n Nao Existem Receitas para Exibir \n");
  } else {
    printf("\n= = = Receita = = =\n");
	printf("Codigo da Receita: %s\n", rec->codReceita);
    printf("Nome: %s\n", rec->nome);
    printf("Origem: %s\n", rec->origem);
    printf("Obtencao: %s\n", rec->obtencao);
    printf("Tempo de Preparo: %s minutos\n", rec->tempo);
    printf("Dificuldade de Preparo: %s\n", rec->dificuldade);
	printf("Status da Receita: %c\n", rec->status);
  }
}

//Exibir preparo da Receita
void exibirPreparo(Preparo* prep){
	if (prep == NULL) {
    printf("\n Nao Existem Receitas para Exibir \n");
  } else {
    printf("\n= = = Preparo = = =\n");
	printf("Preparo :  %s \n",prep->preparo);
	printf("\n= = = Ingredientes da Receita = = =\n");
  }
}

//Exibir ingredientes da Receita
void exibirIngredientes(char* cod){
	FILE* cd;
	Ingredientes* ing;
	ing = (Ingredientes*) malloc(sizeof(Ingredientes));
	cd = fopen("Ingredientes.dat", "rb");
	if (cd == NULL) {
		printf("Arquivo de ingredientes nao encontrado!");
	}
	while(!feof(cd)) {
		fread(ing, sizeof(Ingredientes), 1, cd);
		if (ing == NULL) {
				printf("\n Nao Existem Ingredientes para Exibir \n");
		}
		if(strcmp(ing->codReceita, cod) == 0 && ing->status == 'd'){
			printf("\n Nao Existem Ingredientes para Exibir \n");
			fclose(cd);	
			free(ing);
			break;
		}
		if(strcmp(ing->codReceita, cod) == 0 && ing->status == 'a' && !feof(cd)) {			
			printf("Item :  %s  - %s  - %s\n",ing->ingredientes,ing->quantidade,ing->medida);
			if (vernoEstoque(ing)){
				printf("	NAO Contem no Estoque!\n");
			}
			else{
				printf("	Contem no Estoque!\n");
			}
		}
	}
	fclose(cd);	
	free(ing);
}



//Função para Encontrar Receitas

void encontrarReceitas(void) {
    system("cls");
	Receita* rec;
	Preparo* prep;
	Ingredientes* ing;
	char cod[4];
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------- Encontrar Receita   -------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Digite o Codigo da Receitas:                                **\n");	
	printf("             ");
	scanf("%[^\n]", cod);
	rec = buscarReceita(cod);
	prep = buscaPreparo(cod);
	getchar();
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	exibirReceita(rec);
	exibirPreparo(prep);
	exibirIngredientes(cod);
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	free(rec);
	free(prep);
}

//Função para Atualizar as Receitas

void atualizarReceitas(void) {
    system("cls");
	Receita* rec;
	Preparo* prep;
	Ingredientes* ing;
	char cod[4];
	char op;
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Atualizar Receita --------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Codigo da Receita para Atualizar:                           **\n");
	printf("             ");
	scanf("%[^\n]", cod);
	getchar();
	rec = buscarReceita(cod);
	prep = buscaPreparo(cod);
	ing = buscaIngredientes(cod);
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	op = telaescolha();	
	system("cls");
	switch (op)
	{
		case '1' :
		printf("\n");
		printf("\n");
		printf("	Nome:%s\n\n",rec->nome);
		printf("	Entre com o novo nome:");
		scanf("%[^\n]", rec->nome);
		getchar();
		system("cls");
		break;

		case '2' :
		printf("\n");
		printf("\n");
		printf("	Origem:%s\n\n",rec->origem);
		printf("	Entre com a Origem:");
		scanf("%[^\n]", rec->origem);
		getchar();
		system("cls");
		break; 

		case '3' :
		printf("\n");
		printf("\n");
		printf("	Obtencao:%s\n",rec->obtencao);
		printf("	Entre com a Obtencao:");
		scanf("%[^\n]", rec->obtencao);
		getchar();
		system("cls");
		break;

		case '4' :
		printf("\n");
		printf("\n");
		printf("	Tempo de Preparo:%s\n\n",rec->tempo);
		printf("	Entre com o tempo de preparo:");
		scanf("%[^\n]", rec->tempo);
		getchar();
		system("cls");
		break;

		case '5' :
		printf("\n");
		printf("\n");
		printf("	Dificuldade de Preparo:%s\n\n",rec->dificuldade);
		printf("	Entre com a dificuldade de Preparo:");
		scanf("%[^\n]", rec->dificuldade);
		getchar();
		system("cls");
		break;

		case '6' :
		printf("\n");
		printf("\n");
		printf("	Preparo:\n	%s\n\n",prep->preparo);
		printf("	Entre com o Preparo:");
		scanf("%[^\n]", rec->dificuldade);
		getchar();
		system("cls");
		break;
	}
	strcpy(rec->codReceita, cod);
	strcpy(prep->codReceita, cod);
	strcpy(ing->codReceita, cod);
	regravarReceita(rec);
	regravarPreparo(prep);
	regravarIngredientes(ing);
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	system("cls");
	printf("\n");
	printf("				RECEITA ATUALIZADA!!");
	printf("\n");
	free(rec);
	free(prep);
	free(ing);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

//Tela de escolha para atualização
char telaescolha(void) {
	char op;
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           --------------  ATUALIZAR RECEITA -------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           1. NOME                                                     **\n");
	printf("**           2. ORIGEM                                                   **\n");
	printf("**           3. OBTENCAO                                                 **\n");
    printf("**           4. TEMPO DE PREPARO                                         **\n");
	printf("**           5. DIFICULDADE                                              **\n");
	printf("**           6. PREPARO                                                  **\n");
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

//Tela de escolha para Pesquisa
char telaescolhaPesquisa(void) {
	char op;
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- PESQUISAR RECEITA --------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           1. CODIGO                                                   **\n");
	printf("**           2. NOME                                                     **\n");
	printf("**           3. OBTENCAO                                                 **\n");
    printf("**           4. TEMPO DE PREPARO                                         **\n");
	printf("**           5. DIFICULDADE                                              **\n");
	printf("**           6. ORIGEM                                                   **\n");
	printf("**           7. INGREDIENTES                                             **\n");
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


//Função para Deletar Receitas

void deletarReceitas(void) {
    system("cls");
	Receita* rec;
	Preparo* prep;
	Ingredientes* ing;
	rec = (Receita*) malloc(sizeof(Receita));
	prep = (Preparo*) malloc(sizeof(Preparo));
	ing = (Ingredientes*) malloc(sizeof(Ingredientes));
	char cod[4];
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Deletar Receita ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Nome da Receita para Deletar:                               **\n");
	printf("             ");
	scanf("%[^\n]", cod);
	getchar();
	rec = buscarReceita(cod);
	prep = buscaPreparo(cod);
	ing = buscaIngredientes(cod);
	if (rec == NULL) {
    	printf("\n\nReceita não encontrada!\n\n");
  	} else {
		  ing->status = 'd';
		  rec->status = 'd';
		  prep->status = 'd';
		  regravarIngredientes(ing);
		  regravarReceita(rec);
		  regravarPreparo(prep);
		  
	}
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	printf("\n");
	printf("				RECEITA DELETADA!!");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	free(rec);
	free(prep);
	free(ing);
}

//Função para Ver todos os nomes das Receitas 

void verReceitas(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           --------------   Ver Receitas  ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	exibirtodas();
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}


//Funcao para exibir Receitas
void exibirtodas(void){
	FILE* cd;
	Receita* rec;
	rec = (Receita*) malloc(sizeof(Receita));
	cd = fopen("Receitas.dat", "rb");
	if (cd == NULL) {
		printf("Arquivos de Receitas nao Existe!");
	}
	else{
		while(!feof(cd)) {
			fread(rec, sizeof(Receita), 1, cd);
			if ( rec->status == 'a' && !feof(cd)) {
			printf("Codigo da Receita: %s\n", rec->codReceita);
			printf("Nome: %s\n", rec->nome);
			printf("\n");
			}
		}
	}
		free(rec);
}

//Ver iten da receita e estoque
int vernoEstoque(Ingredientes* ing){
	Estoque* est;
	est = (Estoque*) malloc(sizeof(Estoque));
	est = procurarEstoque(ing->ingredientes);
	if(est == NULL){
		return 1;
	}
	return 0;
}