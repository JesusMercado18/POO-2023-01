#pragma once
#include "Avro.h"
#include "Boeing.h"
#include "LineaNazca.h"
#include <vector>

class CControlador{
private:
	CLineaNazca* objLineaNazca;
	vector<CAvro*> vecAvro;
	vector<CBoeing*> vecBoeing;

public:
	CControlador(){
		//PARA QUE SE DIBUJE NI BIEN LLAME A LA CLASE
		objLineaNazca = new CLineaNazca();
	}
	~CControlador(){}


	void agregarAvro() {
		vecAvro.push_back(new CAvro(10, 10));
	}

	void agregarBoeing() {
		vecBoeing.push_back(new CBoeing(30, 10));
	}

	void borrarTodo() {
		objLineaNazca->borrar();
		//AVRO
		for (int i = 0; i < vecAvro.size(); i++){
			vecAvro[i]->borrar();
		}
		//BOEING
		for (int i = 0; i < vecBoeing.size(); i++){
			vecBoeing[i]->borrar();
		}
	}

	void dibujarTodo() {
		objLineaNazca->dibujar();
		//AVRO
		for (int i = 0; i < vecAvro.size(); i++) {
			vecAvro[i]->dibujar();
		}
		//BOEING
		for (int i = 0; i < vecBoeing.size(); i++) {
			vecBoeing[i]->dibujar();
		}
	}

	void moverTodo() {
		//AVRO
		for (int i = 0; i < vecAvro.size(); i++) {
			vecAvro[i]->mover();
		}
		//BOEING
		for (int i = 0; i < vecBoeing.size(); i++) {
			vecBoeing[i]->mover();
		}
	}
};