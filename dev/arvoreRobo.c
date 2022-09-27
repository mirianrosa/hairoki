#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_COL 7
#define MAX_INPUT_USER 10

char tabuleiroPecasGenericas[5][TAM_MAX_COL];

void printarTabuleiro(int num, char tabuleiro[5][TAM_MAX_COL])
{
    num == 1 ? printf("    1 2 3 4  \n") : printf("    1 2 3 4 5 6  \n");
    num == 1 ? printf("  * * * * * *\n") : printf("  * * * * * * * *\n");

    int cont = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("%d *", i + 1);
        for (int j = 0; j < TAM_MAX_COL; j++)
        {
            if (tabuleiro[i][j] == '\0')
                continue;
            printf(" %c", tabuleiro[i][j]);
        }
        (num == 2 && (cont == 3 || cont == 4)) ? printf("\n") : printf(" *\n");
        cont++;
    }
    num == 1 ? printf("  * *     * *\n") : printf("  * * * * * * * *\n");
}

void copiarMatriz(char matriz[5][TAM_MAX_COL], char tabuleiroJogo[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < TAM_MAX_COL; j++)
        {
            tabuleiroJogo[i][j] = matriz[i][j];
        }
    }
}

int moverDireita(char tipo, char letra, char tabuleiroJogo[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == letra)
            {
                if (tipo == 'D' && tabuleiroJogo[i][j + 2] == ' ' && tabuleiroJogo[i + 1][j + 2] == ' ')
                {
                    tabuleiroJogo[i][j + 2] = letra;
                    tabuleiroJogo[i + 1][j + 2] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'D')
                {
                    return 0;
                }

                if (tipo == 'B' && tabuleiroJogo[i][j + 2] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 2] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'B')
                {
                    return 0;
                }
                if (tipo == 'P' && tabuleiroJogo[i][j + 1] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 1] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'P')
                {
                    return 0;
                }
                if (tipo == 'Q' && tabuleiroJogo[i][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return 1;
                }
                else if (tipo == 'Q')
                {
                    return 0;
                }
                if (tipo == 'S' && tabuleiroJogo[i][j + 2] == ' ')
                {
                    tabuleiroJogo[i][j + 2] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return 1;
                }
                else if (tipo == 'S')
                {
                    return 0;
                }
                if (tipo == 'C' && tabuleiroJogo[i][j + 1] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 1] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j - 1] = ' ';
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    printf("INTERNAL ERROR: MOVIMENTO DIREITA INVALIDO\n");
    return 0;
}

