#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gl_canvas2d.h"

//#include "Bola.h"
//#include "Relogio.h"
#include "Bmp.h"

//#define life_potion 3
//#define ranged 1
//#define clock 3

int screenWidth = 621, screenHeight = 580; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.
//----- VARIABLES FUNCTION ENEMIES -----
int sense1 = 130, sense2, sense3 = 190, enemie_direction1, enemie_direction2, enemie_direction3;
//----- VARIABLES FUNCTION CHARACTER -----
int keypress = 0, position_x = 310, position_y = 271, distance3 = 0, life_potion = 3, lose = 0;
//----- VARIABLES FUNCTION CRASH TEST -----
int crash_up = 0, crash_down = 0, crash_left = 0, crash_right = 0, crash_up_bau = 0, crash_down_bau = 0, crash_left_bau = 0, crash_right_bau = 0;
int crash_left_bau_enemies = 0, crash_right_bau_enemies = 0;

int blocks_stones[58][4] ={611,571,10,529,   // superior
                            50,529,10,50,    // lateral esquerda
                            611,491,10,530,  // superior2
                            570,530,611,50,  // lateral direita
                            130,450,90,491,  // primeira camada de pedras
                            210,450,170,491,
                            290,450,250,491,
                            370,450,330,491,
                            450,370,410,491,
                            490,410,450,491, // atrás porta
                            530,370,490,491,
                            130,370,90,411,  // terceira camada de pedras
                            210,370,170,411,
                            290,370,250,411,
                            370,370,330,411,
                            571,291,490,331,
                            450,291,410,331, // divisória meio mapa
                            410,291,370,331,
                            370,291,330,331,
                            330,291,290,331,
                            290,291,250,331,
                            250,291,210,331,
                            210,291,170,331, // divisória meio mapa
                            130,291,50,331,
                            531,251,571,291,
                             90,251,50,291,
                            130,211,50,251,  // quinta camada de pedras
                            210,211,170,251,
                            290,211,250,251,
                            370,211,330,251,
                            450,211,410,251,
                            571,211,531,251,
                            531,211,490,251,
                             90,171,50,211,
                            531,171,571,211,
                            131,131,50,171,  // sexta camada de pedras
                            211,131,170,171,
                            291,131,250,171,
                            371,131,330,171,
                            451,131,410,171,
                            571,131,530,171,
                            530,131,490,171,
                            571,50,530,91,
                            530,50,490,91,    // última camada de pedras
                            490,50,450,91,
                            450,50,410,91,
                            410,50,370,91,
                            370,50,330,91,
                            330,50,290,91,
                            290,50,250,91,
                            250,50,210,91,
                            250,50,210,91,
                            210,50,170,91,
                            170,50,130,91,
                            130,50,90,91,
                             90,50,50,91,
                            611,50,10,10};     // inferior

int blocks_bau[28][4] = {90,450,50,491,   //  ----- BAÚS ÁREA SUPERIOR -----
                      170,450,130,491,
                      250,450,210,491,
                      330,450,290,491,
                      370,410,330,450,
                      370,330,330,370,
                      130,330,90,370,
                      250,370,210,410,
                      571,410,530,450,
                      571,370,530,410,
                      210,251,170,291,  //  ----- BAÚS ÁREA INFERIOR -----
                      250,251,210,291,
                      290,251,250,291,
                      370,251,330,291,
                      410,251,370,291,
                      450,251,410,291,
                      250,211,210,251,
                      250,171,210,211,
                      250,131,210,171,
                      410,211,370,251,
                      410,171,370,211,
                      410,131,370,171,
                       90,91,50,131,
                      130,91,90,131,
                      170,91,130,131,
                      490,91,450,131,
                      530,91,490,131,
                      570,91,530,131};

void fixed_blocks() {
    CV::color(0.5,0,0);
    CV::rectFill(blocks_stones[0][0],blocks_stones[0][1],blocks_stones[0][2],blocks_stones[0][3]); // superior

    CV::color(1,0.5,0);
    for(int i = 1; i<56 ; i++){
        CV::rectFill(blocks_stones[i][0],blocks_stones[i][1],blocks_stones[i][2],blocks_stones[i][3]);
    }

    CV::color(0.5,0,0);
    CV::rectFill(blocks_stones[56][0], blocks_stones[56][1], blocks_stones[56][2], blocks_stones[56][3]);    // inferior
}

