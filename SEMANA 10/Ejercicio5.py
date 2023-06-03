#DEFINIENDO
medioTransporte = " "
tiempoDuracion = 0
momentoDia = 0
rutaElegida = " "
encuestas = []
#CONTADORES
contA = 0
contT = 0
contP = 0

contMomento1 = 0
contMomento2 = 0
contMomento3 = 0
contMomento4 = 0


contRutaA = 0.0
sumTiempoA = 0.0

contRutaB = 0.0
sumTiempoB = 0.0

contRutaC = 0.0
sumTiempoC = 0.0

contRutaO = 0.0
sumTiempoO = 0.0

promA = 0.0
promB = 0.0
promC = 0.0
promO = 0.0

#VALIDANDO
while medioTransporte.upper() != "X":
    medioTransporte = " "
    tiempoDuracion = 0
    momentoDia = 0
    rutaElegida = " "
    #VALIDANDO DATOS DE ENTRADA
    while medioTransporte.upper() != "A" and medioTransporte.upper() != "T" and medioTransporte.upper() != "P" and medioTransporte.upper() != "X":
        medioTransporte = input("Medio de transporte (A: Auto propio; T: Privado (Taxi); P: Transporte público): ")
    if medioTransporte.upper() == "X":
        break

    while tiempoDuracion < 1:
        tiempoDuracion = int(input("Tiempo de duracion del viaje (Expresado en minutos): "))

    while momentoDia < 1 or momentoDia > 4:
        momentoDia = int(input("Momento del dia (1: Entre 7:00 y 9:00; 2: Entre 12:00 y 14:00; 3: Entre 17:00 y 19:00; 4: A partir de las 22:00): "))

    while rutaElegida.upper() != "A" and rutaElegida.upper() != "B" and rutaElegida.upper() != "C" and rutaElegida.upper() != "O":
        rutaElegida = input("Ruta elegida (A: Av. Arequipa; B: Av. Brasil; C: Paseo de la República; O: Otra ruta): ")

    print("\n")
    #CREANDO DICCIONARIO
    usuario = dict(MedioTransporte = medioTransporte.upper(), TiempoDuracion = tiempoDuracion, 
                    MomentoDia = momentoDia, RutaElegida = rutaElegida.upper())
    encuestas.append(usuario)

#RESOLVIENDO
for i in encuestas:
    #REPORTE 1: Cantidad de usuarios por medio de transporte
    if i.get("MedioTransporte") == "A":
        contA += 1
    if i.get("MedioTransporte") == "T":
        contT += 1
    if i.get("MedioTransporte") == "P":
        contP += 1

    #REPORTE 2: Momentos con mayor cantidad de viajes
    if i.get("MomendoDia") == 1:
        contMomento1 += 1
    if i.get("MomendoDia") == 2:
        contMomento2 += 1
    if i.get("MomendoDia") == 3:
        contMomento3 += 1
    if i.get("MomendoDia") == 4:
        contMomento4 += 1

    #REPORTE 3: Tiempo promedio de viaje por ruta
    if i.get("RutaElegida") == "A":
        contRutaA += 1
        sumTiempoA += i.get("TiempoDuracion")
    if i.get("RutaElegida") == "B":
        contRutaB += 1
        sumTiempoB += i.get("TiempoDuracion")
    if i.get("RutaElegida") == "C":
        contRutaC += 1
        sumTiempoC += i.get("TiempoDuracion")
    if i.get("RutaElegida") == "O":
        contRutaO += 1
        sumTiempoO += i.get("TiempoDuracion")

#IMPRIMIENDO
print("Medio Transporte\t Tiempo Duracion\t Momento Dia\t Ruta Elegida")
for i in encuestas:
    print(i.get("MedioTransporte"), i.get("TiempoDuracion"),i.get("MomentoDia"),i.get("RutaElegida"), sep="\t ")

print("Cantidad de usuarios por medio de transporte: ")
print(f"Auto propio: {contA}")
print(f"Privado: {contT}")
print(f"Transporte publico: {contP}")

print("\nMomento con mayor cantidad de viajes son: ")
if contMomento1 > contMomento2 and contMomento1 > contMomento3 and contMomento1 > contMomento4:
    print(f"El momento del dia con mas viajes es 1 con la cantidad de {contMomento1}")
if contMomento2 > contMomento1 and contMomento2 > contMomento3 and contMomento2 > contMomento4:
    print(f"El momento del dia con mas viajes es 2 con la cantidad de {contMomento2}")
if contMomento3 > contMomento1 and contMomento3 > contMomento2 and contMomento3 > contMomento4:
    print(f"El momento del dia con mas viajes es 3 con la cantidad de {contMomento3}")
if contMomento4 > contMomento1 and contMomento4 > contMomento3 and contMomento4 > contMomento1:
    print(f"El momento del dia con mas viajes es 4 con la cantidad de {contMomento4}")
if contMomento1 >= contMomento2 or contMomento1 >= contMomento3 or contMomento1 > contMomento4:
    print(f"El momento del dia con mas viajes es 4 con la cantidad de {contMomento4}")

print("\nTiempo promedio de viaje por ruta son: ")
promA = sumTiempoA / contRutaA
promB = sumTiempoB / contRutaB
promC = sumTiempoC / contRutaC
#promO = sumTiempoO / contRutaO
print(f"Av. Arequipa: {promA}")
print(f"Av. Brasil: {promB}")
print(f"Av. Paseo de la republica: {promC}")
#print(f"Otra ruta: {promO}")