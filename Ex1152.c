#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int origem, destino, peso;
} Aresta;

typedef struct {
    int pai;
    int rank;
} Subconjunto;

int compararArestas(const void *a, const void *b) {
    Aresta *arestaA = (Aresta *)a;
    Aresta *arestaB = (Aresta *)b;
    return arestaA->peso - arestaB->peso;
}

int encontrar(Subconjunto subconjuntos[], int i) {
    if (subconjuntos[i].pai != i)
        subconjuntos[i].pai = encontrar(subconjuntos, subconjuntos[i].pai);
    return subconjuntos[i].pai;
}

void unir(Subconjunto subconjuntos[], int x, int y) {
    int raizX = encontrar(subconjuntos, x);
    int raizY = encontrar(subconjuntos, y);

    if (subconjuntos[raizX].rank < subconjuntos[raizY].rank)
        subconjuntos[raizX].pai = raizY;
    else if (subconjuntos[raizX].rank > subconjuntos[raizY].rank)
        subconjuntos[raizY].pai = raizX;
    else {
        subconjuntos[raizY].pai = raizX;
        subconjuntos[raizX].rank++;
    }
}

int kruskal(Aresta arestas[], int V, int E) {
    // Ordenar as arestas pelo peso
    qsort(arestas, E, sizeof(Aresta), compararArestas);

    Subconjunto *subconjuntos = (Subconjunto *)malloc(V * sizeof(Subconjunto));
    for (int v = 0; v < V; v++) {
        subconjuntos[v].pai = v;
        subconjuntos[v].rank = 0;
    }

    int custoTotal = 0;
    int arestasIncluidas = 0;

    for (int i = 0; i < E && arestasIncluidas < V - 1; i++) {
        Aresta proximaAresta = arestas[i];

        int x = encontrar(subconjuntos, proximaAresta.origem);
        int y = encontrar(subconjuntos, proximaAresta.destino);

        if (x != y) {
            custoTotal += proximaAresta.peso;
            unir(subconjuntos, x, y);
            arestasIncluidas++;
        }
    }

    free(subconjuntos);
    return custoTotal;
}

int main() {
    int V, E;

    while (1) {
        scanf("%d %d", &V, &E);
        if (V == 0 && E == 0)
            break;

        Aresta *arestas = (Aresta *)malloc(E * sizeof(Aresta));
        int custoOriginal = 0;

        for (int i = 0; i < E; i++) {
            scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].peso);
            custoOriginal += arestas[i].peso;
        }

        int custoMST = kruskal(arestas, V, E);

        printf("%d\n", custoOriginal - custoMST);

        free(arestas);
    }

    return 0;
}
