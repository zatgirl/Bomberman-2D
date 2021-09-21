#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

//#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"

//#include "Bola.h"
//#include "Relogio.h"
#include "Bmp.h"

#define life potion 3
#define ranged 1
#define clock 3

int screenWidth = 621, screenHeight = 580; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int d1 = 70, d2, d3 = 70, direcao_inimigo1, direcao_inimigo2, direcao_inimigo3;
int mkey = 0, mkeyx = 310, mkeyy = 271;

void matriz_base(){
   int j = 1;
   for (int cont1 = 0 ; cont1 < 15 ; cont1++) {
       for (int cont2 = 0 ; cont2 < 15 ; cont2++){
        CV::color(0,1,0);
        CV::rectFill(10+(40*(cont1+1)), 10+(40*cont2), 10+(40*cont1), 10+(40*cont1));
       }
   }
}

void blocos_fixos() {
    CV::color(0.5,0,0);
    CV::rectFill(611,571,10,529);  // superior
    CV::color(1,0.5,0);
    CV::rectFill(50,529,10,50);    // lateral esquerda
    CV::rectFill(611,491,10,530);  // superior2
    CV::rectFill(570,530,611,50);  // lateral direita
    CV::rectFill(130,450,90,491);  // primeira camada de pedras
    CV::rectFill(210,450,170,491);
    CV::rectFill(290,450,250,491);
    CV::rectFill(370,450,330,491);
    CV::rectFill(450,370,410,491);
    CV::rectFill(490,410,450,491); // atras porta
    CV::rectFill(530,370,490,491);
    CV::rectFill(130,370,90,411);  // terceira camada de pedras
    CV::rectFill(210,370,170,411);
    CV::rectFill(290,370,250,411);
    CV::rectFill(370,370,330,411);
    CV::rectFill(571,291,490,331); // divisória meio mapa
    CV::rectFill(450,291,170,331); // divisória meio mapa
    CV::rectFill(130,291,50,331);  // divisória meio mapa
    CV::rectFill(531,251,571,291); //
    CV::rectFill(90,251,50,291);   //
    CV::rectFill(130,211,50,251);  // quinta camada de pedras
    CV::rectFill(210,211,170,251);
    CV::rectFill(290,211,250,251);
    CV::rectFill(370,211,330,251);
    CV::rectFill(450,211,410,251);
    CV::rectFill(571,211,490,251);
    CV::rectFill(90,171,50,211);   //
    CV::rectFill(531,171,571,211); //
    CV::rectFill(131,131,50,171);  // sexta camada de pedras
    CV::rectFill(211,131,170,171);
    CV::rectFill(291,131,250,171);
    CV::rectFill(371,131,330,171);
    CV::rectFill(451,131,410,171);
    CV::rectFill(571,131,490,171);
    CV::rectFill(571,50,50,91);    // ultima camada
    CV::color(0.5,0,0);
    CV::rectFill(611,50,10,10);    // inferior
}

void blocos_destrutiveis(){
    CV::color(1,0,0);
//  ----- BAÚS ÁREA SUPERIOR -----
    CV::rectFill(90,450,50,491);
    CV::rectFill(170,450,130,491);
    CV::rectFill(250,450,210,491);
    CV::rectFill(330,450,290,491);
    CV::rectFill(370,410,330,450);
    CV::rectFill(370,330,330,370);
    CV::rectFill(130,330,90,370);
    CV::rectFill(250,370,210,410);
    CV::rectFill(571,410,530,450);
    CV::rectFill(571,370,530,410);

//  ----- BAÚS ÁREA INFERIOR -----
    CV::rectFill(210,251,170,291);
    CV::rectFill(250,251,210,291);
    CV::rectFill(290,251,250,291);
    CV::rectFill(370,251,330,291);
    CV::rectFill(410,251,370,291);
    CV::rectFill(450,251,410,291);
    CV::rectFill(250,211,210,251);
    CV::rectFill(250,171,210,211);
    CV::rectFill(250,131,210,171);
    CV::rectFill(410,211,370,251);
    CV::rectFill(410,171,370,211);
    CV::rectFill(410,131,370,171);
    CV::rectFill(90,91,50,131);
    CV::rectFill(130,91,90,131);
    CV::rectFill(170,91,130,131);
    CV::rectFill(490,91,450,131);
    CV::rectFill(530,91,490,131);
    CV::rectFill(570,91,530,131);
}

void inimigos(){
    //-----INIMIGO ROTA SUPERIOR
    if(d1 == 551){
        direcao_inimigo1 = 1;
    }
    if(d1 == 70) {
        direcao_inimigo1 = 0;
    }
    if(direcao_inimigo1 == 1){
        d1--;
    }
    if(direcao_inimigo1 == 0){
        d1++;
    }
    CV::color(1); CV::circleFill(d1,351,19,20);

    //-----INIMIGO ROTA INFERIOR
    if(d3 == 551){
        direcao_inimigo3 = 1;
    }
    if(d3 == 70) {
        direcao_inimigo3 = 0;
    }
    if(direcao_inimigo3 == 1){
        d3--;
    }
    if(direcao_inimigo3 == 0){
        d3++;
    }
    CV::color(1); CV::circleFill(d3,111,19,20);
}

void personagem(){
    CV::color(1,1,1);
    switch (mkey){
        case 200:
            mkeyx -= 1;
            break;
        case 201:
            mkeyy += 1;
            break;
        case 202:
            mkeyx += 1;
            break;
        case 203:
            mkeyy -= 1;
            break;
    }
    CV::circleFill(mkeyx,mkeyy,19,20);
    mkey = 0;
}

void render()
{
   matriz_base();
   blocos_fixos();
   blocos_destrutiveis();
   inimigos();
   personagem();
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
    mkey = key;
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
   printf("\nLiberou: %d" , key);
}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{

}

int main(void)
{

   CV::init(&screenWidth, &screenHeight, "Bomberman 2D");
   CV::run();
}
