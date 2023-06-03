import random as r

class CContrasena():
    #ATRIBUTOS PRIVADOS INICIALIZADOS POR DEFECTO
    __longitud = 8
    __contrasena = [] #ESTO ES UNA LISTA
    __contMayuscula = 0
    __contMinuscula = 0
    __contNumero = 0

    #REALIZAMOS EL CONSTRUCTOR QUE RECIBE COMO PARAMETRO LA LONGITUD
    def __init__(self, longitud):
        self.__longitud = longitud
        self.__contrasena = self.generarContrasena() #NO OLVIDAR CAMBIAR POR LA FUNCION QUE RETORNA UNA LISTA DE CONTRASEÑA
        self.__contMayuscula
        self.__contMinuscula
        self.__contNumero

    #METODOS GET
    def getLongitud(self):
        return self.__longitud
    def getContrasena(self):
        return self.__contrasena

    #METODO SET
    def setLongitud(self, longitud):
        self.__longitud = longitud

    #METODO O FUNCION QUE GENERA CONTRASEÑA
    def generarContrasena(self):
        contrasenaAleatorio = []

        for i in range(self.__longitud):
            caracterRandom = r.randint(0,2)

            if caracterRandom == 0:
                #AGREGAMOS UNA LETRA MAYUSCULA DEL CODIGO ASCII
                contrasenaAleatorio.append(chr(r.randint(65,90)))
                #CONTAMOS ESA MAYUSCULA
                self.__contMayuscula += 1
            elif caracterRandom == 1:
                #AGREGAMOS UNA LETRA MINUSCULA DEL CODIGO ASCII
                contrasenaAleatorio.append(chr(r.randint(97,122)))
                #CONTAMOS ESA MINUSCULA
                self.__contMinuscula += 1
            elif caracterRandom == 2:
                #AGREGAMOS UN NUMERO DEL CODIGO ASCII
                contrasenaAleatorio.append(chr(r.randint(48,57)))
                #CONTAMOS ESE NUMERO
                self.__contNumero += 1

        return contrasenaAleatorio

    #METODO O FUNCION PARA SABER SI ES SEGURO
    def esSeguro(self):
        if self.__contMayuscula > 2 and self.__contMinuscula > 1 and self.__contNumero > 5:
            return True
        else:
            return False

    #METODO O FUNCION QUE MUESTRA DATOS
    def mostrarDatos(self):
        print(f"Longitud: {self.__longitud}")
        print(f"Contrasena: {self.__contrasena}")
        print(f"Cont mayuscula: {self.__contMayuscula}")
        print(f"Cont minuscula: {self.__contMinuscula}")
        print(f"Cont numeros: {self.__contNumero}")