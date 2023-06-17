import CDataFrame as cdf
#ESTAS LIBRERIAS SON OPCIONALES
import os
from msvcrt import getch
##---------------------------

def menu():
    print("1.Generar y mostrar DF diccionario")
    print("2.Generar y mostrar DF lista")
    print("3.Salir")

#INICIALIZAMOS VARIABLES
objCDF = cdf.dataFrame()
opcion = 0

while opcion != 3:
    menu()
    opcion = int(input("Ingrese una opcion: "))

    if opcion == 1:
        objCDF.generarYMostrarDFDiccionario()
    elif opcion == 2:
        objCDF.generarYMostrarDFLista()

    getch()
    os.system("cls")