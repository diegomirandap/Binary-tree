#include <stdio.h>
#include <stdlib.h>
#define VETSIZE 10

struct no {
  int valor;
  struct no *esq;
  struct no *dir;
};
typedef struct no No;

//a)

No* cria(int valor){
  No* novo=(No*)malloc(sizeof(No));
  novo->valor=valor;
  novo->esq=NULL;
  novo->dir=NULL;
  
  return novo;
}

//b) 

void insereNivel(No** raiz, int valor){
  No* novo = cria(valor);

  if(*raiz == NULL){
    *raiz = novo;
    return;
  }

  No* fila[VETSIZE];
  int frente = 0, fim = 0;
  fila[fim++] = *raiz;

  while(frente < fim){
    No* atual = fila[frente++];
    if(atual->esq == NULL){
      atual->esq = novo;
      return;
    } else {
      fila[fim++] = atual->esq;
    }
    if(atual->dir == NULL){
      atual->dir = novo;
      return;
    } else {
      fila[fim++] = atual->dir;
    }
  }
}

//c)

No *insereABB(No *raiz, int val) {
  No *p;
  if (raiz == NULL) {
    p = (No*)malloc(sizeof(No)); /* Atribuir os valores */
    p->valor = val;
    p->dir = NULL;
    p->esq = NULL;
    return p;
  }
  if (raiz->valor > val)  /* Analisar onde inserir, seguindo os padroes para ABB */
    raiz->esq = insereABB(raiz->esq, val);
  else if (raiz->valor < val)
    raiz->dir = insereABB(raiz->dir, val);
  return raiz;
}

//d)

void exibepreordem(No *p) {
  if (p == NULL)
    printf("arv n criada\n");
  printf("p:%p - val:%d - esq:%p - dir:%p\n", p, p->valor, p->esq, p->dir);
  if (p->esq != NULL)
    exibepreordem(p->esq);
  if (p->dir != NULL)
    exibepreordem(p->dir);
}

//e) 

int analisa(No*p,int max, int min){
  if (p==NULL) /* se for vazia, retorna como binaria */
    return 1;
  if(p->valor<=min||p->valor >=max) /* compara com os valores limites, que serão atualizados ao longo da execucao,
  retorna 0 caso nao seja binaria*/
    return 0;
  return analisa(p->esq,p->valor,min)&&analisa(p->dir, max, p->valor); /* verifica se os nos subsequentes seguem
  as especificacoes para serem binarios tambem */
}

//f)

int altura(No* r){
  if(r==NULL)
    return 0;
  int AltEsq=altura(r->esq);
  int AltDir=altura(r->dir);
  if(AltEsq>AltDir)
    return (AltEsq+1);
  else
    return(AltDir+1);
}

//g) 

No* inverte(No* r) {
  if (r == NULL) {
    return NULL;
  }

  No* esq = inverte(r->esq);
  No* dir = inverte(r->dir);

  r->esq = dir;
  r->dir = esq;

  return r;
}