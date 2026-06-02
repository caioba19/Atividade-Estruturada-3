# 📚 Atividade Estruturada 3 — Pilhas Sequenciais em C

> **Disciplina:** Estrutura de Dados

> **Aluno:** Caio Vinicius

> **Curso:** Análise e Desenvolvimento de Sistemas

> **Tema:** Implementação de pilhas sequenciais e suas aplicações práticas

---

## 📁 Estrutura do Projeto

```
📂 pilhas-sequenciais/
├── ex1_decimal_binario.c     # Conversão decimal → binário
├── ex2_parenteses.c          # Verificação de parênteses
├── ex3_palindromo.c          # Reconhecimento de palíndromo
└── ex4_notacao_polonesa.c    # Calculadora em Notação Polonesa Reversa
```

---

## 🧱 Estrutura Base da Pilha

Todos os exercícios utilizam uma pilha sequencial implementada com vetor estático. As operações fundamentais são:

| Operação | Descrição |
|----------|-----------|
| `push(valor)` | Insere um elemento no topo da pilha |
| `pop()` | Remove e retorna o elemento do topo |
| `vazia()` | Retorna 1 se a pilha estiver vazia, 0 caso contrário |

---

## ⚙️ Como Compilar e Executar

Utilize o compilador GCC em qualquer sistema com suporte a C:

```bash
gcc ex1_decimal_binario.c  -o ex1  && ./ex1
gcc ex2_parenteses.c       -o ex2  && ./ex2
gcc ex3_palindromo.c       -o ex3  && ./ex3
gcc ex4_notacao_polonesa.c -o ex4  && ./ex4
```

---

## 📝 Exercícios

---

### Exercício 1 — Conversão Decimal para Binário

**Arquivo:** `ex1_decimal_binario.c`

**Lógica:** O algoritmo divide o número por 2 repetidamente e empilha cada resto. Ao desempilhar, os bits são exibidos na ordem correta (do bit mais significativo ao menos significativo).

```
Número: 13
13 ÷ 2 = 6  → resto 1  → push(1)
 6 ÷ 2 = 3  → resto 0  → push(0)
 3 ÷ 2 = 1  → resto 1  → push(1)
 1 ÷ 2 = 0  → resto 1  → push(1)

Desempilhando: 1 1 0 1  →  Resultado: 1101
```

**Exemplos de uso:**

```
Digite um numero inteiro maior que zero: 13
Binario: 1101

Digite um numero inteiro maior que zero: 255
Binario: 11111111
```

---

### Exercício 2 — Verificação de Parênteses Balanceados

**Arquivo:** `ex2_parenteses.c`

**Lógica:** Percorre a expressão caractere a caractere. Todo `(` é empilhado. Ao encontrar `)`, desempilha um `(`. Se a pilha estiver vazia ao tentar desempilhar, ou não estiver vazia ao final, os parênteses não estão balanceados.

```
Expressão: (()())

( → push     pilha: [ ( ]
( → push     pilha: [ ( ( ]
) → pop      pilha: [ ( ]
( → push     pilha: [ ( ( ]
) → pop      pilha: [ ( ]
) → pop      pilha: [ ]

Pilha vazia no final → BALANCEADO ✅
```

**Exemplos de uso:**

```
Digite a expressao: (()())
Parenteses balanceados!

Digite a expressao: (()
Parenteses NAO balanceados!
```

---

### Exercício 3 — Reconhecimento de Palíndromo

**Arquivo:** `ex3_palindromo.c`

**Lógica:** A primeira metade da palavra é empilhada. O caractere central (quando o tamanho é ímpar) é ignorado. Em seguida, cada letra da segunda metade é comparada com o que é desempilhado.

```
Palavra: "raiar"  (tamanho=5, metade=2)

Push: r, a           pilha: [ r, a ]
Ignora: i (central)
Comparação:
  palavra[3]='a' == pop()='a'  ✅
  palavra[4]='r' == pop()='r'  ✅

→ É um palíndromo! ✅
```

**Exemplos de uso:**

```
Digite uma palavra: ovo
'ovo' eh um palindromo!

Digite uma palavra: raiar
'raiar' eh um palindromo!

Digite uma palavra: mussum
'mussum' eh um palindromo!

Digite uma palavra: caio
'caio' nao eh um palindromo!
```

---

### Exercício 4 — Calculadora em Notação Polonesa Reversa (NPR)

**Arquivo:** `ex4_notacao_polonesa.c`

**Sobre a NPR:** Na notação pós-fixa, o operador vem após os dois operandos. Isso elimina a necessidade de parênteses e define a precedência de forma implícita.

| Notação Infixa | Notação Polonesa Reversa |
|----------------|--------------------------|
| `(2 + 3) * 5`  | `23+5*`                  |
| `2 + 3 * 5`    | `235*+`                  |

**Lógica:** Percorre a expressão caractere a caractere. Dígito → empilha. Operador → desempilha `b` e `a`, calcula `a operador b` e empilha o resultado.

```
Expressão: 23+5*

'2' → push(2)          pilha: [ 2 ]
'3' → push(3)          pilha: [ 2, 3 ]
'+' → b=pop()=3
      a=pop()=2
      push(2+3=5)       pilha: [ 5 ]
'5' → push(5)          pilha: [ 5, 5 ]
'*' → b=pop()=5
      a=pop()=5
      push(5*5=25)      pilha: [ 25 ]

Resultado: 25.00 ✅
```

**Exemplos de uso:**

```
Digite a expressao em notacao polonesa reversa: 23+5*
Resultado: 25.00

Digite a expressao em notacao polonesa reversa: 235*+
Resultado: 17.00
```

---

## ✅ Resultados dos Testes

| Exercício | Entrada | Saída Esperada | Status |
|-----------|---------|----------------|--------|
| Ex1 | `13` | `1101` | ✅ |
| Ex1 | `255` | `11111111` | ✅ |
| Ex2 | `(()())` | Balanceados | ✅ |
| Ex2 | `(()` | Não balanceados | ✅ |
| Ex3 | `ovo` | É palíndromo | ✅ |
| Ex3 | `mussum` | É palíndromo | ✅ |
| Ex3 | `caio` | Não é palíndromo | ✅ |
| Ex4 | `23+5*` | `25.00` | ✅ |
| Ex4 | `235*+` | `17.00` | ✅ |
