import math as m # as -- traducido --> como

#SOLICITANDO DATOS
arista = int(input("Ingrese la arista: "))

#RESOLVER FORMULA DEL AREA
area = round( arista**2 * m.sqrt(3), 6)

#RESOLVER FORMULA DEL VOLUMEN
volumen = round( ( m.sqrt(2) / 12 ) * arista**3, 3)

#MOSTRANDO RESULTADOS
print(f"El valor del area es: {area}")
print(f"El valor del volumen es: {volumen}")