#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "graph.h"

#define tamanhoMax 8 //quantidade de arestas

int main(void)
{
    char ch, nVert, cabeca;
    int newVert, isVertex, isWeight, cont, ordem, indiceVert = 0;
    long peso;

    FILE *arq = fopen("file.txt","r");

    if(arq == NULL)
    {
        printf("Erro ao abrir arquivo");
    }
    else
    {
        fscanf(arq, "%c", &nVert);
        ordem = (int)(nVert - '0'); // quantidade de vertices do grafo - 1a linha do arquivo
    }

    Edge edges[tamanhoMax]; //cria a struct de arestas com seus pesos

    while( (ch=fgetc(arq))!= EOF )
    {
        if(ch == '\n')
        {
            newVert = 1;
        }
        else if(ch != '\n')
        {
            if(!isspace(ch))
            {
                if(ordem==1)
                {
                    ordem = (int)(ch - '0'); //atualiza o valor do numero de vertices do grafo, verificando a 1a linha do arq
                }
                else if(newVert == 0)
                {

                    if(isalpha(ch))  //verifica se o elemento é um número (peso) ou uma letra (vértice)
                    {
                        isVertex = 1;
                        isWeight = 0;
                    }
                    else
                    {
                        isVertex = 0;
                        isWeight = 1;
                    }

                    if(isVertex == 1)
                    {
                        edges[indiceVert].dest = ch;
                        edges[indiceVert].src = cabeca;
                        isVertex = 0;
                        isWeight = 1;
                    }
                    else if(isWeight == 1)
                    {

                        char pesoString[10] = {NULL};
                        cont=0;
                        pesoString[cont] = ch;
                        cont++;

                        while((ch = fgetc(arq)) != '\n' || !isspace(ch))
                        {

                            if(!isspace(ch))
                            {
                                pesoString[cont] = ch;
                                cont++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        if(ch == '\n'){
                            newVert = 1;
                        }
                        peso = strtol(pesoString,NULL,10);
                        edges[indiceVert].weight = peso;
                        indiceVert++;
                    }
                }
                else if(newVert == 1)  //se for uma nova linha, identifica o primeiro char como o v?rtice principal
                {
                    cabeca = ch;

                    newVert = 0; // define que talvez os proximos vertices serão seus "filhos"
                }
            }
        }
    }

    // calcula qtde de arestas
    int n = sizeof(edges)/sizeof(edges[0]);

    // constroi o grapho a partir das arestas
    Graph* grafo = createGraph(edges, n);

    //DFS(grafo, ordem);
    //printGraph(grafo,n);
    dijkstra(grafo, ordem, 0);

    printf("\n");

    return 0;
}
