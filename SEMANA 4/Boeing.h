#pragma once
#include "Avion}.h"

class CBoeing : public CAvion{
private:

public:
	CBoeing(int x, int y) : CAvion(x, y){//HEREDANDO CONSTRUCTOR CON PARAMETROS
		dx = 1;
		dy = 1;
		ancho = 20; //EDITARLO LUEGO DE DIBUJAR
		alto = 3;
	}
	~CBoeing(){}

	void dibujar() {
		Console::SetCursorPosition(x, y);     cout << "       __!__       ";
		Console::SetCursorPosition(x, y + 1); cout << "________(*)________";
		Console::SetCursorPosition(x, y + 2); cout << "       o/ \o       ";
	}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "                   ";
		Console::SetCursorPosition(x, y + 1); cout << "                   ";
		Console::SetCursorPosition(x, y + 2); cout << "                   ";
	}
};