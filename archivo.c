#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*crear un archivo y colocar lo que el usuario ingresa por pantalla*/

int main()
{
    FILE *file;
    char string[1000];
    printf("ingrese el texto por pantalla");
    fflush(stdin);
    gets(string);
    file=fopen("C:\Program Files (x86)\archivo.txt","w");
    fwrite(string,sizeof(char),strlen(string),file);
    fclose(file);
    return 0;
}
