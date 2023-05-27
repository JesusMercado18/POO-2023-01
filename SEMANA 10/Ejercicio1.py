#REALIZANDO FUNCIONES
def hallarFactorial(i):
    fact = 1 #LE ASIGNO 1 PORQUE EL FACTORIAL DEBE COMENZAR A MULTIPLICAR DESDE 1
    for j in range(1, i + 1):
        fact = fact * j
    return fact

#DEFINIENDO VARIABLES
n = 0
e = 0.0
factorial = 0.0

#VALIDANDO DATOS
while n < 1 or n > 121:
    n = int(input("Ingrese valor de N: "))

#RESOLVIENDO
for i in range(1, n+1):
    factorial = hallarFactorial(i)
    e += (i**2) / (2*factorial)

print(f"El valor del numero e es: {round(e,5)}")