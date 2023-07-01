import CControlador as cc
#----ESTAS LIBRERIAS SON OPCIONALES----
import os
from msvcrt import getch
#----SIRVEN PARA LIMPIAR DATOS DE LA PANTALLA----

def menu():
    print("1.Generar lista")
    print("2.Imprimir lista")
    print("3.Cantidad de pacientes adultos mayores")
    print("4.Promedio de edades de pacientes que solicitaron prueba COVID")
    print("5.Nivel de satisfaccion con mayor frecuencia")
    print("6.Mujer mas jove que no se realizo prueba COVID")

#DEFINIMOS VARIABLES
opcion = 0
n = 0
objControlador = cc.CControlador()

while opcion != 7:
    menu()
    opcion = int(input("Ingrese una opcion: "))

    if opcion == 1:
       n = int(input("Ingrese cantidad de encuestas: "))
       for i in range(n):
           objControlador.agregarEncuesta()
       print("SE REALIZO CON EXITO")
    elif opcion == 2:
        objControlador.listarEncuesta()
    elif opcion == 3:
        objControlador.adultosMayores()
    elif opcion == 4:
        objControlador.promEdadCovid()
    elif opcion == 5:
        objControlador.satisfaccionMayorFrecuencia()
    elif opcion == 6:
        if objControlador.mujerJovenNoPruebaCovid() != 0:
            print("La edad de la mujer es: {objControlador.mujerJovenNoPruebaCovid()}")
        else:
            print("NO EXISTE PACIENTE QUE CUMPLE CON LA CONDICION")

    getch()
    os.system("cls")