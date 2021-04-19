
#include "Vetor.h"
//Implementações para as buscas do vetor

//busca binaria RECURSIVA
int BuscaBinariaRecursiva(int *vetor, int chave, int inicio, int fim){
  int meio = inicio + floor((fim - inicio)/2);

  if(inicio > fim){
    return -1; //elemento não encontrado
  }else if(vetor[meio] == chave){
    return meio;
  }else if(vetor[meio] > chave){
    return  BuscaBinariaRecursiva(vetor, chave,inicio, meio-1);
  }else{
     return  BuscaBinariaRecursiva(vetor, chave,meio+1, fim);
  }

}

//busca binaria INTERATIVA 
int BuscaSequencial(int *vet, int chave, int valormaximo){
  while(valormaximo--)
	  if(vet[valormaximo] == chave)
	      return 0;	
  return 1;
}
