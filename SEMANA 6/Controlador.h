#pragma once
#include "Persona.h"
#include "Bicicleta.h"
#include "Bus.h"
#include "Carro.h"
#include <vector>

class CControlador{
private:
	CPersona* objPersona;
	vector<CBicicleta*> vecBici;
	vector<CBus*> vecBus;
	vector<CCarro*> vecCarro;

public:
	CControlador(){
		objPersona = new CPersona(40, 45);
		for (int i = 0; i < 2; i++){
			vecBici.push_back(new CBicicleta());
			vecBus.push_back(new CBus());
			vecCarro.push_back(new CCarro());
		}
	}
	~CControlador(){}

	void borrarTodo() {
		objPersona->borrar();
		for (int i = 0; i < vecBici.size(); i++){
			vecBici[i]->borrar();
		}
		for (int i = 0; i < vecBus.size(); i++){
			vecBus[i]->borrar();
		}
		for (int i = 0; i < vecCarro.size(); i++){
			vecCarro[i]->borrar();
		}
	}

	void moverVehiculos() {
		for (int i = 0; i < vecBici.size(); i++) {
			vecBici[i]->moverTransporte();
		}
		for (int i = 0; i < vecBus.size(); i++) {
			vecBus[i]->moverTransporte();
		}
		for (int i = 0; i < vecCarro.size(); i++) {
			vecCarro[i]->moverTransporte();
		}
	}

	void dibujarTodo() {
		objPersona->dibujar();
		for (int i = 0; i < vecBici.size(); i++) {
			vecBici[i]->dibujar();
		}
		for (int i = 0; i < vecBus.size(); i++) {
			vecBus[i]->dibujar();
		}
		for (int i = 0; i < vecCarro.size(); i++) {
			vecCarro[i]->dibujar();
		}
	}

	//---------COLISIONES---------

	bool colisionCarro() {
		for (int i = 0; i < vecCarro.size(); i++){
			//OBTIENDO Y ASIGNANDO VALORES PARA LA PERSONA
			int x1 = objPersona->getX(); int y1 = objPersona->getY();
			int ancho1 = objPersona->getAncho(); int alto1 = objPersona->getAlto();
			//OBTIENDO Y ASIGNANDO VALORES PARA EL CARRO
			int x2 = vecCarro[i]->getX(); int y2 = vecCarro[i]->getY();
			int ancho2 = vecCarro[i]->getAncho(); int alto2 = vecCarro[i]->getAlto();
			//VALIDANDO COLISION ENTRE CARRO Y PERSONA
			if (!(x1 + ancho1 < x2 || y1 + alto1 < y2 || x1 > x2 + ancho2 || y1 > y2 + alto2)) {
				return true;
			}
		}
	}

	bool colisionBus() {
		for (int i = 0; i < vecBus.size(); i++) {
			//OBTIENDO Y ASIGNANDO VALORES PARA LA PERSONA
			int x1 = objPersona->getX(); int y1 = objPersona->getY();
			int ancho1 = objPersona->getAncho(); int alto1 = objPersona->getAlto();
			//OBTIENDO Y ASIGNANDO VALORES PARA EL BUS
			int x2 = vecBus[i]->getX(); int y2 = vecBus[i]->getY();
			int ancho2 = vecBus[i]->getAncho(); int alto2 = vecBus[i]->getAlto();
			//VALIDANDO COLISION ENTRE Bus Y PERSONA
			if (!(x1 + ancho1 < x2 || y1 + alto1 < y2 || x1 > x2 + ancho2 || y1 > y2 + alto2)) {
				return true;
			}
		}
	}

	void colisionBici() {
		for (int i = 0; i < vecBici.size(); i++) {
			//OBTIENDO Y ASIGNANDO VALORES PARA LA PERSONA
			int x1 = objPersona->getX(); int y1 = objPersona->getY();
			int ancho1 = objPersona->getAncho(); int alto1 = objPersona->getAlto();
			//OBTIENDO Y ASIGNANDO VALORES PARA EL Bici
			int x2 = vecBici[i]->getX(); int y2 = vecBici[i]->getY();
			int ancho2 = vecBici[i]->getAncho(); int alto2 = vecBici[i]->getAlto();
			//VALIDANDO COLISION ENTRE Bici Y PERSONA
			if (!(x1 + ancho1 < x2 || y1 + alto1 < y2 || x1 > x2 + ancho2 || y1 > y2 + alto2)) {
				objPersona->setX(40);
				objPersona->setY(45);
			}
		}
	}

	CPersona* getPersona() { return objPersona; }
};