#pragma once
#include "Avion}.h"

class CLineaNazca : public CAvion{
private:

public:
	CLineaNazca() : CAvion(){//HEREDANDO CONSTRUCTOR SIN PARAMETROS
		ancho = 13; //EDITARLO LUEGO DE DIBUJAR
		alto = 4;
	}
	~CLineaNazca(){}

	void dibujar() {
		Console::SetCursorPosition(x, y);     cout << " ||     ||  ";
		Console::SetCursorPosition(x, y + 1); cout << " \\  () //  ";
		Console::SetCursorPosition(x, y + 2); cout << " // (__) \\ ";
		Console::SetCursorPosition(x, y + 3); cout << " ||      || ";
	}

	void borrar() {
		Console::SetCursorPosition(x, y);     cout << "            ";
		Console::SetCursorPosition(x, y + 1); cout << "            ";
		Console::SetCursorPosition(x, y + 2); cout << "            ";
		Console::SetCursorPosition(x, y + 3); cout << "            ";
	}
};