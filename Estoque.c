#include <ctype.h>

struct estoque {
	char item[20];
	char quantidade[50];
	char preco[20];
	
};

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

//Função para adicionar Estoque

void adicionarEstoque(void) {
	Estoque* est;
	est = (Estoque*)malloc(sizeof(Estoque));
	char quant[12];
	char saida[12];
	char medida[10];

    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------- Adicionar Estoque ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("             Item:  ");
	scanf("%20[^\n]", est->item);
	getchar();
	printf("             Quantidade:   ");
	do{
		scanf("%s",quant);
		getchar();
		if(!entradaInt(quant)){
			printf("	     Entrada Invalida!\n	     Digite Novamente: ");
		}
	}while(!entradaInt(quant));
	printf("	     Entre com a medida:(kg,litro,g,unidade): ");
	do{
		scanf("%[^\n]",medida);
		getchar();
		if(!entradaMedida(medida)){
			printf("	     Entrada Invalida!\n	     Digite Novamente: ");
		}
	}while(!entradaMedida(medida));
	printf("             Valor Gasto R$(00.00):    ");
	do{
		scanf("%s",saida);
		getchar();
		if(!entradaFinanca(saida)){
			printf("	   Entrada Invalida!\n	     Digite NovamenteR$(00.00): R$ ");
		}
	}while(!entradaFinanca(saida));
	printf("**                                                                       **\n");	
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	free(est);
}

//Função para Remover Estoque
void removerEstoque(void) {
    system("cls");
	char item[50];
	char quant[12];
	char medida[10];
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
	printf("**           Quantidade: ");
	do{
		scanf("%s",quant);
		getchar();
		if(!entradaInt(quant)){
			printf("	     Entrada Invalida!\n	     Digite Novamente: ");
		}
	}while(!entradaInt(quant));
	printf("	     Entre com a medida:(kg,litro,g,unidade): ");
	do{
		scanf("%[^\n]",medida);
		getchar();
		if(!entradaMedida(medida)){
			printf("	     Entrada Invalida!\n	     Digite Novamente: ");
		}
	}while(!entradaMedida(medida));
	
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

//Função para ver o que tem no Estoque
void verEstoque(void) {
    system("cls");
	printf("\n");
	printf("******************************************************\n");
	printf("**                                  			    **\n");
	printf("** -----------------------------------------------  **\n");
	printf("** ---------------   Ver Estoque  ----------------  **\n");
	printf("** -----------------------------------------------  **\n");
	printf("**                                                  **\n");
	printf("             Nome |   Quantidade |  Medida        \n");
	printf("                  |              |			      \n");
	printf("                  |              |			      \n");
	printf("                  |              |		          \n");
	printf("                  |              |		          \n");			
	printf("******************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
