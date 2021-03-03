#include <stdlib.h>
#include <ctype.h>

int valQuantidade(char q){
    if(!isdigit(q)){
        return 0;
    }

    return 1;

}