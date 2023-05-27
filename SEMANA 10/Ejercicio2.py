#DEFINIENDO VARIABLES
numero = 0
cont = 0
ultimoTermino = 0

#VALIDANDO DATOS
while numero < 4 or numero > 15:
    numero = int(input("Ingrese un numero: "))

#RECORDAR QUE PARA DIBUJAR PRIMERO SE COMIENZA CON LAS FILAS Y LUEGO LAS COLUMNAS
for filas in range(1, numero + 1):
    #RESTAR CON 32 PORQUE LA PIRAMIDE SE EMPIEZA A DIBUJAR DESDE UNA POSICION 32 Y VA RESTANDO FILAS PARA REALIZAR ESPACIOS
    for espacios in range(1, 32 - filas + 1):
        print(" ", end="") #PARA DIBUJAR EN PYTHON SE DEBE PONER, end="" PARA QUE HAGA SALTOS DE LINEA
    ultimoTermino = filas + cont

    for columnas in range(1, ultimoTermino + 1):
        if columnas == 1 or columnas == ultimoTermino: #PARA VALIDAR BORDES
            if filas % 2 == 0: #SI LA FILA ES PAR SE TIENE QUE DIBUJAR |
                print("|", end="")
            else: #DE LO CONTRARIO SI ES IMPAR SE TIENE QUE DIBUJAR _
                print("_", end="")
        else: #PARA DIBUJAR EL CONTENIDO DE LA PIRAMIDE CON .
            print(".",end="")
    cont += 1
    print("\n",end="")