int moverEsquerda(char tipo, char letra, char tabuleiroJogo[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == letra)
            {
                if (j > 0 && tipo == 'D' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    tabuleiroJogo[i + 1][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'D')
                {
                    return 0;
                }

                if (j > 0 && tipo == 'B' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'B')
                {
                    return 0;
                }
                if (j > 0 && tipo == 'P' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'P')
                {
                    return 0;
                }
                if (j > 0 && tipo == 'Q' && tabuleiroJogo[i][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return 1;
                }
                else if (tipo == 'Q')
                {
                    return 0;
                }
                if (j > 0 && tipo == 'S' && tabuleiroJogo[i][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'S')
                {
                    return 0;
                }
                if (j > 0 && tipo == 'C' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 2] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 2] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    printf("INTERNAL ERROR: MOVIMENTO ESQUERDA INVALIDO\n");
    return 0;
}

int moverTopo(char tipo, char letra, char tabuleiroJogo[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == letra)
            {
                if (i > 0 && tipo == 'D' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i - 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i - 1][j + 1] = letra;
                    tabuleiroJogo[i + 1][j] = ' ';
                    tabuleiroJogo[i + 1][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'D')
                {
                    return 0;
                }

                if (i > 0 && tipo == 'B' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i - 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i - 1][j + 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'B')
                {
                    return 0;
                }
                if (i > 0 && tipo == 'P' && tabuleiroJogo[i - 1][j] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i + 1][j] = ' ';
                    return 1;
                }
                else if (tipo == 'P')
                {
                    return 0;
                }
                if (i > 0 && tipo == 'Q' && tabuleiroJogo[i - 1][j] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return 1;
                }
                else if (tipo == 'Q')
                {
                    return 0;
                }
                if (i > 0 && tipo == 'S' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i - 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i - 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'S')
                {
                    return 0;
                }
                if (tipo == 'C' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i][j - 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j] = ' ';
                    tabuleiroJogo[i + 1][j - 1] = ' ';
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    printf("INTERNAL ERROR: MOVIMENTO TOPO INVALIDO\n");
    return 0;
}

int moverBaixo(char tipo, char letra, char tabuleiroJogo[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == letra)
            {
                if (i < 5 && tipo == 'D' && tabuleiroJogo[i + 2][j] == ' ' && tabuleiroJogo[i + 2][j + 1] == ' ')
                {
                    tabuleiroJogo[i + 2][j] = letra;
                    tabuleiroJogo[i + 2][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'D')
                {
                    return 0;
                }

                if (i < 5 && tipo == 'B' && tabuleiroJogo[i + 2][j] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i + 2][j] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'B')
                {
                    return 0;
                }
                if (i < 5 && tipo == 'P' && tabuleiroJogo[i + 2][j] == ' ')
                {
                    if (i + 2 < 5)
                    {
                        tabuleiroJogo[i + 2][j] = letra;
                        tabuleiroJogo[i][j] = ' ';
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (tipo == 'P')
                {
                    return 0;
                }
                if (i < 5 && tipo == 'Q' && tabuleiroJogo[i + 1][j] == ' ')
                {
                    if (i + 1 < 5)
                    {
                        tabuleiroJogo[i + 1][j] = letra;
                        tabuleiroJogo[i][j] = ' ';
                        return 1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if (tipo == 'Q')
                {
                    return 0;
                }
                if (i < 5 && tipo == 'S' && tabuleiroJogo[i + 1][j] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i + 1][j] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return 1;
                }
                else if (tipo == 'S')
                {
                    return 0;
                }
                if (tipo == 'C' && tabuleiroJogo[i + 2][j] == ' ' && tabuleiroJogo[i + 2][j - 1] == ' ')
                {
                    tabuleiroJogo[i + 2][j] = letra;
                    tabuleiroJogo[i + 2][j - 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j - 1] = ' ';
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    printf("INTERNAL ERROR: MOVIMENTO BAIXO INVALIDO\n");
    return 0;
}

int moverDirecao(char direcao, char tipo, char letra, char tabuleiroJogo[5][TAM_MAX_COL])
{
    int pecaMov = 0;
    switch (direcao)
    {
    case 'D':
        pecaMov = moverDireita(tipo, letra, tabuleiroJogo);
        break;
    case 'E':
        pecaMov = moverEsquerda(tipo, letra, tabuleiroJogo);
        break;
    case 'T':
        pecaMov = moverTopo(tipo, letra, tabuleiroJogo);
        break;
    case 'B':
        pecaMov = moverBaixo(tipo, letra, tabuleiroJogo);
        break;
    default:
        printf("INTERNAL ERROR: DIRECAO INVALIDA");
        break;
    }
    return pecaMov;
}

char encontrarLetra(char char_i, char char_j, char tabuleiroJogo[5][TAM_MAX_COL])
{
    int i = (char_i - '0');
    int j = (char_j - '0');
    return tabuleiroJogo[i - 1][j - 1];
}

char checarTipoPeca(char letra, char tabuleiroJogo[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == letra)
            {
                if (tabuleiroJogo[i][j + 1] == letra)
                {
                    if (tabuleiroJogo[i + 1][j] == letra)
                    {
                        if (tabuleiroJogo[i + 1][j + 1] == letra)
                        {
                            return 'D';
                        }
                        return 'B';
                    }
                    return 'S';
                }
                else if (tabuleiroJogo[i + 1][j] == letra)
                {
                    if (j != 0 && tabuleiroJogo[i + 1][j - 1] == letra)
                    {
                        return 'C';
                    }

                    return 'P';
                }
                else
                    return 'Q';
            }
        }
    }
    printf("INTERNAL ERROR: TIPO INVALIDO\n");
    return 'e';
}

void generalizarPecasNaHoraDeSalvar(char tabuleiro[5][TAM_MAX_COL])
{

    char tabuleiroBranco[5][TAM_MAX_COL] = {
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'}};
    copiarMatriz(tabuleiroBranco, tabuleiroPecasGenericas);
    copiarMatriz(tabuleiro, tabuleiroPecasGenericas);
    char tipoPeca = ' ';

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiro[i][j] == '\0' || tabuleiro[i][j] == ' ')
                continue;
            tipoPeca = checarTipoPeca(tabuleiro[i][j], tabuleiro);
            tabuleiroPecasGenericas[i][j] = tipoPeca;
        }
    }
}

typedef struct node
{
    char fotoTabuleiroAtual[5][TAM_MAX_COL];
    int numTabuleiro;
    struct node *proximo;
} Node;

Node *criarNode()
{
    Node *novoNode = (Node *)malloc(sizeof(Node));
    return novoNode;
}

Node *inserirNodeNoFim(Node *listaEncadeada, int configTabuleiro, char tabuleiroJogo[5][TAM_MAX_COL])
{ // insere novo node no fim da lista encadeada (historico e lista de sugestoes)

    Node *novoNode = criarNode();
    copiarMatriz(tabuleiroJogo, novoNode->fotoTabuleiroAtual);
    novoNode->numTabuleiro = configTabuleiro;

    if (listaEncadeada == NULL)
    {
        listaEncadeada = novoNode;
        novoNode->proximo = NULL;
    }
    else
    {
        Node *auxiliar = listaEncadeada;

        while ((auxiliar->proximo) != NULL)
        {
            auxiliar = auxiliar->proximo;
        }

        auxiliar->proximo = novoNode;
        novoNode->proximo = NULL;
    }

    return listaEncadeada;
}

Node *listaRepetidosGlobal = NULL;
typedef struct nodeTree
{
    char fotoTabuleiroAtual[5][TAM_MAX_COL];
    int numTabuleiro;
    struct nodeTree *filhos[8];
    struct nodeTree *pai;
    int quantNivel;
} NodeTree;

NodeTree *inserirRaizTree(NodeTree *noAtual, char tabuleiro[5][TAM_MAX_COL], int numTab, NodeTree *ptPai, int nivel)
{
    // printf("\nInserir raiz\n");
    NodeTree *novoNode = (NodeTree *)malloc(sizeof(NodeTree));
    if (noAtual == NULL)
    {
        // é verdadeira penas a primeira vez para criar a raiz primaria
        copiarMatriz(tabuleiro, novoNode->fotoTabuleiroAtual);
        novoNode->numTabuleiro = numTab;
        novoNode->quantNivel = nivel;
        novoNode->pai = ptPai;
        novoNode->filhos[0] = NULL;
        novoNode->filhos[1] = NULL;
        novoNode->filhos[2] = NULL;
        novoNode->filhos[3] = NULL;
        novoNode->filhos[4] = NULL;
        novoNode->filhos[5] = NULL;
        novoNode->filhos[6] = NULL;
        novoNode->filhos[7] = NULL;
    }
    return novoNode;
}

int verificaFim(int configTabuleiro, char tabuleiro[5][TAM_MAX_COL], int nivel)
{
    if (configTabuleiro == 1)
    {
        if (tabuleiro[4][1] == 'D' && tabuleiro[4][2] == 'D')
        {
            return 1;
        }
        // printf("\nNivel: %d\n", nivel);
        // printarTabuleiro(1, tabuleiro);
    }
    else if (configTabuleiro == 2)
    {
        if (tabuleiro[4][5] == 'D')
        {
            return 1;
        }
        // printf("\nNivel: %d\n", nivel);
        // printarTabuleiro(2, tabuleiro);
    }
    return 0;

    // if (configTabuleiro == 1)
    // {
    //     if (tabuleiro[4][1] == 'D' && tabuleiro[4][2] == 'D')
    //     {
    //         return 1;
    //     }
    // }
    // else if (configTabuleiro == 2 && tabuleiro[4][5] == 'D')
    // {
    //     return 1;
    // }
    // return 0;
}

void imprimeSolucao(NodeTree *no)
{
    NodeTree *auxiliar = no;
    if (auxiliar != NULL)
    {
        imprimeSolucao(auxiliar->pai);
        printarTabuleiro(auxiliar->numTabuleiro, auxiliar->fotoTabuleiroAtual);
        printf("\n");
    }
    return;
}

int compararTabuleiros(int num, char tabuleiro1[5][TAM_MAX_COL], char tabuleiro2[5][TAM_MAX_COL])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < TAM_MAX_COL; j++)
        {
            if (tabuleiro1[i][j] != tabuleiro2[i][j])
                return 0;
        }
    }
    return 1;
}

int checaPaisIguais(NodeTree *no, char candidatoSugestao[5][TAM_MAX_COL])
{
    NodeTree *auxiliar = no;

    while ((auxiliar->pai) != NULL)
    {
        if (compararTabuleiros(auxiliar->numTabuleiro, candidatoSugestao, auxiliar->fotoTabuleiroAtual) == 1)
        {
            // Candidato ja existe na arvore, cancela ele
            // printf("Existe pai igual\n");
            return 1;
        }
        auxiliar = auxiliar->pai;
    }
    if ((auxiliar->pai) == NULL)
    {
        if (compararTabuleiros(auxiliar->numTabuleiro, candidatoSugestao, auxiliar->fotoTabuleiroAtual) == 1)
        {
            // Candidato ja existe na arvore, cancela ele
            // printf("Existe pai igual\n");
            return 1;
        }
    }
    // printf("NAO existe pai igual\n");
    return 0; // Tudo certo com o candidato, nao existe nenhum pai igual
}

void mostrarListaEncadeada(Node *lista)
{
    Node *auxiliar = lista;

    printf("\nImprimindo lista encadeada:\n");

    while (auxiliar != NULL)
    {
        printarTabuleiro(auxiliar->numTabuleiro, auxiliar->fotoTabuleiroAtual);
        printf("\n");
        auxiliar = auxiliar->proximo;
    }

    printf("\nFim------------------------\n");
}

int checaRepetidosGlobais(char tabuleiro[5][7], int configTabuleiro)
{
    generalizarPecasNaHoraDeSalvar(tabuleiro);

    if (listaRepetidosGlobal == NULL)
    {
        listaRepetidosGlobal = inserirNodeNoFim(listaRepetidosGlobal, configTabuleiro, tabuleiroPecasGenericas);
        return 0;
    }

    Node *auxiliar = listaRepetidosGlobal;

    while ((auxiliar->proximo) != NULL)
    {
        if (compararTabuleiros(auxiliar->numTabuleiro, auxiliar->fotoTabuleiroAtual, tabuleiroPecasGenericas) == 1)
        {
            // mostrarListaEncadeada(listaRepetidosGlobal);
            return 1;
        }
        auxiliar = auxiliar->proximo;
    }
    if ((auxiliar->proximo) == NULL)
    {
        if (compararTabuleiros(auxiliar->numTabuleiro, auxiliar->fotoTabuleiroAtual, tabuleiroPecasGenericas) == 1)
        {
            return 1;
        }
    }
    inserirNodeNoFim(listaRepetidosGlobal, configTabuleiro, tabuleiroPecasGenericas);
    return 0;
}

Node *filtroPrioridade(Node *sugestoes, char tabuleiroJogo[5][TAM_MAX_COL])
{
    Node *aux = sugestoes;
    Node *ordemNova = NULL;
    int posicaoDaDonzela = 1;
    int n = (aux->numTabuleiro == 1 ? 3 : 4);

    for (int i = 0; i < 5; i++) // checa se a donzela consegue mover
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == 'D')
            {
                if ((j > 0 && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 1] == ' ') ||
                    (j < n && tabuleiroJogo[i][j + 2] == ' ' && tabuleiroJogo[i + 1][j + 2] == ' ') ||
                    (i < 3 && tabuleiroJogo[i + 2][j] == ' ' && tabuleiroJogo[i + 2][j + 1] == ' ') ||
                    (i > 0 && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i - 1][j + 1] == ' '))
                {
                    while (aux != NULL) // se ela move colocar a sugestão dela como 1 da lista dentro do ordemNova
                    {
                        if ((j > 0 && aux->fotoTabuleiroAtual[i][j - 1] == 'D' && aux->fotoTabuleiroAtual[i + 1][j - 1] == 'D') ||
                            (j < n && aux->fotoTabuleiroAtual[i][j + 2] == 'D' && aux->fotoTabuleiroAtual[i + 1][j + 2] == 'D') ||
                            (i < 3 && aux->fotoTabuleiroAtual[i + 2][j] == 'D' && aux->fotoTabuleiroAtual[i + 2][j + 1] == 'D') ||
                            (i > 0 && aux->fotoTabuleiroAtual[i - 1][j] == 'D' && aux->fotoTabuleiroAtual[i - 1][j + 1] == 'D'))
                        {
                            if (posicaoDaDonzela > 1)
                            {
                                ordemNova = inserirNodeNoFim(ordemNova, aux->numTabuleiro, aux->fotoTabuleiroAtual);
                            }
                            break;
                        }
                        ++posicaoDaDonzela;
                        aux = aux->proximo;
                    }
                }
            }
        }
    }

    if (ordemNova != NULL) // se ela move colocar coloca as outras sugestoes atras dele
    {
        int posicaoDaLista = 1;
        aux = sugestoes;
        while (aux != NULL)
        {
            if (posicaoDaLista != posicaoDaDonzela)
            {
                inserirNodeNoFim(ordemNova, aux->numTabuleiro, aux->fotoTabuleiroAtual);
            }
            ++posicaoDaLista;
            aux = aux->proximo;
        }
        return ordemNova;
    }
    return sugestoes;
}

