/* Exemplo de teste da heap. Lê alguns números da entrada e imprime a heap
 * resultante.
 *
 * Para compilar, especifique todos os arquivos .c na linha de comando.
 *
 * Exemplo:
 * 	gcc teste.c heap.c -o heap
 */

#include <stdio.h>
#include "heap.h"

void imprime_vetor(int *vet, int tam)
{
	if (tam == 0) {
		printf("Vazio\n");
		return;
	}
	
	printf("%d", vet[0]);
	for (int i = 1; i < tam; i++) {
		printf(", %d", vet[i]);
	}
	printf("\n");
}

int main(void)
{
	int heap[100];
	int tam;
	int num;

	printf("Digite até 100 elementos inteiros.\n");
	printf("Digite -1 para encerrar.\n");

	tam = 0;
	scanf("%d", &num);
	while (tam < 100 && num != -1) {
		heap[tam] = num;
		tam++;
	
		scanf("%d", &num);
	}

	printf("Ordem de leitura:\n");
	imprime_vetor(heap, tam);

	montar_heap(heap, tam);

	printf("Ordem dos elementos na heap:\n");
	imprime_vetor(heap, tam);
}
