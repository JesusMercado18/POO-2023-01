#include "Controlador.h"

int main() {
	srand(time(NULL));
	int tiempo = 600;
	int cantVirus;
	char key;
	CControlador* objControlador;
	cout << "Ingrese la cantidad de virus: "; cin >> cantVirus;
	objControlador = new CControlador(cantVirus);
	Console::Clear();

	while (tiempo != 0){
		Console::SetCursorPosition(1, 0); cout << "                  ";
		Console::SetCursorPosition(1, 0); cout << "TIEMPO: " << tiempo / 10;
		Console::SetCursorPosition(1, 1); cout << "                  ";
		Console::SetCursorPosition(1, 1); cout << "INMUNIDAD: " << objControlador->getPersona()->getInmunidad();
		Console::SetCursorPosition(1, 2); cout << "                  ";
		Console::SetCursorPosition(1, 2); cout << "VIDA: " << objControlador->getPersona()->getVida();

		objControlador->borraTodo();
		if (tiempo % 100 == 0)objControlador->agregarVacuna(); // AGREGAMOS VACUNA CADA 10 SEGUNDOS
		if (objControlador->personaColisionCasa())break;// objControlador->personaColisionCasa()==true
		if (objControlador->personaColisionVirus())break;
		objControlador->personaColisionVacuna();
		if (objControlador->getPersona()->getCantMov() == 0) {
			objControlador->getPersona()->setInmunidad(false);
		}
		
		if (_kbhit()) {
			key = _getch();
			key = toupper(key);
			objControlador->getPersona()->mover(key);
		}

		objControlador->moverTodo();
		objControlador->dibujarTodo();

		_sleep(100);
		tiempo--;
	}

	cout << "GAME OVER"<<endl;
	cout << "MOVIMIENTOS TOTALES: " << objControlador->getPersona()->getCantMovTotal();

	_getch();
	return 0;
}