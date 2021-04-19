
#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBB.h"
#include "ListaDE.h"
#include "randomico.h"
#include <time.h>
#include "Vetor.h"
#define N 12000 // será o valor de referencia pro N
#define K 7300000 // será o valor de referencia pro K

//valores para ABB ter 2s: N = 12000 e K = 7300000
int main(){
  srand(time(NULL));
  //variaveis para o tempo
  time_t
  comeco,fim;
  long double total;

  //inicializando a arvore binaria de busca
  Node *raiz = inicializarArvore();

  int i = 0;

  //inicializando a lista duplamente encadeada
  Tlista l1;
  inicializaLista(&l1);

  int y; 

  int *vetordechaves;
  vetordechaves = (int*)malloc(N*sizeof(int));

  for(y=0;y<N;y++){
  //preenche a arvore com as chaves e os valores sorteados
	struct tupla t;
	t = gerar_tupla();

	if(buscarArvore(raiz, t.chave) == NULL) {
    raiz = inserirArvore(raiz, t.valor, t.chave);
    inserirInicioLista(&l1, t.valor, t.chave);
	  }
  }

  //percorre a ABB em ordem e adiciona os valores em um vetor
  percorrerEmOrdem(raiz,vetordechaves,&i);
  int numero_sorteado;
  //imprime se existe ou nao a chave buscada NA ARVORE
  printf("\nBUSCA NA ARVORE: \n");
  
  comeco = clock();
  for(i=0; i<K; i++){
    numero_sorteado = rand();
    buscarArvore(raiz, numero_sorteado); //funcao de busca
  }
  fim = clock();
  total = (long double)(fim - comeco)/CLOCKS_PER_SEC;
  printf("Tempo de busca: %.2Lf\n", total);

  // buscando chave na busca binaria RECURSIVA
  printf("\nBUSCA BINARIA RECURSIVA NO VETOR: \n");
  int z;
  comeco = clock();
  for(i=0;i<K;i++){
    numero_sorteado = rand();
     z = BuscaBinariaRecursiva(vetordechaves, numero_sorteado, 0, N-1);
  }

  fim = clock();
  total = (long double)(fim - comeco)/CLOCKS_PER_SEC;
  printf("Tempo de busca: %.2Lf\n", total);

  //buscando chave na busca sequencial INTERATIVA
  printf("\nBUSCA SEQUENCIAL NO VETOR: \n");
  int w;
  comeco = clock();


  for(i=0; i<K; i++) {
      numero_sorteado = rand();
      BuscaSequencial(vetordechaves, numero_sorteado, N);
  }
  fim = clock();
  total = (long double)(fim - comeco)/CLOCKS_PER_SEC;
  printf("Tempo de busca: %.2Lf\n", total);

  //imprime se existe ou nao a chave buscada NA LISTA 
  printf("\nBUSCA NA LISTA DUP. ENCADEADA: \n");
  int x;
  comeco = clock();
  for(i=0; i<K; i++){
    numero_sorteado = rand(); 
    x = BuscarLista(&l1, numero_sorteado);
  }
  fim = clock();
  total = (long double)(fim - comeco)/CLOCKS_PER_SEC;
  printf("Tempo de busca: %.2Lf\n", total);


  //libera a arvore binaria de busca 
  liberarArvore(raiz);
} 