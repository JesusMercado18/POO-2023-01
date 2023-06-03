import CPersona as CP

#DEFINIR VARIABLES
nombre = input("Ingrese el nombre: ")
edad = int(input("Ingrese la edad: "))
sexo = input("Ingrese el sexo (H:Hombre; M:Mujer): ")
altura = float(input("Ingrese la altura: "))
peso = float(input("Ingrese el peso: "))

#CREAMOS OBJETO DE LA PERSONA
objPersona = CP.CPersona(nombre,edad,sexo,peso,altura)

#MOSTRAMOS DATOS
objPersona.mostrarDatos()

#COMPROBAMOS EL PESO IDEAL
if objPersona.calcularIMC() == -1:
    print("Peso ideal")
elif objPersona.calcularIMC() == 0:
    print("Debajo de su peso ideal")
elif objPersona.calcularIMC() == 1:
    print("Sobrepeso")

#COMPROBAMOS SI ES MAYOR DE EDAD
if objPersona.esMayorDeEdad() == True:
    print("Es mayor de edad")
elif objPersona.esMayorDeEdad() == False:
    print("Es menor de edad")