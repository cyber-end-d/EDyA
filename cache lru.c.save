#include <stdio.h>
#include <stdlib.h>
#define N_PAGINAS 10

struct pagina {
    struct pagina *ant, *sig;
    unsigned numeroPagina;
};
typedef struct pagina Pagina;

struct cache {
    unsigned cantidad;
    unsigned capacidad;
    struct pagina *cabecera, *trasero;
};
typedef struct cache Cache;

Pagina * newPagina(unsigned);
Cache * crearCache(unsigned);
void initHash(Pagina *[]);
int isFull(Cache *);
int isCacheEmpty(Cache *);
void deCache(Cache *);
void enCache(Cache *, Pagina **, unsigned);
void solicitarPagina(Cache *, Pagina*[], unsigned);

int main() {
    Pagina * hash[N_PAGINAS]; // Es posible solicitar 10 paginas distintas

    initHash(hash);
    Cache* cache = crearCache(4);

    solicitarPagina(cache, hash, 2);
    solicitarPagina(cache, hash, 1);
    //solicitarPagina(cache, hash, 10);
    solicitarPagina(cache, hash, 4);
    solicitarPagina(cache, hash, 1);
    solicitarPagina(cache, hash, 5);

    printf ("%d ", cache->cabecera->numeroPagina);
    printf ("%d ", cache->cabecera->sig->numeroPagina);
    printf ("%d ", cache->cabecera->sig->sig->numeroPagina);
    printf ("%d ", cache->cabecera->sig->sig->sig->numeroPagina);

    return 0;
}

Pagina * newPagina(unsigned numeroPagina) {

    Pagina* temp = (Pagina *) malloc(sizeof(Pagina));
    temp->numeroPagina = numeroPagina;

    temp->ant = temp->sig = NULL;

    return temp;
}

Cache * crearCache(unsigned capacidad) {
    Cache * cache = (Cache *) malloc(sizeof(Cache));

    cache->cantidad = 0;
    cache->cabecera = cache->trasero = NULL;

    cache->capacidad = capacidad;

    return cache;
}

void initHash(Pagina *hash[N_PAGINAS]) {
    int i;

    for( i = 0; i < N_PAGINAS; ++i ) {
        hash[i] = NULL;
    }
}

int isFull(Cache * cache) {
    return cache->cantidad == cache->capacidad;
}

int isCacheEmpty(Cache * cache) {
    return cache->trasero == NULL;
}

void deCache(Cache * cache) {
    if(isCacheEmpty(cache)) {
        return;
    }

    if(cache->cabecera == cache->trasero) {
        cache->cabecera = NULL;
    }

    Pagina * temp = cache->trasero;
    cache->trasero = cache->trasero->ant;

    if (cache->trasero) {
        cache->trasero->sig = NULL;
    }

    free( temp );

    cache->cantidad--;
}

void enCache(Cache * cache, Pagina * hash[N_PAGINAS], unsigned numeroPagina) {

    if (isFull(cache)) {

        hash[cache->trasero->numeroPagina] = NULL;
        deCache(cache);
    }

    Pagina * temp = newPagina(numeroPagina);
    temp->sig = cache->cabecera;

    if (isCacheEmpty(cache)) {

        cache->trasero = cache->cabecera = temp;
    } else {

        cache->cabecera->ant = temp;
        cache->cabecera = temp;
    }

    hash[numeroPagina] = temp;

    cache->cantidad++;
}

void solicitarPagina(Cache * cache, Pagina* hash[N_PAGINAS], unsigned numeroPagina) {
    Pagina * reqPage = hash[numeroPagina];

    if ( reqPage == NULL ) {
        enCache(cache, hash, numeroPagina);
    }

    else if (reqPage != cache->cabecera) {
        reqPage->ant->sig = reqPage->sig;

        if (reqPage->sig) {
            reqPage->sig->ant = reqPage->ant;
        }

        if (reqPage == cache->trasero) {
           cache->trasero = reqPage->ant;
           cache->trasero->sig = NULL;
        }

        reqPage->sig = cache->cabecera;
        reqPage->ant = NULL;

        reqPage->sig->ant = reqPage;

        cache->cabecera = reqPage;
    }
}
