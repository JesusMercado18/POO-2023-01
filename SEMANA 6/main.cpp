#include "Controlador.h"

int main() {
	srand(time(NULL));
	Console::CursorVisible = false;
	int tiempo = 600;
	char key;
	CControlador* objControlador = new CControlador();

	while (true){
		Console::SetCursorPosition(15, 45); cout << "                         ";
		Console::SetCursorPosition(15, 45); cout << "Tiempo: " << tiempo / 10;

		objControlador->borrarTodo();
		if (objControlador->colisionCarro())break;
		if (objControlador->colisionBus())break;
		objControlador->colisionBici();

		if (_kbhit()) {
			key = _getch();
			key = toupper(key);
			objControlador->getPersona()->moverPersona(key);
		}

		objControlador->moverVehiculos();
		objControlador->dibujarTodo();

		_sleep(100);
		tiempo--;
		if (tiempo == 0)break;
	}

	cout << "PERDISTE :(";

	_getch();
	return 0;
}