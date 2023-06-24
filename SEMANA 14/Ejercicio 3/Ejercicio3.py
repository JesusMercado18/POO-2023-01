import pandas as pd
import matplotlib.pyplot as plt

def graficoEvolucionIngresosGastos(dfDatos):
    #DEFIMOS NUESTRA FIGURA Y LOS EJES
    fig, ax = plt.subplots()
    #DIBUJAMOS EL GRAFICO DE LINEAS
    dfDatos.plot(kind="line",ax=ax)
    #AÑADIMOS LA ESCALA EN EL EJE Y
    ax.set_ylim([0, max(dfDatos.Ingresos.max(), dfDatos.Gastos.max()) + 500 ])
    #AÑADIMOS TITULO
    plt.title("Evolucion de ingresos y gastos")
    #DEVOLVEMOS EL OBJETO CON LOS EJES Y EL GRAFICO QUE CONTIENE
    return ax

#CREAMOS NUESTRO DICCIONARIO CON DATOS
dictDatos = {
        "Mes":["Enero","Febrero","Marzo","Abril"],
        "Ingresos":[3405,5340,1024,5034],
        "Gastos":[1023,1203,1954,1846]
    }
dfDatos = pd.DataFrame(dictDatos).set_index("Mes")

graficoEvolucionIngresosGastos(dfDatos)
plt.show()