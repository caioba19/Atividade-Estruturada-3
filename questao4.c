#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

float pilha[MAX];
int topo = -1;

void push(float valor) {
    pilha[++topo] = valor;
}

float pop() {
    return pilha[topo--];
}

int main() {
    char expressao[MAX];

    printf("Digite a expressao em notacao polonesa reversa: ");
    scanf("%s", expressao);

    int i, tamanho = strlen(expressao);

    for (i = 0; i < tamanho; i++) {
        if (isdigit(expressao[i])) {
            push(expressao[i] - '0');
        } else {
            float b = pop();
            float a = pop();

            if (expressao[i] == '+') push(a + b);
            else if (expressao[i] == '-') push(a - b);
            else if (expressao[i] == '*') push(a * b);
            else if (expressao[i] == '/') push(a / b);
        }
    }

    printf("Resultado: %.2f\n", pop());

    return 0;
}