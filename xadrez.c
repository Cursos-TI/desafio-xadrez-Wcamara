/*
 * DESAFIO: NÍVEL MESTRE - MOVIMENTOS COMPLEXOS
 *
 * Objetivo: Implementar movimentos de xadrez usando
 * recursividade (Torre, Bispo, Rainha) e loops
 * complexos/aninhados (Cavalo, Bispo).
 */

#include <stdio.h>

/*
 * ======================================
 * PROTÓTIPOS DAS FUNÇÕES
 * ======================================
 * Declarações das funções que serão usadas no programa.
 */

// --- Funções Recursivas ---
void moverTorreRecursivo(int casasFaltando);
void moverBispoRecursivo(int casasFaltando);
void moverRainhaRecursivo(int casasFaltando);

// --- Funções de Loops ---
void moverBispoLoopsAninhados(int tamanho);
void moverCavaloLoopsComplexos();


/*
 * ======================================
 * FUNÇÃO PRINCIPAL (MAIN)
 * ======================================
 * Ponto de entrada do programa. Chama as simulações
 * de movimento em sequência.
 */
int main() {
    printf("=========================================\n");
    printf("     SIMULADOR DE MOVIMENTO - NÍVEL MESTRE   \n");
    printf("=========================================\n\n");

    // --- 1. TORRE (Recursão) ---
    printf("### 1. TORRE (Recursividade) ###\n");
    printf("Movendo 5 casas para a Direita:\n");
    moverTorreRecursivo(5);

    printf("\n"); // Linha em branco para separar

    // --- 2. BISPO (Implementação Dupla) ---
    // 2a. Simulação recursiva
    printf("### 2a. BISPO (Recursividade) ###\n");
    printf("Movendo 5 casas (Cima, Direita):\n");
    moverBispoRecursivo(5);

    printf("\n");

    // 2b. Simulação com loops aninhados
    printf("### 2b. BISPO (Loops Aninhados) ###\n");
    printf("Simulando diagonal 5x5 (Externo=Vertical, Interno=Horizontal):\n");
    moverBispoLoopsAninhados(5);

    printf("\n");

    // --- 3. RAINHA (Recursão) ---
    printf("### 3. RAINHA (Recursividade) ###\n");
    printf("Movendo 8 casas para a Esquerda:\n");
    moverRainhaRecursivo(8);

    printf("\n");

    // --- 4. CAVALO (Loops Complexos Aninhados) ---
    printf("### 4. CAVALO (Loops Complexos Aninhados) ###\n");
    printf("Movendo em 'L' (2 Cima, 1 Direita):\n");
    moverCavaloLoopsComplexos();


    printf("\n=========================================\n");
    printf("            Fim da Simulação\n");
    printf("=========================================\n");

    return 0; // Indica que o programa terminou com sucesso
}


/*
 * ======================================
 * IMPLEMENTAÇÃO DAS FUNÇÕES RECURSIVAS
 * ======================================
 */

/**
 * @brief Move a Torre N casas para a Direita usando recursão.
 * @param casasFaltando O número de casas restantes para mover.
 */
void moverTorreRecursivo(int casasFaltando) {
    // Caso Base (Condição de Parada)
    if (casasFaltando <= 0) {
        return; 
    }

    // Ação
    printf("  Casa %d: Direita\n", casasFaltando);

    // Chamada Recursiva (passos - 1)
    moverTorreRecursivo(casasFaltando - 1);
}

/**
 * @brief Move o Bispo N casas (Cima, Direita) usando recursão.
 * @param casasFaltando O número de casas restantes para mover.
 */
void moverBispoRecursivo(int casasFaltando) {
    // Caso Base
    if (casasFaltando <= 0) {
        return;
    }
    // Ação
    printf("  Casa %d: Cima, Direita\n", casasFaltando);
    // Chamada Recursiva
    moverBispoRecursivo(casasFaltando - 1);
}

/**
 * @brief Move a Rainha N casas para a Esquerda usando recursão.
 * @param casasFaltando O número de casas restantes para mover.
 */
void moverRainhaRecursivo(int casasFaltando) {
    // Caso Base
    if (casasFaltando <= 0) {
        return;
    }
    // Ação
    printf("  Casa %d: Esquerda\n", casasFaltando);
    // Chamada Recursiva
    moverRainhaRecursivo(casasFaltando - 1);
}


/*
 * ======================================
 * IMPLEMENTAÇÃO DOS LOOPS COMPLEXOS
 * ======================================
 */

/**
 * @brief Simula o movimento do Bispo usando loops aninhados.
 * Loop externo (y) controla o vertical.
 * Loop interno (x) controla o horizontal.
 * @param tamanho O tamanho da "grade" para simular (ex: 5x5).
 */
void moverBispoLoopsAninhados(int tamanho) {
    // Loop Externo (Vertical, 'y')
    for (int y = 1; y <= tamanho; y++) {
        
        // Loop Interno (Horizontal, 'x')
        for (int x = 1; x <= tamanho; x++) {
            
            // Imprime apenas a diagonal principal (onde y == x)
            if (y == x) {
                printf("  (Pos y=%d, x=%d): Cima, Direita\n", y, x);
            }
        }
    }
}

/**
 * @brief Simula o movimento do Cavalo (2 Cima, 1 Direita)
 * usando loops aninhados, 'continue' e 'break'.
 */
void moverCavaloLoopsComplexos() {
    int passosVerticais = 2;
    int passosHorizontais = 1;

    // Loop externo para os passos verticais (Cima)
    for (int y = 1; y <= passosVerticais; y++) {
        
        printf("  Movimento Vertical %d: Cima\n", y);

        // Se não for o último passo vertical, pula o loop horizontal
        if (y < passosVerticais) {
            // 'continue' avança para a próxima iteração do loop 'y'
            continue; 
        }
        
        // Loop interno (só executa quando y == passosVerticais)
        for (int x = 1; x <= passosHorizontais; x++) {
            printf("  Movimento Horizontal %d: Direita\n", x);
            
            // 'break' sai do loop interno 'x'
            break; 
        }
    }
}
