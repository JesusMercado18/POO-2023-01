#include "Persona.h"

using namespace std;

int main() {
	srand(time(NULL)); //FUNCION NECESARIA PARA CUANDO COMPILEN SE GENERE UN ALEATORIO DIFERENTE

	//OBJETOS DE LA CLASE
	CPersona* objPersona1;
	CPersona* objPersona2;
	CPersona* objPersona3;
	char sexo;

	//PRIMERA PERSONA
	cout << "PERSONA 1" << endl;
	objPersona1 = new CPersona("Jesus", 24, 'H');
	objPersona1->devolverInfo();
	cout << "El resultado del IMC es: " << objPersona1->calcularIMC() << endl;
	cout << "La persona es mayor de edad?: " << objPersona1->esMayorDeEdad() << endl;

	//SEGUNDA PERSONA
	cout << "PERSONA 2" << endl;
	objPersona2 = new CPersona("Jesus", 24, 'H', 85, 1.83);
	objPersona2->devolverInfo();
	cout << "El resultado del IMC es: " << objPersona2->calcularIMC() << endl;
	cout << "La persona es mayor de edad?: " << objPersona2->esMayorDeEdad() << endl;

	//TERCERA PERSONA
	cout << "PERSONA 3" << endl;
	objPersona3 = new CPersona();
	objPersona3->devolverInfo();
	
	objPersona3->setNombre("Alex");
	cout << objPersona3->getNombre();
	//objPersona3->devolverInfo();

	_getch();
	return 0;
}