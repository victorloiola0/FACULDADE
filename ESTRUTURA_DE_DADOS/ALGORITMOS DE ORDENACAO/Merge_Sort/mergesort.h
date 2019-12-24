#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct lista Lista;


Lista *buscar(Lista *l,int v);
Lista *lista_criar();
Lista *lista_libera();
Lista *lista_inserir(Lista *l,int valor);
Lista *lista_remover(Lista *l,int v);
int lista_vazia(Lista *l);
void lista_imprimir(Lista *l);
Lista *dividir(Lista *l);
void merge(Lista *l,Lista *l2);
Lista *mergeSort(Lista *l);
void menu();

