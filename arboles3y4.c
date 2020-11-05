#include <stdio.h>
#include <stdlib.h>
#define N 5

struct nodo {
    int valor;
    struct nodo * der;
    struct nodo * izq;
};

typedef struct nodo Nodo;
Nodo * newNodo(void);
void insertarEnArbol(Nodo **, Nodo *);
void inOrden(Nodo *);
void preOrden(Nodo *);

int main() {
    Nodo * raiz = NULL;
    int i;
    int valor;
    Nodo * nodo;

    for(i = 0; i < N; i++) {
        printf("Numero: ");
        scanf("%d", &valor);
        nodo = newNodo();
        nodo->valor = valor;
        insertarEnArbol(&raiz, nodo);
    }

    printf("\ninOrden: ");
    inOrden(raiz);
    printf("\npreOrden: ");
    preOrden(raiz);
    printf("\nposOrden: ");
    posOrden(raiz);

    printf("\nProfundidad: %d", profundidad(raiz));

    getch();

    return 0;
}

Nodo * newNodo() {
    Nodo * aux;

    aux = (Nodo *) malloc(sizeof(Nodo));

    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}

void insertarEnArbol(Nodo ** pRaiz, Nodo * nodo) {

    if(*pRaiz == NULL) {
        *pRaiz = nodo;
    } else {

        if((*pRaiz)->valor < nodo->valor) {

            insertarEnArbol(&((*pRaiz)->der), nodo);
        } else if ((*pRaiz)->valor > nodo->valor) {

            insertarEnArbol(&((*pRaiz)->izq), nodo);
        } else {

            printf("Valor duplicado");
        }
    }
}

void inOrden(Nodo * raiz) {

    if(raiz != NULL) {
        inOrden(raiz->izq);
        printf("%d ", raiz->valor);
        inOrden(raiz->der);
    }
}

void preOrden(Nodo * raiz) {

    if(raiz != NULL) {
        printf("%d ", raiz->valor);
        inOrden(raiz->izq);
        inOrden(raiz->der);
    }
}

void posOrden(Nodo * raiz) {

    if(raiz != NULL) {
        inOrden(raiz->izq);
        inOrden(raiz->der);
        printf("%d ", raiz->valor);
    }
}
int profundidad(Nodo * raiz) {
    int profIzq;
    int profDer;

    if(raiz == NULL) {
        return 0;
    } else {
        printf("\nder %d izq %d", profDer, profIzq);
        profIzq = profundidad(raiz->izq);
        profDer = profundidad(raiz->der);
    }

    if(profDer > profIzq) {
        return profDer + 1;
    } else {
        return profIzq + 1;
    }
}
