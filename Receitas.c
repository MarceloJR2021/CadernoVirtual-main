#include "Validacoes.h"
#include <ctype.h>

struct receitas {
	int codReceita;
	char nome[50];
	char origem[20];
	char obtencao[30];
	char tempo[6];
	char dificuldade[2];

};

struct preparo {
	int codReceita;
	char preparo[200];

};

struct ingredientes {
	int codReceita;
	char ingredientes[50];
	char medida[12];
	char quantidade[50];
};

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
	rec = (Receita*)malloc(sizeof(Receita));
	prep = (Preparo*)malloc(sizeof(Preparo));
	ing = (Ingredientes*)malloc(sizeof(Ingredientes));
	char ingredientes[200];
	char medida[12];
	char quantidade[12];
	char quant[2];
	int cont = 0;

    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------  Cadastrar Receitas  -------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("           Codigo da Receita: ");
	scanf("%d", rec->codReceita);
	getchar();
	system("cls");
	printf("\n");
	printf("           Nome da Receita: ");
	scanf("%50[^\n]", rec->nome);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Ingredientes: \n");
	do{
		printf("           Entre com o nome do Ingrediente: ");
		scanf("%50[^\n]",ing->ingredientes);
		getchar();
		printf("	   Entre com a medida:(kg,litro,g,unidade): ");
		do{
			scanf("%[^\n]",medida);
			getchar();
			if(!entradaMedida(medida)){
				printf("	   Entrada Invalida!\n	   Digite Novamente: ");
			}
		}while(!entradaMedida(medida));
		printf("           Entre com a Quantidade do Ingrediente(So Numero): ");
		do{
			scanf("%s",quantidade);
			getchar();
			if(!entradaInt(quantidade)){
				printf("	   Entrada Invalida!\n	   Digite Novamente: ");
			}
		}while(!entradaInt(quantidade));
		printf("	   Deseja Adicionar mais Ingredientes(S/N) :");
		scanf("%[^\n]",quant);
		getchar();
		system("cls");
		printf("\n");
	}while(strcmp(quant,"S") == 0 || strcmp(quant,"s") == 0);
		
	
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
    printf("           Modo de Preparo: ");
	scanf("%200[^\n]", prep->preparo);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Origem da Receita(Pais ou Regiao): ");
	scanf("%20[^\n]",rec->origem);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Local de Obtencao da Receita(Site,Livro,Revista): ");
	scanf("%30[^\n]",rec->obtencao);
	getchar();
	printf("\n");
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Tempo de Preparo em minutos(Somente numeros) : ");
	scanf("%6[^\n]",rec->tempo);
	getchar();
	printf("\n");
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Dificuldade de preparo,primeira letra(F[facil],M[medio] OU D[dificil]): ");
	scanf("%2[^\n]",rec->dificuldade);
	getchar();
	printf("\n");
	printf("***************************************************************************\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	printf("\n");
	printf("Nome da Receita : %s",rec[0].nome);
	printf("\n");
	printf("Modo de Preparo :\n%s",prep[0].preparo);
	printf("\n");
	printf("Origem : %s",rec[0].origem);
	printf("\n");
	printf("Local de Obtencao : %s",rec[0].obtencao);
	printf("\n");
	printf("Tempo de Preparo(Minutos) : %s",rec[0].tempo);
	printf("\n");
	printf("Dificuldade de Preparo : %s",rec[0].dificuldade);
	printf("\n");
	getchar();
	free(rec);
	free(ing);
	free(prep);
}

//Função para Encontrar Receitas

void encontrarReceitas(void) {
    system("cls");
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
	getchar();
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	printf("\n");
	printf("Nome da Receita : %s",&nome);
	printf("\n");
	printf("Ingredientes :");
	printf("\n");
	printf("Modo de Preparo :");
	printf("\n");
	printf("Origem :");
	printf("\n");
	printf("Local de Obtencao :");
	printf("\n");
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
	printf("**           |Nome da Receita|                                           **\n");
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
