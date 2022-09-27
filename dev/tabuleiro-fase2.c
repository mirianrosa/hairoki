#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_COL 7
#define MAX_INPUT_USER 10

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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
                    return 0;
                }
            }
        }
    }
    printf("INTERNAL ERROR");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
                    return 0;
                }
            }
        }
    }
    printf("INTERNAL ERROR");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
                    return 0;
                }
            }
        }
    }
    printf("INTERNAL ERROR");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                        printf("\nNao e possivel mover peca\n");
                        return 0;
                    }
                }
                else if (tipo == 'P')
                {
                    printf("\nNao e possivel mover peca\n");
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
                        printf("\nNao e possivel mover peca\n");
                        return 0;
                    }
                }
                else if (tipo == 'Q')
                {
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
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
                    printf("\nNao e possivel mover peca\n");
                    return 0;
                }
            }
        }
    }
    printf("INTERNAL ERROR");
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
    printf("INTERNAL ERROR: TIPO INVALIDO");
    return 'e';
}

void banner(void)
{
    printf("-----------------\n");
    printf("HAIKORI\n");
    printf("Por Larissa, Mirian e Yuri\n");
    printf("-----------------\n");
    printf("\n");
}

void help1(void)
{
    printf("Modo de uso: ./tabuleiro [opcoes]\n");

    printf("\n========================= NOTAS =========================\n");
    printf("FASE 2 - Ler .txt, movimento iterativo de pecas e historico.\n");

    printf("\n======================== OPCOES ========================\n");
    printf(" -f <nome_arquivo.txt> : Especifica qual tabuleiro o jogo deve utilizar.\n");
    printf("                         Default: haikori.txt\n");

    printf("\n======================== EXEMPLOS =======================\n");
    printf(" ./tabuleiro\n");
    printf(" ./tabuleiro -f meuarquivo.txt\n");
}

void help2(void)
{
    printf("\n======================== OPCOES ========================\n");
    printf(" l                   : Listar todas as opcoes numeradas dos tabuleiros.\n");
    printf(" c <config_tab>      : Especifica qual dos tabuleiros disponiveis o jogo deve utilizar.\n");
    printf("                       Se a configuracao for alterada no meio de um jogo, todo o progresso anterior sera perdido.\n\n");
    printf(" m <lin> <col> <dir> : Movimenta a peca que esta na posicao (lin,col) para a direcao dir.\n");
    printf("                       Direcoes: D - Direita | E - Esquerda | B - Baixo | T - Topo\n");
    printf(" p                   : Imprime o historico de movimentacoes desde a configuracao inicial.\n\n");
}

int interacoesUsuario(int argc, char argumento[], int configTabuleiro, int jaEscolheuTabuleiro)
{
    int i = 0;
    int j = 0;
    char direcao = '0';

    if (argc == 3 || argc > 4)
    {
        printf("[!]1 Erro nos argumentos\n\n");
        help2();
        return 0;
    }
    if (argc == 1)
    {
        if (argumento[0] == 'l')
        {
            return 5; // listar os tabuleiros disponiveis
        }
        else if (argumento[0] == 'p')
        {

            return 4; // mostrar o historico
        }
        else
        {
            printf("[!]2 Erro: Argumento invalido\n\n");
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
                    if (configTabuleiro == 1){
                        printf("\nTabuleiro escolhido ja esta sendo utilizado.\n\n");
                        return 0;
                    } else {
                    printf("Tem certeza que quer trocar de tabuleiro? Todo o seu progresso sera perdido.\n");
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
                    if (configTabuleiro == 2){
                        printf("\nTabuleiro escolhido ja esta sendo utilizado.\n\n");
                        return 0;
                    } else {
                    printf("Tem certeza que quer trocar de tabuleiro? Todo o seu progresso sera perdido.\n");
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
                printf("[!]3 Erro: Configuração de tabuleiro invalida\n\n");
                help2();
                return 0;
            }
        }
        else
        {
            printf("[!]4 Erro: Argumento invalido\n\n");
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
                printf("[!]5 Erro: Tabuleiro nao escolhido\n\n");
                help2();
                return 0;
            }

            direcao = argumento[6];

            if (direcao != 'D' && direcao != 'E' && direcao != 'T' && direcao != 'B')
            {
                printf("[!]6 Erro: Direção inválida\n\n");
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
                    printf("[!] Erro6: Coordenadas inválidas\n\n");
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
                    printf("[!] Erro7: Coordenadas inválidas\n\n");
                    help2();
                    return 0;
                }
            }
            return 3; // Movimento valido da peca
        }
        else
        {
            printf("[!] Erro8: Argumento invalido\n\n");
            help2();
            return 0;
        }
    }
    printf("[!] ERRO 9: INTERNAL ERROR\n\n");
    return 0;
}