Node *filtroRepetido(Node *sugestoes, NodeTree *noAtual) // usado somente para o robo
{
    Node *filtro = NULL;
    int matrizRepetidaGlobal = 0;
    int matrizRepetida = 0;

    while (sugestoes != NULL)
    {
        matrizRepetida = checaPaisIguais(noAtual, sugestoes->fotoTabuleiroAtual);
        if (!matrizRepetida)
        {
            matrizRepetidaGlobal = checaRepetidosGlobais(sugestoes->fotoTabuleiroAtual, sugestoes->numTabuleiro);
            if (!matrizRepetidaGlobal)
            {
                filtro = inserirNodeNoFim(filtro, sugestoes->numTabuleiro, sugestoes->fotoTabuleiroAtual);
            }
        }
        matrizRepetida = 0;
        matrizRepetidaGlobal = 0;
        sugestoes = sugestoes->proximo;
    }

    return filtro;
}

Node *encontrarProxsJogadas(int configTabuleiro, char tabuleiroJogo[5][TAM_MAX_COL], Node *sugestoes, NodeTree *noAtual)
{
    Node *possiveisJogadas = sugestoes;
    char tabuleiroAux[5][TAM_MAX_COL];
    copiarMatriz(tabuleiroJogo, tabuleiroAux);
    char tipoPeca = ' ';
    int movValido;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == ' ')
            {
                if (tabuleiroJogo[i][j + 1] == ' ')
                {
                    // vazio horizontal ['', '']
                    if (i > 0)
                    {
                        // Checando em cima
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i - 1][j], tabuleiroJogo);
                        movValido = moverDirecao('B', tipoPeca, tabuleiroJogo[i - 1][j], tabuleiroAux);
                        // if (tipoPeca == 'D' && movValido == 1) printf("Movi D Baixo\n");
                        if (movValido)
                        {
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                        if (tabuleiroJogo[i - 1][j] != tabuleiroJogo[i - 1][j + 1])
                        {
                            tipoPeca = checarTipoPeca(tabuleiroJogo[i - 1][j + 1], tabuleiroJogo);
                            movValido = moverDirecao('B', tipoPeca, tabuleiroJogo[i - 1][j + 1], tabuleiroAux);
                            if (movValido)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                                copiarMatriz(tabuleiroJogo, tabuleiroAux);
                            }
                        }
                    }

                    if (i < 4)
                    {
                        // Checando embaixo
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i + 1][j], tabuleiroJogo);
                        movValido = moverDirecao('T', tipoPeca, tabuleiroJogo[i + 1][j], tabuleiroAux);
                        // if (tipoPeca == 'D' && movValido == 1) printf("Movi D Topo\n");
                        if (movValido)
                        {
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                        if (tabuleiroJogo[i + 1][j] != tabuleiroJogo[i + 1][j + 1])
                        {
                            tipoPeca = checarTipoPeca(tabuleiroJogo[i + 1][j + 1], tabuleiroJogo);
                            movValido = moverDirecao('T', tipoPeca, tabuleiroJogo[i + 1][j + 1], tabuleiroAux);
                            if (movValido)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                                copiarMatriz(tabuleiroJogo, tabuleiroAux);
                            }
                        }
                    }

                    if (j > 0)
                    {
                        // Checando esquerda
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j - 1], tabuleiroJogo);
                        movValido = moverDirecao('D', tipoPeca, tabuleiroJogo[i][j - 1], tabuleiroAux);
                        if (movValido)
                        {
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    int n = (configTabuleiro == 1 ? 3 : 4);
                    if (j < n)
                    {
                        // Checando direita
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j + 2], tabuleiroJogo);
                        movValido = moverDirecao('E', tipoPeca, tabuleiroJogo[i][j + 2], tabuleiroAux);
                        if (movValido)
                        {
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    return possiveisJogadas;
                }
                else if (tabuleiroJogo[i + 1][j] == ' ')
                {
                    if (i > 0)
                    {
                        // vazio Vertical ['']
                        //                ['']
                        // Checando em cima
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i - 1][j], tabuleiroJogo);
                        movValido = moverDirecao('B', tipoPeca, tabuleiroJogo[i - 1][j], tabuleiroAux);
                        if (movValido)
                        {
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    if (i < 3)
                    {
                        // Checando embaixo
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i + 2][j], tabuleiroJogo);
                        movValido = moverDirecao('T', tipoPeca, tabuleiroJogo[i + 2][j], tabuleiroAux);
                        if (movValido)
                        {
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    if (j > 0)
                    {
                        // Checando esquerda
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j - 1], tabuleiroJogo);
                        movValido = moverDirecao('D', tipoPeca, tabuleiroJogo[i][j - 1], tabuleiroAux);
                        // if (tipoPeca == 'D' && movValido == 1) printf("Movi D Dir\n");
                        if (movValido)
                        {
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                        if (tabuleiroJogo[i][j - 1] != tabuleiroJogo[i + 1][j - 1])
                        {
                            tipoPeca = checarTipoPeca(tabuleiroJogo[i + 1][j - 1], tabuleiroJogo);
                            movValido = moverDirecao('D', tipoPeca, tabuleiroJogo[i + 1][j - 1], tabuleiroAux);

                            if (movValido)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                                copiarMatriz(tabuleiroJogo, tabuleiroAux);
                            }
                        }
                    }

                    int n = (configTabuleiro == 1 ? 3 : 5);

                    if (j < n)
                    {
                        // Checando direita
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j + 1], tabuleiroJogo);
                        movValido = moverDirecao('E', tipoPeca, tabuleiroJogo[i][j + 1], tabuleiroAux);
                        // if (tipoPeca == 'D' && movValido == 1) printf("Movi D Esq\n");
                        if (movValido)
                        {
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                        if (tabuleiroJogo[i][j + 1] != tabuleiroJogo[i + 1][j + 1])
                        {
                            tipoPeca = checarTipoPeca(tabuleiroJogo[i + 1][j + 1], tabuleiroJogo);
                            movValido = moverDirecao('E', tipoPeca, tabuleiroJogo[i + 1][j + 1], tabuleiroAux);
                            if (movValido)
                            {
                                possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                                copiarMatriz(tabuleiroJogo, tabuleiroAux);
                            }
                        }
                    }
                    return possiveisJogadas;
                }
                else
                {
                    if (i > 0)
                    {
                        // Checando em cima
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i - 1][j], tabuleiroJogo);
                        movValido = moverDirecao('B', tipoPeca, tabuleiroJogo[i - 1][j], tabuleiroAux);
                        if (movValido)
                        {
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    if (i < 4)
                    {
                        // Checando embaixo
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i + 1][j], tabuleiroJogo);
                        movValido = moverDirecao('T', tipoPeca, tabuleiroJogo[i + 1][j], tabuleiroAux);
                        if (movValido)
                        {
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    if (j > 0)
                    {
                        // Checando esquerda
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j - 1], tabuleiroJogo);
                        movValido = moverDirecao('D', tipoPeca, tabuleiroJogo[i][j - 1], tabuleiroAux);
                        if (movValido)
                        {
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }

                    int n = (configTabuleiro == 1 ? 3 : 5);

                    if (j < n)
                    {
                        // Checando direita
                        tipoPeca = checarTipoPeca(tabuleiroJogo[i][j + 1], tabuleiroJogo);
                        movValido = moverDirecao('E', tipoPeca, tabuleiroJogo[i][j + 1], tabuleiroAux);
                        if (movValido)
                        {
                            possiveisJogadas = inserirNodeNoFim(possiveisJogadas, configTabuleiro, tabuleiroAux);
                            copiarMatriz(tabuleiroJogo, tabuleiroAux);
                        }
                    }
                }
            }
        }
    }
    return possiveisJogadas;
}

