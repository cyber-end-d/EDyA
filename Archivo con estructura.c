
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*una estructura de 3 personas y persistirla en un archivo y dsp mostrarla*/
typedef struct {
char nombre[50];
int edad;
}persona;

int main(){
    char nombre[10], *string;
    int edad,i,cant,cantidad;
    persona *personas, *archivo;
    FILE *file;

    printf("ingrese cant");
    scanf("%d",&cant);
    personas=(persona *)malloc(sizeof(persona)*cant);

    for (i=0;i<cant;i++){
        printf("nombre");
        fflush(stdin);
        gets(personas[i].nombre);
        printf("edad");
        fflush(stdin);
        scanf("%d",&(personas[i].edad));
    }

    file=fopen("personas.dat","ab+");
    fwrite(personas,sizeof(persona),cant,file);

    if(file!=NULL){
        fseek(file,0,SEEK_END);
        cantidad=ftell(file)/sizeof(persona);
        fseek(file,0,SEEK_SET);
        archivo=(persona *)malloc(sizeof(persona)*(cantidad));
        fread(archivo,sizeof(persona),cantidad,file);

        for (i=0;i<cantidad;i++){

            printf("%s\n",personas[i].nombre);
            printf("%d\n",personas[i].edad);
        }

    } else {
        printf("no se encontro el archivo");
    }

    fclose(file);

    return 0;
}
