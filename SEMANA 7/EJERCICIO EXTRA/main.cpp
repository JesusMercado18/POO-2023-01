#include "Controlador.h"

int main() {
	srand(time(NULL));
	Console::CursorVisible = false;
	int tiempo = 600;
	char key;
	CControlador* objControlador = new CControlador();


	while (tiempo != 0){
		Console::SetCursorPosition(1, 0); cout << "                                               ";
		Console::ForegroundColor = ConsoleColor::Cyan;
		Console::SetCursorPosition(1, 0); cout << "Puntos: " << objControlador->getPersona()->getPuntos();
		Console::SetCursorPosition(1, 1); cout << "                     ";
		Console::ForegroundColor = ConsoleColor::Cyan;
		Console::SetCursorPosition(1, 1); cout << "Tiempo: " << tiempo / 10;
		Console::SetCursorPosition(1, 2); cout << "                                               ";
		Console::ForegroundColor = ConsoleColor::Cyan;
		Console::SetCursorPosition(1, 2); cout << "Vida: " << objControlador->getPersona()->getVida();
		objControlador->borrarTodo();
		if (objControlador->colisionPersonaEnemigo())break; // objControlador->colisionPersonaEnemigo() == true
		objControlador->colisionBalaEnemigo();

		if (_kbhit()) {
			key = _getch();
			key = toupper(key);
			objControlador->getPersona()->moverPersona(key);
			if (key == 32) { objControlador->agregarBala(); }
		}

		objControlador->moverTodo();
		objControlador->dibujarTodo();

		_sleep(100);
		tiempo--;
	}

	cout << "GAME OVER";

	_getch();
	return 0;
}