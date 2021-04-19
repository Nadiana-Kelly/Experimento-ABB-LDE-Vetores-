
#include "ListaDE.h"

//LISTA DUPLAMENTE ENCADEADA

//inicializando a lista duplamente encadeada
void inicializaLista( Tlista *list){
  (*list).inicio = NULL;
  (*list).fim = NULL;
}

//insere um elemento no inicio da lista duplamente encadeada
void inserirInicioLista(Tlista *list, float valor, int chave){
  no *novo = (no*)malloc(sizeof(no));
  (*novo).valor = valor;
  (*novo).chave = chave;
  (*novo).prox = NULL;
  (*novo).ant = NULL;

  if((*list).inicio == NULL){
    (*list).inicio = novo;
    (*list).fim = novo;
  }else{
    (*(*list).inicio).ant = novo;
    (*novo).prox = (*list).inicio;
    (*list).inicio = novo;
  }

}

//insere um elemento no fim da lista duplamente encadeada
void inserirFimLista(Tlista *list, float valor, int chave){
  no *novo = (no*)malloc(sizeof(no));
  (*novo).valor = valor;
  (*novo).chave = chave;
  (*novo).prox = NULL;
  (*novo).ant = NULL;
  if((*list).inicio == NULL){
    (*list).inicio = novo;
    (*list).fim = novo;
  }else{
    (*(*list).fim).prox = novo;
    (*novo).ant = (*list).fim;
    (*list).fim = novo;
  }

}

//buscar elemento na lista duplamente encadeada
int BuscarLista(Tlista *list, int chave){
  no *elemAtual, *elemProx, *elemAnt;
  int resp = 0;
  if((*list).inicio == NULL){
    printf("\n");
    printf("\nlista vazia!");
  }else{
    elemAtual = (*list).inicio;
    while(elemAtual != NULL ){
      elemProx = (*elemAtual).prox;
      elemAnt = (*elemAtual).ant;

      if((*elemAtual).chave == chave){
       resp = 1;
        break;
      }else{
        elemAtual = (*elemAtual).prox;
      }
    }
  }
  return resp;
}

//imprime a lista pelo inicio
void imprimirInicioLista(Tlista *list){
  no *aux;
  if((*list).inicio == NULL){
    printf("\n");
    printf("\nLista vazia");
  }else{
    aux = (*list).inicio;
    printf("\n");
    printf("\nValores da Lista Duplamente Encadeada: ");
    while(aux != NULL){
      printf(" %0.1f ", (*aux).valor);
      aux = (*aux).prox;
    }
  }
}

//imprime a lista pelo fim
void imprimirFimLista(Tlista *list){
  no *aux;
  if((*list).fim == NULL){
    printf("\n");
    printf("\nLista vazia");
  }else{
    aux = (*list).fim;
    printf("\n");
    printf("\nValores da Lista Duplamente Encadeada: ");
    while(aux != NULL){
       printf(" %0.1f ", (*aux).valor);
      aux = (*aux).ant;
    }
  }
}
