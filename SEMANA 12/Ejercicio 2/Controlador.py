import Hora as h

class Controlador():
    def __init__(self):
        self.__listaHora = []

    #RESOLVIENDO
    def ingresarHora(self, hora, minuto, segundo):
        objHora = h.Hora(hora,minuto,segundo)
        self.__listaHora.append(objHora)

    def listarHora(self):
        for i in self.__listaHora:
            index = self.__listaHora.index(i)
            self.__listaHora[index].imprimirHora()

    def aumentarSegundoAHora(self):
        for i in self.__listaHora:
            index = self.__listaHora.index(i)
            #AUMENTAMOS SEGUNDOS
            self.__listaHora[index].aumentarSegundo()
            if self.__listaHora[index].getSegundo() == 60:
                self.__listaHora[index].setSegundo(0)
                #AUMENTAMOS MINUTOS
                self.__listaHora[index].aumentarMinuto()
                if self.__listaHora[index].getMinuto() == 60:
                    self.__listaHora[index].setMinuto(0)
                    #AUMENTAMOS HORAS
                    self.__listaHora[index].aumentarHora()
                    if self.__listaHora[index].getHora() == 24:
                        self.__listaHora[index].setHora(0)
            self.__listaHora[index].imprimirHora()

    def tiempoFinalDia(self):
        for i in self.__listaHora:
            index = self.__listaHora.index(i)

            hora = 24 - self.__listaHora[index].getHora()
            minuto = 60 - self.__listaHora[index].getMinuto()
            segundo = 60 - self.__listaHora[index].getSegundo()
            print(f"Tiempo #{index+1}")
            print(f"Tiempo para llegar al final del dia: {hora}:{minuto}:{segundo}")

    def tiempoExistente(self):
        mayorHora = -1
        mayorMinuto = -1
        mayorSegundo = -1
        menorHora = 25
        menorMinuto = 61
        menorSegundo = 61
        auxMaH = 0
        auxMaM = 0
        auxMaS = 0
        auxMeH = 0
        auxMeM = 0
        auxMeS = 0
        for i in self.__listaHora:
            index = self.__listaHora.index(i)
            #HALLAMOS MAYORES
            if self.__listaHora[index].getHora() > mayorHora:
                mayorHora = self.__listaHora[index].getHora()
                auxMaH = self.__listaHora.index(i)
            if self.__listaHora[index].getMinuto() > mayorMinuto:
                mayorMinuto = self.__listaHora[index].getMinuto()
                auxMaM = self.__listaHora.index(i)
            if self.__listaHora[index].getSegundo() > mayorSegundo:
                mayorSegundo = self.__listaHora[index].getSegundo()
                auxMaS = self.__listaHora.index(i)
            #HALLAMOS MENORES
            if self.__listaHora[index].getHora() < menorHora:
                menorHora = self.__listaHora[index].getHora()
                auxMeH = self.__listaHora.index(i)
            if self.__listaHora[index].getMinuto() < menorMinuto:
                menorMinuto = self.__listaHora[index].getMinuto()
                auxMeM = self.__listaHora.index(i)
            if self.__listaHora[index].getSegundo() > menorSegundo:
                menorSegundo = self.__listaHora[index].getSegundo()
                auxMeS = self.__listaHora.index(i)
        diferenciaHora = self.__listaHora[auxMaH].getHora() - self.__listaHora[auxMeH].getHora()
        diferenciaMinuto = self.__listaHora[auxMaM].getMinuto() - self.__listaHora[auxMeM].getMinuto()
        diferenciaSegundo = self.__listaHora[auxMaS].getSegundo() - self.__listaHora[auxMeS].getSegundo()
        print(f"La diferencia que existe es: {diferenciaHora}:{diferenciaMinuto}:{diferenciaSegundo}")

