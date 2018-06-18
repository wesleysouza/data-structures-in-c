#include <stdio.h>
#include <stdlib.h>

struct arv {
       int info;
       struct arv* esq;
       struct arv* dir;
};

typedef struct arv Arv;

Arv* cria (void)
{
     return NULL;
}

Arv* insere(Arv* a, int v)
{
     if (a == NULL){
           a = (Arv*) malloc(sizeof(Arv));
           a->info = v;
           a -> esq = a->dir = NULL;
}
else if(v < a->info)
     a->esq = insere(a->esq,v);
else
     a->dir = insere(a->dir,v);
return a;
}

void imprimeEmOrdem(Arv* a, FILE* arquivo)
{
     if(a != NULL) {
          imprimeEmOrdem(a->esq, arquivo);
          fprintf(arquivo, "%d ",a->info);
          imprimeEmOrdem(a->dir, arquivo);
     }
}

void imprimeEmPreOrdem(Arv* a, FILE* arquivo)
{
     if(a != NULL){
          fprintf(arquivo, "%d ",a->info);
          imprimeEmPreOrdem(a->esq, arquivo);
          imprimeEmPreOrdem(a->dir, arquivo);
     }
}

void imprimeEmPosOrdem(Arv* a,FILE* arquivo)
{
      if(a != NULL){
          imprimeEmPosOrdem(a->esq, arquivo);
          imprimeEmPosOrdem(a->dir, arquivo);
          fprintf(arquivo,"%d ",a->info);
      }
}

int main(int argc, char* argv[])
{
    Arv* r;
    FILE* entrada;
    FILE* saida;
    int n, c, i;

    entrada = fopen(argv[1],"r");
    saida = fopen(argv[2],"w");
    r = cria();

    fscanf(entrada,"%d",&n);
    for (i = 0; i < n; i++){
        fscanf(entrada,"%d",&c);
        r = insere(r,c);
    }
    imprimeEmOrdem(r,saida);
    fprintf(saida, "\n");
    imprimeEmPreOrdem(r,saida);
    fprintf(saida, "\n");
    imprimeEmPosOrdem(r,saida);



    return 0;
}



