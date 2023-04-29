#pragma once
#include "Terrestre.h"

class CBicicleta : public CTerrestre{
private:
public:
	CBicicleta() : CTerrestre() {
		dx = 1;
		ancho = 7;
		alto = 2;
	}
	~CBicicleta(){}

	void dibujar() {
		Console::SetCursorPosition(x, y);     cout << " .._\ ";
		Console::SetCursorPosition(x, y + 1); cout << "(o)(o)";
	}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "      ";
		Console::SetCursorPosition(x, y + 1); cout << "      ";
	}
};