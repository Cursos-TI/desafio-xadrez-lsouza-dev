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

void imprimirMovimento(
    bool cima,
    bool baixo,
    bool esquerda,
    bool direita,
    int quantidade
);


int main()
{
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
    imprimirMovimento(
        direcao == 'A' || direcao == 'B',
        direcao == 'C' || direcao == 'D',
        direcao == 'A' || direcao == 'D',
        direcao == 'B' || direcao == 'C',
        quantidade
    );
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
    imprimirMovimento(
        direcao == 'C' ,
        direcao == 'D' ,
        direcao == 'A' ,
        direcao == 'B' ,
        quantidade
    );
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
    imprimirMovimento(
        direcao == 'A' || direcao == 'B' || direcao == 'G',
        direcao == 'C' || direcao == 'D' || direcao == 'H',
        direcao == 'A' || direcao == 'D' || direcao == 'F',
        direcao == 'B' || direcao == 'C' || direcao == 'E',
        quantidade
    );
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

void imprimirMovimento(bool cima,
                       bool baixo,
                       bool esquerda,
                       bool direita,
                       int quantidade)
{
    if (quantidade == 0)
        return;

    if (cima)
        printf("Cima\n");

    if (baixo)
        printf("Baixo\n");

    if (esquerda)
        printf("Esquerda\n");

    if (direita)
        printf("Direita\n");

    printf("Movimentos restantes: %d\n", quantidade - 1);

    imprimirMovimento(
        cima,
        baixo,
        esquerda,
        direita,
        quantidade - 1
    );
}