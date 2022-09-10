
# Haikori Musume

[![Escrito em C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](https://img.shields.io/badge/)

Existe uma antiga lenda japonesa sobre a ”Hakoiri Musume”, uma pequena donzela, que não sabe nada sobre o mundo e que está encarcerada numa caixa de ilusões. Seu caminho para
a liberdade é impedido por sua mãe, seu pai, irmãos e irmãs. Enquanto ela não sair desta
caixa, não conhecerá a luz da verdade.

Seu trabalho de programação deste semestre é ajudar a pobre Hakoiri Musume a encontrar seu caminho até a luz! Porém, neste mundo cheio de simbolismos da cultura japonesa, cada personagem será representado no computador por uma figura geométrica que corresponde
à inocência da personagem, mais que a forma física. Assim a nossa pobre Hakoiri Musume é representada pela maior figura do tabuleiro, representando que sua inocência a impede de
encontrar o caminho até a saída, enquanto sua família impõe dificuldades neste caminho.

As regras são simples: você deve levar a donzela até a saída da caixa, deslocando as outras
figuras para dar passagem. Neste nosso tabuleiro matemático, cada peça é representada por
um número e as casas vazias são representadas por zeros. O tabuleiro tem NxM casas com
as posições iniciais das peças. Uma figura só pode ser movimentada se existirem casas livres
suficientes para a movimentação e só pode ser movimentada na horizontal ou na vertical, nunca
na diagonal. Seu objetivo é levar a donzela até a porta de saída.

Por exemplo, a configuração 1 do tipo:

![Figura 1: Configuração 1](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/th5xamgrr6se0x5ro4g6.png)

Se atribuímos uma letra para cada tipo de peça, poderíamos ter:

\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*

\* &nbsp;a&nbsp;D&nbsp; D&nbsp;b&nbsp; \*

\* &nbsp;a&nbsp;D&nbsp; D&nbsp;b&nbsp; \*

\* &nbsp;c&nbsp;d&nbsp; d&nbsp; e&nbsp; \*

\* &nbsp;c&nbsp;g&nbsp; h&nbsp; e&nbsp; \*

\* &nbsp;f&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;i&nbsp; \*

\* \* &nbsp; &nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\* \*

Uma solução possível para este problema é o da força bruta, procurando todas as possibilidades até colocar a donzela na posição adequada do tabuleiro. Esta busca pode ser computacionalmente muito intensiva e você deve eliminar os caminhos já percorridos. Uma forma de
diminuir este trabalho seria armazenar cada movimento possível numa árvore (não binária). Se
cada possível configuração do tabuleiro possuir uma identifição única, se você atingir uma
configuração que já se encontra na árvore, você pode continuar a partir deste ponto.

![Figura 2: Configuração 2](https://dev-to-uploads.s3.amazonaws.com/uploads/articles/th5xamgrr6se0x5ro4g6.png)

A figura 2 possui a seguinte representação:

\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*

\*&nbsp;&nbsp;D&nbsp;D&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;a&nbsp; a&nbsp;b&nbsp; *

\*&nbsp;&nbsp;D&nbsp;D&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;a&nbsp; c&nbsp;d&nbsp; *

\*&nbsp;&nbsp;e&nbsp;&nbsp;e&nbsp; f&nbsp; g&nbsp;&nbsp;d d&nbsp; *

\*&nbsp;&nbsp;h&nbsp; h&nbsp; i&nbsp;&nbsp; j&nbsp;&nbsp; k&nbsp; l

\*&nbsp; h&nbsp;&nbsp; i&nbsp;&nbsp;i&nbsp; m&nbsp; k&nbsp; l

\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*

### Fase 1

Escreva um programa em C que receba argumentos da linha de comando que escolham a
configuração 1 ou 2 e também direcionem uma das peças para um movimento. A saída de seu
programa deve ser uma matriz com a peça pedida movimentada corretamente, se possível. Se
a configuração for inválida, ou seja, diferente de 1 ou 2, deve ser emitida mensagem de erro.
Também deve ser emitida mensagem de erro se não for possível movimentar a peça.

Os parâmetros são:

-cn:&nbsp;&nbsp;&nbsp;&nbsp;no qual n é a configuração 1 ou 2, ex. -n1 ou -n2. Se for o único comando, deve imprimir a
configuração pedida. O valor default, isto é, se não for especificada nenhuma configuração, é 1.

-m x y d:&nbsp;&nbsp;&nbsp;&nbsp;movimenta a peça que está nas coordenadas *(x,y)* para a direção *d*. As coordenadas
x e y começam em 1 e não levam em conta as paredes do jogo. Assim, na configuração **1** as
coordenadas vão de *1,1* até *5,4* e na configuração **2**, de *1,1* até *5,6*. O valor de **d** pode ser
**T, B, E ou D**, que representam, respectivamente movimentos para o **T**opo, para **B**aixo,
para **D**ireita ou **E**squerda. Após o comando, deve ser impressa a configuração inicial e a
configuração após o movimento. Se não for possível movimentar a peça, deve ser emitida mensagem de erro.

### Fase 2

Modique seu programa anterior para ele agora ler de um arquivo a conguração da matriz de
entrada.
Seu novo programa deve agora ter os parâmetros -f nomeArquivo.txt no qual o arquivo
contém uma ou mais congurações de peças, seguindo as regras anteriores. Pesquise no livro
ou na Internet como abrir e ler um arquivo texto em C. A sintaxe de seu arquivo deve conter
um nome do problema e logo em seguida a conguração desejada. O nome default do arquivo é
haikori.txt, que deve ser escolhido se nenhuma opção for apresentada.
Assim, se você digitar:
haikori ele carrega o arquivo haikori.txt.
Porém, se for digitado:
haikori -f meuarquivo.txt,
deve ser carregado o arquivo meuarquivo.txt.
O arquivo deve usar a seguinte conguração (nome seguido do problema, com uma linha
separando cada uma delas):

Floco de Neve  
\******  
\*aDDb*  
\*aDDb*  
\*cdde*  
\*cghe*  
\*f&nbsp;&nbsp;j*  
\** **  

Engarrafamento  
\********  
\*DD aab*  
\*DD acd*  
\*eefgdd*  
\*hhijkl  
\*hiimkl  
********  

As opções anteriores deixam de existir e agora o programa, após ler o arquivo, entra no modo
interativo.  
No modo interativo, o programa pode receber os comandos l, c <n> e, m <linha> <coluna>
<direção> (seguidos de *enter*)

Comandos:

l&nbsp;&nbsp;&nbsp;&nbsp;listar todas as opções numeradas dos problemas que podem ser escolhidos.

c <n>&nbsp;&nbsp;&nbsp;&nbsp;escolhe a conguração de número <n> do arquivo. Usar este comando depois de ter
carregado uma conguração faz o programa perguntar se o usuário realmente quer isso,
pois vai perder tudo que foi feito na conguração anterior.

m <linha> <coluna> <direção>&nbsp;&nbsp;&nbsp;&nbsp;movimenta a peça que está na posição **linha, coluna** na direção escolhida entre **T, B, E** ou **D** (Topo, Baixo, Esquerda e Direita, respectivamente). O programa deve apresentar a nova conguração com o movimento executado e
um contador de movimentos, além de numerar as linhas e colunas para facilitar a escolha
dos movimentos. A sequência de movimentos deve ser guardada para futuras impressões.
Não existe limite para o número de movimentos.

p&nbsp;&nbsp;&nbsp;&nbsp;imprime todos os movimentos executados até o momento, desde a conguração inicial.

Se o usuário digitar uma opção inválida, o programa deve emitir mensagem de erro e apre-
sentar as opções válidas. Note o espaçamento entre as letras. Seu programa deve identicar comandos ou movimentos inválidos


### Fase Final

Coloque a configuração inicial numa árvore (não binária) e acrescente o comando **s** ao seu programa. Ao receber este comando, seu programa deve criar um nível na árvore com outras configurações resultantes de possíveis movimentos da árvore anterior. Seu programa deve imprimir na tela essas configurações numeradas de 1 a n (o número máximo de possíveis movimentos). 
No próximo movimento, o usuário deve poder escolher um número entre 1 e n (das configurações apresentadas) e seu programa deve gerar novas configurações a partir da configuração escolhida, de novo apresentando as possíveis configurações numeradas, repetindo o processo de escolha de número e geração de novas configurações a partir da configuração escolhida. A cada nova configuração gerada seu programa deve testar se atingiu uma posição de saída do labirinto, finalizando o jogo.

Implemente também o comando **r**, que faz seu programa procurar a saída do quebra-cabeças automaticamente sem intervenção do usuário. Ao final da execução, o programa deve apresentar o caminho de saída desde a configuração inicial até a resolução final do quebra-cabeças.

## Instalação

Para testar a solução deste repositório, rode:

```bash
  gcc hairoki.c -o hairoki
```

## Feedback

Se você tiver algum feedback, avise-me abrindo uma issue ou pull request!

