import CEncuesta as ce

class CControlador():
    def __init__(self):
        self.__listaEncuesta = []

    def agregarEncuesta(self):
        objEncuesta = ce.CEncuesta()
        self.__listaEncuesta.append(objEncuesta)

    def listarEncuesta(self):
        for i in self.__listaEncuesta:
            #EN LA VARIABLE index ALMACENO EL INDICE DEL OBJ QUE SE ENCUENTRA EN ESA POSICION
            index = self.__listaEncuesta.index(i)
            print(f"PACIENTE #{index+1}")
            self.__listaEncuesta[index].consultarEncuesta()

    #REPORTES
    #Determinar y mostrar cuántos pacientes son adultos mayores (adulto mayor es quien tiene 60 o más años).
    def adultosMayores(self):
        cont = 0
        for i in self.__listaEncuesta:
            #EN LA VARIABLE index ALMACENO EL INDICE DEL OBJ QUE SE ENCUENTRA EN ESA POSICION
            index = self.__listaEncuesta.index(i)
            if self.__listaEncuesta[index].getEdad() >= 60:
                cont += 1
                self.__listaEncuesta[index].consultarEncuesta()
        print(f"LA CANTIDAD DE ADULTOS MAYORES ES: {cont}")

    #Determinar y mostrar cuál es el promedio de edad de los pacientes que solicitaron una prueba COVID.
    def promEdadCovid(self):
        contPacientesCovid = 0
        sumaEdad = 0
        promedio = 0.0
        for i in self.__listaEncuesta:
            #EN LA VARIABLE index ALMACENO EL INDICE DEL OBJ QUE SE ENCUENTRA EN ESA POSICION
            index = self.__listaEncuesta.index(i)
            if self.__listaEncuesta[index].getTipoPrueba() == "COVID":
                sumaEdad+= self.__listaEncuesta[index].getEdad()
                contPacientesCovid += 1
        promedio = sumaEdad / contPacientesCovid
        print(f"EL PROMEDIO DE EDAD DE LOS PACIENTES QUE SOLICITARON PRUEBA COVID ES: {promedio}")

    #Hallar y mostrar cuál es el nivel o niveles de satisfacción que tienen una mayor frecuencia
    def satisfaccionMayorFrecuencia(self):
        contBueno = 0
        contRegular = 0
        contMalo = 0
        for i in self.__listaEncuesta:
            #EN LA VARIABLE index ALMACENO EL INDICE DEL OBJ QUE SE ENCUENTRA EN ESA POSICION
            index = self.__listaEncuesta.index(i)
            if self.__listaEncuesta[index].getNivelSatisfaccion() == "Bueno":
                contBueno += 1
            if self.__listaEncuesta[index].getNivelSatisfaccion() == "Regular":
                contRegular += 1
            if self.__listaEncuesta[index].getNivelSatisfaccion() == "Malo":
                contMalo += 1
        #RESOLVIENDO O COMPARANDO
        if contBueno > contRegular and contBueno > contMalo:
            print("El nivel de satisfaccion BUENO tiene mayor frecuencia")
        if contRegular > contBueno and contRegular > contMalo:
            print("El nivel de satisfaccion REGULAR tiene mayor frecuencia")
        if contMalo > contBueno and contMalo > contRegular:
            print("El nivel de satisfaccion MALO tiene mayor frecuencia")

    #Determinar y mostrar cuál es la edad de la mujer más joven que no se realizó una prueba COVID.
    #En caso no exista algún paciente con dichas características, mostrar un mensaje.
    def mujerJovenNoPruebaCovid(self):
        menor = 80
        for i in self.__listaEncuesta:
            #EN LA VARIABLE index ALMACENO EL INDICE DEL OBJ QUE SE ENCUENTRA EN ESA POSICION
            index = self.__listaEncuesta.index(i)
            if self.__listaEncuesta[index].getEdad() < menor and self.__listaEncuesta[index].getSexo() == "Femenino" and self.__listaEncuesta[index].getTipoPrueba() != "COVID":
                menor = self.__listaEncuesta[index].getEdad()
                return menor
            else:
                return 0