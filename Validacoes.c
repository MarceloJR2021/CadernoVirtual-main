#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int entradaInt(char ent){
    if(!isdigit(ent)){
        return 0;
    }

    return 1;

}

int entradaMedida(char medida[]){
    int m;
    m = strlen(medida);
    for(int i=0;i < m;i++){
        medida[i] = toupper(medida[i]);
    }
    if (strcmp(medida,"KG") == 0 || strcmp(medida,"LITRO") == 0 || strcmp(medida,"G") == 0 || strcmp(medida,"UNIDADE") == 0){
        return 1;
    }
    return 0;
}