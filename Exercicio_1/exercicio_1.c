#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination){
    if (source == destination) return true;
    
    bool mapaVisitado[n], mapaPilha[n];
    for (int i = 0; i < n; i++){
        mapaPilha[i] = false;      // Para registrar elementos que tivemos na pilha
        mapaVisitado[i] = false;   // Para registrar vértices que visitamos
    } 
    int pilha[n];
    unsigned int pt = -1;
    pilha[++pt] = source;      // empilhar a origem
    mapaPilha[source] = true;  // registrar na pilha

    while (pt != -1){
        while (mapaVisitado[pilha[pt]] == true) pt--; // desempilhar enquanto o vértice no topo da pilha foi visitado
        mapaVisitado[pilha[pt]] = true;
        int topo = pilha[pt--];      // desempilhar o elemento do topo da pilha e pegar o seu valor
        mapaPilha[topo] = false;     // como desempilhamos o elemento, ele não está mais na pilha

        /* Começamos a percorrer a matriz "edges", 
        encontrando vértices adjacentes ao vértice "topo"*/
        for(int i = 0; i < edgesSize; i++){
            for(int j = 0; j < *edgesColSize; j++){
                if (edges[i][j] == topo){    
                    int vertice = edges[i][*edgesColSize-1-j];
                    if (vertice == destination) return true;
                    if (mapaVisitado[vertice] == false && mapaPilha[vertice] == false){
                        /* se o vértice adjacente não foi visitado e não está na pilha, 
                        empilhe-o na pilha.*/
                        pilha[++pt] = vertice; 
                        mapaPilha[vertice] = true;
                    } 
                    edges[i][j] = n;                          // mude as arestas usadas para um número inválido
                    edges[i][*edgesColSize-1-j] = n;
                    break;
                }
            }
        } 
    }
    return mapaVisitado[destination];
}