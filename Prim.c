// Função principal do algoritmo de Prim
void primMST(int grafo[V][V]) {
    int pai[V];      // Array para armazenar a MST
    int chaves[V];   // Chaves usadas para escolher a aresta de peso mínimo
    bool mstIncluido[V]; // Array para rastrear vértices já incluídos na MST
    // Inicializa todas as chaves como "infinito" e mstIncluido como falso
    for (int i = 0; i < V; i++) {
        chaves[i] = INT_MAX;
        mstIncluido[i] = false;
    }
    // O primeiro vértice é sempre incluído na MST
    chaves[0] = 0;   // Chave do primeiro vértice é 0
    pai[0] = -1;     // O primeiro vértice é a raiz da MST

    // Construindo a MST
    for (int count = 0; count < V - 1; count++) {
        // Escolhe o vértice com a chave mínima que ainda não está na MST
        int u = encontrarVerticeMinimo(chaves, mstIncluido);
        // Adiciona o vértice escolhido à MST
        mstIncluido[u] = true;
        // Atualiza as chaves e os pais dos vértices adjacentes ao vértice escolhido
        for (int v = 0; v < V; v++) {
            // Atualiza apenas se o vértice não estiver na MST, houver uma aresta entre u e v,
            // e o peso da aresta for menor que a chave atual de v
            if (grafo[u][v] && mstIncluido[v] == false && grafo[u][v] < chaves[v]) {
                pai[v] = u;
                chaves[v] = grafo[u][v];
            }
        }
    }
    // Imprime a MST
    imprimirMST(pai, grafo);
}