void crash_test_up(int position_x, int position_y){
     for(int i=0;i<57;i++){
        if(((position_x <= blocks_stones[i][0]) && (position_x >= blocks_stones[i][2]))
         && (position_y+20 <= blocks_stones[i][3]) && (position_y+20 >= blocks_stones[i][1])){
            crash_up = -1;
        }
     }
}

void crash_test_down(int position_x, int position_y){
     for(int i=0;i<57;i++){
        if(((position_x <= blocks_stones[i][0]) && (position_x >= blocks_stones[i][2]))
         && (position_y-20 >= blocks_stones[i][1]) && (position_y-20 <= blocks_stones[i][3])){
            crash_down = -1;
        }
     }
}

void crash_test_left(int position_x, int position_y){
     for(int i=0;i<57;i++){
        if(((position_x-20 <= blocks_stones[i][0]) && (position_x-20 >= blocks_stones[i][2]))
         && (position_y >= blocks_stones[i][1]) && (position_y <= blocks_stones[i][3])){
            crash_left = -1;
        }
     }
}

void crash_test_right(int position_x, int position_y){
     for(int i=0;i<57;i++){
        if(((position_x+20 <= blocks_stones[i][0]) && (position_x+20 >= blocks_stones[i][2]))
         && (position_y >= blocks_stones[i][1]) && (position_y <= blocks_stones[i][3])){
            crash_right = -1;
        }
     }
}

void crash_test_up_bau(int position_x, int position_y){
     for(int i=0;i<28;i++){
        if(((position_x <= blocks_bau[i][0]) && (position_x >= blocks_bau[i][2]))
         && (position_y+20 <= blocks_bau[i][3]) && (position_y+20 >= blocks_bau[i][1])){
            crash_up_bau = -1;
        }
     }
}

void crash_test_down_bau(int position_x, int position_y){
     for(int i=0;i<28;i++){
        if(((position_x <= blocks_bau[i][0]) && (position_x >= blocks_bau[i][2]))
         && (position_y-20 >= blocks_bau[i][1]) && (position_y-20 <= blocks_bau[i][3])){
            crash_down_bau = -1;
        }
     }
}

void crash_test_left_bau(int position_x, int position_y){
     for(int i=0;i<28;i++){
        if(((position_x-20 <= blocks_bau[i][0]) && (position_x-20 >= blocks_bau[i][2]))
         && (position_y >= blocks_bau[i][1]) && (position_y <= blocks_bau[i][3])){
            crash_left_bau = -1;
        }
     }
}

void crash_test_right_bau(int position_x, int position_y){
     for(int i=0;i<28;i++){
        if(((position_x+20 <= blocks_bau[i][0]) && (position_x+20 >= blocks_bau[i][2]))
         && (position_y >= blocks_bau[i][1]) && (position_y <= blocks_bau[i][3])){
            crash_right_bau = -1;
        }
     }
}

void crash_test_left_bau_enemies(int position_x, int position_y){
     for(int i=0;i<28;i++){
        if(((position_x-20 <= blocks_bau[i][0]) && (position_x-20 >= blocks_bau[i][2]))
         && (position_y >= blocks_bau[i][1]) && (position_y <= blocks_bau[i][3])){
            crash_left_bau_enemies = -1;
        }
     }
}

void crash_test_right_bau_enemies(int position_x, int position_y){
     for(int i=0;i<28;i++){
        if(((position_x+20 <= blocks_bau[i][0]) && (position_x+20 >= blocks_bau[i][2]))
         && (position_y >= blocks_bau[i][1]) && (position_y <= blocks_bau[i][3])){
            crash_right_bau_enemies = -1;
        }
     }
}

