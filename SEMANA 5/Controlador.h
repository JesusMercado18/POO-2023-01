#pragma once
#include "RazaAlfa.h"
#include "RazaBeta.h"
#include "RazaGamma.h"
#include <vector>

class CControlador{
private:
	vector<CRazaAlfa*> vecRazaAlfa;
	vector<CRazaBeta*> vecRazaBeta;
	vector<CRazaGamma*> vecRazaGamma;

public:
	CControlador(){}
	~CControlador(){}

	//HACEMOS ESTOS GET PARA AGREGAR LAS OTRAS NAVES U OVNIS
	int getSizeAlfa() { return vecRazaAlfa.size(); }
	int getSizeBeta() { return vecRazaBeta.size(); }

	//HACEMOS ESTE GET PARA SABER LA CANTIDAD DE OVNIS QUE HAY EN TOTAL
	int totalOvnis() { return vecRazaAlfa.size() + vecRazaBeta.size() + vecRazaGamma.size(); }

	void agregarAlfa() {
		//CREAMOS OBJETO PARA ALMACENAR EN VECTOR
		CRazaAlfa* objRazaAlfa = new CRazaAlfa(1, 5);
		//AGREGAMOS EL OBJETO CREADO EN EL VECTOR CON EL PUSH_BACK
		vecRazaAlfa.push_back(objRazaAlfa);
	}

	void agregarBeta() {
		//CREAMOS OBJETO PARA ALMACENAR EN VECTOR
		CRazaBeta* objRazaBeta = new CRazaBeta(40, 5);
		//AGREGAMOS EL OBJETO CREADO EN EL VECTOR CON EL PUSH_BACK
		vecRazaBeta.push_back(objRazaBeta);
	}

	void agregarGamma() {
		//CREAMOS OBJETO PARA ALMACENAR EN VECTOR
		CRazaGamma* objRazaGamma = new CRazaGamma(90, 5);
		//AGREGAMOS EL OBJETO CREADO EN EL VECTOR CON EL PUSH_BACK
		vecRazaGamma.push_back(objRazaGamma);
	}

	void borrarTodo() {
		for (int i = 0; i < vecRazaAlfa.size(); i++){
			vecRazaAlfa[i]->borrar();
		}
		for (int i = 0; i < vecRazaBeta.size(); i++){
			vecRazaBeta[i]->borrar();
		}
		for (int i = 0; i < vecRazaGamma.size(); i++){
			vecRazaGamma[i]->borrar();
		}
	}

	//ESTA FUNCION ES PARA EL MOV. REBOTE
	void moverTodoRebote() {
		for (int i = 0; i < vecRazaAlfa.size(); i++) {
			vecRazaAlfa[i]->moverRebote();
		}
		for (int i = 0; i < vecRazaBeta.size(); i++) {
			vecRazaBeta[i]->moverRebote();
		}
		for (int i = 0; i < vecRazaGamma.size(); i++) {
			vecRazaGamma[i]->moverRebote();
		}
	}

	//ESTA FUNCION ES PARA EL MOV. CAIDA
	void moverTodoCaida() {
		for (int i = 0; i < vecRazaAlfa.size(); i++) {
			vecRazaAlfa[i]->moverCaida();
		}
		for (int i = 0; i < vecRazaBeta.size(); i++) {
			vecRazaBeta[i]->moverCaida();
		}
		for (int i = 0; i < vecRazaGamma.size(); i++) {
			vecRazaGamma[i]->moverCaida();
		}
	}

	//VAMOS A CREAR ESTA FUNCION PARA ELIMINAR A LOS OVNIS QUE PASEN EL LIMITE DE Y = 50
	void eliminarCaidos() {
		for (int i = 0; i < vecRazaAlfa.size(); i++){
			//EJEMPLO 1: USANDO LOS GET TRADICIONALES
			/*if (vecRazaAlfa[i]->getY() + vecRazaAlfa[i]->getDy() + vecRazaAlfa[i]->getAlto() >= 50) {
				vecRazaAlfa.erase(vecRazaAlfa.begin() + i);
			}*/
			//EJEMPLO 2: USANDO EL GET CON LOS 3 SUMADOS
			if (vecRazaAlfa[i]->getYmasAltomasDy() >= 50) {
				vecRazaAlfa.erase(vecRazaAlfa.begin() + i);
			}
		}

		for (int i = 0; i < vecRazaBeta.size(); i++){
			if (vecRazaBeta[i]->getYmasAltomasDy() >= 50) {
				vecRazaBeta.erase(vecRazaBeta.begin() + i);
			}
		}

		for (int i = 0; i < vecRazaGamma.size(); i++) {
			if (vecRazaGamma[i]->getYmasAltomasDy() >= 50) {
				vecRazaGamma.erase(vecRazaGamma.begin() + i);
			}
		}
	}

	void dibujarTodo() {
		for (int i = 0; i < vecRazaAlfa.size(); i++) {
			vecRazaAlfa[i]->dibujar();
		}
		for (int i = 0; i < vecRazaBeta.size(); i++) {
			vecRazaBeta[i]->dibujar();
		}
		for (int i = 0; i < vecRazaGamma.size(); i++) {
			vecRazaGamma[i]->dibujar();
		}
	}



};