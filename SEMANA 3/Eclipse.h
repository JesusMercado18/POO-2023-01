#pragma once
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

//------ARREGLO O VECTOR DE OPCIONES-------
							//POS 0 | POS 1
string tiposEclipses[2] = { "Solar", "Lunar" };
string respuestas[2] = { "Si","No" };
string continentes[5] = { "America del sur","Europa","Africa","America del norte","Asia" };

class CEclipse{
private:
	string tipoEclipse;
	string fecha;
	int	   hora;
	string sismos;
	string lluvias;
	string visibilidad;

public:
	//-----CONSTRUCTOR------
	CEclipse(string fecha){
		tipoEclipse = tiposEclipses[rand() % 2];
		this->fecha = fecha;
		hora = (rand() % 24 + 1) * 100;
		sismos = respuestas[rand() % 2];
		lluvias = respuestas[rand() % 2];
		visibilidad = continentes[rand() % 5];
	}

	//-----DESTRUCTOR------
	~CEclipse(){}

	//-------GETs-------
	string getVisibilidad() { return visibilidad; }
	string getSismos() { return sismos; }
	int getHora() { return hora; }

	//-------SETs--------
	void setTipoEclipse(string tipoEclipse) { this->tipoEclipse = tipoEclipse; }

	//-------DATOS DE LOS ECLIPSES----------
	void datosEclipses() {
		cout << "Tipo de eclipse: " << tipoEclipse << endl;
		cout << "Fecha: " << fecha << endl;
		cout << "Hora: " << hora << endl;
		cout << "Sismos: " << sismos << endl;
		cout << "Lluvias: " << lluvias << endl;
		cout << "Visibilidad: " << visibilidad << endl;
	}
};