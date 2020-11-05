#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    struct nodo*sig;
    char string[100];
}nodo;

int hash(char[]);
void dispAb(nodo*[],int,char[]);

int main(){
    nodo*hash[B];
    int clase;
    char string[100];

    printf("Ingrese el texto: ");
    fflush(stdin);
    gets(string);

    clase=hash(string);
    dispAb(hash,clase,string);

    return 0;

}

int hash(char s[100]){
    int i, res;

    for(i=0;s[i]!='\0';i++){
        res+=(int)s[i];
    }
    return res%B;
}

void dispAb(nodo*hash[B],int clase,char string){
    nodo*aux=NULL;

    aux=hash[clase];
    if(aux==NULL){//no hay colision
        hash[clase]=newNodo(string);
    }else{//colision
        for(;(aux->sig)!=NULL;aux=(aux->sig)){
            aux->sig=newNodo(string);
        }
    }
}
