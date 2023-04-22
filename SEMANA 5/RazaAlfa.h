#pragma once
#include "Ovni.h"

class CRazaAlfa : public COvni{
private:

public:
	CRazaAlfa(int x, int y) : COvni(x, y){
		dy = 1;
		ancho = 23; //LUEGO DE DIBUJAR EDITAMOS
		alto = 6;
	}
	~CRazaAlfa(){}

	void dibujar() {
		Console::SetCursorPosition(x, y);	  cout << "       _.---._        ";
		Console::SetCursorPosition(x, y + 1); cout << "        |   |         ";
		Console::SetCursorPosition(x, y + 2); cout << "       '     '        ";
		Console::SetCursorPosition(x, y + 3); cout << " _.-~===========~-._  ";
		Console::SetCursorPosition(x, y + 4); cout << "(___________________) ";
		Console::SetCursorPosition(x, y + 5); cout << "     \_________/      ";
	}

	void borrar() {
		Console::SetCursorPosition(x, y);	  cout << "                      ";
		Console::SetCursorPosition(x, y + 1); cout << "                      ";
		Console::SetCursorPosition(x, y + 2); cout << "                      ";
		Console::SetCursorPosition(x, y + 3); cout << "                      ";
		Console::SetCursorPosition(x, y + 4); cout << "                      ";
		Console::SetCursorPosition(x, y + 5); cout << "                      ";
	}
};