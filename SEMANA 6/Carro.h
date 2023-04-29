#pragma once
#include "Terrestre.h"

class CCarro : public CTerrestre{
private:
public:
	CCarro() : CTerrestre(){
		dx = rand() % 3 + 2;
		ancho = 8;
		alto = 3;
	}
	~CCarro(){}

	void dibujar() {
		Console::SetCursorPosition(x, y);     cout << " __|~\_";
		Console::SetCursorPosition(x, y + 1); cout << "[__|_|-";
		Console::SetCursorPosition(x, y + 2); cout << "(_) (_)";
	}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "       ";
		Console::SetCursorPosition(x, y + 1); cout << "       ";
		Console::SetCursorPosition(x, y + 2); cout << "       ";
	}
};