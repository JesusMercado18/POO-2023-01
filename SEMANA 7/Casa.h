#pragma once
#include "Caracter.h"

class CCasa : public CCaracter{
private:
public:
	CCasa(int x, int y) : CCaracter(x, y){
		ancho = 11; //LO CAMBIAMOS LUEGO DE DIBUJAR
		alto = 4;
	}
	~CCasa(){}

	void dibujar() {
		Console::SetCursorPosition(x, y);   cout << "  __I_    ";
		Console::SetCursorPosition(x, y+1); cout << " /\-_--\  ";
		Console::SetCursorPosition(x, y+2); cout << "/  \_-__\ ";
		Console::SetCursorPosition(x, y+3); cout << "|[]| [] | ";
	}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "          ";
		Console::SetCursorPosition(x, y + 1); cout << "          ";
		Console::SetCursorPosition(x, y + 2); cout << "          ";
		Console::SetCursorPosition(x, y + 3); cout << "          ";
	}
};