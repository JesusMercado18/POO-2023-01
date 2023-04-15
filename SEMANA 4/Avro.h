#pragma once
#include "Avion}.h"

class CAvro : public CAvion{
private:

public:
	CAvro(int x, int y) : CAvion(x, y){//HEREDANDO CONSTRUCTOR CON PARAMETROS
		dx = 2;
		dy = 2;
		ancho = 13; //EDITARLO LUEGO DE DIBUJAR
		alto = 3;
	}
	~CAvro(){}

	void dibujar() {
		Console::SetCursorPosition(x, y);     cout << "------------";
		Console::SetCursorPosition(x, y + 1); cout << "_\\__(_)__/_";
		Console::SetCursorPosition(x, y + 2); cout << "   ./ \\.   ";
	}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "            ";
		Console::SetCursorPosition(x, y + 1); cout << "            ";
		Console::SetCursorPosition(x, y + 2); cout << "            ";
	}
};