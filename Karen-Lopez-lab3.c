#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void inicializarLaberinto(char**);
void printLaberinto(char**);
void moverLaberinto(char**, char, int*, int*);
int columna(char**);
int fila(char**);
void random(char**, int*);

int main(int argc, char const *argv[])
{	
	int* puntosPtr;
	int puntos = 0;
	puntosPtr = &puntos;
	int* turnoPtr;
	int turno = 0;
	turnoPtr = &turno;
	char** laberinto = new char*[10];
	char movimiento;
	inicializarLaberinto(laberinto);
	printLaberinto(laberinto);
	do
	{
		random(laberinto, &turno);
		cin>>movimiento;
		moverLaberinto(laberinto, movimiento, &puntos, &turno);
		if (*puntosPtr<=0)
		{
			cout<<"Perdiste"<<endl;
			movimiento = '0';
			break;
		}
	} while (movimiento != '0');

	
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
    	j++; 
  	  	i += j/ 10;  
   		j= j % 10; 
  } 
  myfile.close();
}

void printLaberinto(char** laberinto){
	cout<<"Tu eres el 2, muevete a traves del laberinto con las teclas: s--> izquierda, d--> derecha, e--> arriba, x--> abajo. Para salir introduce 0"<<endl;
	for (int m = 0; m < 10; m++)
	{ 
	  	for (int n = 0; n < 10; n++)
	  	{
  			cout<<laberinto[m][n]<<" ";
  		}
  		cout<<endl;
  	}
}

