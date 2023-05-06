#pragma once
#include "Caracter.h"

class CPersona : public CCaracter{
private:
	char direccionP; //PARA OBTENER LA DIRECCION DE LA PERSONA Y PASARLA A LA BALA
	int punto;
	int vida;
public:
	CPersona(int x, int y) : CCaracter(x,y){
		dx = 1;
		dy = 1;
		ancho = 2;
		alto = 2;
		direccionP = 'D'; //INICIALMENTE DISPARA A LA DERECHA
		punto = 0;
		vida = 3;
	}
	~CPersona(){}

	char getDireccionP() { return direccionP; }
	int getPuntos() { return punto; }
	int getVida() { return vida; }

	void agregarPuntos() { punto++; }
	void DisminuirVida() { vida--; }

	void moverPersona(char key) {
		switch (key) {
		case 'A':
			if (x + dx >= 0) x -= dx;
			direccionP = 'A';
			break;
		case 'D':
			if (x + dx + ancho <= 70) x += dx;
			direccionP = 'D';
			break;
		case 'W':
			if (y + dy >= 0) y -= dy;
			direccionP = 'W';
			break;
		case 'S':
			if (y + dy + alto <= 50) y += dy;
			direccionP = 'S';
			break;
		}
	}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << " ";
		Console::SetCursorPosition(x, y + 1); cout << " ";
	}
	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Green;
		Console::SetCursorPosition(x, y);     cout << "@";
		Console::SetCursorPosition(x, y + 1); cout << char(197);
	}
};