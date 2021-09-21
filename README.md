# Computer-Graphics_Study-Introduction
Repository for personal studies in computer graphics using C++ and C#.

# Bomberman 2D [Jogo em construção]

## Objetivo:<br/>
Destruir obstáculos e inimigos em busca itens especiais para avançar os níveis. 

## Jogabilidade:<br/> 
Setas direcionais = Movem o personagem<br/>
Espaço/Enter = Lança a bomba de destruição

## Itens:<br/>
* Bomba: Explode em forma de "+" destruindo paredes ou inimigos.<br/>
* Baú: Pode conceder carta especial love potion e/ou key.<br/>
* Blocos: Ao serem destruídos podem conceder cartas especiais.<br/>
* Carta Especial Bomba: Aumenta em 1 a capacidade de bombas a serem plantadas simultâneamente.<br/>
* Carta Especial Speed: Aumenta a velocidade do jogador.<br/> 
* Carta Especial Ranged: Aumenta em 1 bloco o tamanho de explosão da bomba.

## Dicas:<br/> 
* Ao início do jogo, o jogador receberá 3 life potions e cada uma terá a duração de 1min, ao zerar, o jogador perde.<br/> 
* Fique longe de inimigos, 1 life potion será perdida a cada ataque sofrido.<br/> 
* Cuidado ao destruir bombas pelo mapa, 1 life potion será perdida a cada auto-ataque sofrido.<br/> 
* Colete 3 keys pelo mapa para passar de fase.

## Telas:<br/> 
[1] Início = Play || Exit<br/> 
[2] Jogo = Apenas setas direcionais, tecla espaço e tecla ESC serão lidas. (ESC em qualquer momento do jogo irá retornar a tela de Início.<br/> 
[3] Game Over = Try Again || Exit<br/> 


## REFERÊNCIAS:<br/> 
[1] [Introdução a Computação Gráfica] http://www-usr.inf.ufsm.br/~pozzer/ <br/> 
[2] [Manipulação de Imagens] https://www.inf.pucrs.br/~pinho/CG-PPGCC/PraticaOpenGLImagens/ImageClass.html
<br/> 
<br/> 
<br/> 
## NOTA DE ALTERAÇÃO 21/09/2021<br/> 
*collision system for character and enemies on walls and chests;<br/> 
*reorganizing blocks_stones (still needs attention);<br/> 
*rearranging blocks_bau (done).<br/> 
<br/> 
<br/> 
### Next Step:<br/> 
* * creation of the reward system;<br/>                  
* * bomb activation and block destruction;<br/>          
* * texture insertion;<br/>                             
* * code scope redundancy analysis; <br/>                
* * start screen creation, finish and adjustments. <br/> 
<br/>
<br/> 
Desenvolvido por Mauren Walter D'Avila<br/> 
Acadêmica do 7° Semestre de Engenharia de Computação
