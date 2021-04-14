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
	Preparo* prep;
	Ingredientes* ing;
	rec = (Receita*) malloc(sizeof(Receita));
	prep = (Preparo*) malloc(sizeof(Preparo));
	ing = (Ingredientes*)malloc(sizeof(Ingredientes));
	char escolha[2];
	int cont = 0;

    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------  Cadastrar Receitas  -------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("\n");
	rec->codReceita = 0;
	printf("           Nome da Receita: ");
	scanf("%[^\n]", rec->nome);
	getchar();
	system("cls");
	printf("\n");
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
		
	
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
    printf("           Modo de Preparo: ");
	scanf("%[^\n]", prep->preparo);
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
	gravarReceita(rec);
	getchar();
	free(rec);
	free(ing);
	free(prep);
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



//Buscar Receita
Receita* buscarReceita(char* nome) {
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
    if (strcmp(rec->nome, nome) == 0) {
      fclose(cd);
      return rec;
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
	printf("Codigo da Receita: %d\n", rec->codReceita);
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
	char nome[50];
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------- Encontrar Receita   -------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Digite o nome da Receitas:                                  **\n");	
	printf("             ");
	scanf("%[^\n]", nome);
	rec = buscarReceita(nome);
	getchar();
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	exibirReceita(rec);
	free(rec);
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

//Função para Atualizar as Receitas

void atualizarReceitas(void) {
    system("cls");
	char nome[50];
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Atualizar Receita --------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Nome da Receita para Atualizar:                             **\n");
	printf("             ");
	scanf("%[^\n]", nome);
	getchar();
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

//Função para Deletar Receitas

void deletarReceitas(void) {
    system("cls");
	char nome[50];
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Deletar Receita ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Nome da Receita para Deletar:                               **\n");
	printf("             ");
	scanf("%[^\n]", nome);
	getchar();
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
