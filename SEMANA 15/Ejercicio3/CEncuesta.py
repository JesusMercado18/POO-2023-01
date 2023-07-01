import random as r

listaSexo = ["Femenino", "Masculino"]
listaTipoPrueba = ["Renal", "Hepatico", "COVID"]
listaNivelSatisfaccion = ["Bueno", "Regular", "Malo"]


class CEncuesta():
    def __init__(self, edad, sexo, tipoPrueba, nivelSatisfaccion):
        self.__edad = edad
        self.__sexo = sexo
        self.__tipoPrueba = tipoPrueba
        self.__nivelSatisfaccion = nivelSatisfaccion

    def __init__(self):
        self.__edad = r.randint(18,75)
        self.__sexo = listaSexo[r.randint(0,1)]
        self.__tipoPrueba = listaTipoPrueba[r.randint(0,2)]
        self.__nivelSatisfaccion = listaNivelSatisfaccion[r.randint(0,2)]

    #METODOS GET
    def getEdad(self):
        return self.__edad
    def getSexo(self):
        return self.__sexo
    def getTipoPrueba(self):
        return self.__tipoPrueba
    def getNivelSatisfaccion(self):
        return self.__nivelSatisfaccion

    #METODOS SET
    def setEdad(self, edad):
        self.__edad = edad
    def setSexo(self, sexo):
        self.__sexo = sexo
    def setTipoPrueba(self, tipoPrueba):
        self.__tipoPrueba = tipoPrueba
    def setNivelSatisfaccion(self, nivelSatisfaccion):
        self.__nivelSatisfaccion = nivelSatisfaccion

    #METODO PARA VER TODOS LOS DATOS
    def consultarEncuesta(self):
        print(f"Edad: {self.__edad}")
        print(f"Sexo: {self.__sexo}")
        print(f"Tipo prueba: {self.__tipoPrueba}")
        print(f"Nivel satisfaccion: {self.__nivelSatisfaccion}")