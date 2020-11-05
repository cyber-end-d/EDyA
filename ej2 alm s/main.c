#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define end_reg '|'
#define end_campo '_'
int main()
{
    char datos[300], *token, datos2[600];
    int c=0, i, j=0;
    printf("\nIngrese datos- <nombre>,<apellido>,<direccion>,<codigo postal>,<provincia>:\n");
    fflush(stdin);
    gets(datos);

    token=strtok(datos, " ,");
    while(token!=NULL){
        printf("\n%s (%d)",token, c);
        for(i=0;token[i]!='\0';i++){
            token[i]=datos2[i];
            j++;
            if(c%5==0){
                datos2[i+1]='|';
                i++;
            }else{
                datos2[i+1]='_';
                i++;
            }
        c++;
        }
        token=strtok(NULL, " ,");
    }
    printf("\n%s", datos2);
    return 0;
}
