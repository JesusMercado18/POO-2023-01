#pragma once
#include <vector>
#include "Eclipse.h"

class CManejador{
private:
	vector<CEclipse*> vecEclipse;

public:
	CManejador(){}
	~CManejador(){}

	//--------------REALIZAMOS EL CRUD (C: CREATE; R: READ; U: UPDATE; D: DELETE)----------------

	void agregarEclipse(string fecha) {
		CEclipse* objEclipse = new CEclipse(fecha);
		vecEclipse.push_back(objEclipse);
	}

	void modificarTipoEclipse(int posicion, string tipoEclipse) {
		vecEclipse.at(posicion)->setTipoEclipse(tipoEclipse);
	}

	void borrarEclipsePosicion(int posicion) {
		vecEclipse.erase(vecEclipse.begin() + posicion);
	}

	void borrarEclipse() {
		vecEclipse.pop_back();
	}

	void imprimirDatosEclipses() {
		for (int i = 0; i < vecEclipse.size(); i++){
			cout << "Eclipse Nro. " << i << endl;
			vecEclipse[i]->datosEclipses();
		}
	}


	//---------------REPORTES--------------

	void eclipsesVisiblesEuropa() {
		for (int i = 0; i < vecEclipse.size(); i++){
			if (vecEclipse[i]->getVisibilidad() == "Europa") {
				vecEclipse[i]->datosEclipses();
			}
		}
	}

	void eclipsesOcasionaronSismos() {
		for (int i = 0; i < vecEclipse.size(); i++){
			if (vecEclipse[i]->getSismos() == "Si") {
				vecEclipse[i]->datosEclipses();
			}
		}
	}

	void eclipsesNoche() {
		for (int i = 0; i < vecEclipse.size(); i++){
			if (vecEclipse[i]->getHora() >= 1800) {
				vecEclipse[i]->datosEclipses();
			}
		}
	}

};