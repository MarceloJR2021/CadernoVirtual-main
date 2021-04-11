void relatorioReceitas(void) {
	char op;
	char quant[] = "21";
	char nome[] = "Macarrao com Salsicha"; 
	char Ingredientes[] = " 1 Unidade de Macarrao,5 unidades de Salsicha,\n             50 g de Manteiga,1 Unidade de molho\n";
	char preparo[] = "1 - Ferver a Água com Macarrao ; 2 - cortar as salsichas ; \n 		3 - temperar  o macarrao com molho e manteiga e jogar as salsichas\n";
    char origem[] = "Italia";
	char obtencao[] = "www.receitas.com.br";
	system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------  Relatorio de Receitas -----------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("**           Quantidade de Receitas: %s                                  **\n", &quant);
	printf("**           Ultima receita Adicionada                                   **\n\n");
	printf("             Nome:  %s \n\n",&nome);
	printf("             Ingredientes:  %s \n",&Ingredientes);
	printf("             Preparo:  %s \n",&preparo);
	printf("             Origem:  %s \n\n",&origem);
	printf("             Obtencao:  %s \n",&obtencao);
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void relatorioEstoque(void) {
	char op;
	char itens[] = "35 Itens";
	char Item[] = "5 Unidades de Salsicha";
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------  Relatorio de Estoque ------------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("             Quantidade de Itens no Estoque: %s                           \n", &itens);
	printf("**           Ultima Iten Adicionado                                      **\n");
	printf("             Item : %s \n",&Item);
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void relatorioFinancas(void) {
	char op;
	char financas[] = "R$ 185,00";
	char entrada[] = "R$ 35,50";
	char saida[] = "R$ 15,50";
    system("cls");
	printf("\n");
	printf("***************************************************************************\n");
	printf("**                                                                       **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**           ------------  Relatorio de Financas -----------             **\n");
	printf("**           -----------------------------------------------             **\n");
	printf("**                                                                       **\n");
	printf("             Financas: %s                                                 \n\n",&financas);
	printf("             Ultima entrada: %s                                     \n\n",&entrada);
	printf("             Ultima Saida:   %s                                     \n",&saida);
	printf("**                                                                       **\n");
	printf("**                                                                       **\n");
	printf("***************************************************************************\n");
	printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}