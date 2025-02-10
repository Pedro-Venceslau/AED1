#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int origem, destino;
    double peso;
} Aresta;

typedef struct {
    int nro_vertices, nro_arestas;
    int **matriz_adj; // Matriz de adjacência para representar o grafo
} Grafo;

// Função para encontrar a Árvore Geradora Mínima (MST) usando o algoritmo de Prim
void algPRIM(Grafo *gr, int orig, int *pai) {
    int i, j, NV = gr->nro_vertices;
    double *dist = (double *)malloc(NV * sizeof(double)); // Distância de cada vértice à MST
    int *visitado = (int *)malloc(NV * sizeof(int));      // Vetor para marcar vértices visitados

    // Inicialização
    for (i = 0; i < NV; i++) {
        dist[i] = INT_MAX; // Distância infinita inicialmente
        visitado[i] = 0;   // Nenhum vértice foi visitado
        pai[i] = -1;       // Sem pai inicialmente
    }

    // A distância do vértice de origem é 0
    dist[orig] = 0;
    pai[orig] = orig;

    // Algoritmo de Prim
    for (i = 0; i < NV - 1; i++) {
        // Encontra o vértice com a menor distância que ainda não foi visitado
        int u = -1;
        double menorPeso = INT_MAX;
        for (j = 0; j < NV; j++) {
            if (!visitado[j] && dist[j] < menorPeso) {
                menorPeso = dist[j];
                u = j;
            }
        }

        // Se não encontrou um vértice válido, o grafo é desconexo
        if (u == -1) {
            printf("Grafo desconexo! Não é possível gerar uma MST.\n");
            free(dist);
            free(visitado);
            return;
        }

        // Marca o vértice como visitado
        visitado[u] = 1;

        // Atualiza as distâncias dos vértices adjacentes ao vértice selecionado
        for (j = 0; j < NV; j++) {
            if (gr->matriz_adj[u][j] && !visitado[j] && gr->matriz_adj[u][j] < dist[j]) {
                dist[j] = gr->matriz_adj[u][j];
                pai[j] = u;
            }
        }
    }

    // Libera memória alocada
    free(dist);
    free(visitado);
}

int main() {
    // Exemplo de uso
    Grafo gr;
    int i, j;

    gr.nro_vertices = 5;
    gr.nro_arestas = 7;

    // Aloca memória para a matriz de adjacência
    gr.matriz_adj = (int **)malloc(gr.nro_vertices * sizeof(int *));
    for (i = 0; i < gr.nro_vertices; i++) {
        gr.matriz_adj[i] = (int *)malloc(gr.nro_vertices * sizeof(int));
        for (j = 0; j < gr.nro_vertices; j++) {
            gr.matriz_adj[i][j] = 0; // Inicializa a matriz com 0 (sem arestas)
        }
    }

    // Adiciona arestas ao grafo (grafo não direcionado)
    gr.matriz_adj[0][1] = gr.matriz_adj[1][0] = 2;
    gr.matriz_adj[0][3] = gr.matriz_adj[3][0] = 6;
    gr.matriz_adj[1][2] = gr.matriz_adj[2][1] = 3;
    gr.matriz_adj[1][3] = gr.matriz_adj[3][1] = 8;
    gr.matriz_adj[1][4] = gr.matriz_adj[4][1] = 5;
    gr.matriz_adj[2][4] = gr.matriz_adj[4][2] = 7;
    gr.matriz_adj[3][4] = gr.matriz_adj[4][3] = 9;

    int *pai = (int *)malloc(gr.nro_vertices * sizeof(int));
    algPRIM(&gr, 0, pai);

    // Exibe a MST
    printf("Arestas da Árvore Geradora Mínima:\n");
    for (i = 1; i < gr.nro_vertices; i++) {
        printf("(%d - %d)\n", pai[i], i);
    }

    // Libera memória
    for (i = 0; i < gr.nro_vertices; i++) {
        free(gr.matriz_adj[i]);
    }
    free(gr.matriz_adj);
    free(pai);

    return 0;
}
