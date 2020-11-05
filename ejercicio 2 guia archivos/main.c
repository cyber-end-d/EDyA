#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char END_REGISTRY[2] ={'#'};
char END_FIELD[2] ={','};
char* strconcat(char*,char*);
char* escapear(char*);
int main()
{
    char buffer[100];
    char *string=NULL;
    int cantidad=0,i;
    FILE* file;
    printf("Ingrese la cantidad de personas guardar\n");
    scanf("%d",&cantidad);
    for(i=0;i<cantidad;i++)
    {
        printf("Ingrese el nombre\n");
        fflush(stdin);
        gets(buffer);
        string=strconcat(string,escapear(buffer));
        string=strconcat(string,&END_FIELD);
        printf("Ingrese el apellido\n");
        fflush(stdin);
        gets(buffer);
        string=strconcat(string,escapear(buffer));
        string=strconcat(string,&END_FIELD);
        printf("Ingrese el domicilio\n");
        fflush(stdin);
        gets(buffer);
        string=strconcat(string,escapear(buffer));
        string=strconcat(string,&END_FIELD);
        printf("Ingrese el codigo postal\n");
        fflush(stdin);
        gets(buffer);
        string=strconcat(string,escapear(buffer));
        string=strconcat(string,&END_FIELD);
        printf("Ingrese la provincia\n");
        fflush(stdin);
        gets(buffer);
        string=strconcat(string,escapear(buffer));
        string=strconcat(string,&END_REGISTRY);
        printf("resultado: %s\n",string);
        fflush(stdin);
    }
    file=fopen("archivo.txt","a");
    fwrite(string,sizeof(char),strlen(string),file);
    fclose(file);
    return 0;
}
char* strconcat(char *string, char *buffer)
{
    char *concat;
    int largoBuffer=strlen(buffer),i;
    if(string!=NULL)
    {
        int largoString=strlen(string);
        concat = malloc(sizeof(char)* (largoString+largoBuffer+1));
        for(i=0;i< largoString;i++)
        {
            concat[i]=string[i];
        }
        for(i=0;i< largoBuffer;i++)
        {
            concat[i+largoString]=buffer[i];
        }
        concat[i+largoString]='\0';
    }
    //*string es NULL
    else
    {
        int largoBuffer=strlen(buffer),i;
        concat = malloc(sizeof(char)* (largoBuffer+1));
        //printf("buffer: %s\n",buffer);
        //printf("string: %s\n", string);
        for(i=0;i< largoBuffer;i++)
        {
            concat[i]=buffer[i];
        }
        concat[i]='\0';
    }
    return concat;
}
char* escapear(char* texto)
{
    int cantidadCaracteresEscapeables = 0;
    int i=0;
    for(;texto[i]!='\0';i++)
    {
        if(texto[i]=='END_REGISTRY' || texto[i]=='END_FIELD')
        {
            cantidadCaracteresEscapeables++;
        }
    }
    char *string = malloc(sizeof(char) * (strlen(texto) + cantidadCaracteresEscapeables+1));//El mas 1 es para el \0
    int j=0;
    for(i=0;i<strlen(texto);i++)
    {
        if(texto[i]=='END_REGISTRY'|| texto[i]=='END_FIELD')
        {
            string[j]='\\';
            j++;
        }

        string[j]=texto[i];
        j++;
    }
    string[j]='\0';
    return string;
}

