// Função de remoção recursiva
struct No* remover(struct No* raiz, int valor) {
    // Caso base: se a árvore estiver vazia, retorna NULL
    if (raiz == NULL) {
        return raiz;
    }

    // Se o valor for menor que o valor do nó atual, remove na subárvore esquerda
    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    }
    // Se o valor for maior que o valor do nó atual, remove na subárvore direita
    else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    }
    // Se o valor for igual ao valor do nó atual, este é o nó a ser removido
    else {
        // Caso 1: nó sem filhos ou com apenas um filho
        if (raiz->esquerda == NULL) {
            struct No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        // Caso 2: nó com dois filhos
        // Encontra o nó com o menor valor na subárvore direita (sucessor)
        struct No* temp = encontrarMenorValor(raiz->direita);

        // Copia o valor do sucessor para o nó atual
        raiz->valor = temp->valor;

        // Remove o sucessor da subárvore direita
        raiz->direita = remover(raiz->direita, temp->valor);
    }

    // Retorna o nó atual (possivelmente modificado)
    return raiz;
}
