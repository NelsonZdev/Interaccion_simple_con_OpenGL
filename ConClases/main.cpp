#include <iostream>
#include <GL/freeglut.h>
#include "escena.h"


using namespace std;

int main (int argc,char* argv[]){
	system("clear");
	cout<<"********* Inicio Programa **********"<<endl;
	cout<<"** Desarrollado por Nelson Zapata **"<<endl;
	glutInit(&argc,argv);                      //Inicia el glut
	Escena escena1;
	glutMainLoop();     
	system("clear");
	return 0;
}
