#include <iostream>
#include <GL/freeglut.h>

float _255To1(unsigned int value = 255);

double posX = 0;
double posY = 0;

int direccionX = 0;
int direccionY = 0;

const char* nombreVentana = "Escena Principal";

using namespace std;

void G_Display();
void Teclado (unsigned char input = ' ', int x = 0,int y = 0);
void TeclasExtra(int input = 0, int x = 0, int y = 0);
void Update();
void Draw();
void Awake();
void StartOpenGL(int argc,char** argv);

int main (int argc,char** argv)
{
	system("clear");
	cout<<"Programa ceado por Nelson Zapata"<<endl;
	cout<<"\n***** Inicio del programa junto a OpenGL :)*****"<<endl;

	StartOpenGL(argc, argv);

	cout<<"\n\n****** Fin del programa *******\n"<<endl;
	cout<<"Preciona enter para salir"<<endl;
	cin.get();
	system("clear");
	return 0;
}

void StartOpenGL(int argc,char** argv){
	glutInit(&argc,argv);                      //Inicia el glut
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE); //Modo de reprecentacion de video (RGB|buffer doble)
	glutInitWindowSize(800,600);               //Establece tamaño de pantalla
	glutInitWindowPosition(10,10);             //Ubica la pantalla generada en (x,y)ubicacion
	glutCreateWindow(nombreVentana);		   //Asigna un nombre a la pantalla
	glutDisplayFunc(G_Display);                //Declara callbacks / Establece el modo de reprecentacion
	Awake();	
	glutIdleFunc(Update);					   //Mantiene la escena en un bucle	   
	glutKeyboardFunc(Teclado);
	glutSpecialFunc(TeclasExtra);
	glutMainLoop();                            //Ingresa en un bucle de deteccion de eventos
}

void G_Display(){ 								//Envia la informacion de la pantalla al monitor
	glClear(GL_COLOR_BUFFER_BIT);

	Draw();

	glutSwapBuffers();                          
}

void Awake(){
	glClearColor(_255To1(55),_255To1(205),_255To1(205),_255To1());                   //Limpia la patalla con un parametro (rgbA) asignado 0 min / 1 Max
	glPointSize(5);                             //Establece el tamaño de dibujado de puntos
	glOrtho(0,800,600,0,-1,1);                  //Establece un tipo de camara y sus propiedades
	glMatrixMode(GL_MODELVIEW);					//Modo de reprecentacion de la matriz de dibujado
	glLoadIdentity();
}

void Draw(){
	glBegin(GL_POINTS);                          //Inicia el dibujado
	
	glPushMatrix();

	glColor3f(1,0,0);                            //Establece el color de dibujado
	
	glVertex2f(0.0f,0.0f);
	glVertex2f(posX,posY);

	glEnd();									 //Termina el dibujado
	glPopMatrix();
}

void Teclado (unsigned char input, int x,int y){
	switch (input)
	{
	case 'w':
		direccionX = 0;
		direccionY = 1;
		break;
	case 'a':
		direccionX = -1;
		direccionY = 0;
		break;
	case 's':
		direccionX = 0;
		direccionY = -1;
		break;
	case 'd':
		direccionX = 1;
		direccionY = 0;
		break;
	
	default:
		direccionX = 0;
		direccionY = 0;
		break;
	}
}

void TeclasExtra(int input, int x, int y){
	if (input == GLUT_KEY_F4)
	{
		exit(1);
	}
	
}

void Update(){
	if (direccionX != 0)
	{
		posX =(posX < 0.99f && posX > -0.99f)? posX + (0.01f * direccionX):posX * -0.98f;
	}
	if (direccionY != 0)
	{
		posY =(posY < 0.99f && posY > -0.99f)? posY + (0.01f * direccionY) : posY * -0.98f;
	}
	glutPostRedisplay();
}

float _255To1(unsigned int value){
	float resultado;
	if (value != 0)
	{
		resultado = (float)value/255;;
	}else
	{
		resultado = value;
	}
	return resultado;
}


