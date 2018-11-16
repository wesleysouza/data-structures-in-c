#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* prox;
};

typedef struct Node List; 

typedef List* Graph;

List* aloca(void){return (List*) malloc(sizeof(List));} 

//Função que incializa a lista com uma cabeça = -1
//Assim não teremos que tratar nada quando remover o vértice penas bota um NULL e pronto :)
List* initializes()
{
	List* l;
	l = aloca();
	l->data = -1;
	l->prox = NULL;
	return l;
}

//Sua função que adiciona noo fim da lista

void add(List* l, int data)
{
	List* aux, *new;
	aux = l;
	
	while(aux->prox != NULL)
	{
		aux = aux->prox;
	}
	
	new = aloca();
	new->data = data;
	new->prox = NULL;
	
	aux->prox = new;
}

List* remNode( List* l, int data )
{
	List *ant = NULL;
	List* p = l;

	//procurando elemento na lista
	while(p!= NULL && p->data != data)
	{
		ant = p;
		p = p->prox;
	}
	
	//verifica se achou o elemento
	if(p == NULL)
	{
		return l;//Não achou, retorna a lista origibal
	}
	
	//remove elemento
	if(ant == NULL)
	{
		//retira do inicio
		l = p->prox;
	}
	else
	{
		//retira elemento do meio da lista
		ant->prox = p->prox;
	}
	free(p);
	return l;

}

/*
 * Função que retorna o tamanho da lista 
*/

int lengthList(List* l)
{
	List* p;
	int count = 0;
	p = l;
	if(l != NULL)
	{
		while(p != NULL)
		{
			p = p->prox;
			count++;
		}
	}
	return count;
}

/*
 * Função que busca um elemento na lista 
*/

/*
 * Imprime a lista
*/

void printList(List* l)
{
	List* p;
	for(p = l; p != NULL; p = p->prox)
	{
		printf("Date: %d ", p->data);
	}
}

//Criando o Grafo

Graph* buildGraph(int nvertex)
{
	Graph* g;
	int i;
	g = (Graph*) malloc(sizeof(Graph) * nvertex);
	for(i = 0; i < nvertex; i++)
	{
		 g[i] = initializes(); // Adiciona cabeça = -1 para cade vértice
	}
	return g;
}

/*
 * Função para adicionar arestas 
 * 
 * Parâmetros
 * g -> Grafo, com as listas 
 * vertex1 -> Representa o número da lista onde o elemento vai ser adicionado
 * vertex1 -> Elemento que vai ser adicionado a lista vertex1
*/

void addEdge(Graph* g, int vertex1, int vertex2)
{
	add(g[vertex1], vertex2);
}

/*
 * Função pra remover adjacencia 
*/

void removeEdge(Graph* g, int vertex1, int vertex2)
{
	remNode(g[vertex1], vertex2);
}

/*
 * Função pra imprimir a EA, pra testar tudo hauehuehuhe
*/

void printEA(Graph* g, int nvertex)
{
	int i;
	for(i = 0; i < nvertex; i++)
	{
		 printList(g[i]);
		 printf("\n");
	}
}

/*
 * Função que busca um vertice com grau de entrada nulo 
*/ 

int searchVertexNull(Graph* g, int lengthGraph)
{
	int i;
	for(i = 0; i < lengthGraph; i++)
	{
		if(lengthList(g[i]) == 1)
		{
			g[i] = NULL;
			return i;
		}
	}
	return -1;
}

/*
 * Função que remove as arestas divergentes a um vertice v 
*/ 

void removeDivergent(Graph* g, int lenghtGraph, int vertex)
{
	int i;
	for(i = 0; i < lenghtGraph; i++)
	{
		removeEdge(g, i, vertex);
	}
}

/*
 * Função de Ordenação Topologica 
*/

void ordenationTopologic(Graph* g, int lengthGraph)
{
	int i;
	int vertex;
	for(i = 0; i < lengthGraph; i++)
	{
		vertex = searchVertexNull(g, lengthGraph);
		removeDivergent(g, lengthGraph, vertex);
		printf("%d ", vertex + 1); // + 1 por que eu começo a rotular os vertices de 0 ao invés de 1, daí tenho q somar + 1 a impressao.
	}
}

int main()
{
	Graph* g;
	int sizeGraph;
	int nRules, nDependent, i, j;
	int vertex, edge;
	scanf("%d", &sizeGraph);
	g = buildGraph(sizeGraph);
	scanf("%d", &nRules);
	for(i = 0; i < nRules; i++)
	{
		scanf("%d", &vertex);
		scanf("%d", &nDependent);
		for(j = 0; j < nDependent; j++)
		{
			scanf("%d", &edge);
			addEdge(g, vertex - 1, edge - 1); // inicia do 0 e na entrada inicia com 1
		}
	}
	//printEA(g, sizeGraph);
	ordenationTopologic(g, sizeGraph);
	return 0;
}
