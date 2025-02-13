// Definição da estrutura do nó
struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
};

// Função para criar um novo nó
struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função de inserção recursiva
struct No* inserir(struct No* raiz, int valor) {
    // Caso base: se a árvore estiver vazia, cria um novo nó
    if (raiz == NULL) {
        return criarNo(valor);
    }

    // Se o valor for menor que o valor do nó atual, insere na subárvore esquerda
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    // Se o valor for maior que o valor do nó atual, insere na subárvore direita
    else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    // Retorna o nó atual (sem alterações se o valor já existir)
    return raiz;
}
