#pragma once
#include "Persona.h"
#include "Bala.h"
#include "Enemigo.h"
#include <vector>

class CControlador {
private:
	CPersona* objPersona;
	vector<CBala*> vecBala;
	vector<CEnemigo*> vecEnemigo;

public:
	CControlador() {
		objPersona = new CPersona(4, 4);
		for (int i = 0; i < 3; i++) {
			vecEnemigo.push_back(new CEnemigo());
		}
	}
	~CControlador() {}

	void agregarBala() {
		CBala* objBala = new CBala(objPersona->getX(), objPersona->getY(), objPersona->getDireccionP());
		vecBala.push_back(objBala);

	}

	void borrarTodo() {
		objPersona->borrar();
		for (int i = 0; i < vecBala.size(); i++) {
			vecBala[i]->borrar();
		}
		for (int i = 0; i < vecEnemigo.size(); i++) {
			vecEnemigo[i]->borrar();
		}
	}

	void moverTodo() {
		for (int i = 0; i < vecBala.size(); i++) {
			vecBala[i]->moverBala();
		}
		for (int i = 0; i < vecEnemigo.size(); i++) {
			vecEnemigo[i]->moverEnemigo();
		}
	}

	void dibujarTodo() {
		objPersona->dibujar();
		for (int i = 0; i < vecBala.size(); i++) {
			vecBala[i]->dibujar();
		}
		for (int i = 0; i < vecEnemigo.size(); i++) {
			vecEnemigo[i]->dibujar();
		}
	}

	bool colisionPersonaEnemigo() {
		for (int i = 0; i < vecEnemigo.size(); i++){
			//OBTENIENDO Y ASIGNANDO VALORES PARA PERSONA
			int x1 = objPersona->getX(); int y1 = objPersona->getY();
			int ancho1 = objPersona->getAncho(); int alto1 = objPersona->getAlto();
			// OBTENIENDO Y ASIGNANDO VALORES PARA ENEMIGO
			int x2 = vecEnemigo[i]->getX(); int y2 = vecEnemigo[i]->getY();
			int ancho2 = vecEnemigo[i]->getAncho(); int alto2 = vecEnemigo[i]->getAlto();
			// VALIDANDO COLISION PERSONA CON ENEMIGO
			if (!(x1 + ancho1 < x2 || y1 + alto1 < y2 || x1 > x2 + ancho2 || y1 > y2 + alto2)) {
				objPersona->DisminuirVida();
				if (objPersona->getVida() == 0) {
					return true;
				}
			}
		}
	}

	void colisionBalaEnemigo() {
		//VALIDANDO
		for (int i = 0; i < vecBala.size(); i++){
			// OBTENIENDO Y ASIGNANDO VALORES PARA BALA
			int x2 = vecBala[i]->getX(); int y2 = vecBala[i]->getY();
			int ancho2 = vecBala[i]->getAncho(); int alto2 = vecBala[i]->getAlto();
			int dx = vecBala[i]->getDx(); int dy = vecBala[i]->getDy();
			// VALIDANDO SI LA BALA PASA RANGO DE CONSOLA
			if (x2 + dx <= 4 || x2 + dx + ancho2 >= 70 || y2 + dy <= 4 || y2 + dy + alto2 >= 40) {
				vecBala[i]->setVisibilidad(false);
			}
		}
		for (int i = 0; i < vecEnemigo.size(); i++) {
			for (int j = 0; j < vecBala.size(); j++) {
				// OBTENIENDO Y ASIGNANDO VALORES PARA ENEMIGO
				int x1 = vecEnemigo[i]->getX(); int y1 = vecEnemigo[i]->getY();
				int ancho1 = vecEnemigo[i]->getAncho(); int alto1 = vecEnemigo[i]->getAlto();
				// OBTENIENDO Y ASIGNANDO VALORES PARA BALA
				int x2 = vecBala[j]->getX(); int y2 = vecBala[j]->getY();
				int ancho2 = vecBala[j]->getAncho(); int alto2 = vecBala[j]->getAlto();
				int dx = vecBala[j]->getDx(); int dy = vecBala[j]->getDy();
				// VALIDANDO COLISION BALA CON ENEMIGO
				if (!(x1 + ancho1 < x2 || y1 + alto1 < y2 || x1 > x2 + ancho2 || y1 > y2 + alto2)) {
					objPersona->agregarPuntos();
					vecEnemigo[i]->setVisibilidad(false);
					vecBala[j]->setVisibilidad(false);
				}
			}
		}
		//BORRANDO BALA
		for (int i = 0; i < vecBala.size(); i++){
			if (!vecBala[i]->getVisibilidad()) { // vecBala[i]->getVisibilidad() == false
				vecBala.erase(vecBala.begin() + i);
			}
		}
		//BORRANDO ENEMIGO
		for (int i = 0; i < vecEnemigo.size(); i++) {
			if (!vecEnemigo[i]->getVisibilidad()) { // vecEnemigo[i]->getVisibilidad() == false
				vecEnemigo.erase(vecEnemigo.begin() + i);
			}
		}
	}

	CPersona* getPersona() { return objPersona; }
};