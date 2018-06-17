#include <stdio.h>
#include <stdlib.h>

struct Obj
{
	int data;
	struct Obj *next;
};

typedef struct Obj stack;

stack* alloc();
stack* create();
stack* push(stack * s, int data);
int top(stack* s);
stack* pop(stack* s);
int isEmpty(stack* s);
void printStack(stack* s);

int main()
{
	stack *l = create();
	l = push(l , 1);
	l = push(l , 2);
	l = push(l , 3);
	l = pop(l);
	printStack(l);
	printf("Topo da Pilha:%d\n", top(l));
	return 0;
}


//Aloca a memoria suficiente para 1 Obj
stack* alloc()
{
	stack *s = (stack*) malloc(sizeof(stack));
	return s;
}

//Aterra o ponteiro da pilha
stack* create()
{
	return NULL;
}

//Empilha
stack* push(stack* s, int data)
{
	stack* aux;
	aux = alloc();
	aux->data = data;
	aux->next = s;
	return aux;
}

//Retorna o elemento do topo da pilha
int top(stack* s)
{
	return s->data;
}

//Remove o topo
stack* pop(stack *s)
{
	stack *p;
	p = s->next;
	free(s);
	return p;
}

//Caso a plha estiver vazia retorna 1, caso contrário retorna 0
int isEmpty(stack* s)
{
	if(s == NULL)
		return 1;
	else
		return 0;
}

//Imprime lista
void printStack(stack* s)
{
	stack *p;
	if(s != NULL)
	{
		for(p = s; p != NULL; p = p->next)
		{
			printf("%d\n", p->data);
		}
	}
	else
		printf("%s\n", "Stack is Empty!");
}