void abreArquivo(char nomeArquivoTxt[], char tabuleiro1[5][TAM_MAX_COL], char tabuleiro2[5][TAM_MAX_COL], char titulo1Nome[14], char titulo2Nome[15])
{

    FILE *arqTxtTabuleiros;

    if ((arqTxtTabuleiros = fopen(nomeArquivoTxt, "r")) == NULL)
    {
        printf("[!] Erro na abertura do arquivo de tabuleiros.\n");
        exit(1);
    }
    else
    {
        printf("Arquivo aberto com sucesso.\n\n");

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

typedef struct node{
    char fotoTabuleiroAtual[5][TAM_MAX_COL];
    int numTabuleiro;
    struct node *proximo;
}Node;

Node* criarNode(){
    Node *novoNode = (Node*)malloc(sizeof(Node));
    return novoNode;
}

Node* inserirNodeNoFim(Node* historico, int configTabuleiro, char tabuleiroJogo[5][TAM_MAX_COL]){
    Node *novoNode = criarNode();
    copiarMatriz(tabuleiroJogo, novoNode -> fotoTabuleiroAtual);
    novoNode -> numTabuleiro = configTabuleiro;

    if (historico == NULL){
        historico = novoNode;
        novoNode -> proximo = NULL;
    } else {
        Node *auxiliar = historico;

        while ((auxiliar -> proximo) != NULL){
            auxiliar = auxiliar -> proximo;
        }

        auxiliar -> proximo = novoNode;
        novoNode -> proximo = NULL;
    }

    return historico;
}

void mostrarHistorico(Node* historico){
    Node *auxiliar = historico;

    while (auxiliar != NULL){
        printarTabuleiro(auxiliar -> numTabuleiro, auxiliar -> fotoTabuleiroAtual);
        printf("\n");
        auxiliar = auxiliar -> proximo;
    }
}

int main(int argc, char *argv[])
{

    banner();

    Node *historico = NULL;

    int jaEscolheuTabuleiro = 0;
    int configTabuleiro = 1;
    int fim = 0;
    int contMov = 0;

    char titulo1Nome[14];
    char titulo2Nome[15];

    char tabuleiro1[5][TAM_MAX_COL] = {
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'}};

    char tabuleiro2[5][TAM_MAX_COL] = {
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
        {'\0', '\0', '\0', '\0', '\0', '\0', '\0'}};

    char tabuleiroJogo[5][TAM_MAX_COL];

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
            printf("[!] Erro nos argumentos\n\n");
            help1();
            return 1;
        }
    }
    else
    {
        printf("[!] Erro nos argumentos\n\n");
        help1();
        return 1;
    }

    while (fim != 1)
    {
        char inputUsuario[MAX_INPUT_USER] = "          ";
        printf("Digite o comando: ");
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
                printf("\nTchau, obrigado por ter jogado!");
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
            int resultado = interacoesUsuario(len, inputUsuario, configTabuleiro, jaEscolheuTabuleiro);
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

                if (movCerto == 1)
                {
                    printf("\nMovimento %d\n", ++contMov);
                    historico = inserirNodeNoFim(historico, configTabuleiro, tabuleiroJogo);
                }
                printarTabuleiro(configTabuleiro, tabuleiroJogo);
            }
            else if (resultado == 4)
            {
                printf("\nHistorico de movimentos\n\n");
                mostrarHistorico(historico);
            }
            else
            {
                // Listar tabuleiros
                printf("1\n%s\n", titulo1Nome);
                printarTabuleiro(1, tabuleiro1);
                printf("\n2\n%s\n", titulo2Nome);
                printarTabuleiro(2, tabuleiro2);
            }
        }
    }
    
    return 0;
}