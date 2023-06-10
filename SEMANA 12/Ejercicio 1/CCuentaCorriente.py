class CCuentaCorriente():
    #CONSTRUCTOR POR DEFECTO INICIALIZAMOS
    def __init__(self):
        self.__dni = " "
        self.__nombre = " "
        self.__apellido = " "
        self.__distrito = " "
        self.__telefono = " "
        self.__saldo = 0.0

    #CONSTRUCTOR QUE RECIBE ARGUMENTOS
    def __init__(self, dni, nombre, apellido, distrito, telefono, saldo):
        self.__dni = dni
        self.__nombre = nombre
        self.__apellido = apellido
        self.__distrito = distrito
        self.__telefono = telefono
        self.__saldo = saldo

    #METODOS GET
    def getDni(self):
        return self.__dni
    def getNombre(self):
        return self.__nombre
    def getApellido(self):
        return self.__apellido
    def getDistrito(self):
        return self.__distrito
    def getTelefono(self):
        return self.__telefono
    def getSaldo(self):
        return self.__saldo

    #METODOS SET
    def setDni(self, dni):
        self.__dni = dni
    def setNombre(self, nombre):
        self.__nombre = nombre
    def setApellido(self, apellido):
        self.__apellido = apellido
    def setDistrito(self, distrito):
        self.__distrito = distrito
    def setTelefono(self, telefono):
        self.__telefono = telefono
    def setSaldo(self, saldo):
        self.__saldo = saldo

    #METODO resta al saldo una cantidad de dinero pasada como argumento
    def retirarDinero(self, monto):
        self.__saldo -= monto #self.__saldo = self.__saldo - monto
        return self.__saldo

    #METODO añade al saldo una cantidad de dinero
    def ingresarDinero(self, monto):
        self.__saldo += monto #self.__saldo = self.__saldo + monto
        return self.__saldo

    #METODO visualizará los datos de la cuenta
    def consultarCuenta(self):
        print(f"DNI: {self.__dni}")
        print(f"Nombre: {self.__nombre}")
        print(f"Apellido: {self.__apellido}")
        print(f"Distrito: {self.__distrito}")
        print(f"Telefono: {self.__telefono}")
        print(f"Saldo: {self.__saldo}")

    #METODO devolverá un valor lógico indicando si la cuenta está o no en números rojos
    def saldoNegativo(self):
        if self.__saldo < 0:
            return True
        else:
            return False