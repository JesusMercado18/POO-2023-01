import pandas as pd
import matplotlib.pyplot as plt

def graficoEvolucionVentas(serieVentas, tipoGrafico):
    #DEFINIMOS EN UN DICCIONARIO LOS TIPOS DE GRAFICOS
    graficos = {"lineas":"line", "barras":"bar", "pie":"pie", "areas":"area"}
    #DEFINIMOS LA FIGURA Y LOS EJES DEL GRAFICO
    fig, ax = plt.subplots()
    #DIBUJAMOS LA SERIE DE VENTAS SEGUN EL TIPO DE GRAFICO
    serieVentas.plot(kind=graficos[tipoGrafico], ax = ax)
    #AÑADIMOS TITULO
    plt.title("EVOLUCION DEL NUMERO DE VENTAS")
    #DEVOLVER EL OBJETO CON LOS EJES Y EL GRAFICO QUE CONTIENE
    return ax

#CREAMOS NUESTRA SERIE
serieVentas = pd.Series([1250,2450,3000,4593,1294],index=[2000,2001,2002,2003,2004])
#SOLICITAMOS EL TIPO DE GRAFICO
tipoGrafico = input("Ingrese el tipo de grafico (lineas, barras, pie, areas): ")

graficoEvolucionVentas(serieVentas,tipoGrafico)
plt.show()