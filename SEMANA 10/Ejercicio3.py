#DEFINIENDO VARIABLES
n = 0
b = 0.0
divisor = 4
s = 0.0

#VALIDANDO DATOS
while n < 1:
    n = int(input("Ingrese el valor de N: "))

while b < 1 or b > 5:
    b = float(input("Ingrese el valor de b: "))

#RESOLVIENDO
for i in range(1, n+1):
    s += (-1)**(i+1) * ( ((2*i)*b) / divisor)
    divisor += 3

print(f"Resultado: {round(s,6)}")