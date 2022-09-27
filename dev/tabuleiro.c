#include <stdio.h>

#define TAM_MAX_COL 7

static char tabuleiro1[5][TAM_MAX_COL] = {
    {'a', 'D', 'D', 'b', '\0', '\0', '\0'},
    {'a', 'D', 'D', 'b', '\0', '\0', '\0'},
    {'c', 'd', 'd', 'e', '\0', '\0', '\0'},
    {'c', 'g', 'h', 'e', '\0', '\0', '\0'},
    {'f', ' ', ' ', 'i', '\0', '\0', '\0'}};
    
static char tabuleiro2[5][TAM_MAX_COL] = {
    {'D', 'D', ' ', 'a', 'a', 'b', '\0'},
    {'D', 'D', ' ', 'a', 'c', 'd', '\0'},
    {'e', 'e', 'f', 'g', 'd', 'd', '\0'},
    {'h', 'h', 'i', 'j', 'k', 'l', '\0'},
    {'h', 'i', 'i', 'm', 'k', 'l', '\0'}};

char tabuleiroJogo[5][TAM_MAX_COL];

void printarTabuleiro(int num)
{
    num == 1 ? printf("* * * * * *\n") : printf("* * * * * * * *\n");
    
    int cont = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("*");
        for (int j = 0; j < TAM_MAX_COL; j++)
        {
          if(tabuleiroJogo[i][j] == '\0') continue;
          printf(" %c", tabuleiroJogo[i][j]);
        }
        (num == 2 && (cont == 3 || cont == 4)) ? printf("\n") : printf(" *\n");
        cont++;
    }
    num == 1 ? printf("* *     * *\n") : printf("* * * * * * * *\n");
}

void copiarMatriz(char matriz[5][TAM_MAX_COL]){  
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < TAM_MAX_COL; j++)
        {
            tabuleiroJogo[i][j] = matriz[i][j];
        }
    } 
}

void moverDireita(char tipo, char letra)
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
                    return;
                } else if (tipo == 'D') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                
                if (tipo == 'B' && tabuleiroJogo[i][j + 2] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 2] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'B') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'P' && tabuleiroJogo[i][j + 1] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 1] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'P') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'Q' && tabuleiroJogo[i][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return;
                } else if (tipo == 'Q') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'S' && tabuleiroJogo[i][j + 2] == ' ')
                {
                    tabuleiroJogo[i][j + 2] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return;
                } else if (tipo == 'S') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'C' && tabuleiroJogo[i][j + 1] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i][j + 1] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j - 1] = ' ';
                    return;
                } else {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
            }
        }
    }
}

void moverEsquerda(char tipo, char letra)
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
                    return;
                } else if (tipo == 'D') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                
                if (j > 0 && tipo == 'B' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'B') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (j > 0 && tipo == 'P' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'P') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (j > 0 && tipo == 'Q' && tabuleiroJogo[i][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return;
                } else if (tipo == 'Q') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (j > 0 && tipo == 'S' && tabuleiroJogo[i][j - 1] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    return;
                } else if (tipo == 'S') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (j > 0 && tipo == 'C' && tabuleiroJogo[i][j - 1] == ' ' && tabuleiroJogo[i + 1][j - 2] == ' ')
                {
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j - 2] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
            }
        }
    }
}

void moverTopo(char tipo, char letra)
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
                    return;
                } else if (tipo == 'D') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                
                if (i > 0 && tipo == 'B' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i - 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i - 1][j + 1] = letra;
                    tabuleiroJogo[i][j + 1] = ' ';
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'B') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i > 0 && tipo == 'P' && tabuleiroJogo[i - 1][j] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i + 1][j] = ' ';
                    return;
                } else if (tipo == 'P') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i > 0 && tipo == 'Q' && tabuleiroJogo[i - 1][j] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return;
                } else if (tipo == 'Q') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i > 0 && tipo == 'S' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i - 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i - 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return;
                } else if (tipo == 'S') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'C' && tabuleiroJogo[i - 1][j] == ' ' && tabuleiroJogo[i][j - 1] == ' ')
                {
                    tabuleiroJogo[i - 1][j] = letra;
                    tabuleiroJogo[i][j - 1] = letra;
                    tabuleiroJogo[i + 1][j] = ' ';
                    tabuleiroJogo[i + 1][j - 1] = ' ';
                    return;
                } else {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
            }
        }
    }
}

