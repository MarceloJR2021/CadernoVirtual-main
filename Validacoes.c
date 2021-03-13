#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int entradaInt(char ent[]){
    int i;
    int m = strlen(ent);
    for(i = 0;i < m;i++){
        if(!isdigit(ent[i])){
            return 0;
        }
    }
    return 1;

}

int entradaMedida(char medida[]){
    int m;
    int i;
    m = strlen(medida);
    for(i = 0;i < m;i++){
        medida[i] = toupper(medida[i]);
    }
    if (strcmp(medida,"KG") == 0 || strcmp(medida,"LITRO") == 0 || strcmp(medida,"G") == 0 || strcmp(medida,"UNIDADE") == 0){
        return 1;
    }
    return 0;
}

int entradaFinanca(char financa[]){
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
        }
    }
    if(contponto == 0){
        return 0;
    }
    return 1;


}