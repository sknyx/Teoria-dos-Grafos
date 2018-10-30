#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "graph.h"

int busca_noh(char info, Graph* grafo, int ordem)
{
    int i;
    for(i=0; i<ordem ; i++)
    {
        if(grafo->head[i] != NULL)
        {
            if(grafo->head[i]->info == info)
            {
                return i;
            }
        }
    }
    return -1;
}

void adiciona_node(Graph* grafo, char info, int n, Node* node)
{
    int flg_node = busca_noh(info,grafo,n);
    if(flg_node == -1)
    {
        printf("Tentativa de inserir node em vertice que nao existe");
        return -1;
    }
    if(grafo->head[flg_node]->head == NULL)
    {
        grafo->head[flg_node]->head = node;
    }
    else
    {
        Node* tmp = grafo->head[flg_node]->head;
        while(tmp != NULL)
        {
            if(tmp->next == NULL)
            {
                tmp->next = node;
                break;
            }
            tmp = tmp->next;
        }
    }
}

struct Graph* createGraph(Edge edges[], int n)
{
    unsigned i;

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->head = (Noh*)malloc(sizeof(Noh)*n);//adicionado

    for (i = 0; i < n; i++)
    {
        graph->head[i] = NULL;
    }

    for (i = 0; i < n; i++)
    {
        char src = edges[i].src;
        char dest = edges[i].dest;
        long weight = edges[i].weight;
        //printf("SRC: %c DEST:%c WEIGHT:%d\n",src,dest,weight);

        if(busca_noh(src, graph, n) == -1) //Busca no array de Vertices se existe o SRC, se n?o existe ele cria e adiciona ao array.
        {
            Noh* novoNoh = (Noh*)malloc(sizeof(Noh));
            novoNoh->info = src;
            novoNoh->head = NULL;
            int flg;
            for(flg = 0; flg < n ; flg++)
            {
                if(graph->head[flg]==NULL)
                {
                    graph->head[flg]=novoNoh;
                    break;
                }
            }
        }
        if(busca_noh(dest, graph, n) == -1) //Busca no array de Vertices se existe o DEST, se n?o existe ele cria e adiciona ao array.
        {
            Noh* novoNoh = (Noh*)malloc(sizeof(Noh));
            novoNoh->info = dest;
            novoNoh->head = NULL;
            int flg;
            for(flg = 0; flg < n ; flg++)
            {
                if(graph->head[flg]==NULL)
                {
                    graph->head[flg]=novoNoh;
                    break;
                }
            }
        }

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->dest = dest;
        newNode->weight = weight;
        newNode->next = NULL;

        adiciona_node(graph,src,n,newNode);
    }
    return graph;
}

void printGraph(Graph* graph, int n)
{
    //printf("\n\n#Utilizando a estrutura#\n\n\nARRAY VERTICES:\n");
    int kk;
    for(kk = 0; kk < n ; kk++)//varre a lista de vertices
    {
        if(graph->head[kk] != NULL)
        {
            printf("Vértice[%d]: %c ", kk, graph->head[kk]->info); //graph->head[kk] ? o Vertice
            Node* tmp = graph->head[kk]->head;
            while(tmp != NULL){//Varre a lista de adjacencias de cada vertice
                printf("-> (dest): %c (peso):%ld ", tmp->dest, tmp->weight);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
}