void moverBaixo(char tipo, char letra)
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
                    return;
                } else if (tipo == 'D') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                
                if (i < 5 && tipo == 'B' && tabuleiroJogo[i + 2][j] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i + 2][j] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return;
                } else if (tipo == 'B') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i < 5 && tipo == 'P' && tabuleiroJogo[i + 2][j] == ' ')
                {
                    tabuleiroJogo[i + 2][j] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return;
                } else if (tipo == 'P') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i < 5 && tipo == 'Q' && tabuleiroJogo[i  + 1][j] == ' ')
                {
                    tabuleiroJogo[i + 1][j] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    return;
                } else if (tipo == 'Q') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (i < 5 && tipo == 'S' && tabuleiroJogo[i + 1][j] == ' ' && tabuleiroJogo[i + 1][j + 1] == ' ')
                {
                    tabuleiroJogo[i + 1][j] = letra;
                    tabuleiroJogo[i + 1][j + 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i][j + 1] = ' ';
                    return;
                } else if (tipo == 'S') {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
                if (tipo == 'C' && tabuleiroJogo[i + 2][j] == ' ' && tabuleiroJogo[i + 2][j - 1] == ' ')
                {
                    tabuleiroJogo[i + 2][j] = letra;
                    tabuleiroJogo[i + 2][j - 1] = letra;
                    tabuleiroJogo[i][j] = ' ';
                    tabuleiroJogo[i + 1][j - 1] = ' ';
                    return;
                } else {
                    printf("\nNao e possivel mover peca\n");
                    return;
                }
            }
        }
    }
}

void moverDirecao(char direcao, char tipo, char letra)
{
    switch (direcao)
    {
    case 'D':
        moverDireita(tipo, letra);
        break;
    case 'E':
        moverEsquerda(tipo, letra);
        break;
    case 'T':
        moverTopo(tipo, letra);
        break;
    case 'B':
        moverBaixo(tipo, letra);
        break;
    default:
        printf("INTERNAL ERROR: DIRECAO INVALIDA");
        break;
    }
    
}

char encontrarLetra(int x, int y){
    return tabuleiroJogo[x-1][y-1];
}

char checarTipoPeca(char letra)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (tabuleiroJogo[i][j] == letra) {
                if (tabuleiroJogo[i][j + 1]  == letra)
                {
                    if(tabuleiroJogo[i + 1][j]  == letra) {
                        if (tabuleiroJogo[i + 1][j + 1]  == letra)
                        {
                           return 'D';
                        }
                        return 'B';                        
                    }
                    return 'S';
                } else if (tabuleiroJogo[i + 1][j]  == letra)
                {
                    if (j != 0 && tabuleiroJogo[i + 1][j - 1]  == letra)
                    {
                        return 'C';
                    }
                    
                    return 'P';
                } else return 'Q';                
            }
        }
    }
    printf("INTERNAL ERROR: TIPO INVALIDO");
    return 'e';
}


void banner(void) {

  printf("-----------------\n");
  printf("HAIKORI\n");
  printf("Por Larissa, Mirian e Yuri\n");
  printf("-----------------\n");
  printf("\n");

}

void help(void) {

  printf("Modo de uso: ./tabuleiro [opcoes]\n");

  printf("\n========================= NOTAS =========================\n");
  printf("FASE 1 - Linha de comando e movimento de pecas\n");


  printf("\n======================== OPCOES ========================\n");
  printf(" -c<config_tabuleiro> : Especifica qual tabuleiro o jogo deve utilizar.\n");
  printf("                        Configuracoes: 1 - Menor [default] | 2 - Maior\n\n");
  printf(" -m <x> <y> <direcao> : Movimenta a peca que esta nas coordenadas (x,y) para a direcao d.\n");
  printf("                        Direcoes: D - Direita | E - Esquerda | B - Baixo | T - Topo\n");
    
  printf("\n======================== EXEMPLOS =======================\n");
  printf(" ./tabuleiro\n");
  printf(" ./tabuleiro -c1\n");
  printf(" ./tabuleiro -c2\n");
  printf(" ./tabuleiro -c2 -m 1 1 D\n");
  printf(" ./tabuleiro -c2 -m 2 2 B\n");
  printf(" ./tabuleiro -m 2 2 T\n");

}

