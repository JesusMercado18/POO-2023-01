#pragma once
#include "Terrestre.h"

class CBus : public CTerrestre{
private:
public:
	CBus() : CTerrestre(){
		dx = rand() % 4 + 2;
		ancho = 14;
		alto = 3;
	}
	~CBus(){}

	void dibujar() {
		Console::SetCursorPosition(x, y);     cout << " _/_|[][][][]";
		Console::SetCursorPosition(x, y + 1); cout << "(           |";
		Console::SetCursorPosition(x, y + 2); cout << "=-OO     OO-=";
	}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "             ";
		Console::SetCursorPosition(x, y + 1); cout << "             ";
		Console::SetCursorPosition(x, y + 2); cout << "             ";
	}
};