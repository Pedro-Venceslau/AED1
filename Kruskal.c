#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para representar uma aresta
struct Aresta {
    int origem, destino, peso;
};

// Definição da estrutura para representar um grafo
struct Grafo {
    int V; // Número de vértices
    int E; // Número de arestas
    struct Aresta* arestas; // Lista de arestas
};

// Função para criar um grafo com V vértices e E arestas
struct Grafo* criarGrafo(int V, int E) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->V = V;
    grafo->E = E;
    grafo->arestas = (struct Aresta*)malloc(E * sizeof(struct Aresta));
    return grafo;
}

// Função para encontrar o conjunto de um elemento (usando path compression)
int encontrarConjunto(int pai[], int i) {
    if (pai[i] == i)
        return i;
    return encontrarConjunto(pai, pai[i]);
}

// Função para unir dois conjuntos (união por rank)
void unirConjuntos(int pai[], int rank[], int x, int y) {
    int raizX = encontrarConjunto(pai, x);
    int raizY = encontrarConjunto(pai, y);

    if (rank[raizX] < rank[raizY])
        pai[raizX] = raizY;
    else if (rank[raizX] > rank[raizY])
        pai[raizY] = raizX;
    else {
        pai[raizY] = raizX;
        rank[raizX]++;
    }
}

// Função para comparar duas arestas com base no peso (usada para ordenação)
int compararArestas(const void* a, const void* b) {
    struct Aresta* aresta1 = (struct Aresta*)a;
    struct Aresta* aresta2 = (struct Aresta*)b;
    return aresta1->peso - aresta2->peso;
}

// Algoritmo de Kruskal para encontrar a MST
void kruskal(struct Grafo* grafo) {
    int V = grafo->V;
    struct Aresta resultado[V]; // Armazena a MST
    int e = 0; // Índice para resultado[]
    int i = 0; // Índice para arestas ordenadas

    // Passo 1: Ordenar todas as arestas em ordem crescente de peso
    qsort(grafo->arestas, grafo->E, sizeof(grafo->arestas[0]), compararArestas);

    // Alocar memória para criar V conjuntos disjuntos
    int* pai = (int*)malloc(V * sizeof(int));
    int* rank = (int*)malloc(V * sizeof(int));

    // Inicializar conjuntos disjuntos
    for (int v = 0; v < V; v++) {
        pai[v] = v;
        rank[v] = 0;
    }

    // Passo 2: Iterar sobre as arestas ordenadas
    while (e < V - 1 && i < grafo->E) {
        // Escolher a próxima aresta
        struct Aresta proximaAresta = grafo->arestas[i++];

        int x = encontrarConjunto(pai, proximaAresta.origem);
        int y = encontrarConjunto(pai, proximaAresta.destino);

        // Se a aresta não forma um ciclo, adicioná-la ao resultado
        if (x != y) {
            resultado[e++] = proximaAresta;
            unirConjuntos(pai, rank, x, y);
        }
    }

    // Passo 3: Imprimir a MST
    printf("Arestas na Árvore Geradora Mínima:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d\tPeso: %d\n", resultado[i].origem, resultado[i].destino, resultado[i].peso);
    }

    // Liberar memória
    free(pai);
    free(rank);
}

// Função principal
int main() {
    int V = 4; // Número de vértices
    int E = 5; // Número de arestas
    struct Grafo* grafo = criarGrafo(V, E);

    // Exemplo de grafo
    grafo->arestas[0].origem = 0;
    grafo->arestas[0].destino = 1;
    grafo->arestas[0].peso = 10;

    grafo->arestas[1].origem = 0;
    grafo->arestas[1].destino = 2;
    grafo->arestas[1].peso = 6;

    grafo->arestas[2].origem = 0;
    grafo->arestas[2].destino = 3;
    grafo->arestas[2].peso = 5;

    grafo->arestas[3].origem = 1;
    grafo->arestas[3].destino = 3;
    grafo->arestas[3].peso = 15;

    grafo->arestas[4].origem = 2;
    grafo->arestas[4].destino = 3;
    grafo->arestas[4].peso = 4;

    // Executar o algoritmo de Kruskal
    kruskal(grafo);

    // Liberar memória
    free(grafo->arestas);
    free(grafo);

    return 0;
}
