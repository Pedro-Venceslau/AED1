#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int origem, destino;
    double peso;
} Aresta;

typedef struct {
    int nro_vertices, nro_arestas;
    Aresta *arestas;
} Grafo;

// Função para comparar arestas pelo peso (usada no qsort)
int comparaArestas(const void *a, const void *b) {
    Aresta *arestaA = (Aresta *)a;
    Aresta *arestaB = (Aresta *)b;
    return (arestaA->peso > arestaB->peso) - (arestaA->peso < arestaB->peso);
}

// Função para encontrar o representante do conjunto (Union-Find com path compression)
int find(int *pai, int v) {
    if (pai[v] == v)
        return v;
    return pai[v] = find(pai, pai[v]);
}

// Função para unir dois conjuntos (Union-Find com union by rank)
void unionSet(int *pai, int *rank, int v1, int v2) {
    v1 = find(pai, v1);
    v2 = find(pai, v2);
    if (v1 != v2) {
        if (rank[v1] > rank[v2])
            pai[v2] = v1;
        else if (rank[v1] < rank[v2])
            pai[v1] = v2;
        else {
            pai[v2] = v1;
            rank[v1]++;
        }
    }
}

// Implementação do algoritmo de Kruskal
void kruskal(Grafo *gr) {
    if (gr->nro_vertices == 0 || gr->nro_arestas == 0) {
        printf("Grafo vazio ou inválido.\n");
        return;
    }

    int i, numArestas = 0;
    int *pai = (int *)malloc(gr->nro_vertices * sizeof(int));
    int *rank = (int *)malloc(gr->nro_vertices * sizeof(int));

    if (pai == NULL || rank == NULL) {
        printf("Erro na alocação de memória.\n");
        free(pai);
        free(rank);
        return;
    }

    // Inicializa o Union-Find
    for (i = 0; i < gr->nro_vertices; i++) {
        pai[i] = i;
        rank[i] = 0;
    }

    // Ordena as arestas por peso
    qsort(gr->arestas, gr->nro_arestas, sizeof(Aresta), comparaArestas);

    printf("Arestas da Árvore Geradora Mínima:\n");
    for (i = 0; i < gr->nro_arestas && numArestas < gr->nro_vertices - 1; i++) {
        int origem = gr->arestas[i].origem;
        int destino = gr->arestas[i].destino;

        // Se origem e destino pertencem a componentes diferentes, adiciona a MST
        if (find(pai, origem) != find(pai, destino)) {
            printf("(%d - %d) peso: %.2f\n", origem, destino, gr->arestas[i].peso);
            unionSet(pai, rank, origem, destino);
            numArestas++;
        }
    }

    free(pai);
    free(rank);
}

int main() {
    // Exemplo de uso do Kruskal
    Grafo gr;
    gr.nro_vertices = 4;
    gr.nro_arestas = 5;
    gr.arestas = (Aresta *)malloc(gr.nro_arestas * sizeof(Aresta));

    if (gr.arestas == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    gr.arestas[0] = (Aresta){0, 1, 10};
    gr.arestas[1] = (Aresta){0, 2, 6};
    gr.arestas[2] = (Aresta){0, 3, 5};
    gr.arestas[3] = (Aresta){1, 3, 15};
    gr.arestas[4] = (Aresta){2, 3, 4};

    kruskal(&gr);

    free(gr.arestas);
    return 0;
}
