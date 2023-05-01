#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {

    int  *cor  = (int *)calloc(1, sizeof(int) * graphSize);    
    int  *fila  = (int *)calloc(1, sizeof(int) * graphSize);

    int head =0;
    int tail =0;

    /* Itera através de cada nó usando BFS. */
    for ( int i=0; i< graphSize; i++ ) {

        /* Nó com uma cor já foi visitado. */
        if ( cor[i] != 0 )
            continue;
    
        /* Nós sem cor são o primeiro nó de um grupo, então podemos
         * atribuir um valor arbitrário.
         */
        cor[i] = 1;

        fila[tail++] = i;
        
        while ( head != tail ) {
            
            /* Desenfileira o nó mais antigo. */
            int pai = fila[head++];
            
            for ( int j=0; j<graphColSize[pai]; j++ ) {
                int filho = graph[pai][j];
                
                /* Se o nó conectado ainda não foi visitado, atribua a
                 * cor oposta.
                 */
                if ( cor[filho] ==0 ) {
                    cor[filho]  = -cor[pai];
                    
                    /* Adiciona o nó conectado à fila. */
                    fila[tail++] = filho;
                } else if (cor[filho] == cor[pai]){
                    return false;
                }
            }
        }
    }
    
    return true;
}
