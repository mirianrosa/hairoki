
# Hakoiri Musume

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

![Figura 1: Configuração 1](/img/config1.png)

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

![Figura 2: Configuração 2](/img/config2.png)

A figura 2 possui a seguinte representação:

\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*

\*&nbsp;&nbsp;D&nbsp;D&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;a&nbsp; a&nbsp;b&nbsp; *

\*&nbsp;&nbsp;D&nbsp;D&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;a&nbsp; c&nbsp;d&nbsp; *

\*&nbsp;&nbsp;e&nbsp;&nbsp;e&nbsp; f&nbsp; g&nbsp;&nbsp;d d&nbsp; *

\*&nbsp;&nbsp;h&nbsp; h&nbsp; i&nbsp;&nbsp; j&nbsp;&nbsp; k&nbsp; l

\*&nbsp; h&nbsp;&nbsp; i&nbsp;&nbsp;i&nbsp; m&nbsp; k&nbsp; l

\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*&nbsp;&nbsp;\*

## Fase 1

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

## Fase 2

Modique seu programa anterior para ele agora ler de um arquivo a conguração da matriz de
entrada.
Seu novo programa deve agora ter os parâmetros -f nomeArquivo.txt no qual o arquivo
contém uma ou mais congurações de peças, seguindo as regras anteriores. Pesquise no livro
ou na Internet como abrir e ler um arquivo texto em C. A sintaxe de seu arquivo deve conter
um nome do problema e logo em seguida a conguração desejada. O nome default do arquivo é
hakoiri.txt, que deve ser escolhido se nenhuma opção for apresentada.
Assim, se você digitar:
hakoiri ele carrega o arquivo hakoiri.txt.
Porém, se for digitado:
hakoiri -f meuarquivo.txt,
deve ser carregado o arquivo meuarquivo.txt.
O arquivo deve usar a seguinte configuração (nome seguido do problema, com uma linha
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
\*********  

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


## Fase Final

Coloque a configuração inicial numa árvore (não binária) e acrescente o comando **s** ao seu programa. Ao receber este comando, seu programa deve criar um nível na árvore com outras configurações resultantes de possíveis movimentos da árvore anterior. Seu programa deve imprimir na tela essas configurações numeradas de 1 a n (o número máximo de possíveis movimentos). 
No próximo movimento, o usuário deve poder escolher um número entre 1 e n (das configurações apresentadas) e seu programa deve gerar novas configurações a partir da configuração escolhida, de novo apresentando as possíveis configurações numeradas, repetindo o processo de escolha de número e geração de novas configurações a partir da configuração escolhida. A cada nova configuração gerada seu programa deve testar se atingiu uma posição de saída do labirinto, finalizando o jogo.

Implemente também o comando **r**, que faz seu programa procurar a saída do quebra-cabeças automaticamente sem intervenção do usuário. Ao final da execução, o programa deve apresentar o caminho de saída desde a configuração inicial até a resolução final do quebra-cabeças.

## Um pouco sobre o jogo de tabuleiro

[Klotski](https://pt.wikipedia.org/wiki/Klotski) (do polonês *klocki*–blocos de madeira) é um quebra-cabeça de blocos deslizantes que se acredita ter se originado no início do século XX. O nome pode se referir a um layout específico de dez blocos, ou em um sentido mais global, para se referir a todo um grupo de quebra-cabeças de blocos deslizantes semelhantes, onde o objetivo é mover um bloco específico para algum local predefinido.

Como outros quebra-cabeças de blocos deslizantes, várias peças de blocos de tamanhos diferentes são colocadas dentro de uma caixa. Entre os blocos, existe um especial (geralmente o maior) que deve ser movido para uma área designada pelo tabuleiro de jogo. O jogador não tem permissão para remover blocos e só pode deslizar blocos horizontalmente e verticalmente. Objetivos comuns são resolver o quebra-cabeça com um número mínimo de movimentos ou em um período mínimo de tempo.

O número mínimo de jogadas para o quebra-cabeça Klotski original, ilustrado na figura abaixo, é 81, que é verificado pelo computador como o mínimo absoluto para o layout inicial padrão, se você considerar deslizar uma única peça para qualquer posição acessível como uma única jogada.

![Figura 3: Em um quebra-cabeça de Klotski, o maior bloco deve ser movido para o local central do meio, para que possa deslizar sobre a borda, sem que nenhum dos outros blocos seja removido dessa maneira](/img/klotski.jpeg)

Existem várias variações deste jogo, algumas com nomes específicos para a cultura de certos países, outras com diferentes arranjos de blocos. As seguintes variações têm basicamente o mesmo layout e disposição dos blocos, variando apenas em nome (humano, animal ou outros), geralmente com algum tipo de história por trás dos nomes.

#### Huarong Dao

O jogo de madeira Huarong Dao, que data da década de 1930, segue o mesmo padrão de Klotski
Huarong Dao (também chamado Caminho Huarong ou Trilha Huarong) é a variação chinesa, baseada em uma história fictícia no romance histórico Romance dos Três Reinos sobre o senhor da guerra Cao Cao recuando pela Trilha Huarong (atualmente Jianli County, Jingzhou, Hubei) após sua derrota na Batalha dos Penhascos Vermelhos no inverno de 208/209 dC durante o final da Dinastia Han Oriental. Ele encontrou um general inimigo, Guan Yu, que estava guardando o caminho e esperando por ele. Guan Yu poupou Cao Cao e permitiu que o último passasse pela Trilha Huarong por conta do generoso tratamento que recebeu de Cao no passado. O maior bloco do jogo é chamado "Cao Cao".

![Figura 4: O jogo de madeira chinês Huarong Dao (華容道), que data da década de 1930, segue o mesmo padrão de Klotski](/img/klotskihuarong.jpeg)

#### Filha na caixa

O quebra-cabeça de madeira A Filha na Caixa (nome japonês: hakoiri musume 箱入り娘) mostra uma jovem inocente que não conhece nada do mundo presa em um prédio. A peça maior é chamada de "filha" e outros blocos recebem nomes de outros membros da família (como pai, mãe e assim por diante).
Outra variação japonesa usa os nomes de peças de shogi.

![Figura 5: Uma Filha na Caixa（箱入り娘）](/img/klotskidonzela.jpeg)

#### L'âne rouge
Na França, é conhecido como L'âne rouge. Apresenta um burro vermelho (a maior peça) tentando escapar de um labirinto de cercas e canetas para chegar às cenouras.

#### Khun Chang Khun Phaen
Esta é uma variação da Tailândia. Khun Phaen é um personagem famoso da lenda tailandesa, e o jogo recebeu o nome do épico poema Khun Chang Khun Phaen, no qual o personagem está preso. O jogo mostra Khun Phaen saindo da prisão superando suas nove sentinelas.

Há uma pequena diferença entre Khun Chang Khun Phaen e o layout padrão - os dois blocos 1×1 do meio são movidos para o fundo. Fora isso, todos os outros blocos são iguais. A origem dessa variação é desconhecida.


## Instalação

Para testar a solução deste repositório, rode:

```bash
  gcc hakoiri.c -o hakoiri && ./hakoiri
```

## Feedback

Se você tiver algum feedback, avise-me abrindo uma issue ou pull request!

