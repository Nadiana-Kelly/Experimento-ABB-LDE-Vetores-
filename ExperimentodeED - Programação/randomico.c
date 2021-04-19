
#include "randomico.h"

//sortear n valores inteiro de chave
int sorteaChaves(int quantidadeChaves){
	int x = rand() % quantidadeChaves;
	return x;
}

//sortear n valores valores floats de chave 
float sorteaValores(){
  float max = 20, min =  1;
	float res = min + rand() * (max - min) / RAND_MAX;
	return res;
}

struct tupla gerar_tupla() {
	struct tupla result;
	result.valor = sorteaValores();
	result.chave = sorteaChaves(1<<30);
	return result;
}

