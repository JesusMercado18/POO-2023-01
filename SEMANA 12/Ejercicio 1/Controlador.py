import CCuentaCorriente as cc

class CControlador(object):
    def __init__(self):
        self.__listaCuenta = []

    #SOLUCIONANDO PROBLEMA

    def agregarCuenta(self, dni, nombre, apellido, distrito, telefono, saldo):
        objCuenta = cc.CCuentaCorriente(dni,nombre,apellido,distrito,telefono,saldo)
        self.__listaCuenta.append(objCuenta)

    def listarCuenta(self):
        for i in self.__listaCuenta:
            #VARIABLE index ALMACENAR EL INDICE DEL VALOR I
            index = self.__listaCuenta.index(i)
            self.__listaCuenta[index].consultarCuenta()

   #METODO PARA REALIZAR O SIMULAR LA TRANSFERENCIA
    def transferencia(self, dniRetira, dniDepositar, monto):
       #BUSCAR A LA PERSONA QUE SE RETIRA DINERO
       for i in self.__listaCuenta:
           #VARIABLE index ALMACENAR EL INDICE DEL VALOR I
           index = self.__listaCuenta.index(i)
           if self.__listaCuenta[index].getDni() == dniRetira:
               self.__listaCuenta[index].retirarDinero(monto)
       #BUSCAR A LA PERSONA A QUIEN DEPOSITAMOS
       for i in self.__listaCuenta:
           #VARIABLE index ALMACENAR EL INDICE DEL VALOR I
           index = self.__listaCuenta.index(i)
           if self.__listaCuenta[index].getDni() == dniDepositar:
               self.__listaCuenta[index].ingresarDinero(monto)

    #METODO PARA HALLAR EL SALDO PROMEDIO POR DISTRITO
    def saldoPromedioXDistrito(self, distrito):
        cont = 0
        contSaldo = 0
        promedio = 0.0
        for i in self.__listaCuenta:
           #VARIABLE index ALMACENAR EL INDICE DEL VALOR I
           index = self.__listaCuenta.index(i)
           if self.__listaCuenta[index].getDistrito() == distrito:
               cont += 1
               contSaldo += self.__listaCuenta[index].getSaldo()
               promedio = contSaldo / cont

        print(f"El saldo promedio de las personas que viven en {distrito} es: {promedio}")

    #METODO PARA HALLAR APELLIDO CON LA INICIAL
    def apellidoXInicial(self, inicial):
        for i in self.__listaCuenta:
           #VARIABLE index ALMACENAR EL INDICE DEL VALOR I
           index = self.__listaCuenta.index(i)
           if self.__listaCuenta[index].getApellido()[0] == inicial:
               self.__listaCuenta[index].consultarCuenta()

    #METODO PARA HALLAR MAYOR SALDO
    def mayorSaldo(self):
        mayor = 0
        auxIndex = 0
        for i in self.__listaCuenta:
           #VARIABLE index ALMACENAR EL INDICE DEL VALOR I
           index = self.__listaCuenta.index(i)
           if self.__listaCuenta[index].getSaldo() > mayor:
               mayor = self.__listaCuenta[index].getSaldo()
               auxIndex = index

        #AQUI MOSTRAMOS TODOS LOS DATOS DE LA PERSONA CON MAYOR SALDO
        self.__listaCuenta[auxIndex].consultarCuenta()
        #AQUI MOSTRAMOS SOLO LA POSICION Y EL SALDO DE ESA PERSONA
        print(f"La posicion seria {auxIndex} el saldo es {self.__listaCuenta[auxIndex].getSaldo()}")