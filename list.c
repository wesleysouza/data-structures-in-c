#include <stdlib.h>
#include <stdio.h>

struct list
{
	int dado;
	struct list *prox;
};

typedef struct list List;

List* initialize()
{
	return NULL;
}

List* alocc()
{
	List *l = malloc(sizeof(List));
	return l;
}

//Inserção na cabeça da lista
List* addNode(List* l, int dado)
{
	List* aux;
	aux = alocc();
	aux->dado = dado;
	aux->prox = l;
	return aux;
}

void printList(List* l)
{
	List* aux;
	for(aux = l; aux != NULL; aux = aux->prox)
	{
		printf("%d", aux->dado);
	}
}

int main()
{
	List *l;
	l = initialize();
	addNode(l , 1);
	addNode(l , 2);
	printList(l);
	return 0;#include <stdlib.h>
#include <stdio.h>

struct list
{
	int dado;
	struct list *prox;
};

typedef struct list List;

List* initialize()
{
	return NULL;
}

List* alocc()
{
	List *l = malloc(sizeof(List));
	return l;
}

//Inserção na cabeça da lista
List* addNode(List* l, int dado)
{
	List* aux;
	aux = alocc();
	aux->dado = dado;
	aux->prox = l;
	free(l);
	l = aux;
	free(aux);
}

void printList(List* l)
{
	List* aux;
	for(aux = l; aux != NULL; aux = aux->prox)
	{
		printf("%d", aux->dado);
	}
}

int main()
{
	List *l;
	l = initialize();
	addNode(l , 1);
	addNode(l , 2);
	printList(l);
	return 0;
}
