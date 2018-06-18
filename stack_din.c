#include <stdio.h>
#include <stdlib.h>

struct lista{
       int info;
       struct lista* prox;
};

typedef struct lista Lista;

struct pilha{
       Lista* prim;
};

typedef struct pilha Pilha;

// Função  que cria e aloca a Pilha

Pilha* cria(void)
{
       Pilha* p = (Pilha*) malloc(sizeof(Pilha));
       p->prim = NULL;  // Inicia a Lista como sendo vazia 
       return p;
}

// Função que insere um elemento na Pilha

void push(Pilha* p, int v)  
{
       Lista* n = malloc(sizeof(Lista));
       n->info = v;
       n->prox = p->prim;
       p->prim = n;
}

// Função que retira um elemento da Pilha

int pop(Pilha*p)
{
       Lista* t;
       int v;
       if (pilha_vazia(p))
          return 0;     // caso a pilha estiver vazia não retorna nada   
       t = p->prim;
       v = t->info;
       p->prim = t ->prox;
       free(t);
       return v;
}

// Função que verifica se a Pilha esta vazia

int pilha_vazia(Pilha* p)
{
       return (p->prim == NULL);
}

// Função de impressão da Pilha

void imprime(Pilha* p)
{
     Lista* q;
     for (q = p->prim; q != NULL; q = q->prox)
           printf("Info %d \n",q->info);
}

// Função Principal

int main(void){
    Pilha* p;
    p = cria();
    pop(p);
    push(p,20);
    push(p,50);
    pop(p);
    imprime(p);
    system("pause");
    return(0);
}
              
