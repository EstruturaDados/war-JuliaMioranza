#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// estrutura básica de território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// função que sorteia e atribui uma missão ao jogador
void atribuirMissao(char *destino, char *missoes[], int totalMissoes) {
    int indice = rand() % totalMissoes;
    strcpy(destino, missoes[indice]);
}

// função que exibe a missão do jogador
void exibirMissao(char *missao) {
    printf("\n>>> Sua missão: %s\n", missao);
}

// função simples pra simular um ataque entre territórios
void atacar(Territorio *atacante, Territorio *defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("\nVocê não pode atacar um território da mesma cor!\n");
        return;
    }

    int dadoA = rand() % 6 + 1;
    int dadoD = rand() % 6 + 1;

    printf("\nAtaque de %s (%d tropas) contra %s (%d tropas)\n", atacante->nome, atacante->tropas, defensor->nome, defensor->tropas);
    printf("Rolagem: atacante %d x defensor %d\n", dadoA, dadoD);

    if (dadoA > dadoD) {
        printf("O atacante venceu a batalha!\n");
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas /= 2;
    } else {
        printf("O atacante perdeu e uma tropa foi removida.\n");
        atacante->tropas--;
        if (atacante->tropas < 0) atacante->tropas = 0;
    }
}

// função que verifica se a missão foi cumprida (simples pra exemplo)
int verificarMissao(char *missao, Territorio *mapa, int tamanho) {
    // aqui só pra simular, se tiver 3 territórios da mesma cor = vitória
    int cont = 0;
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(mapa[i].cor, "azul") == 0) cont++;
    }
    if (strstr(missao, "3 territórios") && cont >= 3)
        return 1;

    return 0;
}

// mostra o mapa do jogo
void exibirMapa(Territorio *mapa, int tamanho) {
    printf("\n=== MAPA ATUAL ===\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s - Cor: %s - Tropas: %d\n", mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// libera toda memória dinâmica usada
void liberarMemoria(Territorio *mapa, int qtd, char **missoesJogadores, int qtdJogadores) {
    free(mapa);
    for (int i = 0; i < qtdJogadores; i++) {
        free(missoesJogadores[i]);
    }
    free(missoesJogadores);
}

int main() {
    srand(time(NULL));

    // missões pré-definidas
    char *missoes[] = {
        "Conquistar 3 territórios seguidos",
        "Eliminar todas as tropas da cor vermelha",
        "Dominar metade do mapa",
        "Ter pelo menos 10 tropas em um território",
        "Conquistar um território de cada cor"
    };
    int totalMissoes = 5;

    int qtdJogadores = 2;
    char **missoesJogadores = (char**) malloc(qtdJogadores * sizeof(char*));
    for (int i = 0; i < qtdJogadores; i++) {
        missoesJogadores[i] = (char*) malloc(100 * sizeof(char));
        atribuirMissao(missoesJogadores[i], missoes, totalMissoes);
    }

    // cria alguns territórios pra exemplo
    int qtdTerritorios = 5;
    Territorio *mapa = (Territorio*) calloc(qtdTerritorios, sizeof(Territorio));

    strcpy(mapa[0].nome, "Brasil");
    strcpy(mapa[0].cor, "azul");
    mapa[0].tropas = 5;

    strcpy(mapa[1].nome, "Argentina");
    strcpy(mapa[1].cor, "vermelho");
    mapa[1].tropas = 3;

    strcpy(mapa[2].nome, "Chile");
    strcpy(mapa[2].cor, "verde");
    mapa[2].tropas = 2;

    strcpy(mapa[3].nome, "Peru");
    strcpy(mapa[3].cor, "vermelho");
    mapa[3].tropas = 4;

    strcpy(mapa[4].nome, "Uruguai");
    strcpy(mapa[4].cor, "amarelo");
    mapa[4].tropas = 1;

    // mostra missão inicial
    printf("=== JOGO INICIADO ===\n");
    for (int i = 0; i < qtdJogadores; i++) {
        printf("\nJogador %d", i + 1);
        exibirMissao(missoesJogadores[i]);
    }

    exibirMapa(mapa, qtdTerritorios);

    // simula uma rodada
    printf("\n--- Rodada de ataque ---\n");
    atacar(&mapa[0], &mapa[1]);
    exibirMapa(mapa, qtdTerritorios);

    // verifica se alguém ganhou
    for (int i = 0; i < qtdJogadores; i++) {
        if (verificarMissao(missoesJogadores[i], mapa, qtdTerritorios)) {
            printf("\n>>> O jogador %d cumpriu sua missão e venceu o jogo!\n", i + 1);
        }
    }

    liberarMemoria(mapa, qtdTerritorios, missoesJogadores, qtdJogadores);
    return 0;
}
// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.

// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.

// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
// Função utilitária:

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // 1. Configuração Inicial (Setup):
    // - Define o locale para português.
    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
    // - Define a cor do jogador e sorteia sua missão secreta.

    // 2. Laço Principal do Jogo (Game Loop):
    // - Roda em um loop 'do-while' que continua até o jogador sair (opção 0) ou vencer.
    // - A cada iteração, exibe o mapa, a missão e o menu de ações.
    // - Lê a escolha do jogador e usa um 'switch' para chamar a função apropriada:
    //   - Opção 1: Inicia a fase de ataque.
    //   - Opção 2: Verifica se a condição de vitória foi alcançada e informa o jogador.
    //   - Opção 0: Encerra o jogo.
    // - Pausa a execução para que o jogador possa ler os resultados antes da próxima rodada.

    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.

    return 0;
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