void moverLaberinto(char** laberinto, char movimiento, int* puntosPtr, int* turnoPtr){
	int i = fila(laberinto);
	int j = columna(laberinto);
	switch(movimiento){
		case 's':
			if(laberinto[i][j-1] == '1') {
				laberinto[i][j] = ' ';
				laberinto[i][j-1] = '2';
				printLaberinto(laberinto);
				*puntosPtr= *puntosPtr + 1;
				*turnoPtr= *turnoPtr + 1;
				cout<<"Puntos: "<<*puntosPtr<<"  Turno: "<<*turnoPtr<<endl;
			}
			else if (laberinto[i][j-1] == ' ')
			{
				laberinto[i][j] = ' ';
				laberinto[i][j-1] = '2';
				printLaberinto(laberinto);
				*turnoPtr= *turnoPtr + 1;
				cout<<"Puntos: "<<*puntosPtr<<"  Turno: "<<*turnoPtr<<endl;
			}
			else if(laberinto[i][j-1] == '3') {
				cout<<"¡¡FELICIDADES!! encontraste la salida";
			}
			else if(laberinto[i][j-1] == '0'){
				cout<<"Movimiento no permitido, hay pared";
			}
			else if(laberinto[i][j-1] == '5'){
				laberinto[i][j] = ' ';
				laberinto[i][j-1] = '2';
				printLaberinto(laberinto);
				*puntosPtr= *puntosPtr - 5;
				*turnoPtr= *turnoPtr + 1;
				cout<<"Puntos: "<<*puntosPtr<<"  Turno: "<<*turnoPtr<<endl;
			}
			break;

		case 'd':
			if (j == 9)
			{
				cout<<"No se puede mover hacia adelante";
			}
			else if(laberinto[i][j+1] == '1') {
				laberinto[i][j] = ' ';
				laberinto[i][j+1] = '2';
				printLaberinto(laberinto);
				*puntosPtr= *puntosPtr + 1;
				*turnoPtr= *turnoPtr + 1;
				cout<<"Puntos: "<<*puntosPtr<<"  Turno: "<<*turnoPtr<<endl;
			}
			else if (laberinto[i][j+1] == ' ')
			{
				laberinto[i][j] = ' ';
				laberinto[i][j+1] = '2';
				printLaberinto(laberinto);
				*turnoPtr= *turnoPtr + 1;
				cout<<"Puntos: "<<*puntosPtr<<"  Turno: "<<*turnoPtr<<endl;
			}
			else if(laberinto[i][j+1] == '3') {
				cout<<"¡¡FELICIDADES!! encontraste la salida";
			}
			else if(laberinto[i][j+1] == '0'){
				cout<<"Movimiento no permitido, hay pared";
			}
			else if(laberinto[i][j+1] == '5'){
				laberinto[i][j] = ' ';
				laberinto[i][j+1] = '2';
				printLaberinto(laberinto);
				*puntosPtr= *puntosPtr - 5;
				*turnoPtr= *turnoPtr + 1;
				cout<<"Puntos: "<<*puntosPtr<<"  Turno: "<<*turnoPtr<<endl;
			}
			break;
		case 'x':
			if(laberinto[i+1][j] == '1') {
				laberinto[i][j] = ' ';
				laberinto[i+1][j] = '2';
				printLaberinto(laberinto);
				*puntosPtr= *puntosPtr + 1;
				*turnoPtr= *turnoPtr + 1;
				cout<<"Puntos: "<<*puntosPtr<<"  Turno: "<<*turnoPtr<<endl;
			}
			else if (laberinto[i+1][j] == ' ')
			{
				laberinto[i][j] = ' ';
				laberinto[i+1][j] = '2';
				printLaberinto(laberinto);
				*turnoPtr= *turnoPtr + 1;
				cout<<"Puntos: "<<*puntosPtr<<"  Turno: "<<*turnoPtr<<endl;
			}
			else if(laberinto[i+1][j] == '3') {
				cout<<"¡¡FELICIDADES!! encontraste la salida";
			}
			else if(laberinto[i+1][j] == '0'){
				cout<<"Movimiento no permitido, hay pared";
			}
			else if(laberinto[i+1][j] == '5'){
				laberinto[i][j] = ' ';
				laberinto[i+1][j] = '2';
				printLaberinto(laberinto);
				*puntosPtr= *puntosPtr - 5;
				*turnoPtr= *turnoPtr + 1;
				cout<<"Puntos: "<<*puntosPtr<<"  Turno: "<<*turnoPtr<<endl;
			}
			break;
		case 'w':
			if(laberinto[i-1][j] == '1') {
				laberinto[i][j] = ' ';
				laberinto[i-1][j] = '2';
				printLaberinto(laberinto);
				*turnoPtr= *turnoPtr + 1;
				*puntosPtr= *puntosPtr + 1;
				cout<<"Puntos: "<<*puntosPtr<<"  Turno: "<<*turnoPtr<<endl;
			}
			else if (laberinto[i-1][j] == ' ')
			{
				laberinto[i][j] = ' ';
				laberinto[i-1][j] = '2';
				printLaberinto(laberinto);
				*turnoPtr= *turnoPtr + 1;
				cout<<"Puntos: "<<*puntosPtr<<"  Turno: "<<*turnoPtr<<endl;
			}
			else if(laberinto[i-1][j] == '3') {
				cout<<"¡¡FELICIDADES!! encontraste la salida";
			}
			else if(laberinto[i-1][j] == '0'){
				cout<<"Movimiento no permitido, hay pared";
			}
			else if(laberinto[i-1][j] == '5'){
				laberinto[i][j] = ' ';
				laberinto[i-1][j] = '2';
				printLaberinto(laberinto);
				*puntosPtr= *puntosPtr - 5;
				*turnoPtr= *turnoPtr + 1;
				cout<<"Puntos: "<<*puntosPtr<<"  Turno: "<<*turnoPtr<<endl;
			}
			break;
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
void random(char** laberinto, int* turnoPtr){
	int randi;
	int randj;

    srand (time(NULL));
	if (*turnoPtr+1 !=0 && (*turnoPtr+1)%5 == 0)
	{
    	randi = rand() % 10;
    	randj = rand() % 10;
    	laberinto[randi][randj] = '5';
	}
}






