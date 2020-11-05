#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Persona{
char * nombre;
char * apellido;
char * domicilio;
}Persona;

char* llave(Persona *);

int main()
{
    Persona p1;
    char * res;
    p1.nombre="Brian";
    p1.apellido="Seery";
    p1.domicilio="plaza";
    llave(&p1);
    printf("%s",res);
    return 0;
}

char *llave(Persona * p1)
{
    char* nombre, *apellido,*res;
    char* esp = " ";
    int longitud;
    int i;

    nombre = p1->nombre;
    apellido = p1->apellido;

    longitud = sizeof(char) * (strlen(nombre)+strlen(apellido)+strlen(esp)+1);

    res = (char *) malloc(longitud);

    for(i=0; i<longitud;i++) {

        res[i]='\0';

    }

    strcat(res,apellido);
    strcat(res,esp);
    strcat(res,nombre);

    for(i=0; i<longitud; i++) {

        res[i] = putchar(toupper(res[i]));

    }

    return res;

}
