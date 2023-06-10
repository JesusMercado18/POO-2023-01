import Controlador as c
import os
from msvcrt import getch

#METODOS O FUNCIONES
def menu():
    print("1. Anadir")
    print("2. Incrementar segundo")
    print("3. Tiempo que falta para llegar al final del dia")
    print("4. Tiempo existente entre la menor y mayor hora")
    print("5. Listar")
    print("6. Salir")

#DEFINIMOS VARIABLES
objControlador = c.Controlador()
opcion = 0

while opcion != 6:
    hora = -1
    minuto = -1
    segundo = -1
    menu()
    opcion = int(input("Ingrese una opcion: "))

    if opcion == 1:
        while hora < 0 or hora > 23:
            hora = int(input("Ingrese una hora: "))
        while minuto < 0 or minuto > 59:
            minuto = int(input("Ingrese una minuto: "))
        while segundo < 0 or segundo > 59:
            segundo = int(input("Ingrese una segundo: "))
        objControlador.ingresarHora(hora,minuto, segundo)
        print("SE REGISTRO CON EXITO")
    elif opcion == 2:
        objControlador.aumentarSegundoAHora()
        print("SE AUMENTO CON EXITO")
    elif opcion == 3:
        objControlador.tiempoFinalDia()
    elif opcion == 4:
        objControlador.tiempoExistente()
    elif opcion == 5:
        objControlador.listarHora()

    getch()
    os.system("cls")

print("GRACIAS POR USAR EL SISTEMA...")