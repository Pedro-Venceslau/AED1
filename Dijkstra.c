#include <stdio.h>
#include <limits.h>

#define V 6 // Número de vértices no grafo

// Função para encontrar o vértice com a menor distância que ainda não foi processado
int encontrarMenorDistancia(int distancias[], int processado[]) {
    int menor = INT_MAX, indiceMenor;

    for (int v = 0; v < V; v++) {
        if (processado[v] == 0 && distancias[v] <= menor) {
            menor = distancias[v];
            indiceMenor = v;
        }
    }

    return indiceMenor;
}

// Função para imprimir as distâncias finais
void imprimirDistancias(int distancias[]) {
    printf("Vértice \t Distância do Início\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, distancias[i]);
    }
}

// Algoritmo de Dijkstra
void dijkstra(int grafo[V][V], int inicio) {
    int distancias[V];      // Array para armazenar as distâncias mais curtas
    int processado[V];      // Array para marcar os vértices já processados

    // Inicializa todas as distâncias como INFINITO e processado[] como 0 (não processado)
    for (int i = 0; i < V; i++) {
        distancias[i] = INT_MAX;
        processado[i] = 0;
    }

    // A distância do vértice inicial para ele mesmo é sempre 0
    distancias[inicio] = 0;

    // Encontrar o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        // Escolhe o vértice com a menor distância que ainda não foi processado
        int u = encontrarMenorDistancia(distancias, processado);

        // Marca o vértice como processado
        processado[u] = 1;

        // Atualiza as distâncias dos vértices adjacentes ao vértice escolhido
        for (int v = 0; v < V; v++) {
            // Atualiza distancias[v] apenas se:
            // 1. O vértice v não foi processado.
            // 2. Existe uma aresta de u para v.
            // 3. A distância total do início até v passando por u é menor que o valor atual de distancias[v].
            if (!processado[v] && grafo[u][v] && distancias[u] != INT_MAX &&
                distancias[u] + grafo[u][v] < distancias[v]) {
                distancias[v] = distancias[u] + grafo[u][v];
            }
        }
    }

    // Imprime as distâncias finais
    imprimirDistancias(distancias);
}

int main() {
    // Exemplo de grafo representado por uma matriz de adjacência
    int grafo[V][V] = {
        {0, 2, 4, 0, 0, 0},
        {2, 0, 1, 7, 0, 0},
        {4, 1, 0, 0, 3, 0},
        {0, 7, 0, 0, 2, 1},
        {0, 0, 3, 2, 0, 5},
        {0, 0, 0, 1, 5, 0}
    };

    int inicio = 0; // Vértice inicial

    dijkstra(grafo, inicio);

    return 0;
}
