#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_LIN 5
#define TAM_MAX_COL 7
#define MAX_INPUT_USER 10

typedef struct node
{
    char fotoTabuleiroAtual[TAM_MAX_LIN][TAM_MAX_COL];
    int numTabuleiro;
    struct node *proximo;
} Node;

typedef struct nodeTree
{
    char fotoTabuleiroAtual[TAM_MAX_LIN][TAM_MAX_COL];
    int numTabuleiro;
    struct nodeTree *filhos[8];
    struct nodeTree *pai;
    int quantNivel;
} NodeTree;

char tabuleiroPecasGenericas[TAM_MAX_LIN][TAM_MAX_COL];
void printarTabuleiro(int num, char tabuleiro[TAM_MAX_LIN][TAM_MAX_COL]);
void copiarMatriz(char matriz[TAM_MAX_LIN][TAM_MAX_COL], char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL]);
int moverDireita(char tipo, char letra, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL]);
int moverEsquerda(char tipo, char letra, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL]);
int moverTopo(char tipo, char letra, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL]);
int moverBaixo(char tipo, char letra, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL]);
int moverDirecao(char direcao, char tipo, char letra, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL]);
char encontrarLetra(char char_i, char char_j, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL]);
char checarTipoPeca(char letra, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL]);
void banner(void);
void help1(void);
void help2(void);
int verificaFim(int configTabuleiro, char tabuleiro[TAM_MAX_LIN][TAM_MAX_COL]);
int interacoesUsuario(int argc, char argumento[], int configTabuleiro, int jaEscolheuTabuleiro, char comandoAtivo, int numSugestao);
void abreArquivo(char nomeArquivoTxt[], char tabuleiro1[TAM_MAX_LIN][TAM_MAX_COL], char tabuleiro2[TAM_MAX_LIN][TAM_MAX_COL], char titulo1Nome[14], char titulo2Nome[15]);
Node *criarNode();
Node *inserirNodeNoFim(Node *listaEncadeada, int configTabuleiro, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL]);
Node *listaRepetidosGlobal = NULL;
NodeTree *inserirRaizTree(NodeTree *noAtual, char tabuleiro[TAM_MAX_LIN][TAM_MAX_COL], int numTab, NodeTree *ptPai, int nivel);
void mostrarHistoricoOuSugestao(Node *lista, int isSugestao);
int contSugestoes(Node *sugestoes);
Node *encontrarProxsJogadas(int configTabuleiro, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL], Node *sugestoes);
void generalizarPecasNaHoraDeSalvar(char tabuleiro[TAM_MAX_LIN][TAM_MAX_COL]);
int compararTabuleiros(int num, char tabuleiro1[TAM_MAX_LIN][TAM_MAX_COL], char tabuleiro2[TAM_MAX_LIN][TAM_MAX_COL]);
int checaPaisIguais(NodeTree *no, char candidatoSugestao[TAM_MAX_LIN][TAM_MAX_COL]);
int checaRepetidosGlobais(char tabuleiro[TAM_MAX_LIN][TAM_MAX_COL], int configTabuleiro);
Node *filtroPrioridade(Node *sugestoes, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL]);
Node *filtroRepetido(Node *sugestoes, NodeTree *noAtual);
void imprimeSolucao(NodeTree *no);
int interacaoRobo(NodeTree *noAtual, Node *sugestoes, int nivel);

