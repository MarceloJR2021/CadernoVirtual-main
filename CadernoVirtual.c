#include <stdio.h>
#include <stdlib.h>

char menuPrincipal(void);

char menuReceitas(void);
void CadastrarReceitas(void);
void deletarReceitas(void);
void encontrarReceitas(void);
void atualizarReceitas(void);
void verReceitas(void);

char menuEstoque(void);
void adicionarEstoque(void);
void removerEstoque(void);
void verEstoque(void);

char menuFinancas(void);
void adicionarFinancas(void);
void removerFinancas(void);
void verFinancas(void);

void telaSobre(void);

void menuInformacoes(void);

int main(void) {
	char opcao;

	telaSobre();
	opcao = menuPrincipal();
	switch (opcao)
	{
		case '1' :
		opcao = menuReceitas();
		switch (opcao) 
		{
			case '1' :
			CadastrarReceitas();
			break;

			case '2' :
			encontrarReceitas();
			break; 

			case '3' :
			atualizarReceitas();
			break;

			case '4' :
			deletarReceitas();
			break;

			case '5' :
			verReceitas();
			break;
		}

		break;

		case '2' :
		menuEstoque();
		scanf("%d", &opcao);
		switch (opcao) 
		{
			case '1' :
			adicionarEstoque();
			break;

			case '2' :
			removerEstoque();
			break; 

			case '3' :
			verEstoque();
			break;
		}
		break;

		case '3' :
		menuFinancas();
		scanf("%d", &opcao);
		switch (opcao) 
		{
			case '1' :
			adicionarFinancas();
			break;

			case '2' :
			removerFinancas();
			break; 

			case '3' :
			verFinancas();
			break;
		}
		break;

		case '4' :
		menuInformacoes();
		break;

		case '5' :
		return 0;


	}



	
    	

    return 0;

}

void telaSobre(void) {
    printf("\n");
    printf("*****************************************************************************\n");
    printf("**      Projeto Caderno Virtual de Receitas Culinarias                     **\n");
    printf("**      Desenvolvedor - Marcelo Jailson de Araujo Junior                   **\n");
    printf("**                                                                         **\n");
    printf("*****************************************************************************\n");
    printf("**                                                                         **\n");
    printf("**      --------- Caderno Virtual de Receitas Culinarias ---------         **\n");
    printf("**                                                                         **\n");
    printf("**  Programa projeto de um caderno virtual de receitas culinarias com      **\n");
    printf("**  a finalidade de Cadastrar,pesquisar,seja por nome,ingredientes,        **\n");
    printf("**  localidade,custo ou outro,adicionando ou removendo como o usuario      **\n");
    printf("**  desejar.Em resumo e um sistema capaz de gerenciar um conjunto de       **\n");
    printf("**  receitas culinarias,por meio da busca por pratos que contenham         **\n");
    printf("**  determinados ingredientes e a respectiva otimizacao dos estoques.      **\n");
    printf("**                                                                         **\n");
    printf("*****************************************************************************\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

char menuPrincipal(void) {
	char op;
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
    printf("**     		 Projeto Caderno Virtual de Receitas Culinarias              **\n");
    printf("**    	     Desenvolvedor - Marcelo Jailson de Araujo Junior            **\n");
    printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ---------------  Menu Principal ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           1. Modo Receitas                                            **\n");
	printf("**           2. Modo Estoque                                             **\n");
	printf("**           3. Modo Financas                                            **\n");
    printf("**           4. Informacoes sobre o sistema                              **\n");
	printf("**           5. Encerra o programa                                       **\n");
	printf("**                                                                       **\n");
	printf("             Escolha a opcao desejada:  ");
	scanf("%c", &op);
	getchar();
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
	return op;
}

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
	printf("**           0. Sair                                                     **\n");
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
	printf("**           0. Sair                                                     **\n");
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

char menuFinancas(void) {
	char op;
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ---------------  Menu Financas  ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           1. Adicionar Financas                                       **\n");
	printf("**           2. Remover   Financas                                       **\n");
    printf("**           3. Ver Financas                                             **\n");
	printf("**           0. Sair                                                     **\n");
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

void menuInformacoes(void) {
	char op;
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ---------------  Informacoes    ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Quantidade de Receitas:                                     **\n");
	printf("**           Quantidade de Itens no Estoque:                             **\n");
    printf("**           Financas:                                                   **\n");
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void CadastrarReceitas(void) {
	char nome[50];
	char preparo[200];
	char origem[20];
	char obtencao[50];
	char ingredientes[200];
	int quantidade[50];
	int quant;
	int cont;

    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------  Cadastrar Receitas  -------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("           Nome da Receita: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ,.;0-9]", nome);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Ingredientes: \n");
	printf("           Digite a Quantidade de Ingredientes diferentes na Receita: ");
	scanf("%d",&quant);
	getchar();
	for ( cont = 1; cont <= quant; cont++)
	{
		printf("           Ingrediente e tipo(kg,litro,g,unidade): \n");
		printf("           (Exemplo:carne de sol,kg):");
		scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.,;0-9]",&ingredientes[cont]);
		getchar();
		printf("           Quantidade(So Numero): ");
		scanf("%d", &quantidade[cont]);
		getchar();
	}
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
    printf("           Modo de Preparo: ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.,;]", preparo);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Origem da Receita(Pais ou Regiao): ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.;,0-9]",origem);
	getchar();
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("           Local de Obtencao da Receita(Site,Livro,Revista): ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ.;,0-9]",obtencao);
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
}

void encontrarReceitas(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------ Encontrar Receita por ------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           1. Nome:                                                    **\n");
	printf("**           2. Ingrediente:                                             **\n");
    printf("**           3. Origem:                                                  **\n");
	printf("**           0. Voltar                                                   **\n");
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void atualizarReceitas(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Atualizar Receita --------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Nome da Receita para Atualizar:                             **\n");
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void deletarReceitas(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Deletar Receita ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Nome da Receita para Deletar:                               **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

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

void adicionarEstoque(void) {
	char item[20];
	int quant;
	float valor;

    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------- Adicionar Estoque ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("             Item:  ");
	scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ,.;0-9]", item);
	getchar();
	printf("             Quantidade:   ");
	scanf("%d",&quant);
	getchar();
	printf("             Valor Gasto R$(00.00):    ");
	scanf("%f",&valor);
	getchar();
	printf("**                                                                       **\n");	
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void removerEstoque(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Remover Estoque ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Item:                                                       **\n");
	printf("**           Quantidade:                                                 **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void verEstoque(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ---------------   Ver Estoque  ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**             Nome              |            Quantidade                 **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                               |                                       **\n");
	printf("**                                                                       **\n");			
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void adicionarFinancas(void) {
	float financa;

    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------- Adicionar Financas --------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Valor(R$):   ");
	scanf("%f",&financa);
	getchar();
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void removerFinancas(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           -------------- Remover Financas ---------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Valor(R$):                                                  **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void verFinancas(void) {
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           --------------   Ver Financas  ----------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Valor das Financas:                                         **\n");
	printf("**           R$                                                          **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}