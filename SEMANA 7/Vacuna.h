#pragma once
#include "Caracter.h"

class CVacuna : public CCaracter{
private:
	int tipoMov;

public:
	CVacuna() : CCaracter(){
		tipoMov = rand() % 2;
		dx = rand() % 3 + 1;
		dy = rand() % 3 + 1;
		ancho = 5;
		alto = 1;
	}
	~CVacuna(){}

	void dibujar() {
		Console::SetCursorPosition(x, y); cout << "|->|";
	}

	void borrar() {
		Console::SetCursorPosition(x, y); cout << "    ";
	}

	void mover() {
		if (tipoMov == 0) { //MOVIMIENTO HORIZONTAL
			if (x + dx <= 0 || x + dx + ancho >= 70) dx *= -1;
			x += dx;
		}
		if (tipoMov == 1){ // MOVIMIENTO VERTICAL
			if (y + dy <= 0 || y + dy + alto >= 50) dy *= -1;
			y += dy;
		}
	}

};