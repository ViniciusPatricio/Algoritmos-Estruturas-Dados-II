/* Implementação de heap máxima para inteiros.
 */

/* Protótipos declarados aqui e disponíveis para o usuário. A função
 * montar_heap() constrói a heap a partir de um vetor e faz parte da interface
 * pública deste módulo. A função heapify() é utilizada pela ED para fazer a
 * manutenção da heap.
 */
#include "heap.h"

void heapify(int *vet, int pai, int tam);


/* Macros utilizadas para encontrar os índices dos elementos dentro da heap.
 */
#define PAI(i) (i / 2)
#define ESQ(i) (i * 2 + 1)
#define DIR(i) (i * 2 + 2)


/* A função heapify() toma como entrada uma "quase-heap" e corrige o primeiro
 * elemento.
 * Pré-condições:
 *    O elemento vet[pai] deve ser válido e pertencer ao vetor
 *    Se existir, vet[ESQ(pai)] deve ser o primeiro elemento de uma heap máxima
 *    Se existir, vet[DIR(pai)] deve ser o primeiro elemento de uma heap máxima
 * Pós-condições:
 *    O elemento vet[pai] é o primeiro de uma heap máxima
 */
void heapify(int *vet, int pai, int tam)
{
	/* Encontra o maior elemento dentre o pai e seus filhos (se houver)
	 */
	int maior = pai;
	if (ESQ(pai) < tam && vet[ESQ(pai)] > vet[pai]) {
		maior = ESQ(pai);
	}
	if (DIR(pai) < tam && vet[DIR(pai)] > vet[maior]) {
		maior = DIR(pai);
	}

	/* Se o pai (raiz) não for o maior dos três, então ele é trocado com o
	 * maior e a função é chamada recursivamente para continuar corrigindo
	 * a heap
	 */
	if (maior != pai) {
		int aux = vet[pai];
		vet[pai] = vet[maior];
		vet[maior] = aux;

		heapify(vet, maior, tam);
	}
}


/* A função montar_heap() recebe como entrada um vetor e arrumar todos os seus
 * elementos para comporem uma heap.
 */
void montar_heap(int *vet, int tam)
{
	/* Seleciona a posição do último elemento que possui um filho e aplica
	 * a operação heapify, da direita para a esquerda, montando a heap
	 */
	int pos = (tam / 2) - 1;
	while (pos >= 0) {
		heapify(vet, pos, tam);
		pos--;
	}
}
