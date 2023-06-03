import CContrasena as CC

#DEFINIMOS VARIABLES
longitud = int(input("Ingrese longitud: "))

#DECLARAMOS OBJETOS DE LA CLASE
objContrasena = CC.CContrasena(longitud)

#IMPRIMIMOS DATOS
objContrasena.mostrarDatos()

#COMPROBAMOS SI ES SEGURO O NO
if objContrasena.esSeguro() == True:
    print("CONTRASEÑA SEGURA")
elif objContrasena.esSeguro() == False:
    print("CONTRASEÑA NO SEGURA")