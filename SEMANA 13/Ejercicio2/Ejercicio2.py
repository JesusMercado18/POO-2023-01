import CDataFrame as CDF
import pandas as pd
import random as r
#ESTAS LIBRERIAS SON OPCIONALES
import os
from msvcrt import getch
##---------------------------

def menu():
    print("1.Imprimir df")
    print("2.Realizar y mostrar balance A")
    print("3.Realizar y mostrar balance B")
    print("4.Salir")

#INICIALIZAMOS VARIABLES
datos = {
         "Mes":["Enero","Febrero","Marzo","Abril"],
         "Ventas":[r.randint(1000,5000),r.randint(1000,5000),r.randint(1000,5000),r.randint(1000,5000)],
         "Gastos":[r.randint(1000,5000),r.randint(1000,5000),r.randint(1000,5000),r.randint(1000,5000)]
    }

df = pd.DataFrame(datos)
objCDF = CDF.dataFrame(df)
opcion = 0

while opcion != 4:
    menu()
    opcion = int(input("Ingrese una opcion: "))
    listaMeses = []

    if opcion == 1:
        print(df)
    elif opcion == 2:
        n = int(input("Ingrese la cantidad de meses: "))
        for i in range(n):
            mes = input("Ingrese un mes: (Enero, Febrero, Marzo, Abril): ")
            listaMeses.append(mes)
        print(objCDF.balance(listaMeses))
    elif opcion == 3:
        n = int(input("Ingrese la cantidad de meses: "))
        for i in range(n):
            mes = input("Ingrese un mes: (Enero, febrero, Marzo, Abril,...): ")
            listaMeses.append(mes)
        print(objCDF.balanceB(listaMeses))

    getch()
    os.system("cls")