int main(int argc, char* argv[]){
    banner();

    int configTabuleiro = 1;
    int usuarioMovePecaTerminal = 0;
    int x = 0;
    int y = 0;
    int argCfoilido = 0;
    int argMfoilido = 0;
    char direcao = '0';

    if (argc == 1){
        configTabuleiro == 1 ? copiarMatriz(tabuleiro1) : copiarMatriz(tabuleiro2);
        printarTabuleiro(configTabuleiro);
        return 0;
    }

    if (argc > 2 && argc < 5){
        printf("[!] Erro nos argumentos\n\n");
        help();
        return 1;
    }

    if (argc > 6){
        printf("[!] Erro: Ultrapassou limite de argumentos\n\n");
        help();
        return 1;
    }

    if (argc == 2){
        char* argumento = argv[1];

        if (argumento[0] == '-' && argumento[1] == 'c'){

            if (argumento[2] == '1' || argumento[2] == '\0'){
                configTabuleiro == 1 ? copiarMatriz(tabuleiro1) : copiarMatriz(tabuleiro2);
                printarTabuleiro(configTabuleiro);
                return 0;

            } else if (argumento[2] == '2'){
                configTabuleiro = 2;
                configTabuleiro == 1 ? copiarMatriz(tabuleiro1) : copiarMatriz(tabuleiro2);
                printarTabuleiro(configTabuleiro);
                return 0;

            } else {
                printf("[!] Erro: Configuração de tabuleiro inválida\n\n");
                help();
                return 1;
            }
        } else if (argumento[0] == '-' && argumento[1] == 'm'){
            printf("[!] Erro: Opção -m exige coordenadas e direção\n\n");
            help();
            return 1;
            } else {
                printf("[!] Erro: Argumento inválido\n\n");
                help();
                return 1;
            }
    }

    if (argc == 5 || argc == 6){

        for (int i = 1; i <= 2; i++){
            char* argumento = argv[i];

            if (argumento[0] == '-' && argumento[1] == 'c') {

                if (argMfoilido == 1){
                    printf("[!] Erro: Ordem inválida de argumentos\n\n");
                    help();
                    return 1;
                } else if (argCfoilido == 1){
                    printf("[!] Erro: Argumentos inválidos\n\n");
                    help();
                    return 1;
                } else {
                    argCfoilido = 1;
                }

                if (argumento[2] == '1' || argumento[2] == '\0'){
                    configTabuleiro = 1;

                } else if (argumento[2] == '2'){
                    configTabuleiro = 2;

                } else {
                    printf("[!] Erro: Configuração de tabuleiro inválida\n\n");
                    help();
                    return 1;
                }
            } else 

            if (argumento[0] == '-' && argumento[1] == 'm'){
                argMfoilido = 1;

                if (argc == 5 && argCfoilido == 1){
                    printf("[!] Erro: Argumentos inválidos\n\n");
                    help();
                    return 1;
                }

                direcao = argv[i+3][0];

                if (direcao != 'D' && direcao != 'E' && direcao != 'T' && direcao != 'B'){
                    printf("[!] Erro: Direção inválida\n\n");
                    help();
                    return 1;
                } 
                
                char x_ = argv[i+1][0];
                char y_ = argv[i+2][0];

                x = x_ - '0';
                y = y_ - '0';

                if (configTabuleiro == 1){
                    if (x >=1 && x <= 5 && y >= 1 && y <= 4){
                        usuarioMovePecaTerminal = 1;
                    } else {
                        printf("[!] Erro1: Coordenadas inválidas\n\n");
                        help();
                        return 1;
                    } 
                }
                
                if (configTabuleiro == 2){
                    if (x >= 1 && x <= 5 && y >= 1 && y <= 6) {
                    usuarioMovePecaTerminal = 1;
                    } else {
                        printf("[!] Erro2: Coordenadas inválidas\n\n");
                        help();
                        return 1;
                    }
                }
            }
        }
    }

    printf("Tabuleiro: %d\n", configTabuleiro);
    if (usuarioMovePecaTerminal == 1){
        printf("Coordenadas: %d, %d\n", x,y);
        printf("Direção do movimento: %c\n\n", direcao);
    }

    configTabuleiro == 1 ? copiarMatriz(tabuleiro1) : copiarMatriz(tabuleiro2);
    printarTabuleiro(configTabuleiro);

    char letra = encontrarLetra(x,y);
    char tipo = checarTipoPeca(letra);
    moverDirecao(direcao, tipo, letra);
    printf("\n");
    printarTabuleiro(configTabuleiro);

    return 0;
}