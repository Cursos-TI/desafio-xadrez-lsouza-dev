#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

void menuBispo();
void menuTorre();
void menuRainha();
void menuCavalo();

void moverPeca(char pecaSelecionada);
void movimentoBispo(char direcao, int quantidade);
void movimentoTorre(char direcao, int quantidade);
void movimentoRainha(char direcao, int quantidade);
void movimentoCavalo(char cirecao);

int main()
{

    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

    char pecaSelecionada;
    printf("**** Selecione a peça *****\n\n");
    printf("Selecione a direção de movimento da peça:");
    printf("\n[B] Bispo");
    printf("\n[T] Torre");
    printf("\n[R] Rainha");
    printf("\n[C] Cavalo");
    printf("\n\nEscolha: ");
    scanf(" %s", &pecaSelecionada);

    moverPeca(toupper(pecaSelecionada));

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    return 0;
}

void moverPeca(char pecaSelecionada)
{
    int qtdMovimentos;
    char direcao;
    int qtdLimiteMovimentos;

    if (pecaSelecionada == 'B' || pecaSelecionada == 'T')
        qtdLimiteMovimentos = 5;
    else
        qtdLimiteMovimentos = 8;

    if (pecaSelecionada == 'B')
        menuBispo();
    if (pecaSelecionada == 'T')
        menuTorre();
    if (pecaSelecionada == 'R')
        menuRainha();
    if (pecaSelecionada == 'C')
        menuCavalo();

    scanf("%s", &direcao);

    bool quantidadeValida = false;
    if (pecaSelecionada != 'C')
    {
        do
        {
            printf("Digite a quantidade de casas que deseja andar:");
            scanf("%d", &qtdMovimentos);

            quantidadeValida = qtdMovimentos > 0 && qtdMovimentos <= qtdLimiteMovimentos;

            if (!quantidadeValida)
            {
                printf("\nQuantidade de passos inválida\n");
            }

        } while (!quantidadeValida);
    }

    printf("\nIniciando o movimento\n");

    if (pecaSelecionada == 'B')
        movimentoBispo(toupper(direcao), qtdMovimentos);
    if (pecaSelecionada == 'T')
        movimentoTorre(toupper(direcao), qtdMovimentos);
    if (pecaSelecionada == 'R')
        movimentoRainha(toupper(direcao), qtdMovimentos);
    if (pecaSelecionada == 'C')
        movimentoCavalo(toupper(direcao));

        printf("\n\n");
}

void menuBispo()
{
    printf("\n**** Bispo Selecionado *****\n\n");
    printf("Selecione a direção de movimento da peça:");
    printf("\n[A] Diagonal Superior Esquerda");
    printf("\n[B] Diagonal Superior Direita");
    printf("\n[C] Diagonal Inferior Direita");
    printf("\n[D] Diagonal Inferior Esquerda");
    printf("\n\nEscolha:");
}

void movimentoBispo(char direcao, int quantidade)
{
    bool isLeft = direcao == 'A' || direcao == 'D';
    bool isRight = direcao == 'B' || direcao == 'C';
    bool isUp = direcao == 'A' || direcao == 'B';
    bool isDown = direcao == 'C' || direcao == 'D';
    for (int i = 0; i < quantidade; i++)
    {
        if (isUp)
            printf("\nCima");
        if (isDown)
            printf("\nBaixo");
        if (isLeft)
            printf("\nEsquerda");
        if (isRight)
            printf("\nDireita");
        printf("\nMovimentos restantes: %d \n", quantidade - (i + 1));
    }
}

void menuTorre()
{
    printf("**** Torre Selecionada *****\n\n");
    printf("Selecione a direção de movimento da peça:");
    printf("\n[A] Esquerda");
    printf("\n[B] Direita");
    printf("\n[C] Cima");
    printf("\n[D] Baixo");
    printf("\n\nEscolha:");
}