int recNova(NodeTree *noAtual, Node *sugestoes, int nivel)
{
    // printf("To aqui nivel: %d\n",nivel);
    int fim = verificaFim(noAtual->numTabuleiro, noAtual->fotoTabuleiroAtual, noAtual->quantNivel);
    if (fim == 1)
    {
        printf("\n[!] A solucao foi encontrada!\nApresentando passos para o resultado...\n\n");
        imprimeSolucao(noAtual);
        return 1;
    }

    int i = 0;

    while (i < 8 && sugestoes != NULL)
    {
        noAtual->filhos[i] = inserirRaizTree(noAtual->filhos[i], sugestoes->fotoTabuleiroAtual, noAtual->numTabuleiro, noAtual, nivel);

        Node *novaSugestao = NULL;
        novaSugestao = encontrarProxsJogadas(noAtual->numTabuleiro, noAtual->filhos[i]->fotoTabuleiroAtual, novaSugestao, noAtual);
        novaSugestao = filtroRepetido(novaSugestao, noAtual->filhos[i]);

        if (novaSugestao != NULL)
        {
            novaSugestao = filtroPrioridade(novaSugestao, noAtual->filhos[i]->fotoTabuleiroAtual);
        }

        fim = recNova(noAtual->filhos[i], novaSugestao, nivel + 1);
        if (fim == 1)
            return fim;

        sugestoes = sugestoes->proximo;
        ++i;
    }

    free(noAtual);

    return 0;
}

