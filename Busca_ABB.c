struct No* buscar(struct No* raiz, int chave) {
    // Caso base: se a árvore estiver vazia ou o valor for encontrado
    if (raiz == NULL || raiz->valor == chave) {
        return raiz;
    }
  
    // Se o valor buscado for menor que o valor do nó atual, busca na subárvore esquerda
    if (chave < raiz->valor) {
        return buscar(raiz->esquerda, chave);
    }

    // Se o valor buscado for maior que o valor do nó atual, busca na subárvore direita
    return buscar(raiz->direita, chave);
}
