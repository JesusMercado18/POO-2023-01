#----ESTAS LIBRERIAS SON OPCIONALES----
import os
from msvcrt import getch
#----SIRVEN PARA LIMPIAR DATOS DE LA PANTALLA----

def menu():
    print("1.Calcular la serie")
    print("2.Graficar")
    print("3.Salir")

def calculoSerie(n, a):
    suma = 0
    for i in range(1, n+1):
        suma += (-1)**(i+1)*( ( (2*i - 1) *  a**(2**(i-1)) ) / (2*i) )
    print(f"el calculo de la serie es: {suma}")

def graficar(n):
    for filas in range(1, n+1):
        for espacios in range(n-filas):
            print(" ",end="")
        for columnas in range(filas):
            print(f"{columnas+1}",end="")
        #AQUI ABAJO COMPLETAMOS LAS COLUMNAS FALTANTES
        if filas > 1:
            for columnasFaltantes in range(filas-1,0,-1):
                print(f"{columnasFaltantes}",end="")
        print("\n",end="")

#DEFINIMOS VARIABLES
opcion = 0
a = 0.0

while opcion != 3:
    menu()
    opcion = int(input("Ingrese la opcion: "))
    n = -1
    if opcion == 1:
        while n < 0 or n > 21:
            n = int(input("Ingrese un valor para N: "))
        while a < 0.5 or a > 2:
            a = float(input("Ingrese un valor para a: "))
        calculoSerie(n,a)
    elif opcion == 2:
        while n < 1 or n > 9:
            n = int(input("Ingrese un valor para N: "))
        graficar(n)

    getch()
    os.system("cls")