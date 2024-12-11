struct no;
typedef struct no No;

No* cria(int valor);

void insereNivel(No** raiz, int valor);

No *insereABB(No *raiz, int val);

void exibepreordem(No *p);

int analisa(No*p,int max, int min);

int altura(No* r);

No* inverte(No* r);
