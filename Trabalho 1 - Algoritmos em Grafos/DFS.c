#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "graph.h"

void DFSaux(int v, Graph* tmp_graph, int ordem)
{
    /* Marca o n� atual como visitado e printa ele */
    tmp_graph->head[v]->visited = 1;

    /* Recursividade para todos os v�rtices adjacentes a este v�rtice */

    if(tmp_graph->head[v] != NULL)
    {
        printf("(%c ",tmp_graph->head[v]->info);

        if(tmp_graph->head[v]->head != NULL)
        {

            Node* tmp = tmp_graph->head[v]->head;
            int indiceTemp = busca_noh(tmp->dest, tmp_graph, ordem);

            while(tmp != NULL)
            {
                if(tmp_graph->head[indiceTemp]->visited != 1)
                {
                    DFSaux(indiceTemp, tmp_graph, ordem);
                    tmp_graph->head[indiceTemp]->visited = 1;
                }
                else if(tmp->next != NULL)
                {
                    tmp = tmp->next;
                    indiceTemp = busca_noh(tmp->dest, tmp_graph, ordem);
                }
                else
                {
                    printf("%c) ", tmp_graph->head[v]->info);
                    return 0;
                }
            }
        }
        else
        {
            printf("%c) ",tmp_graph->head[v]->info);
            return 0;
        }
        printf("\n");
    }
}

void DFS(Graph* grafo, int ordem)
{

    Graph* tmp_graph = grafo;
    // int n = ordemof(tmp_graph)/ordemof(tmp_graph[0]);
    int i;

    /* Marca todos os v�rtices como n�o visitados */
    for(i=0; i<ordem; i++)
    {
        tmp_graph->head[i]->visited = 0;
    }
    /* Chama a fun��o auxiliar recursiva  */
    DFSaux(0, tmp_graph, ordem);
}