int main(int argc, char *argv[])
{
    banner();

    Node *historico = NULL;
    Node *sugestoes = NULL;

    int jaEscolheuTabuleiro = 0;
    int configTabuleiro = 1;
    int fim = 0;
    int contMov = 0;
    int numSugestao = 0;
    char comandoAtivo = ' ';

    char titulo1Nome[14];
    char titulo2Nome[15];

    char tabuleiro1[TAM_MAX_LIN][TAM_MAX_COL] = {
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'}};

    char tabuleiro2[TAM_MAX_LIN][TAM_MAX_COL] = {
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'}};

    char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL];

    if (argc == 1)
    {
        char *nomeArquivoTxt = "haikori.txt";
        abreArquivo(nomeArquivoTxt, tabuleiro1, tabuleiro2, titulo1Nome, titulo2Nome);
    }
    else if (argc == 3)
    {
        if (argv[1][0] == '-' && argv[1][1] == 'f' && argv[1][2] == '\0')
        {
            char *nomeArquivoTxt = argv[2];
            abreArquivo(nomeArquivoTxt, tabuleiro1, tabuleiro2, titulo1Nome, titulo2Nome);
        }
        else
        {
            printf("\n[!] Erro nos argumentos\n\n");
            help1();
            return 1;
        }
    }
    else
    {
        printf("\n[!] Erro nos argumentos\n\n");
        help1();
        return 1;
    }

    help2();

    while (fim != 1)
    {
        char inputUsuario[MAX_INPUT_USER] = "          ";
        printf("\nDigite o comando: ");
        fgets(inputUsuario, MAX_INPUT_USER, stdin);

        if (inputUsuario[0] == 'q')
        {
            printf("Tem certeza que deseja sair?\n");
            printf("Digite 1 para Sim e qualquer outra tecla para Nao: ");
            char temCerteza[MAX_INPUT_USER];
            fgets(temCerteza, MAX_INPUT_USER, stdin);
            printf("\n");
            if (temCerteza[0] == '1')
            {
                fim = 1;
            }
        }
        else if (inputUsuario[0] == 's')
        {
            if (jaEscolheuTabuleiro == 0)
            {
                printf("\n[!] Erro: Nenhum tabuleiro foi escolhido!\n\n");
                help2();
            }
            else
            {
                if (comandoAtivo == 's')
                {
                    printf("\nComando de sugestao esta ativo, deseja desativar?\nDigite 1 para Sim e qualquer outra tecla para Nao: ");
                    char desativar[MAX_INPUT_USER];
                    fgets(desativar, MAX_INPUT_USER, stdin);
                    printf("\n");
                    if (desativar[0] == '1')
                    {
                        printf("\nComando de sugestao desativado!\n");
                        comandoAtivo = ' ';
                    }
                }
                else
                {
                    printf("\nComando de sugestao ativo!\nDigite: 'n', onde n e o numero da sugestao\n");
                    comandoAtivo = 's';
                    sugestoes = encontrarProxsJogadas(configTabuleiro, tabuleiroJogo, sugestoes);
                    mostrarHistoricoOuSugestao(sugestoes, 1);
                    numSugestao = contSugestoes(sugestoes);
                }
            }
        }
        else if (inputUsuario[0] == 'R')
        {
            if (jaEscolheuTabuleiro == 0)
            {
                printf("\n[!] Erro: Nenhum tabuleiro foi escolhido!\n\n");
                help2();
            }
            else
            {
                comandoAtivo = 'R';
                fim = 1;
            }
        }
        else
        {
            int len = 0;
            for (int i = 0; i != MAX_INPUT_USER; i++)
            {
                if (inputUsuario[i] != '\0' && inputUsuario[i] != ' ' && inputUsuario[i] != '\n')
                {
                    ++len;
                }
            }
            int resultado = interacoesUsuario(len, inputUsuario, configTabuleiro, jaEscolheuTabuleiro, comandoAtivo, numSugestao);
            if (resultado == 0)
            {
                continue;
            }
            else if (resultado == 1)
            {
                configTabuleiro = 1;
                jaEscolheuTabuleiro = 1;
                contMov = 0;
                historico = NULL;
                copiarMatriz(tabuleiro1, tabuleiroJogo);
                printarTabuleiro(configTabuleiro, tabuleiroJogo);
                historico = inserirNodeNoFim(historico, configTabuleiro, tabuleiroJogo);
            }
            else if (resultado == 2)
            {
                configTabuleiro = 2;
                jaEscolheuTabuleiro = 1;
                contMov = 0;
                historico = NULL;
                copiarMatriz(tabuleiro2, tabuleiroJogo);
                printarTabuleiro(configTabuleiro, tabuleiroJogo);
                historico = inserirNodeNoFim(historico, configTabuleiro, tabuleiroJogo);
            }
            else if (resultado == 3)
            {
                // Movimentacao
                char letra = encontrarLetra(inputUsuario[2], inputUsuario[4], tabuleiroJogo);
                char tipo = checarTipoPeca(letra, tabuleiroJogo);
                int movCerto = moverDirecao(inputUsuario[6], tipo, letra, tabuleiroJogo);
                int fimDeJogo = 0;

                if (movCerto == 1)
                {
                    printf("\nMovimento %d\n", ++contMov);
                    historico = inserirNodeNoFim(historico, configTabuleiro, tabuleiroJogo);
                    fimDeJogo = verificaFim(configTabuleiro, tabuleiroJogo);
                }
                else
                {
                    printf("\nNao e possivel mover peca\n");
                }
                printarTabuleiro(configTabuleiro, tabuleiroJogo);

                if (fimDeJogo)
                {
                    printf("\n*** Voce Ganhou! ***\n");
                    fim = 1;
                }
            }
            else if (resultado == 4)
            {
                printf("\nHistorico de movimentos\n\n");
                mostrarHistoricoOuSugestao(historico, 0);
            }
            else if (resultado == 5)
            {
                // Listar tabuleiros
                printf("1\n%s\n", titulo1Nome);
                printarTabuleiro(1, tabuleiro1);
                printf("\n2\n%s\n", titulo2Nome);
                printarTabuleiro(2, tabuleiro2);
            }
            else
            {
                printf("Escolha feita:\n");
                int fimDeJogo = 0;
                int sugestaoEscolhida = inputUsuario[0] - '0';
                int i = 1;

                while (sugestoes != NULL && i != 0)
                {
                    if (i == sugestaoEscolhida)
                    {
                        copiarMatriz(sugestoes->fotoTabuleiroAtual, tabuleiroJogo);
                    }
                    sugestoes = sugestoes->proximo;
                    ++i;
                }
                historico = inserirNodeNoFim(historico, configTabuleiro, tabuleiroJogo);
                fimDeJogo = verificaFim(configTabuleiro, tabuleiroJogo);
                printarTabuleiro(configTabuleiro, tabuleiroJogo);

                if (fimDeJogo)
                {
                    printf("\n*** Voce Ganhou! ***\n");
                    fim = 1;
                }
                else
                {
                    sugestoes = encontrarProxsJogadas(configTabuleiro, tabuleiroJogo, sugestoes);
                    mostrarHistoricoOuSugestao(sugestoes, 1);
                    numSugestao = contSugestoes(sugestoes);
                }
            }
        }
    }

    if (comandoAtivo == 'R')
    {
        printf("\nVoce ativou a solucao automatica a partir do momento atual.\n");
        printf("Aguarde enquanto a solucao e calculada para voce...\n");

        NodeTree *noAtual = NULL;
        noAtual = inserirRaizTree(noAtual, tabuleiroJogo, configTabuleiro, NULL, 0);

        sugestoes = NULL;
        sugestoes = encontrarProxsJogadas(configTabuleiro, noAtual->fotoTabuleiroAtual, sugestoes);
        sugestoes = filtroPrioridade(sugestoes, noAtual->fotoTabuleiroAtual);

        interacaoRobo(noAtual, sugestoes, 1);
    }

    printf("\nObrigado por ter jogado!\n");

    return 0;
}

void printarTabuleiro(int num, char tabuleiro[TAM_MAX_LIN][TAM_MAX_COL])
{
    num == 1 ? printf("    1 2 3 4  \n") : printf("    1 2 3 4 5 6  \n");
    num == 1 ? printf("  * * * * * *\n") : printf("  * * * * * * * *\n");

    int cont = 0;
    for (int i = 0; i < TAM_MAX_LIN; i++)
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

void copiarMatriz(char matriz[TAM_MAX_LIN][TAM_MAX_COL], char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL])
{
    for (int i = 0; i < TAM_MAX_LIN; i++)
    {
        for (int j = 0; j < TAM_MAX_COL; j++)
        {
            tabuleiroJogo[i][j] = matriz[i][j];
        }
    }
}

int moverDireita(char tipo, char letra, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL])
{
    for (int i = 0; i < TAM_MAX_LIN; i++)
    {
        for (int j = 0; j < TAM_MAX_COL - 1; j++)
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
    printf("INTERNAL ERROR");
    return 0;
}

int moverEsquerda(char tipo, char letra, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL])
{
    for (int i = 0; i < TAM_MAX_LIN; i++)
    {
        for (int j = 0; j < TAM_MAX_COL - 1; j++)
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
    printf("INTERNAL ERROR");
    return 0;
}

int moverTopo(char tipo, char letra, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL])
{
    for (int i = 0; i < TAM_MAX_LIN; i++)
    {
        for (int j = 0; j < TAM_MAX_COL - 1; j++)
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
    printf("INTERNAL ERROR");
    return 0;
}

int moverBaixo(char tipo, char letra, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL])
{
    for (int i = 0; i < TAM_MAX_LIN; i++)
    {
        for (int j = 0; j < TAM_MAX_COL - 1; j++)
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
    printf("INTERNAL ERROR");
    return 0;
}

int moverDirecao(char direcao, char tipo, char letra, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL])
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

