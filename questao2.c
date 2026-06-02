#include <stdio.h>
#include <string.h>

#define MAX 200

char pilha[MAX];
int topo = -1;

void push(char c) {
    pilha[++topo] = c;
}

char pop() {
    return pilha[topo--];
}

int vazia() {
    return topo == -1;
}

int main() {
    char expressao[MAX];

    printf("Digite a expressao: ");
    scanf("%s", expressao);

    int i, tamanho = strlen(expressao);

    for (i = 0; i < tamanho; i++) {
        if (expressao[i] == '(') {
            push('(');
        } else if (expressao[i] == ')') {
            if (vazia()) {
                printf("Parenteses NAO balanceados!\n");
                return 0;
            }
            pop();
        }
    }

    if (vazia()) {
        printf("Parenteses balanceados!\n");
    } else {
        printf("Parenteses NAO balanceados!\n");
    }

    return 0;
}