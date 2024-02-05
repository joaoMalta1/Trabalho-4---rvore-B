// João Ricardo Malta de Oliveira - 2112714
// Vinicius Machado da Rocha Viana - 2111343
#include <stdio.h>
#include <stdlib.h>

#define MAX 4
#define MIN 2

typedef struct no Page;
struct no {
  int qtdElem;    // quantidade de elementos na chave
  int chave[MAX]; // não inclui overflow da chave
  Page *ramo[MAX + 1];
};

Page *cria(int qtdElem, int chaves[], Page *filhos[]) {
  Page *novo_no = (Page *)malloc(sizeof(Page));
  if (novo_no == NULL) {
    printf("Erro na alocação de memória.");
    return NULL;
  }
  novo_no->qtdElem = qtdElem;

  for (int i = 0; i < qtdElem; i++) {
    novo_no->chave[i] = chaves[i];
  }

  for (int i = 0; i <= qtdElem; i++) {
    novo_no->ramo[i] = filhos[i];
  }

  return novo_no;
}

void intervalo(Page *arv, int lim_inf, int lim_sup) {
  if (arv) {
    int i;
    for (i = 0; i < arv->qtdElem; i++) {
      if (arv->ramo[i]) {
        intervalo(arv->ramo[i], lim_inf, lim_sup);
      }

      if (arv->chave[i] >= lim_inf && arv->chave[i] <= lim_sup) {
        printf("%d ", arv->chave[i]);
      }
      // Considerei que é para incluir os valores nos limites inferiores e
      // superior
    }
    if (arv->ramo[i]) {
      intervalo(arv->ramo[i], lim_inf, lim_sup);
    }
  }
}

int main() {
  Page *nulos[MAX + 1] = {NULL};
  int arr1[] = {10, 40};
  int arr2[] = {60, 70};
  int arr3[] = {80, 90};
  int arr4[] = {110, 115};
  int arr5[] = {130, 135, 140, 170};
  int arr6[] = {220, 230, 240, 250};

  int arr7[] = {50, 75};
  int arr8[] = {120, 200};

  int arr9[] = {100};

  Page *raiz1 = cria(2, arr1, nulos);
  Page *raiz2 = cria(2, arr2, nulos);
  Page *raiz3 = cria(2, arr3, nulos);
  Page *raiz4 = cria(2, arr4, nulos);
  Page *raiz5 = cria(4, arr5, nulos);
  Page *raiz6 = cria(4, arr6, nulos);

  Page *folhas1[] = {raiz1, raiz2, raiz3};
  Page *folhas2[] = {raiz4, raiz5, raiz6};

  Page *no1 = cria(2, arr7, folhas1);
  Page *no2 = cria(2, arr8, folhas2);

  Page *nos_primarios[] = {no1, no2};
  Page *head = cria(1, arr9, nos_primarios);
  intervalo(head, 10, 250);

  return 0;
}
