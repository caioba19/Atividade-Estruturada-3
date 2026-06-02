#include <stdio.h>

#define MAX 100

int pilha[MAX];
int topo = -1;

void push(int valor) {
    pilha[++topo] = valor;
}

int pop() {
    return pilha[topo--];
}

int vazia() {
    return topo == -1;
}

int main() {
    int numero;

    printf("Digite um numero inteiro maior que zero: ");
    scanf("%d", &numero);

    if (numero <= 0) {
        printf("Numero invalido!\n");
        return 1;
    }

    while (numero > 0) {
        push(numero % 2);
        numero /= 2;
    }

    printf("Binario: ");
    while (!vazia()) {
        printf("%d", pop());
    }
    printf("\n");

    return 0;
}