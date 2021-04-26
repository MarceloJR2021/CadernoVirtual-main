#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validacoes.h"
#include <ctype.h>
#include "Receitas.h"


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
	rec = telaPreencherReceita();
	prep = telaPreencherPreparo();
	ing = telaPreencherIngredientes();
	strcpy(ing->codReceita,rec->codReceita);
	strcpy(prep->codReceita,rec->codReceita);
	gravarReceita(rec);
	gravarIngredientes(ing);
	gravarPreparo(prep);
	free(rec);
	free(ing);
	free(prep);
}

//Tela de preencher Ingredientes
Ingredientes* telaPreencherIngredientes(void){
	system("cls");
	Ingredientes* ing;
	char escolha[2];
	int cont = 0;
	ing = (Ingredientes*)malloc(sizeof(Ingredientes));
	ing->status = 'a';
	printf("***************************************************************************\n");
	printf("           Ingredientes: \n");
	do{
		printf("           Entre com o nome do Ingrediente: ");
		scanf("%[^\n]",ing->ingredientes);
		getchar();
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
			scanf("%[^\n]",ing->quantidade);
			getchar();
			if(!entradaInt(ing->quantidade)){
				printf("	   Entrada Invalida!\n	   Digite Novamente: ");
			}
		}while(!entradaInt(ing->quantidade));
		printf("	   Deseja Adicionar mais Ingredientes(S/N) :");
		scanf("%[^\n]",escolha);
		getchar();
		system("cls");
		printf("\n");
		cont++;
	}while(strcmp(escolha,"S") == 0 || strcmp(escolha,"s") == 0);
	
	return ing;
	
}

//Tela de Preencher Preparo da Receita
Preparo* telaPreencherPreparo(void){
	Preparo* prep;
	prep = (Preparo*) malloc(sizeof(Preparo));
	char fim;
	int i=0;
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
	scanf("%[^\n]", prep->preparo);
	getchar();
	system("cls");
	prep->status = 'a';
	return prep;

}



//Tela de Preencher Receita
Receita* telaPreencherReceita(void){
	Receita* rec;
	rec = (Receita*) malloc(sizeof(Receita));

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
	scanf("%[^\n]", rec->codReceita);
	getchar();
	system("cls");
	printf("           Nome da Receita: ");
	scanf("%[^\n]", rec->nome);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Origem da Receita(Pais ou Regiao): ");
	scanf("%[^\n]",rec->origem);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Local de Obtencao da Receita(Site,Livro,Revista): ");
	scanf("%[^\n]",rec->obtencao);
	getchar();
	printf("\n");
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
	scanf("%[^\n]",rec->dificuldade);
	getchar();
	printf("\n");
	rec->status = 'a';
	printf("***************************************************************************\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
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
void regravarIngredienetes(Ingredientes* ing) {
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
	printf("Status da Receita: %c", rec->status);
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
}

//Exibir preparo da Receita
void exibirPreparo(Preparo* prep){
	if (prep == NULL) {
    printf("\n Nao Existem Receitas para Exibir \n");
  } else {
    printf("\n= = = Preparo = = =\n");
	printf("Codigo da Receita: %s\n", prep->codReceita);
	printf("Preparo :  %s \n",prep->preparo);
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
}

//Exibir ingredientes da Receita
void exibirIngredientes(Ingredientes* ing){
	if (ing == NULL) {
    printf("\n Nao Existem Receitas para Exibir \n");
  } else {
    printf("\n= = = Ingredientes = = =\n");
	printf("Codigo da Receita: %s\n", ing->codReceita);
	printf("Item :  %s %s %s\n",ing->ingredientes,ing->quantidade,ing->medida);
  }
  printf("\n\nTecle ENTER para continuar!\n\n");
  getchar();
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
	printf("**           Digite o Codigo da Receitas:                                  **\n");	
	printf("             ");
	scanf("%[^\n]", cod);
	rec = buscarReceita(cod);
	prep = buscaPreparo(cod);
	ing = buscaIngredientes(cod);
	getchar();
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	exibirReceita(rec);
	exibirPreparo(prep);
	exibirIngredientes(ing);
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
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
	op = telaescolha();	
	switch (op)
	{
		case '1' :
		printf("Entre com o novo nome:");
		scanf("%[^\n]", rec->nome);
		getchar();
		system("cls");
		break;

		case '2' :
		printf("Entre com a Origem:");
		scanf("%[^\n]", rec->origem);
		getchar();
		system("cls");
		break; 

		case '3' :
		printf("Entre com a Obtencao:");
		scanf("%[^\n]", rec->obtencao);
		getchar();
		system("cls");
		break;

		case '4' :
		printf("Entre com o tempo de preparo:");
		scanf("%[^\n]", rec->tempo);
		getchar();
		system("cls");
		break;

		case '5' :
		printf("Entre com a dificuldade:");
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
	regravarIngredienetes(ing);
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

//Tela para Atualizar


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
	rec = buscarReceita(cod);
	prep = buscaPreparo(cod);
	ing = buscaIngredientes(cod);
	getchar();
	if (rec == NULL) {
    	printf("\n\nReceita não encontrada!\n\n");
  	} else {
		  rec->status = 'd';
		  prep->status = 'd';
		  ing->status = 'd';
		  regravarReceita(rec);
		  regravarPreparo(prep);
		  regravarIngredienetes(ing);
		  
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
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
