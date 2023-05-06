#pragma once
#include "Caracter.h"

class CPersona : public CCaracter {
private:
	int vida;
	bool inmunidad;
	int cantMov;
	int cantMovTotal;

public:
	CPersona(int x, int y) : CCaracter(x, y) {
		dx = 1;
		dy = 1;
		ancho = 2;
		alto = 2;
		inmunidad = false;
		cantMovTotal = 0; //PARA CONTAR LOS PASOS TOTALES
		cantMov = 0; //PARA ACTIVAR Y DESACTIVAR LA INMUNIDAD
		vida = 3;
	}
	~CPersona() {}

	//GETs PARA MOSTRAR EN PANTALLA VALORES
	int getVida() { return vida; }
	int getInmunidad() { return inmunidad; }
	int getCantMov() { return cantMov; }
	int getCantMovTotal() { return cantMovTotal; }

	//SETs PARA HACER CAMBIOS EN LOS ATRIBUTOS PROPIOS DE LA PERSONA
	void setInmunidad(bool inmunidad) { this->inmunidad = inmunidad; }
	void setCantMov(int cantMov) { this->cantMov = cantMov; }
	
	void disminuirVida() { vida--; }

	void mover(char key) {
		switch (key){
		case 'A':
			if (x + dx >= 0) x -= dx;
			cantMov--;
			cantMovTotal++;
			break;
		case 'D':
			if (x + dx + ancho <= 70) x += dx;
			cantMov--;
			cantMovTotal++;
			break;
		case 'W':
			if (y + dy >= 0) y -= dy;
			cantMov--;
			cantMovTotal++;
			break;
		case 'S':
			if (y + dy + alto <= 50) y += dy;
			cantMov--;
			cantMovTotal++;
			break;
		}
	}

	void dibujar() {
		Console::SetCursorPosition(x, y);     cout << "@";
		Console::SetCursorPosition(x, y + 1); cout << char(197);
	}

	void borrar() {
		Console::SetCursorPosition(x, y);    cout << " ";
		Console::SetCursorPosition(x, y +1); cout << " ";
	}

};