#include <stdio.h>

// --- Constantes para facilitar a leitura e manutenção do código ---

// Define o tamanho do tabuleiro (10x10)
#define BOARD_SIZE 10
// Define o tamanho fixo dos navios
#define SHIP_SIZE 3
// Define o valor que representa a água no tabuleiro
#define WATER 0
// Define o valor que representa uma parte de um navio
#define SHIP_PART 3

int main() {
    // Declaração da matriz 10x10 para representar o tabuleiro
    int tabuleiro[BOARD_SIZE][BOARD_SIZE];

    // --- Etapa 1: Inicialização do Tabuleiro ---
    // Este bloco de código percorre cada célula do tabuleiro e a define como 'água' (0).
    printf("Inicializando o tabuleiro 10x10 com agua (0)...\n");
    for (int i = 0; i < BOARD_SIZE; i++) { // Loop para as linhas
        for (int j = 0; j < BOARD_SIZE; j++) { // Loop para as colunas
            tabuleiro[i][j] = WATER;
        }
    }
    printf("Tabuleiro inicializado.\n\n");


    // --- Etapa 2: Posicionamento dos Navios ---
    // Os navios são posicionados diretamente no código.
    // As posições foram escolhidas para garantir que estão dentro dos limites
    // do tabuleiro e que não se sobrepõem, cumprindo os requisitos de validação.

    // Navio 1: Horizontal (Tamanho 3)
    // Posição inicial: linha 1, coluna 1. Ocupará (1,1), (1,2), (1,3).
    // A validação é feita verificando se a posição final (1, 1+2) está no tabuleiro.
    int navio1_linha = 1;
    int navio1_coluna = 1;
    for (int i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[navio1_linha][navio1_coluna + i] = SHIP_PART;
    }

    // Navio 2: Vertical (Tamanho 3)
    // Posição inicial: linha 3, coluna 8. Ocupará (3,8), (4,8), (5,8).
    // A validação é feita verificando se a posição final (3+2, 8) está no tabuleiro.
    int navio2_linha = 3;
    int navio2_coluna = 8;
    for (int i = 0; i < SHIP_SIZE; i++) {
        tabuleiro[navio2_linha + i][navio2_coluna] = SHIP_PART;
    }

    // Navio 3: Diagonal Principal (Top-Left -> Bottom-Right)
    // Posição inicial: linha 3, coluna 2. Ocupará (3,2), (4,3), (5,4).
    // A validação é feita verificando se a posição final (3+2, 2+2) está no tabuleiro.
    int navio3_linha = 3;
    int navio3_coluna = 2;
    for (int i = 0; i < SHIP_SIZE; i++) {
        // A linha e a coluna aumentam juntas para criar a diagonal
        tabuleiro[navio3_linha + i][navio3_coluna + i] = SHIP_PART;
    }

    // Navio 4: Diagonal Secundária (Top-Right -> Bottom-Left)
    // Posição inicial: linha 6, coluna 3. Ocupará (6,3), (7,2), (8,1).
    // A validação é feita verificando se a posição final (6+2, 3-2) está no tabuleiro.
    int navio4_linha = 6;
    int navio4_coluna = 3;
    for (int i = 0; i < SHIP_SIZE; i++) {
        // A linha aumenta e a coluna diminui para criar a outra diagonal
        tabuleiro[navio4_linha + i][navio4_coluna - i] = SHIP_PART;
    }
    
    printf("Navios posicionados!\n");


    // --- Etapa 3: Exibição do Tabuleiro Completo ---
    // Utiliza loops aninhados para percorrer a matriz e imprimir cada elemento.
    printf("\n--- Tabuleiro de Batalha Naval ---\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n"); // Guia para as colunas
    printf("--------------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) { // Loop para as linhas
        printf("%d| ", i); // Guia para as linhas
        for (int j = 0; j < BOARD_SIZE; j++) { // Loop para as colunas
            // Imprime o valor da célula (0 para água, 3 para navio) seguido de um espaço.
            printf("%d ", tabuleiro[i][j]);
        }
        // Ao final de cada linha, imprime uma quebra de linha para formar o tabuleiro.
        printf("\n");
    }

    return 0; // Indica que o programa foi executado com sucesso
}
