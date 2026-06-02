#include <stdio.h>
#include <string.h>

#define MAX 100

char pilha[MAX];
int topo = -1;

void push(char c) {
    pilha[++topo] = c;
}

char pop() {
    return pilha[topo--];
}

int main() {
    char palavra[MAX];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int tamanho = strlen(palavra);
    int metade = tamanho / 2;
    int i;

    for (i = 0; i < metade; i++) {
        push(palavra[i]);
    }

    int inicio = (tamanho % 2 == 0) ? metade : metade + 1;
    int palindromo = 1;

    for (i = inicio; i < tamanho; i++) {
        if (pop() != palavra[i]) {
            palindromo = 0;
            break;
        }
    }

    if (palindromo) {
        printf("'%s' eh um palindromo!\n", palavra);
    } else {
        printf("'%s' nao eh um palindromo!\n", palavra);
    }

    return 0;
}