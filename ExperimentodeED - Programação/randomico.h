
#ifndef randomico_h
#define randomico_h
#include <stdio.h>
#include <stdlib.h>

struct tupla {
	int   chave;
	float valor;
};

//sortear n valores inteiro de chave
int sorteaChaves(int quantidadeChaves);

//sortear n valores valores floats de chave 
float sorteaValores();

//gera as tuplas
struct tupla gerar_tupla();

#endif 