char encontrarLetra(char char_i, char char_j, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL])
{
    int i = (char_i - '0');
    int j = (char_j - '0');
    return tabuleiroJogo[i - 1][j - 1];
}

char checarTipoPeca(char letra, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL])
{
    for (int i = 0; i < TAM_MAX_LIN; i++)
    {
        for (int j = 0; j < TAM_MAX_COL - 1; j++)
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
    printf("INTERNAL ERROR: TIPO INVALIDO");
    return 'e';
}

void banner(void)
{
    printf(" _   _       _ _              _ \n");
    printf("| | | | __ _(_) | _____  _ __(_)\n");
    printf("| |_| |/ _` | | |/ / _ \\| '__| |\n");
    printf("|  _  | (_| | |   < (_) | |  | |\n");
    printf("|_| |_|\\__,_|_|_|\\_\\___/|_|  |_|\n");
    printf("Por Larissa, Mirian e Yuri\n");
}

void help1(void)
{
    printf("Modo de uso: ./tabuleiro [opcoes]\n");

    printf("\n========================= NOTAS =========================\n");
    printf("ULTIMA FASE - Mostrar sugestoes, criar arvore nao binaria\n");
    printf("e oferecer opcao para programa procurar a saida automatica-\n");
    printf("mente, sem a intervencao do usuario.\n");

    printf("\n======================== OPCOES ========================\n");
    printf(" -f <nome_arquivo.txt> : Especifica qual arquivo de tabuleiros\n");
    printf("                         o jogo deve utilizar.\n");
    printf("                         Default: haikori.txt\n");

    printf("\n======================== EXEMPLOS =======================\n");
    printf(" ./tabuleiro\n");
    printf(" ./tabuleiro -f meuarquivo.txt\n");
}

void help2(void)
{
    printf("======================== OPCOES ========================\n");
    printf(" l                   : Lista e exibe todas as opcoes numeradas dos tabuleiros.\n\n");
    printf(" c <config_tab>      : Especifica qual dos tabuleiros disponiveis (1 ou 2) o jogo deve utilizar.\n");
    printf("                       Se a configuracao for alterada no meio de um jogo, todo o progresso anterior sera perdido.\n\n");
    printf(" m <lin> <col> <dir> : Movimenta a peca que esta na posicao (lin,col) para a direcao dir.\n");
    printf("                       Direcoes: D - Direita | E - Esquerda | B - Baixo | T - Topo\n\n");
    printf(" p                   : Imprime o historico de movimentacoes desde a configuracao inicial.\n\n");
    printf(" s                   : Ativa ou desativa as sugestoes de proximas jogadas para o usuario.\n\n");
    printf(" R                   : Ativa a procura automatica pela solucao a partir do momento atual e imprime os passos.\n\n");
    printf("\n========================================================\n");
}

int verificaFim(int configTabuleiro, char tabuleiro[TAM_MAX_LIN][TAM_MAX_COL])
{
    if (configTabuleiro == 1)
    {
        if (tabuleiro[4][1] == 'D' && tabuleiro[4][2] == 'D')
        {
            return 1;
        }
    }
    else if (configTabuleiro == 2 && tabuleiro[4][5] == 'D')
    {
        return 1;
    }
    return 0;
}

int interacoesUsuario(int argc, char argumento[], int configTabuleiro, int jaEscolheuTabuleiro, char comandoAtivo, int numSugestao)
{
    int i = 0;
    int j = 0;
    char direcao = '0';

    if (argc == 3 || argc > 4)
    {
        printf("\n[!] Erro nos argumentos\n\n");
        help2();
        return 0;
    }
    if (argc == 1)
    {
        if (argumento[0] == 'l')
        {
            return 5; // Listar os tabuleiros disponiveis
        }
        else if (argumento[0] == 'p')
        {
            if (jaEscolheuTabuleiro == 0)
            {
                printf("\n[!] Nenhum tabuleiro foi escolhido!\n\n");
                help2();
                return 0;
            }
            else
            {
                return 4; // Mostrar o historico
            }
        }
        else if (comandoAtivo == 's')
        {
            if ((argumento[0] - '0') >= 1 && (argumento[0] - '0') <= numSugestao)
            {
                return 6; // Escolha da sugestao
            }
            printf("\n[!] Erro: Argumento invalido\n\n");
            help2();
            return 0;
        }
        else
        {
            printf("\n[!] Erro: Argumento invalido\n\n");
            help2();
            return 0;
        }
    }
    if (argc == 2)
    {
        if (argumento[0] == 'c')
        {
            if (argumento[2] == '1')
            {
                if (jaEscolheuTabuleiro)
                {
                    if (configTabuleiro == 1)
                    {
                        printf("\nTabuleiro escolhido ja esta sendo utilizado.\n\n");
                        return 0;
                    }
                    else
                    {
                        printf("\nTem certeza que quer trocar de tabuleiro? Todo o seu progresso sera perdido.\n");
                        printf("Digite 1 para Sim e qualquer outra tecla para Nao: ");
                        char temCerteza[MAX_INPUT_USER];
                        fgets(temCerteza, MAX_INPUT_USER, stdin);
                        printf("\n");
                        if (temCerteza[0] == '1')
                        {
                            return 1; // troca do C2 para C1
                        }
                        else
                        {
                            return 0;
                        }
                    }
                }
                else
                {
                    return 1; // escolher tabuleiro c1 e mostra o tabuleiro c1
                }
            }
            else if (argumento[2] == '2')
            {
                if (jaEscolheuTabuleiro)
                {
                    if (configTabuleiro == 2)
                    {
                        printf("\nTabuleiro escolhido ja esta sendo utilizado.\n\n");
                        return 0;
                    }
                    else
                    {
                        printf("\nTem certeza que quer trocar de tabuleiro? Todo o seu progresso sera perdido.\n");
                        printf("Digite 1 para Sim e qualquer outra tecla para Nao: ");
                        char temCerteza[MAX_INPUT_USER];
                        fgets(temCerteza, MAX_INPUT_USER, stdin);
                        printf("\n");
                        if (temCerteza[0] == '1')
                        {
                            return 2; // troca do C1 para C2
                        }
                        else
                        {
                            return 0;
                        }
                    }
                }
                else
                {
                    return 2; // escolher tabuleiro c2 e mostra o tabuleiro c2
                }
            }
            else
            {
                printf("\n[!] Erro: Configuração de tabuleiro invalida\n\n");
                help2();
                return 0;
            }
        }
        else
        {
            printf("\n[!] Erro: Argumento invalido\n\n");
            help2();
            return 0;
        }
    }

    if (argc == 4)
    {
        if (argumento[0] == 'm')
        {
            if (jaEscolheuTabuleiro == 0)
            {
                printf("\n[!] Erro: Nenhum tabuleiro foi escolhido!\n\n");
                help2();
                return 0;
            }

            direcao = argumento[6];

            if (direcao != 'D' && direcao != 'E' && direcao != 'T' && direcao != 'B')
            {
                printf("\n[!] Erro: Direção inválida\n\n");
                help2();
                return 0;
            }

            char i_ = argumento[2];
            char j_ = argumento[4];

            i = i_ - '0';
            j = j_ - '0';

            if (configTabuleiro == 1)
            {
                if (i >= 1 && i <= 5 && j >= 1 && j <= 4)
                {
                }
                else
                {
                    printf("\n[!] Erro: Coordenadas inválidas\n\n");
                    help2();
                    return 0;
                }
            }

            if (configTabuleiro == 2)
            {
                if (i >= 1 && i <= 5 && j >= 1 && j <= 6)
                {
                }
                else
                {
                    printf("\n[!] Erro: Coordenadas inválidas\n\n");
                    help2();
                    return 0;
                }
            }
            return 3; // Movimento valido da peca
        }
        else
        {
            printf("\n[!] Erro: Argumento invalido\n\n");
            help2();
            return 0;
        }
    }
    printf("\n[!] ERRO: INTERNAL ERROR\n\n");
    return 0;
}

void abreArquivo(char nomeArquivoTxt[], char tabuleiro1[TAM_MAX_LIN][TAM_MAX_COL], char tabuleiro2[TAM_MAX_LIN][TAM_MAX_COL], char titulo1Nome[14], char titulo2Nome[15])
{

    FILE *arqTxtTabuleiros;

    if ((arqTxtTabuleiros = fopen(nomeArquivoTxt, "r")) == NULL)
    {
        printf("\n[!] Erro na abertura do arquivo de tabuleiros.\n");
        exit(1);
    }
    else
    {
        printf("\n[+] Arquivo de tabuleiros carregado com sucesso.\n\n");

        char str1;
        int titulo1 = 0;
        int i = 0;
        int j = 0;
        int titulo2 = 0;

        int contN = 0;

        str1 = fgetc(arqTxtTabuleiros);

        while (str1 != EOF)
        {
            if (str1 != '\n' && str1 != '*' && str1 != '\0')
            {
                if (titulo1 == 0)
                {
                    titulo1Nome[i] = str1;
                    ++i;
                }
                if ((titulo2 == 0) && (titulo1 == 1) && (contN == 9))
                {
                    titulo2Nome[i] = str1;
                    ++i;
                }
                if ((titulo1 == 1) && (titulo2 == 0) && (contN < 7))
                {
                    tabuleiro1[i][j] = str1;
                    ++j;
                }
                if ((titulo2 == 1) && (contN >= 11))
                {
                    tabuleiro2[i][j] = str1;
                    ++j;
                }
            }
            if (str1 == '\n')
            {
                ++contN;
                if (titulo1 == 0)
                {
                    titulo1 = 1;
                    titulo1Nome[i] = '\0';
                    i = 0;
                }
                if ((titulo2 == 0) && (titulo1 == 1) && (contN == 10))
                {
                    titulo2 = 1;
                    titulo2Nome[i] = '\0';
                    i = 0;
                }
                if ((titulo1 == 1) && (titulo2 == 0) && (contN > 2) && (contN < 7))
                {
                    ++i;
                    j = 0;
                }
                if (contN == 7)
                {
                    i = 0;
                    j = 0;
                }
                if ((titulo2 == 1) && (contN > 11) && (contN < 16))
                {
                    ++i;
                    j = 0;
                }
            }
            str1 = fgetc(arqTxtTabuleiros);
        }
        fclose(arqTxtTabuleiros);
    }
}

Node *criarNode()
{
    Node *novoNode = (Node *)malloc(sizeof(Node));
    return novoNode;
}

Node *inserirNodeNoFim(Node *listaEncadeada, int configTabuleiro, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL])
{
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

NodeTree *inserirRaizTree(NodeTree *noAtual, char tabuleiro[TAM_MAX_LIN][TAM_MAX_COL], int numTab, NodeTree *ptPai, int nivel)
{
    NodeTree *novoNode = (NodeTree *)malloc(sizeof(NodeTree));
    if (noAtual == NULL)
    {
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

void mostrarHistoricoOuSugestao(Node *lista, int isSugestao)
{
    Node *auxiliar = lista;
    int i = 1;

    if (isSugestao)
    {
        printf("\nSugestoes de movimentaçao:\n");
    }

    while (auxiliar != NULL)
    {
        if (isSugestao)
        {
            printf("%da Sugestao:\n", i);
        }
        printarTabuleiro(auxiliar->numTabuleiro, auxiliar->fotoTabuleiroAtual);
        printf("\n");
        auxiliar = auxiliar->proximo;
        ++i;
    }
}

int contSugestoes(Node *sugestoes)
{
    Node *auxiliar = sugestoes;
    int numSugestoes = 0;

    while (auxiliar != NULL)
    {
        auxiliar = auxiliar->proximo;
        ++numSugestoes;
    }
    return numSugestoes;
}

Node *encontrarProxsJogadas(int configTabuleiro, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL], Node *sugestoes)
{
    Node *possiveisJogadas = sugestoes;
    char tabuleiroAux[TAM_MAX_LIN][TAM_MAX_COL];
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
                    // Vazio horizontal ['', '']
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
                        // Vazio Vertical ['']
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

void generalizarPecasNaHoraDeSalvar(char tabuleiro[TAM_MAX_LIN][TAM_MAX_COL])
{

    char tabuleiroBranco[TAM_MAX_LIN][TAM_MAX_COL] = {
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'}};
    copiarMatriz(tabuleiroBranco, tabuleiroPecasGenericas);
    copiarMatriz(tabuleiro, tabuleiroPecasGenericas);
    char tipoPeca = ' ';

    for (int i = 0; i < TAM_MAX_LIN; i++)
    {
        for (int j = 0; j < TAM_MAX_COL - 1; j++)
        {
            if (tabuleiro[i][j] == '\0' || tabuleiro[i][j] == ' ')
                continue;
            tipoPeca = checarTipoPeca(tabuleiro[i][j], tabuleiro);
            tabuleiroPecasGenericas[i][j] = tipoPeca;
        }
    }
}

int compararTabuleiros(int num, char tabuleiro1[TAM_MAX_LIN][TAM_MAX_COL], char tabuleiro2[TAM_MAX_LIN][TAM_MAX_COL])
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

int checaPaisIguais(NodeTree *no, char candidatoSugestao[TAM_MAX_LIN][TAM_MAX_COL])
{
    NodeTree *auxiliar = no;

    while ((auxiliar->pai) != NULL)
    {
        if (compararTabuleiros(auxiliar->numTabuleiro, candidatoSugestao, auxiliar->fotoTabuleiroAtual) == 1)
        {
            return 1;
        }
        auxiliar = auxiliar->pai;
    }
    if ((auxiliar->pai) == NULL)
    {
        if (compararTabuleiros(auxiliar->numTabuleiro, candidatoSugestao, auxiliar->fotoTabuleiroAtual) == 1)
        {
            return 1;
        }
    }
    return 0; // Tudo certo com o candidato, nao existe nenhum pai igual
}

int checaRepetidosGlobais(char tabuleiro[TAM_MAX_LIN][TAM_MAX_COL], int configTabuleiro)
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

Node *filtroPrioridade(Node *sugestoes, char tabuleiroJogo[TAM_MAX_LIN][TAM_MAX_COL])
{
    Node *aux = sugestoes;
    Node *ordemNova = NULL;
    int posicaoDaDonzela = 1;
    int n = (aux->numTabuleiro == 1 ? 3 : 4);

    for (int i = 0; i < TAM_MAX_LIN; i++) // Checa se a donzela consegue se mover
    {
        for (int j = 0; j < TAM_MAX_COL - 1; j++)
        {
            if (tabuleiroJogo[i][j] == 'D')
            {
                if ((j > 0 && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 1] == ' ') ||
                    (j < n && tabuleiroJogo[i][j + 2] == ' ' && tabuleiroJogo[i + 1][j + 2] == ' ') ||
                    (i < 3 && tabuleiroJogo[i + 2][j] == ' ' && tabuleiroJogo[i + 2][j + 1] == ' ') ||
                    (i > 0 && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i - 1][j + 1] == ' '))
                {
                    while (aux != NULL) // Se ela move, colocar a sugestao dela como 1a da lista dentro da ordemNova
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

    if (ordemNova != NULL) // Se ela move, colocar as outras sugestoes atras dele
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

Node *filtroRepetido(Node *sugestoes, NodeTree *noAtual) // Usado somente para o robo (evita entrar em loops)
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
        sugestoes = sugestoes->proximo;
    }
    return filtro;
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

int interacaoRobo(NodeTree *noAtual, Node *sugestoes, int nivel)
{
    int fim = verificaFim(noAtual->numTabuleiro, noAtual->fotoTabuleiroAtual);
    if (fim == 1)
    {
        printf("\n[!] A solucao foi encontrada!\nApresentando passos para o resultado...\n\n");
        imprimeSolucao(noAtual);
        printf("Solucao encontrada!\nQuantidade de passos: %d\n", nivel);
        return 1;
    }

    int i = 0;

    while (i < 8 && sugestoes != NULL)
    {
        noAtual->filhos[i] = inserirRaizTree(noAtual->filhos[i], sugestoes->fotoTabuleiroAtual, noAtual->numTabuleiro, noAtual, nivel);

        Node *novaSugestao = NULL;
        novaSugestao = encontrarProxsJogadas(noAtual->numTabuleiro, noAtual->filhos[i]->fotoTabuleiroAtual, novaSugestao);
        novaSugestao = filtroRepetido(novaSugestao, noAtual->filhos[i]);

        if (novaSugestao != NULL)
        {
            novaSugestao = filtroPrioridade(novaSugestao, noAtual->filhos[i]->fotoTabuleiroAtual);
        }

        fim = interacaoRobo(noAtual->filhos[i], novaSugestao, nivel + 1);
        if (fim == 1)
            return fim;

        sugestoes = sugestoes->proximo;
        ++i;
    }

    free(noAtual);

    return 0;
}