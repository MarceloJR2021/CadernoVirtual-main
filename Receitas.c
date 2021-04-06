#include "Validacoes.h"
#include <ctype.h>
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
	char nome[50];
	char preparo[200];
	char origem[20];
	char obtencao[50];
	char ingredientes[200];
	char medida[12];
	char quantidade[12];
	char quant[12];
	int cont;
	int valor;

    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------  Cadastrar Receitas  -------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("           Nome da Receita: ");
	scanf("%[^\n]", nome);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Ingredientes: \n");
	printf("           Digite a Quantidade de Ingredientes diferentes na Receita: ");
	do{
		scanf("%s",quant);
		getchar();
		if(!entradaInt(quant)){
			printf("	   Entrada Invalida!\n	   Digite Novamente: ");
		}
	}while(!entradaInt(quant));
	printf("           Entre com o nome do Ingrediente: ");
	scanf("%[^\n]",ingredientes);
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
		
	
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
    printf("           Modo de Preparo: ");
	scanf("%[^\n]", preparo);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Origem da Receita(Pais ou Regiao): ");
	scanf("%[^\n]",origem);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Local de Obtencao da Receita(Site,Livro,Revista): ");
	scanf("%[^\n]",obtencao);
	getchar();
	printf("\n");
	printf("***************************************************************************\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	system("cls");
	printf("\n");
	printf("Nome da Receita : %s",&nome);
	printf("\n");
	printf("Modo de Preparo :\n%s",&preparo);
	printf("\n");
	printf("Origem : %s",&origem);
	printf("\n");
	printf("Local de Obtencao : %s",&obtencao);
	printf("\n");
	getchar();
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
