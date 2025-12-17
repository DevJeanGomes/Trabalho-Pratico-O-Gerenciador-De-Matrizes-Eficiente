#include <stdio.h>
#include <stdlib.h>

// --- Protótipos ---
int** criarMatriz(int linhas, int colunas);
void preencherMatriz(int** matriz, int linhas, int colunas);
void imprimirMatriz(int** matriz, int linhas, int colunas);
void liberarMatriz(int** matriz, int linhas);

// DESAFIO PRINCIPAL
void trocarLinhas(int** matriz, int linhaA, int linhaB);

int main() {
    int linhas = 3, colunas = 4;
    
    printf("1. Criando Matriz %dx%d...\n", linhas, colunas);
    int** m = criarMatriz(linhas, colunas);
    
    // Preenchendo para teste
    preencherMatriz(m, linhas, colunas);
    
    printf("\n--- Matriz Original ---\n");
    imprimirMatriz(m, linhas, colunas);
    
    printf("\n2. Trocando a linha 0 com a linha 2 (apenas ponteiros)...\n");
    trocarLinhas(m, 0, 2);
    
    printf("\n--- Matriz Apos Troca ---\n");
    imprimirMatriz(m, linhas, colunas);
    
    printf("\n3. Liberando memoria...\n");
    liberarMatriz(m, linhas);

    system("pause");
    
    return 0;
}

// -------------------------------------------------------
// IMPLEMENTE SUAS FUNÇÕES AQUI
// -------------------------------------------------------

/* Exemplo de assinatura:
int** criarMatriz(int linhas, int colunas) {
    // Seu código aqui
}
*/

int** criarMatriz(int linhas, int colunas) {
    int **m = (int **) malloc(linhas * sizeof(int*));

    if (m == NULL) {
        printf("Erro ao alocar linhas\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++) {
        m[i] = (int *) malloc(colunas * sizeof(int));

        if (m[i] == NULL) {
            printf("Erro ao alocar colunas da linha %d\n", i);
            exit(1);
        }
    }

    return m;
}

void preencherMatriz(int** matriz, int linhas, int colunas) {
    int valor = 1;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = valor++;
        }
    }
}

void imprimirMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

//DESAFIO PRINCIPAL
void trocarLinhas(int** matriz, int linhaA, int linhaB) {
    int *temp;

    temp = matriz[linhaA];
    matriz[linhaA] = matriz[linhaB];
    matriz[linhaB] = temp;
}

void liberarMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]); // libera cada linha
    }
    free(matriz); // libera o vetor de ponteiros
}
