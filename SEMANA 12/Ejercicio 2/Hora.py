class Hora():
    def __init__(self):
        self.__hora = 0
        self.__minuto = 0
        self.__segundo = 0

    def __init__(self, hora, minuto, segundo):
        self.__hora = hora
        self.__minuto = minuto
        self.__segundo = segundo

    #METODOS SET
    def setHoraP(self, hora, minuto, segundo):
        if hora < 0 or hora > 23:
            self.__hora = 0
        else:
            self.__hora = hora
        if minuto < 0 or minuto > 59:
            self.__minuto = 0
        else:
            self.__minuto = minuto
        if segundo < 0 or segundo > 59:
            self.__segundo = 0
        else:
            self.__segundo = segundo

    def setHora(self, hora):
        self.__hora = hora
    def setMinuto(self, minuto):
        self.__minuto = minuto
    def setSegundo(self, segundo):
        self.__segundo = segundo

    #METODO GET
    def getHoraP(self):
        listaHora = []
        listaHora.append(self.__hora)
        listaHora.append(self.__minuto)
        listaHora.append(self.__segundo)
        return listaHora

    def getHora(self):
        return self.__hora
    def getMinuto(self):
        return self.__minuto
    def getSegundo(self):
        return self.__segundo

    def aumentarSegundo(self):
        self.__segundo += 1
    def aumentarMinuto(self):
        self.__minuto += 1
    def aumentarHora(self):
        self.__hora += 1

    def imprimirHora(self):
        print(f"{self.__hora}:{self.__minuto}:{self.__segundo}")