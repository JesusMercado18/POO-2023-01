#pragma once
#include "Ovni.h"

class CRazaBeta : public COvni{
private:

public:
	CRazaBeta(int x, int y) : COvni(x, y){
		dy = 3;
		ancho = 12; //LUEGO DE DIBUJAR EDITAMOS
		alto = 3;
	}
	~CRazaBeta(){}

	void dibujar() {
		Console::SetCursorPosition(x, y);	  cout << "   .---.   ";
		Console::SetCursorPosition(x, y + 1); cout << " _/__~0_\_ ";
		Console::SetCursorPosition(x, y + 2); cout << "(_________)";
	}

	void borrar() {
		Console::SetCursorPosition(x, y);	  cout << "           ";
		Console::SetCursorPosition(x, y + 1); cout << "           ";
		Console::SetCursorPosition(x, y + 2); cout << "           ";
	}
};