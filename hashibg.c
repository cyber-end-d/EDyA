#include<stdio.h>
#include<stdlib.h>
#define B 5
int hash(char[]);
int isFull(char*[]);
int miembro(char*[],char[],int[]);
void dispCer(char*[],int,char[],int[]);

int main(){
    char*hash[B];
    int clase;
    char string[100];

    printf("Ingrese el texto: ");
    fflush(stdin);
    gets(string);

    clase=hash(string);
    if(isFull(hash)!=0){
       dispCer(hash,clase,string);
    }
    dispCer(hash,clase,string);

    return 0;

}

int hash(char s[100]){
    int i, res;

    for(i=0;s[i]!='\0';i++){
        res+=(int)s[i];
    }
    return res%B;
}

int isFull(char*hash[B]){
    int i=0;

    while(hash[i]!=NULL&&i<B){
        i++;
    }
    return(i<B)?0:1;0//operacion ternaria
}

int miembro(char*hash[B],char string[100],int permut[B]){
    int i=0;
    int clase=hash(string);
    if (hash[clase]==NULL){//no es miembro
        return 1;
    }else if(strcmp(hash[clase],string)==0){
        return 0;
    }else{
        while(strcmp(hash[permut[i]],string)!=0&&hash[permut[i]]!=NULL){
            i++;
        }
    }
    return(hash[permut[i]]!=NULL)?1:0;
}

void dispCer(char*hash[B],int clase,char string[100],int permut[B]){
    char*aux=NULL;
    int i=0;

    aux=hash[clase];
    if(aux==NULL){//no hay colision
        hash[clase]=&string[0];
    }else{
        while(hash[permut[i]]!=NULL){
            i++;
        }
        hash[permut[i]]=&string[0];
    }
}
