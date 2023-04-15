#include "Controlador.h"

void menu() {
	cout << "LETRA A: AGREGAR AVRO" << endl;
	cout << "LETRA B: AGREGAR BOEING" << endl;
}

int main() {
	Console::CursorVisible = false;
	char key;
	
	menu();

	CControlador* objControlador = new CControlador();

	while (true){
		objControlador->borrarTodo();

		if (_kbhit()){
			key = _getch();
			key = toupper(key);
			if (key == 'A')objControlador->agregarAvro();
			if (key == 'B')objControlador->agregarBoeing();
		}

		objControlador->moverTodo();
		objControlador->dibujarTodo();

		_sleep(100);
	}

	_getch();
	return 0;
}