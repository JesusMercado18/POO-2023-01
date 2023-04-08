#include "Manejador.h"

void menu() {
	cout << "1. Agregar eclipse" << endl;
	cout << "2. Modificar eclipse" << endl;
	cout << "3. Borrar en posicion" << endl;
	cout << "4. Borrar el ultimo" << endl;
	cout << "5. Imprimir datos" << endl;
	cout << "6. Visibles Europa" << endl;
	cout << "7. Ocasionaron sismos" << endl;
	cout << "8. En la noche" << endl;
}

int main() {
	srand(time(NULL));
	int opcion, posicion;
	string fecha;
	string tipoEclipse;
	CManejador* objManejador = new CManejador();

	while (true){
		menu(); cout << "Ingrese una opcion: "; cin >> opcion;

		switch (opcion) {
		case 1:
			cout << "Ingrese fecha: "; cin >> fecha;
			objManejador->agregarEclipse(fecha);
			cout << "SE INGHRESO CON EXITO" << endl;
			break;
		case 2:
			cout << "Ingrese una posicino a modificar: "; cin >> posicion;
			cout << "Ingrese nuevo valor: "; cin >> tipoEclipse;
			objManejador->modificarTipoEclipse(posicion, tipoEclipse);
			cout << "SE INGHRESO CON EXITO" << endl;
			break;
		case 3:
			cout << "Ingrese una posicino a borrar: "; cin >> posicion;
			objManejador->borrarEclipsePosicion(posicion);
			break;
		case 4:
			objManejador->borrarEclipse();
			break;
		case 5:
			objManejador->imprimirDatosEclipses();
			break;
		case 6:
			objManejador->eclipsesVisiblesEuropa();
			break;
		case 7:
			objManejador->eclipsesOcasionaronSismos();
			break;
		case 8:
			objManejador->eclipsesNoche();
			break;
		}
		//---OPCIONAL---
		_getch();
		system("cls");
	}

	_getch();
	return 0;
}