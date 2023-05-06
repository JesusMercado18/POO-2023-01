#pragma once
#include "Caracter.h"

class CVirus : public CCaracter{
private:
public:
	CVirus() : CCaracter(){
		dx = rand() % 3 + 1;
		dy = rand() % 3 + 1;
		ancho = 12;
		alto = 5;
	}
	~CVirus(){}

	void dibujar() {
		Console::SetCursorPosition(x, y);     cout << "     q     ";
		Console::SetCursorPosition(x, y + 1); cout << "  o.-o-.o  ";
		Console::SetCursorPosition(x, y + 2); cout << "o-(o o o)-o";
		Console::SetCursorPosition(x, y + 3); cout << "  o._o_.o  ";
		Console::SetCursorPosition(x, y + 4); cout << "     b     ";
	}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "           ";
		Console::SetCursorPosition(x, y + 1); cout << "           ";
		Console::SetCursorPosition(x, y + 2); cout << "           ";
		Console::SetCursorPosition(x, y + 3); cout << "           ";
		Console::SetCursorPosition(x, y + 4); cout << "           ";
	}

	//MOVER REBOTE
	void mover() {
		if (x + dx <= 0 || x + dx + ancho >= 70) dx *= -1;
		if (y + dy <= 0 || y + dy + alto >= 50) dy *= -1;

		x += dx;
		y += dy;
	}
};