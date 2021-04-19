
#include "ArvoreBB.h"

//ARVORE BINARIA DE BUSCA

//inicializando arvore binaria
Node *inicializarArvore(){
  return NULL;
}

//inserindo valores na arvore binaria
Node *inserirArvore(Node *raiz, float conteudo, int chave){
  if(raiz == NULL){
    Node *aux = (Node*)malloc(sizeof(Node));
    aux->valor = conteudo;
    aux->chave = chave;
    aux->esq = NULL; 
    aux->dir = NULL;
    return aux;
  }else{
    if(chave > raiz->chave){
      raiz->dir = inserirArvore(raiz->dir, conteudo, chave); 
    }else if(chave < raiz->chave){
       raiz->esq = inserirArvore(raiz->esq, conteudo, chave);
    }
  }
  return raiz;
}

//imprimindo valores na arvore binaria
void imprimirArvore(Node *raiz){
  if(raiz != NULL){
    printf(" %0.1f ", raiz->valor);
    imprimirArvore(raiz->esq);
    imprimirArvore(raiz->dir);
  }
}

//liberando arvore binaria
void liberarArvore(Node *raiz){
  if(raiz != NULL){
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
  }
}

//buscando chave na arvore binaria
Node *buscarArvore(Node *raiz, int chave){
  if(raiz != NULL){
    if(raiz->chave == chave){
      return raiz;
    }else{
      if(chave > raiz->chave){
        return buscarArvore(raiz->dir, chave);
      }else{
         return buscarArvore(raiz->esq, chave);
      }
    }
  }
  return NULL; //caso nao exista a chave
}

//percorrendo a arvore binaria em ordem crescente
void percorrerEmOrdem(Node *raiz, int *vetor, int *i){
  if(raiz != NULL){
    percorrerEmOrdem(raiz->esq,vetor, i);
    vetor[*i] = raiz->chave;
    *i = *i+1;
    percorrerEmOrdem(raiz->dir, vetor, i);
  }
}
