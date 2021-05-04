#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>




int entradaInt(char* ent){
    int i;
    int m = strlen(ent);
    for(i = 0;i < m;i++){
        if(!isdigit(ent[i])){
            return 0;
        }
    }
    return 1;

}

int opcaoMenu(char* op){
    int n = strlen(op);
    if(n > 1){
        return 0;
    }
    return 1;

}

int entradaMedida(char* medida){
    int m;
    int i;
    m = strlen(medida);
    for(i = 0;i < m;i++){
        medida[i] = toupper(medida[i]);
    }
    if (strcmp(medida,"KG") == 0 || strcmp(medida,"LITRO") == 0 || strcmp(medida,"G") == 0 || strcmp(medida,"UNIDADE") == 0 || strcmp(medida,"ML") == 0 || strcmp(medida,"MG") == 0 || strcmp(medida,"XICARA") == 0 || strcmp(medida,"COLHER DE SOPA") == 0 ){
        return 1;
    }
    return 0;
}

int entradaFinanca(char* financa){
    int i;
    int m = strlen(financa);
    char ponto = '.';
    int contponto = 0;
    for(i = 0;i < m;i++){
        if(!isdigit(financa[i]) && financa[i] != ponto) {
            return 0;
        }
        if(financa[i] == ponto){
            contponto++;
            if(!isdigit(financa[i+1])){
                return 0;
            }
        }
    }
    if(contponto == 0){
        return 0;
    }
    if(contponto > 1){
        return 0;
    }
    return 1;


}