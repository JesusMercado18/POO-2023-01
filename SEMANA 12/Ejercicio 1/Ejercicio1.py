import Controlador as c
#OPCIONALES PARA USAR EL system("cls")
import os
from msvcrt import getch
#----LAS 2 DE ARRIBA SON OPCIONALES----

#METODO MENU
def menu():
    print("1.Añadir")
    print("2.Tranferencia")
    print("3.Saldo promedio x distrito")
    print("4.Datos de la persona x inicial")
    print("5.Persona que tiene mayor saldo")
    print("6.Listar")
    print("7.Salir")

#DEFINIMOS VARIABLES
objControlador = c.CControlador()
opcion = 0

while opcion != 7:
    menu()
    opcion = int(input("Seleccione una opcion : "))

    if opcion == 1:
        dni = input("Ingrese el dni: ")
        nombre = input("Ingrese el nombre: ")
        apellido = input("Ingrese el apellido: ")
        distrito = input("Ingrese el distrito: ")
        telefono = input("Ingrese el telefono: ")
        saldo = float(input("Ingrese el saldo: "))
        objControlador.agregarCuenta(dni,nombre,apellido,distrito,telefono,saldo)
        print("SE REALIZO CON EXITO")
    elif opcion == 2:
        dniRetira = input("Ingrese el dni de donde retira: ")
        dniDeposita = input("Ingrese el dni de donde deposita: ")
        saldo = float(input("Ingrese el saldo a transferir: "))
        objControlador.transferencia(dniRetira,dniDeposita,saldo)
        print("SE REALIZO CON EXITO")
    elif opcion == 3:
        distrito = input("Ingrese el distrito: ")
        objControlador.saldoPromedioXDistrito(distrito)
        print("SE REALIZO CON EXITO")
    elif opcion == 4:
        inicial = input("Ingrese la inicial del apellido: ")
        objControlador.apellidoXInicial(inicial)
    elif opcion == 5:
        objControlador.mayorSaldo()
    elif opcion == 6:
        objControlador.listarCuenta()

    #ESTO ES OPCIONAL
    getch()
    os.system("cls")

print("GRACIAS POR USAR EL SISTEMA...")