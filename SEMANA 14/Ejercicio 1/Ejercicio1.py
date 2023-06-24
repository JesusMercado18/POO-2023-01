import pandas as pd
import matplotlib.pyplot as plt

def graficoVentas(serieVentas, titulo):
    #DEFINIMOS LA FIGURA Y LOS EJES DEL GRAFICO CON MATPLOTLIB
    fig, ax = plt.subplots()
    #DIBUJAMOS EL GRAFICO DE VENTAS A PARTIR DE LA SERIE
    serieVentas.plot(kind = "pie", ax = ax)
    #ELIMINAMOS EL TITULO DEL EJE Y
    plt.ylabel(" ")
    #AÑADIMOS TITULO
    plt.title(titulo)
    #GUARDAMOS EL GRAFICO COMO IMAGEN PNG
    plt.savefig(titulo + ".png")
    plt.show()

#CREAMOS NUESTRO DICCIONARIO
ventas = {
        "Enero":2500,
        "Febrero":3500,
        "Marzo":4500
    }
#CREAMOS NUESTRA SERIE
serieVentas = pd.Series(ventas)
#SOLICITAMOS UN TITULO
titulo = input("Ingrese un titulo para el grafico: ")
graficoVentas(serieVentas,titulo)