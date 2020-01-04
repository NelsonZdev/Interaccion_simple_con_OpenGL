//escena.h
#ifndef __escena_h__
#define __escena_h__
#include <GL/freeglut.h>

class Escena
{
private:
    static double posX ;
    static double posY ;
    static int direccionX ;
    static int direccionY ;
public:
    Escena();

    static float _255To1(unsigned int value = 255);
    static void G_Display();
    static void Teclado (unsigned char input = ' ', int x = 0,int y = 0);
    static void TeclasExtra(int input = 0, int x = 0, int y = 0);
    static void Awake();
    static void Update();
    static void Draw();
};
#endif