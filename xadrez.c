#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

void menuBispo();
void menuTorre();
void menuRainha();

void moverPeca(char pecaSelecionada);
void movimentoBispo(char direcao, int quantidade);
void movimentoTorre(char direcao, int quantidade);
void movimentoRainha(char direcao, int quantidade);

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

    if(pecaSelecionada == 'B' || pecaSelecionada == 'T') qtdLimiteMovimentos = 5;
    else qtdLimiteMovimentos = 8;

    if (pecaSelecionada == 'B')
        menuBispo();
    if (pecaSelecionada == 'T')
        menuTorre();
    if (pecaSelecionada == 'R')
        menuRainha();

    scanf("%s", &direcao);

    bool quantidadeValida = false;
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

    printf("\nIniciando o movimento\n");

    if (pecaSelecionada == 'B') movimentoBispo(toupper(direcao),qtdMovimentos);
    if (pecaSelecionada == 'T') movimentoTorre(toupper(direcao),qtdMovimentos);
    if (pecaSelecionada == 'R') movimentoRainha(toupper(direcao),qtdMovimentos);

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
        if(isUp)printf("\nCima");
        if(isDown)printf("\nBaixo");
        if(isLeft)printf("\nEsquerda");
        if(isRight)printf("\nDireita");
        printf("\nMovimentos restantes: %d \n",quantidade - (i+1));
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
    bool isLeft = direcao == 'A' ;
    bool isRight = direcao == 'B' ;
    bool isUp = direcao == 'C' ;
    bool isDown = direcao == 'D' ;
    for (int i = 0; i < quantidade; i++)
    {
        if(isUp)printf("\nCima");
        if(isDown)printf("\nBaixo");
        if(isLeft)printf("\nEsquerda");
        if(isRight)printf("\nDireita");
        printf("\nMovimentos restantes: %d \n",quantidade - (i+1));
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
    bool isRight = direcao == 'B' || direcao == 'C'  || direcao == 'F';
    bool isUp = direcao == 'A' || direcao == 'B'  || direcao == 'G';
    bool isDown = direcao == 'C' || direcao == 'D'  || direcao == 'H';
    for (int i = 0; i < quantidade; i++)
    {
        if(isUp)printf("\nCima");
        if(isDown)printf("\nBaixo");
        if(isLeft)printf("\nEsquerda");
        if(isRight)printf("\nDireita");
        printf("\nMovimentos restantes: %d \n",quantidade - (i+1));
    }
}