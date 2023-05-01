#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int shortestPathLength(int** graph, int graphSize, int* graphColSize) {
    int n = graphSize;
    int allVisitedMask = (1<<n)-1;
    int head = 0;
    int tail = 0;

    struct FilaNode {
        int nodeAtual;
        int dist;
        int mask;
    };

    struct FilaNode fila[12 * (1<<12)];
    // Inicialmente, adicione todos os nós na fila para iniciar o caminho com todos os nós;
    bool visto[12][1<<12] = {false};

    for (int i = 0; i < n; i++) {
        fila[tail++] = (struct FilaNode){i, 0, 1<<i};
        visto[i][1<<i] = true;
    }

    while (head != tail) {
        struct FilaNode atual = fila[head++];
        int node = atual.nodeAtual, dist = atual.dist, mask = atual.mask;

        // Se todos os nós forem visitados
        if (mask == allVisitedMask) {
            return dist;
        }

        // Percorra todos os vizinhos
        for (int j = 0; j < graphColSize[node]; j++) {
            int vizinho = graph[node][j];
            int proximaMask = mask | (1<<vizinho);

            if (!visto[vizinho][proximaMask]) {
                fila[tail++] = (struct FilaNode){vizinho, dist+1, proximaMask};
                visto[vizinho][proximaMask] = true;
            }
        }
    }

    return 0;
}