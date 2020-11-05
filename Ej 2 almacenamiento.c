#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define END_REGISTRY '#'
#define END_FIELD '|'

void cambiar(char []);
int main() {
    char texto[1000];
    printf("Ingrese texto: ");
    fflush(stdin);
    gets(texto);
    cambiar(texto);
    return 0;
}

void cambiar(char t[1000])
 {
    int cant=0,i,j;
    char *aux=(char *)malloc(sizeof(char)*(strlen(t)*2));
    strcpy(aux, t);
    for(i=0; *(aux+i) != '\0'; i++)
        {
            if(*(aux+i)=='#')
            {
                for(j=strlen(aux); j>i; j--)
                {
                    *(aux+j+1) = *(aux+j);
                }
                *(aux+j+1) = *(aux+j);
                *(aux+j)='\\';
                i++;
            }
        }
    for(i=0;i<strlen(aux);i++)
        printf("%c", aux[i]);
}
