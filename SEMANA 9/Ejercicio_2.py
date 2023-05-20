import random as r

#GENERANDO DATOS RANDOM
#TTTT = r.randint(1000,9999)
#HH = r.randint(1,24)
#MM = r.randint(1,60)
#SS = r.randint(1,60)

#print(f"El codigo generado es: {TTTT}{HH}{MM}{SS}")
#print(f"El codigo del trabajador es: {TTTT}")
#print(f"La hora de entrada del trabajador es: {HH}")
#print(f"El minuto de entrada del trabajador es: {MM}")
#print(f"El segundo de entrada del trabajador es: {SS}")

#INGRESANDO DATOS MANUALMENTE
codigo = int(input("Ingrese el codigo: "))

TTTT = codigo // 1000000
restoTTTT = codigo % 1000000
HH = restoTTTT // 10000
restoHH = restoTTTT % 10000
MM = restoHH // 100
SS = restoHH % 100

#MOSTRANDO DATOS
print(TTTT)
print(HH)
print(MM)
print(SS)