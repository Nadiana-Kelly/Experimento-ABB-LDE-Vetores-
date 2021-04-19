
#ifndef ListaDE_h
#define ListaDE_h

#include <stdio.h>
#include <stdlib.h>

//LISTA DUPLAMENTE ENCADEADA

//criando o tipo no da lista duplamente encadeada
typedef struct no{
  int chave;
  float valor;
  struct no *prox;
  struct no *ant;
}no;

//criando o tipo lista encadeada
typedef struct Tlista{
  no  *inicio;
  no *fim;
}Tlista;

//inicializando a lista duplamente encadeada
void inicializaLista( Tlista *list);

//insere um elemento no inicio da lista duplamente encadeada
void inserirInicioLista(Tlista *list, float valor, int chave);

//insere um elemento no fim da lista duplamente encadeada
void inserirFimLista(Tlista *list, float valor, int chave);

//buscar elemento na lista duplamente encadeada
int BuscarLista(Tlista *list, int chave);

//imprime a lista pelo inicio
void imprimirInicioLista(Tlista *list);

//imprime a lista pelo fim
void imprimirFimLista(Tlista *list);



#endif 