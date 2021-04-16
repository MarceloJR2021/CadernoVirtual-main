#include <stdio.h>
#include <stdlib.h>
#include "Receitas.h"
#include "Estoque.h"
#include "Financas.h"
#include "Validacoes.h"
#include "Relatorio.h"


char menuPrincipal(void);

void telaSobre(void);

int main(void) {
	char opcao;
	char opcao1;
	char opcao2;
	char opcao3;

	do {
	opcao = menuPrincipal();
	
	switch (opcao)
	{
		case '1' :
		do {
		opcao1 = menuReceitas();
		switch (opcao1) 
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

			case '0' :
			opcao = '6';
			break;
		}
		}while (opcao1 != '0');

		break;

		case '2' :
		do {
		opcao2 = menuEstoque();
		switch (opcao2) 
		{
			case '1' :
			adicionarEstoque();
			break;

			case '2' :
			removerEstoque();
			break; 

			case '3' :
			exibirEstoque();
			break;

			case '0' :
			opcao = '6';
			break;

		}
		} while (opcao2 != '0');
		break;

		case '3' :
		do {
		opcao3 = menuFinancas();
		switch (opcao3) 
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
			
			case '0' :
			opcao = '6';
			break;
		
		}

		} while (opcao3 != '0');
		break;

		case '4' :
		telaSobre();
		break;

		case '5' :
		relatorioReceitas();
		relatorioEstoque();
		relatorioFinancas();
		break;


	}
		if (opcao == '0'){
			return 0;
		}
	} while (opcao != '0');


	
    	

    

}

void telaSobre(void) {
	system("cls");
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
	printf("**           5. Relatorios        		                         **\n");
	printf("**           0. Encerra o programa                                       **\n");
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