void base_matrix(){
   for (int cont1 = 0 ; cont1 < 15 ; cont1++) {
       for (int cont2 = 0 ; cont2 < 15 ; cont2++){
            CV::color(0,1,0);
            CV::rectFill(10+(40*(cont1+1)), 10+(40*cont2), 10+(40*cont1), 10+(40*cont1));
       }
   }
}

void destructible_blocks(){
    CV::color(1,0,0);
//  ----- BAÚS ÁREA SUPERIOR -----
    for(int i = 0; i<10 ; i++){
        CV::rectFill(blocks_bau[i][0],blocks_bau[i][1],blocks_bau[i][2],blocks_bau[i][3]);
    }
//  ----- BAÚS ÁREA INFERIOR -----
    for(int i = 10; i<28 ; i++){
        CV::rectFill(blocks_bau[i][0],blocks_bau[i][1],blocks_bau[i][2],blocks_bau[i][3]);
    }
}

void enemies(){
    //-----INIMIGO ROTA SUPERIOR
    crash_test_left_bau_enemies(sense1,351);
    crash_test_right_bau_enemies(sense1,351);
    if((sense1 == 551) || (crash_right_bau_enemies == -1)){
        enemie_direction1 = 1;
    } crash_right_bau_enemies = 1;
    if((sense1 == 70) || (crash_left_bau_enemies) == -1) {
        enemie_direction1 = 0;
    } crash_left_bau_enemies = 1;
    if(enemie_direction1 == 1){
        sense1--;
    }
    if(enemie_direction1 == 0){
        sense1++;
    }
    CV::color(1); CV::circleFill(sense1,351,19,20);

    //-----INIMIGO ROTA INFERIOR
    crash_test_left_bau_enemies(sense3,111);
    crash_test_right_bau_enemies(sense3,111);
    if((sense3 == 551) || (crash_right_bau_enemies == -1)){
        enemie_direction3 = 1;
    } crash_right_bau_enemies = 1;
    if((sense3 == 70) || (crash_left_bau_enemies == -1)) {
        enemie_direction3 = 0;
    } crash_left_bau_enemies = 1;
    if(enemie_direction3 == 1){
        sense3--;
    }
    if(enemie_direction3 == 0){
        sense3++;
    }
    CV::color(1); CV::circleFill(sense3,111,19,20);

    /*distance3 = (2*(position_x - sense3) + 2*(position_y - 111))/2;
    if (distance3 < 19*2){
        life_potion --;
        if (life_potion = 0){
             lose = 1;
             printf("\n lose");
        }
    }*/
}

void character(){
    CV::color(1,1,1);
    switch (keypress){
        case 200:
            crash_test_left(position_x,position_y);
            crash_test_left_bau(position_x,position_y);
            if ((crash_left || crash_left_bau) == -1) {
                break;
            } else if ((crash_left || crash_left_bau) == 0){
                position_x -= 15;
            }
            break;
        case 201:
            crash_test_up(position_x,position_y);
            crash_test_up_bau(position_x,position_y);
            if ((crash_up || crash_up_bau) == -1) {
                break;
            } else if ((crash_up || crash_up_bau) == 0){
                position_y += 15;
            }
            break;
        case 202:
            crash_test_right(position_x,position_y);
            crash_test_right_bau(position_x,position_y);
            if ((crash_right || crash_right_bau) == -1) {
                break;
            } else if ((crash_right || crash_right_bau) == 0){
                position_x += 15;
            }
            break;
        case 203:
            crash_test_down(position_x,position_y);
            crash_test_down_bau(position_x,position_y);
            if ((crash_down || crash_down_bau) == -1) {
                break;
            } else if ((crash_down || crash_down_bau) == 0){
                position_y -= 15;
            }
            break;
        case 13: //Planta a bomba
            CV::color(1,0,0);
            CV::circleFill(position_x-1,position_y-1,13,4);
            break;
    }
    CV::circleFill(position_x,position_y,19,20);
    keypress = 0;
    crash_up = 0;
    crash_down = 0;
    crash_left = 0;
    crash_right = 0;
}

void render(){
   base_matrix();
   fixed_blocks();
   destructible_blocks();
   enemies();
   character();
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key)
{
    keypress = key;
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
   if (lose != 1){
     CV::run();
   }
}
