#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct persona
{
    char nombre[25],apellido[25],DNI[10],domicilio[15];
}Personas;
char *concat(Personas*);

int main()
{
    Personas *persona;
    char *string;
    printf("Ingrese nombre de persona: ");
    gets(persona->nombre);
    printf("Ingrese apellido de persona: ");
    gets(persona->apellido);
    printf("Ingrese DNI de persona: ");
    gets(persona->DNI);
    printf("Ingrese domicilio de persona: ");
    gets(persona->domicilio);
    string=strcat(string,concat(persona));
    string=strcat(string,persona->DNI);
    string=strcat(string,persona->domicilio);
    printf("%s\n",string);
    return 0;
}
char *concat(Personas *pPers)
{
    char *llave=NULL;
    int tam=sizeof(char)*(strlen(pPers->apellido)+strlen(pPers->nombre)+2);
    llave=(char*)malloc(tam);
    llave=strcat(pPers->apellido,' ');
    llave=strcat(llave,pPers->nombre);
    return strupr(llave);
}
