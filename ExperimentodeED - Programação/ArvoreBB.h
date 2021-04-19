
#ifndef ArvoreBB_h
#define ArvoreBB_h

#include <stdio.h>
#include <stdlib.h>

//ARVORE BINARIA DE BUSCA

//criando tipo de no de arvore binaria
typedef struct node{
  float valor;
  int  chave; 
  struct node *esq;
  struct node *dir;
}Node; // nó

//inicializando arvore binaria
Node *inicializarArvore();

//inserindo valores na arvore binaria
Node *inserirArvore(Node *raiz, float conteudo, int chave);

//imprimindo valores na arvore binaria
void imprimirArvore(Node *raiz);

//liberando arvore binaria
void liberarArvore(Node *raiz);

//buscando chave na arvore binaria
Node *buscarArvore(Node *raiz, int chave);

//percorrendo a ABB em ordem crescente e adicionando em um vetor
void percorrerEmOrdem(Node *raiz, int *vetor, int *i);



#endif 