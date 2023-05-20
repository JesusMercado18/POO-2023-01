#SOLICITAMOS DATOS
codigo = int(input("Ingrese el codigo del producto: "))
unidades = int(input("Ingrese la cantidad de unidades: "))

#HALLANDO EL PRIMER DIGITO DEL CODIGO
primerDigito = codigo//1000

#RESOLVIENDO
if primerDigito == 1:
    montoPagar = unidades*15.75 #IDENTACION => ESPACIO ENTRE EL COMIENZO DE ESTE CODIGO Y EL INICIO DONDE COLOCAMOS LA VARIABLE
elif primerDigito == 2:
    montoPagar = unidades*21
elif primerDigito == 3:
    montoPagar = unidades*8.5
elif primerDigito == 4:
    montoPagar = unidades*25
elif primerDigito == 5:
    montoPagar = unidades*13.25

if montoPagar < 100:
    print(f"El cliente no aplica para el descuento")
    print(f"El monto a pagar es: {montoPagar}")
elif montoPagar >= 100:
    descuento = montoPagar*0.11
    montoFinal = montoPagar - descuento
    print(f"El cliente aplica para un descuento del 11% y es: {descuento}")
    print(f"El monto a pagar es: {montoFinal}")