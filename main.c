#include <stdio.h>
#include <stdlib.h>
#include "aux.h"
#define VETSIZE 10

int main(void) {
  
  No* raiz1=NULL;
  No* raiz2=NULL;
  int cont, altura1, altura2;
  
  //a)

  int vet[VETSIZE];
  int a;
 
  for (int i = 0; i < VETSIZE; i++) {
    a = rand() % 20;
    for(int j=0;j<VETSIZE;j++)
      if (vet[j]==a){
        a = rand() % 20;
        j=0;
      }
    vet[i]=a;
    printf("-%d-", vet[i]);
  }

  //b)

  for(cont=0;cont<VETSIZE;cont++)
    insereNivel(&raiz1, vet[cont]);

  //c)
  
  for(cont=0;cont<VETSIZE;cont++)
    raiz2 = insereABB(raiz2,vet[cont]);
  
  
  //d)
  
  printf("\nArvore 1 por pre ordem:\n");
  exibepreordem(raiz1);

  printf("\nArvore 2 por pre ordem:\n");
  exibepreordem(raiz2);
  
  //e)

  printf("\n");
  int r1=analisa(raiz1,20,0);
  if(r1==0){
    printf("a arvore nao e binaria\n");
  }
  else
    printf("a arvore e binaria\n");
  
  int r2=analisa(raiz2,20,0);
  if(r2==0){
    printf("a arvore nao e binaria\n");
  }
  else
    printf("a arvore e binaria\n");
  
  //f)
  altura1=altura(raiz1);
  printf("A arvore 1 possui altura %d\n", altura1);
  altura2=altura(raiz2);
  printf("A arvore 2 possui altura %d\n", altura2);
  
  //g)
  printf("\nArvore 2 invertida por pre ordem:\n");
  No* raiz2Invertida = inverte(raiz2);
  exibepreordem(raiz2Invertida);
  
  return 0;
}
