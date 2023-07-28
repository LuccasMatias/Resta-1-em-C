# Resta 1 em C puro

*Mini jogo criado como avaliação acadêmica da matéria "Construção de algorítmos"*

A idéia desta avaliação foi de testar a capacidade de resolução de problemas e de raciocínio lógico, buscando a solução mais eficiente e computacionalmente econômica.**

#### Introdução

"O Resta Um é um passatempo bastante popular, cuja regra de jogo é muito
simples, mas o êxito nem tanto. Trata-se de um tabuleiro onde inicialmente há
32 peças distribuídas no formato de cruz, tal que a posição central esteja vazia.
Um movimento válido no jogo consiste em fazer com que uma peça “salte” sobre
outra (apenas uma) e ocupe uma posição vazia à frente dela. Em seguida, a
peça “saltada” deve ser retirada do tabuleiro. É importante destacar que os
movimentos devem ocorrer sempre na horizontal ou na vertical. O jogo termina
quando não é possível executar mais movimentos e, se nessa situação houver
apenas uma peça no tabuleiro, o jogador terá vencido o jogo."

A figura a seguir mostra a configuração inicial do jogo:

![Imagem ilustrativa da funcionalidade do jogo](https://i.pinimg.com/originals/3c/2c/a8/3c2ca84260ead6872ce0d52466f9cd89.gif)

### Requisitos exigidos pelo professor

Conhecendo as regras do jogo e os princípios de construção de algoritmos vistos
em sala de aula, construa um programa em C que simule um jogo de Resta
Um. Para melhorar a interatividade do usuário com o jogo, a execução de um
movimento deve cumprir com os seguintes passos:


1. escolha a peça a ser movida usando as teclas direcionais (esquerda), (direita), (para cima) e  (para baixo);

2. pressione <ENTER> para selecionar a peça;

3. escolha a posição de destino usando as teclas  (esquerda), (direita), (para cima) e  (para baixo);

4. pressione <ENTER> para mover a peça para a nova posição.

Ao final do jogo deve ser retornada uma mensagem indicando a quantidade de
peças restantes no tabuleiro e se o jogador venceu ou não o jogo.
