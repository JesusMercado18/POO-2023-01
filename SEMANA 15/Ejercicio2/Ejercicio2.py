import random as r
#----ESTAS LIBRERIAS SON OPCIONALES----
import os
from msvcrt import getch
#----SIRVEN PARA LIMPIAR DATOS DE LA PANTALLA----

def menu():
    print("1.Generar lista")
    print("2.Imprimir lista")
    print("3.Determinar vocales alternas")
    print("4.Posicion impar descendente")

def generarLista(listaLetras, n):
    for i in range(n):
        letraRandom = r.randint(65,90) #LLENANDO LETRA RANDOM DEL CODIGO ASCII
        listaLetras.append(chr(letraRandom))
        #listaLetras.append(chr(r.randint(65,90))) EJEMPLO CON UNA SOLA LINEA DE CODIGO

def vocalesAlternas(listaLetras, n):
    for i in range(n):
        if listaLetras[i] == 'A' and listaLetras[i+2] == 'E' and listaLetras[i+4] == 'I' and listaLetras[i+6] == 'O':
            return True
        else:
            return False

def posicionImparDescendente(listaLetras, n):
    listaImpar = []
    for i in range(n):
        if i % 2 != 0:
            listaImpar.append(listaLetras[i])
    print("ANTES DE ORDENAR")
    print(listaImpar)
    print("DESPUES DE ORDENAR")
    listaImpar.sort(reverse=True) #ORDENAMOS LA LISTA DE LETRAS IMPARES DESCENDENTEMENTE
    print(listaImpar)

#DEFINIENDO VARIABLES
n = 0
opcion = 0

while opcion != 5:
    menu()
    opcion = int(input("Ingrese la opcion: "))

    if opcion == 1:
        listaLetras = []
        while n < 1 or n > 50:
            n = int(input("Ingrese un valor para N: "))
        generarLista(listaLetras,n)
        print("SE REALIZO CON EXITO")
    elif opcion == 2:
        print(listaLetras)
    elif opcion == 3:
        if vocalesAlternas(listaLetras,n) == True:
            print("CUMPLE CON LA CONDICION")
        else:
            print("NO CUMPLE CON LA CONDICION")
    elif opcion == 4:
        print(listaLetras)
        posicionImparDescendente(listaLetras,n)

    getch()
    os.system("cls")