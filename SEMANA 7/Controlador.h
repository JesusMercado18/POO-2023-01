#pragma once
#include "Persona.h"
#include "Vacuna.h"
#include "Virus.h"
#include "Casa.h"
#include <vector>

class CControlador{
private:
	CPersona* objPersona;
	CCasa* objCasa;
	vector<CVirus*> vecVirus;
	vector<CVacuna*> vecVacuna;

public:
	CControlador(int cantVirus){
		objPersona = new CPersona(4, 4);
		objCasa = new CCasa(60, 40);
		for (int i = 0; i < cantVirus; i++){
			vecVirus.push_back(new CVirus());
		}
	}
	~CControlador(){}

	void agregarVacuna() {
		CVacuna* objVacuna = new CVacuna();
		if (vecVacuna.size() <= 5) {//VALIDANDO QUE SOLO APAREZCAN 5 VACUNAS
			vecVacuna.push_back(objVacuna);
		}
	}

	void borraTodo() {
		objPersona->borrar();
		objCasa->borrar();
		for (int i = 0; i < vecVacuna.size(); i++){
			vecVacuna[i]->borrar();
		}
		for (int i = 0; i < vecVirus.size(); i++){
			vecVirus[i]->borrar();
		}
	}

	void moverTodo() {
		for (int i = 0; i < vecVacuna.size(); i++) {
			vecVacuna[i]->mover();
		}
		for (int i = 0; i < vecVirus.size(); i++) {
			vecVirus[i]->mover();
		}
	}

	void dibujarTodo() {
		objPersona->dibujar();
		objCasa->dibujar();
		for (int i = 0; i < vecVacuna.size(); i++) {
			vecVacuna[i]->dibujar();
		}
		for (int i = 0; i < vecVirus.size(); i++) {
			vecVirus[i]->dibujar();
		}
	}

	//----COLISIONES----


	bool personaColisionVirus() {
		if (objPersona->getInmunidad() == false){
			for (int i = 0; i < vecVirus.size(); i++){
				//OBTENIENDO Y ASIGNANDO VALORES PARA PERSONA
				int x1 = objPersona->getX(); int y1 = objPersona->getY();
				int ancho1 = objPersona->getAncho(); int alto1 = objPersona->getAlto();
				////OBTENIENDO Y ASIGNANDO VALORES PARA VIRUS
				int x2 = vecVirus[i]->getX(); int y2 = vecVirus[i]->getY();
				int ancho2 = vecVirus[i]->getAncho(); int alto2 = vecVirus[i]->getAlto();
				//VALIDAMOS LA COLISION
				if (!(x1 + ancho1 < x2 || y1 + alto1 < y2 || x1 > x2 + ancho2 || y1 > y2 + alto2)) {
					objPersona->disminuirVida();
					objPersona->setX(4);
					objPersona->setY(4);
					if (objPersona->getVida() == 0) {
						return true;
					}
				}
			}
		}
	}

	void personaColisionVacuna() {
		for (int i = 0; i < vecVacuna.size(); i++){
			//OBTENIENDO Y ASIGNANDO VALORES PARA PERSONA
			int x1 = objPersona->getX(); int y1 = objPersona->getY();
			int ancho1 = objPersona->getAncho(); int alto1 = objPersona->getAlto();
			////OBTENIENDO Y ASIGNANDO VALORES PARA VACUNA
			int x2 = vecVacuna[i]->getX(); int y2 = vecVacuna[i]->getY();
			int ancho2 = vecVacuna[i]->getAncho(); int alto2 = vecVacuna[i]->getAlto();
			//VALIDAMOS LA COLISION
			if (!(x1 + ancho1 < x2 || y1 + alto1 < y2 || x1 > x2 + ancho2 || y1 > y2 + alto2)) {
				objPersona->setInmunidad(true);
				objPersona->setCantMov(10);
			}
		}
	}

	bool personaColisionCasa() {
		//OBTENIENDO Y ASIGNANDO VALORES PARA PERSONA
		int x1 = objPersona->getX(); int y1 = objPersona->getY();
		int ancho1 = objPersona->getAncho(); int alto1 = objPersona->getAlto();
		////OBTENIENDO Y ASIGNANDO VALORES PARA CASA
		int x2 = objCasa->getX(); int y2 = objCasa->getY();
		int ancho2 = objCasa->getAncho(); int alto2 = objCasa->getAlto();
		//VALIDAMOS LA COLISION
		if (!(x1 + ancho1 < x2 || y1 + alto1 < y2 || x1 > x2 + ancho2 || y1 > y2 + alto2)) {
			return true;
		}
	}

	CPersona* getPersona() { return objPersona; }

};