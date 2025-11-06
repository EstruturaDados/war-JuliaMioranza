🧩 Sistema de Missões Estratégicas — Trabalho de Estrutura de Dados (C)
👩‍💻 Desenvolvido por: Julia de Mattos Mioranza

Matéria: Estrutura de Dados
Tema: Implementação de missões estratégicas no jogo estilo WAR

🎯 Objetivo do Projeto

A ideia principal desse trabalho é criar uma funcionalidade onde cada jogador recebe uma missão individual e secreta no início do jogo, sorteada automaticamente entre várias opções pré-definidas.
Essas missões trazem uma camada extra de estratégia e tornam o jogo mais dinâmico, já que cada jogador tem um objetivo diferente para vencer.

⚙️ O que o código faz

Cria um vetor de strings com diferentes descrições de missões.

Sorteia uma missão aleatoriamente e atribui para cada jogador usando ponteiros.

Armazena a missão dinamicamente com malloc.

Verifica durante o jogo se a missão foi cumprida (de forma simples, só pra exemplo).

Exibe o mapa e permite simular ataques entre territórios.

No final de cada rodada, o programa verifica se algum jogador venceu.

Tudo é feito de forma modular, com funções separadas e bem organizadas.

🧠 Estrutura usada

struct Territorio → guarda nome, cor e quantidade de tropas.

Vetor de missões → armazena textos com os objetivos possíveis.

Ponteiros e alocação dinâmica (malloc, calloc, free) → usados para guardar as missões dos jogadores e o mapa.

Funções bem divididas:

atribuirMissao() → sorteia e copia a missão para o jogador.

exibirMissao() → mostra a missão sorteada no início.

atacar() → simula uma batalha entre dois territórios.

verificarMissao() → verifica se o jogador cumpriu sua missão.

exibirMapa() → mostra o estado atual do jogo.

liberarMemoria() → libera tudo no final pra evitar vazamento de memória.

🕹️ Como funciona a simulação

O jogo começa com 2 jogadores e 5 territórios.

Cada jogador recebe uma missão aleatória.

É mostrado o mapa com as cores e tropas de cada território.

A função atacar() faz uma simulação simples de batalha (usando rand() para o dado).

Depois do ataque, o jogo checa se alguém atingiu o objetivo da missão.

Se sim, mostra a mensagem de vitória.

💬 Detalhes técnicos importantes

Bibliotecas usadas: stdio.h, stdlib.h, string.h, time.h.

Geração de números aleatórios com srand(time(NULL)).

Passagem de parâmetros por valor e referência.

Uso de strcpy, strcmp e strstr pra manipular strings.

Ao final do programa, toda memória é liberada com free().

