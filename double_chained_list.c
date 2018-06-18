#include <stdio.h>
#include <stdlib.h>

struct lista2{
       int info;
       struct lista2* ant;
       struct lista2* prox;
};

typedef struct lista2 Lista2;

// Inicializa a lista como Nula

Lista2* inicializa (void)
{
return NULL;
}

// Função de Inserção  

Lista2* insere(Lista2* l , int v)
{
        Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
        novo->info = v;
        novo->prox = l;
        novo->ant = NULL;
        // Verifica se a lista não está vazia
        if (l != NULL)    
           l->ant = novo;
return novo;
}

// Função de Busca

Lista2* busca(Lista2* l, int v)
{
        Lista2* p;
        for (p = l;p!=NULL; p = p->prox)
            if(p->info == v)
                       return p;
return NULL; // caso não encontrar o elemento retorna NULL
}

// Função que retira um elemento da lista

Lista2* retira(Lista2* l, int v)
{
        Lista2* p = busca(l,v);
        if (p == NULL)
           return l;  // caso não encontrar o elemento retorna a lista inalterada
        if (l == p)   // testa se é o rpimeiro elemento
           l = p->prox;
        else
            p->ant->prox = p->prox;
        if(p->prox != NULL) // testa se é o ultimo
        p->prox->ant = p->ant;
        free(p);
        return l;
}

// Função de impressão da lista

Lista2 *imprimir(Lista2* l) {
      Lista2* p;
      for (p = l; p != NULL ; p = p ->prox)
      printf("info %d \n",p->info);
}

// Função principal

int main(void)
{
    Lista2* l;
    l = inicializa();
    l = retira(l,0);
    l = insere(l,20);
    l = insere(l,25);
    l = insere(l,40);
    l = insere(l,50);
    l = retira(l,20);
    l = retira(l,25);
    imprimir(l);
    system("pause");
    return(0);
}
        
        