int main()
{
    char tabuleiro1[5][TAM_MAX_COL] = {
        {'a', 'D', 'D', 'b', '\0', '\0', '\0'},
        {'a', 'D', 'D', 'b', '\0', '\0', '\0'},
        {'c', 'd', 'd', 'e', '\0', '\0', '\0'},
        {'c', 'g', 'h', 'e', '\0', '\0', '\0'},
        {'f', ' ', ' ', 'i', '\0', '\0', '\0'}};

    char tabuleiro2[5][TAM_MAX_COL] = {
        {'D', 'D', ' ', 'a', 'a', 'b', '\0'},
        {'D', 'D', ' ', 'a', 'c', 'd', '\0'},
        {'e', 'e', 'f', 'g', 'd', 'd', '\0'},
        {'h', 'h', 'i', 'j', 'k', 'l', '\0'},
        {'h', 'i', 'i', 'm', 'k', 'l', '\0'}};

    NodeTree *noAtual = NULL;

    // Alterar aqui para testar as duas solucoes
    int numTab = 2;
    noAtual = inserirRaizTree(noAtual, tabuleiro2, numTab, NULL, 0);
    //

    // Tabuleiro 1 leva em media 2.5 segundos
    // Tabuleiro 2 leva em media 4 minutos

    Node *sugestoes = NULL;
    sugestoes = encontrarProxsJogadas(numTab, noAtual->fotoTabuleiroAtual, sugestoes, noAtual);

    sugestoes = filtroPrioridade(sugestoes, noAtual->fotoTabuleiroAtual);

    int final = recNova(noAtual, sugestoes, 1);

    printf("\nACHEI: %d", final);

    return 0;
}