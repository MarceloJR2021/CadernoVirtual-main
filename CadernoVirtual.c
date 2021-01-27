#include <stdio.h>
#include <stdlib.h>

void menuPrincipal(void);
void menuReceitas(void);
void menuEstoque(void);
void menuFinancas(void);
void telaCadastrarReceitas(void);
void telaSobre(void);

int main(void) {
    telaSobre();
    menuPrincipal();
    menuReceitas();
    menuFinancas();
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
}

void menuPrincipal(void) {
    system("cls");
	printf("\n");
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
	printf("**           0. Encerra o programa                                       **\n");
	printf("**                                                                       **\n");
	printf("**           Escolha a opcao desejada:                                   **\n");
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("*************************************************************************//\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void menuReceitas(void) {
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
	printf("**           5. Ver Receitas-Somente nome                                **\n");
	printf("**           0. Sair                                                     **\n");
	printf("**                                                                       **\n");
	printf("**           Escolha a opcao desejada:                                   **\n");
	printf("**                                                                       **\n");
	printf("*************************************************************************//\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void menuFinancas(void) {
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
	printf("**           3. Atualizar Financas                                       **\n");
    printf("**           4. Ver Financas                                             **\n");
	printf("**           0. Sair                                                     **\n");
	printf("**                                                                       **\n");
	printf("**           Escolha a opcao desejada:                                   **\n");
	printf("**                                                                       **\n");
	printf("*************************************************************************//\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

