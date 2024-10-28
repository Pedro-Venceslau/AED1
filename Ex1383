#include <stdio.h>
#include <stdlib.h>

int VerificandoLinha(int sudoku[9][9]) {
    int num;
    for(int i=0; i<9; i++) {
        int ocorrencia[10] = {0};
        for(int j=0; j<9; j++) {
            num = sudoku[i][j];
            if(num < 1 || num > 9 || ocorrencia[num] == 1) {
                return 0;
            }
            ocorrencia[num] = 1;
        }
    }
    return 1;
}

int VerificandoColuna(int sudoku[9][9]) {
    int num;
    for(int i=0; i<9; i++) {
        int ocorrencia[10] = {0};
        for(int j=0; j<9; j++) {
            num = sudoku[j][i];
            if(num < 1 || num > 9 || ocorrencia[num] == 1) {
                return 0;
            }
            ocorrencia[num] = 1;
        }
    }
    return 1;
}

int VerificandoBloco(int sudoku[9][9]) {
    int num;
    for(int linha=0; linha<9; linha += 3) {
        for(int coluna=0; coluna<9; coluna += 3) {
            int ocorrencias[10] = {0};
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    num = sudoku[linha + i][coluna + j];
                    if(num < 1 || num > 9 || ocorrencias[num] == 1) {
                        return 0;
                    }
                    ocorrencias[num] = 1;
                }
            }
        }
    }
    return 1;
}

int VerificandoSudoku(int sudoku[9][9]) {
    return VerificandoLinha(sudoku) && VerificandoColuna(sudoku) && VerificandoBloco(sudoku);
}

int main() {
    int sudoku[9][9], n;
    
    printf("Digite o número de matrizes: ");
    scanf("%d", &n);
    
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        printf("Instancia %d\n", k);
        if (VerificandoSudoku(sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
