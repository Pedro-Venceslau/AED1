#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

void simplificar(int *num, int *den) {
    int divisor = mdc(*num, *den);
    *num /= divisor;
    *den /= divisor;
}

int main() {
    int N;
    scanf("%d", &N);
    
    while (N--) {
        int N1, D1, N2, D2, num_res, den_res;
        char op;
        
        scanf("%d / %d %c %d / %d", &N1, &D1, &op, &N2, &D2);
        
        switch (op) {
            case '+':
                num_res = N1 * D2 + N2 * D1;
                den_res = D1 * D2;
                break;
            case '-':
                num_res = N1 * D2 - N2 * D1;
                den_res = D1 * D2;
                break;
            case '*':
                num_res = N1 * N2;
                den_res = D1 * D2;
                break;
            case '/':
                num_res = N1 * D2;
                den_res = N2 * D1;
                break;
        }
        
        printf("%d/%d = ", num_res, den_res);
        
        int num_simp = num_res, den_simp = den_res;
        simplificar(&num_simp, &den_simp);
        printf("%d/%d\n", num_simp, den_simp);
    }
    
    return 0;
}
