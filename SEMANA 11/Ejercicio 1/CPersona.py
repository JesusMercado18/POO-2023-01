import random as r

class CPersona():
    #ATRIBUTOS PRIVADOS INICIALIZADOS POR DEFECTO
    __nombre = " "
    __edad = 0
    __dni = 0
    __sexo = "H"
    __peso = 0.0
    __altura = 0.0

    #SU CONSTRUCTOR QUE RECIBE PARAMETROS
    #LA PALABRA "self" SIEMPRE VA COMO PARAMETRO EN LAS FUNCIONES, YA SE QUE ESTE EN UNA CLASE O NO
    def __init__(self, nombre, edad, sexo, peso, altura):
        self.__nombre = nombre
        self.__edad = edad
        self.__sexo = sexo
        self.__peso = peso
        self.__altura = altura
        self.__dni = self.generaDNI() #NO OLVIDAR ASIGNAR LA FUNCION QUE GENERA DNI RANDOM

    #METODOS GET
    def getNombre(self):
        return self.__nombre
    def getEdad(self):
        return self.__edad
    def getSexo(self):
        return self.__sexo
    def getPeso(self):
        return self.__peso
    def getAltura(self):
        return self.__altura
    def getDNI(self):
        return self.__dni

    #METODOS SET
    def setNombre(self, nombre):
        self.__nombre = nombre
    def setEdad(self, edad):
        self.__edad = edad
    def setSexo(self, sexo):
        self.__sexo = sexo
    def setPeso(self, peso):
        self.__peso = peso
    def setAltura(self, altura):
        self.__altura = altura
    def setDNI(self, dni):
        self.__dni = dni

    #METODO O FUNCION PARA HALLAR EL IMC
    def calcularIMC(self):
        pesoIdeal = self.__peso / (self.__altura**2)

        if pesoIdeal < 20:
            return -1
        elif pesoIdeal >= 20 and pesoIdeal <= 25:
            return 0
        else:
            return 1

    #METODO O FUNCION PARA SABER SI ES MAYOR DE EDAD
    def esMayorDeEdad(self):
        if self.__edad >= 18:
            return True
        else:
            return False

    #METODO O FUNCION PARA GENERAR DNI ALEATORIO
    def generaDNI(self):
        return r.randint(10000000, 99999999)

    #METODO O FUNCION PARA MOSTRAR DATOS
    def mostrarDatos(self):
        print(f"Nombre: {self.__nombre}")
        print(f"Edad: {self.__edad}")
        print(f"Sexo: {self.__sexo}")
        print(f"DNI: {self.__dni}")
        print(f"Peso: {self.__peso}")
        print(f"Altura: {self.__altura}")