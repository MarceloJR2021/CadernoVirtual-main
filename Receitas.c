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

//Função para adicionar Receitas
void CadastrarReceitas(void) {
	Receita* rec;
	rec = telaPreencherReceita();
	gravarReceita(rec);
	free(rec);
}

//Tela preencher Ingredientes
Ingredientes* telaPreencherIngredientes(void){
	Ingredientes* ing;
	char escolha[2];
	int cont = 0;
	ing = (Ingredientes*)malloc(sizeof(Ingredientes));
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



//Preencher Receita
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
	printf("           Codigo da Receita: ");
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

void regravarReceita(Receita* rec) {
	FILE* cd;
	Receita* nrec;
	nrec = (Receita*) malloc(sizeof(Receita));
	cd = fopen("Receitas.dat", "r+b");
	if (cd == NULL) {
		printf("Erro na abertura do arquivo!");
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


//Buscar Receita
Receita* buscarReceita(char* cod) {
	FILE* cd;
	Receita* rec;
	rec = (Receita*) malloc(sizeof(Receita));
	cd = fopen("Receitas.dat", "rb");
	if (cd == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar este programa...\n");
		exit(1);
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
	FILE* pr;
	Preparo* prep;
	prep = (Preparo*) malloc(sizeof(Preparo));
	pr = fopen("Preparo.dat","ab");
	if (pr == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar este programa...\n");
		exit(1);
	}
	while(!feof(pr)) {
		fread(prep, sizeof(Preparo), 1, pr);
		if (strcmp(prep->codReceita, cod) == 0) {
		fclose(pr);
		return prep;
		}
	}
	fclose(pr);
	return NULL;
}

//busca de Ingredientes da Receita
Ingredientes* buscaIngredientes(char* cod){
	FILE* in;
	Ingredientes* ing;
	ing = (Ingredientes*)malloc(sizeof(Ingredientes));
	in = fopen("Ingredientes.dat","ab");
	if (in == NULL) {
		printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
		printf("Não é possível continuar este programa...\n");
		exit(1);
	}
	while(!feof(in)) {
		fread(ing, sizeof(Ingredientes), 1, in);
		if (strcmp(ing->codReceita, cod) == 0) {
		fclose(in);
		return ing;
		}
	}
	fclose(in);

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

//Função para Encontrar Receitas

void encontrarReceitas(void) {
    system("cls");
	Receita* rec;
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
	getchar();
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	exibirReceita(rec);
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

//Função para Atualizar as Receitas

void atualizarReceitas(void) {
    system("cls");
	Receita* rec;
	char cod[4];
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
	strcpy(rec->codReceita, cod);
	regravarReceita(rec);
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	system("cls");
	printf("\n");
	printf("				RECEITA ATUALIZADA!!");
	printf("\n");
	free(rec);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

//Função para Deletar Receitas

void deletarReceitas(void) {
    system("cls");
	Receita* rec;
	rec = (Receita*) malloc(sizeof(Receita));
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
	getchar();
	if (rec == NULL) {
    	printf("\n\nReceita não encontrada!\n\n");
  	} else {
		  rec->status = 'd';
		  regravarReceita(rec);
		  free(rec);
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