void movimentoTorre(char direcao, int quantidade)
{
    bool isLeft = direcao == 'A';
    bool isRight = direcao == 'B';
    bool isUp = direcao == 'C';
    bool isDown = direcao == 'D';
    for (int i = 0; i < quantidade; i++)
    {
        if (isUp)
            printf("\nCima");
        if (isDown)
            printf("\nBaixo");
        if (isLeft)
            printf("\nEsquerda");
        if (isRight)
            printf("\nDireita");
        printf("\nMovimentos restantes: %d \n", quantidade - (i + 1));
    }
}

void menuRainha()
{
    printf("**** Rainha Selecionada *****\n\n");
    printf("Selecione a direção de movimento da peça:");
    printf("\n[A] Diagonal Superior Esquerda");
    printf("\n[B] Diagonal Superior Direita");
    printf("\n[C] Diagonal Inferior Direita");
    printf("\n[D] Diagonal Inferior Esquerda");
    printf("\n[E] Esquerda");
    printf("\n[F] Direita");
    printf("\n[G] Cima");
    printf("\n[H] Baixo");
    printf("\n\nEscolha:");
}

void movimentoRainha(char direcao, int quantidade)
{
    bool isLeft = direcao == 'A' || direcao == 'D' || direcao == 'E';
    bool isRight = direcao == 'B' || direcao == 'C' || direcao == 'F';
    bool isUp = direcao == 'A' || direcao == 'B' || direcao == 'G';
    bool isDown = direcao == 'C' || direcao == 'D' || direcao == 'H';
    for (int i = 0; i < quantidade; i++)
    {
        if (isUp)
            printf("\nCima");
        if (isDown)
            printf("\nBaixo");
        if (isLeft)
            printf("\nEsquerda");
        if (isRight)
            printf("\nDireita");
        printf("\nMovimentos restantes: %d \n", quantidade - (i + 1));
    }
}

void menuCavalo()
{
    printf("\n**** Cavalo Selecionado *****\n\n");
    printf("Selecione a direção de movimento da peça: (Direcao inicial e posição final)");
    printf("\n[A] Cima Esquerda");
    printf("\n[B] Cima Direita");
    printf("\n[C] Direita Cima");
    printf("\n[D] Direita Baixo");
    printf("\n[E] Baixo Direita");
    printf("\n[F] Baixo Esquerda");
    printf("\n[G] Esquerda Baixo");
    printf("\n[H] Esquerda Cima");
    printf("\n\nEscolha:");
}

void movimentoCavalo(char direcao)
{
    int movimentosCima = 0;
    int movimentosBaixo = 0;
    int movimentosDireita = 0;
    int movimentosEsquerda = 0;

    switch (direcao)
    {
    case 'A':
        movimentosCima = 2;
        movimentosEsquerda = 1;
        break;
    case 'B':
        movimentosCima = 2;
        movimentosDireita = 1;
        break;
    case 'C':
        movimentosDireita = 2;
        movimentosCima = 1;
        break;
    case 'D':
        movimentosDireita = 2;
        movimentosBaixo = 1;
        break;
    case 'E':
        movimentosBaixo = 2;
        movimentosDireita = 1;
        break;
    case 'F':
        movimentosBaixo = 2;
        movimentosEsquerda = 1;
        break;
    case 'G':
        movimentosEsquerda = 2;
        movimentosBaixo = 1;
        break;
    case 'H':
        movimentosEsquerda = 2;
        movimentosCima = 1;
        break;
    }

    for (int i = 0; i < 2; i++)
    {
        if (movimentosCima > 1)
            printf("\nCima");
        if (movimentosBaixo > 1)
            printf("\nBaixo");
        if (movimentosDireita > 1)
            printf("\nDireita");
        if (movimentosEsquerda > 1)
            printf("\nEsquerda");
        if (i == 1)
        {
            for (int c = 0; c < 1; c++)
            {
                if (movimentosCima == 1)
                    printf("\nCima");
                if (movimentosBaixo == 1)
                    printf("\nBaixo");
                if (movimentosDireita == 1)
                    printf("\nDireita");
                if (movimentosEsquerda == 1)
                    printf("\nEsquerda");
            }
        }
    }
}