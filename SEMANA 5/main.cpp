#include "Controlador.h"

int main() {
	char key;
	CControlador* objControlador = new CControlador();

	cout << "COMIENZA LA INVASION....!!!" << endl;

	while (objControlador->totalOvnis() < 20){
		objControlador->borrarTodo();
		if (_kbhit()) {
			key = _getch();
			key = toupper(key);
			switch (key){
			case 'A':
				objControlador->agregarAlfa();
				if (objControlador->getSizeAlfa() % 2 == 0) { objControlador->agregarBeta(); }
				if (objControlador->getSizeBeta() % 2 == 0 && objControlador->getSizeAlfa() % 4 == 0) { objControlador->agregarGamma(); }
				break;
			}
		}
		//PARA MOVER EN REBOTE
		//objControlador->moverTodoRebote();
		
		//PARA MOVER EN CAIDA
		objControlador->eliminarCaidos();
		objControlador->moverTodoCaida();


		objControlador->dibujarTodo();

		_sleep(100);
	}

	system("cls");
	Console::SetCursorPosition(20, 20); cout << "HEMOS SIDO INVADIDOS....!!! :(";

	_getch();
	return 0;
}