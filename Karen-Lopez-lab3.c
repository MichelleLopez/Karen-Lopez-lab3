#include <iostream>
#include <fstream>
using namespace std;
void inicializarLaberinto(char**);
void printLaberinto(char**);
void moverLaberinto(char**, char, int);
int columna(char**);
int fila(char**);

int main(int argc, char const *argv[])
{	
	int puntos = 0;
	int* puntosPtr = &puntos;

	char** laberinto = new char*[10];
	char movimiento;
	inicializarLaberinto(laberinto);
	printLaberinto(laberinto);
	do
	{
		cin>>movimiento;
		moverLaberinto(laberinto, movimiento, puntos);
	} while (movimiento != '0');

	for (int i = 0; i < 19; i++) {
        delete[] laberinto[i];
    }
    delete[] laberinto;
	return 0;
}

void inicializarLaberinto(char** laberinto){
	for (int i = 0; i < 10; i++)
	{
		laberinto[i] = new char[10];
	}
	
	ifstream myfile("laberinto.txt");
	int i=0, j=0; 
  	while (!myfile.eof()) { 
    	myfile >> laberinto[i][j]; 
    	j++; //avanza en la fila 
  	  	i += j/ 10; //si pasó de N, le suma a 1 a i (siguiente columna) 
   		j= j % 10; //se asegura que esté entre 0 y N-1 
  } 
  myfile.close();
}

void printLaberinto(char** laberinto){
	cout<<"Tu eres la X, muevete a traves del laberinto con las teclas: s--> izquierda, d--> derecha, e--> arriba, x--> abajo. Para salir introduce 0"<<endl;
	for (int m = 0; m < 10; m++)
	{ 
	  	for (int n = 0; n < 10; n++)
	  	{
  			cout<<laberinto[m][n]<<" ";
  		}
  		cout<<endl;
  	}
}

void moverLaberinto(char** laberinto, char movimiento, int puntos){
	int i = fila(laberinto);
	int j = columna(laberinto);
	switch(movimiento){
		case 's':
			if (j == 0)
			{
				cout<<"No se puede retroceder";
			}
			else if(laberinto[i][j-1] == '1' || laberinto[i][j-1] == ' ') {
				laberinto[i][j] = ' ';
				laberinto[i][j-1] = '2';
				printLaberinto(laberinto);
			}
			else if(laberinto[i][j-1] == '3') {
				cout<<"¡¡FELICIDADES!! encontraste la salida";
			}

			else{
				cout<<"Movimiento no permitido, hay pared";
			}
			break;
		case 'd':
			if (j == 9)
			{
				cout<<"No se puede mover hacia adelante";
			}
			else if(laberinto[i][j+1] == '1' || laberinto[i][j+1] == ' ') {
				laberinto[i][j] = ' ';
				laberinto[i][j+1] = '2';
				printLaberinto(laberinto);
			}
			else if(laberinto[i][j+1] == '3') {
				cout<<"¡¡FELICIDADES!! encontraste la salida";
			}
			else{
				cout<<"Movimiento no permitido, hay pared";
			}
			break;
		case 'x':
			if(laberinto[i+1][j] != '0') {
				laberinto[i][j] = ' ';
				laberinto[i+1][j] = '2';
				printLaberinto(laberinto);
				
			}
			else{
				cout<<"Movimiento no permitido, hay pared";
			}
			break;
		case 'w':
			if(laberinto[i-1][j] != '0') {
				laberinto[i][j] = ' ';
				laberinto[i-1][j] = '2';
				printLaberinto(laberinto);
				
			}
			else{
				cout<<"Movimiento no permitido, hay pared";
			}
			break;
	}
			i = fila(laberinto);
			j = columna(laberinto);
			if (laberinto[i][j] == '3')
				{
					cout<<"!!FELICIDADES¡¡ Ha encontrado la salida";
				}
}

int columna(char** laberinto){
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(laberinto[i][j] == '2'){
				return j;
			}
		}
	}
}
int fila(char** laberinto){
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if(laberinto[i][j] == '2'){
				return i;
			}
		}
	}
}
