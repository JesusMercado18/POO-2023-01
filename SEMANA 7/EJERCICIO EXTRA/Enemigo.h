#pragma once
#include "Caracter.h"

class CEnemigo : public CCaracter{

public:
	CEnemigo() : CCaracter() {
		dx = rand() % 3 + 1;
		dy = rand() % 3 + 1;
		ancho = 4;
		alto = 2;
		visibilidad = true;
	}
	~CEnemigo(){}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "   ";
		Console::SetCursorPosition(x, y + 1); cout << "   ";
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x, y);     cout << " @ ";
		Console::SetCursorPosition(x, y + 1); cout << "¤|¤";
	}
};