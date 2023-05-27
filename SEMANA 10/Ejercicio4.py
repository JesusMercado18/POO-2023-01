import random as r

#REALIZANDO FUNCIONES
def generarDatos(lista, n):
    for i in range(n):
        lista.append(r.randint(1,9))
    print("SE GENERO LA LISTA CON EXITO")

def mostrarDatos(lista, n):
    for i in range(n):
        print(lista[i])

def digitosRepetidos(lista, n):
    print("ORDENANDO LISTA ASCENDENTE:")
    lista.sort()
    print(lista)
    for i in lista:
        print(f"El numero {i} se repite: {lista.count(i)}")

#DEFIENDO VARIABLES
n = 0
lista = [] #ESTO ES UNA LISTA VACIA

while n < 1 or n > 40:
    n = int(input("Ingrese valor para N: "))

#RESOLVIENDO A
generarDatos(lista,n)

#RESOLVIENDO B
#mostrarDatos(lista, n)
print(lista)

#RESOLVIENDO C
digitosRepetidos(lista,n)

#RESOLVIENDO D
for i in lista:
    #LOS NUMEROS PRIMOS DEL 1 AL 9 SON: 2, 3, 5, 7
    if i == 3:
        pos = lista.index(i)
        lista[pos] = 4
    if i == 2:
        pos = lista.index(i)
        lista[pos] = 3
    if i == 5:
        pos = lista.index(i)
        lista[pos] = 6
    if i == 7:
        pos = lista.index(i)
        lista[pos] = 8
print("NUMEROS CAMBIADOS")
print(lista)