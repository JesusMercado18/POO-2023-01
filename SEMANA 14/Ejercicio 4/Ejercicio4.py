import pandas as pd
import matplotlib.pyplot as plt

#CREAMOS DF A PARTIR DEL ARCHIVO CSV
dfTitanic = pd.read_csv("titanic.csv")
#CREAMOS LA FIGURA Y LOS EJES
fig, ax = plt.subplots()
#1. Gráfico de tipo pie con los fallecidos y supervivientes
#dfTitanic.Survived.value_counts().plot(kind = "pie", labels = ["Muertos", "Supervivientes"], title = "Distribucion de supervivientes")
##ELIMINAMOS EL TITULO DEL EJE Y
#plt.ylabel(" ")
#plt.show()

#2. Histograma con las edades
#dfTitanic.Age.plot(kind = "hist", title = "Histograma de edades")
##ELIMINAMOS EL TITULO DEL EJE Y
#plt.ylabel(" ")
#plt.show()

#3. Gráfico de barras con el número de personas en cada clase
#dfTitanic.Pclass.value_counts().plot(kind = "bar", title = "Numero de personas por clase")
#ELIMINAMOS EL TITULO DEL EJE Y
#plt.ylabel(" ")
#plt.show()
 #SEGUNDA FORMA DE SOLUCION PARA EL PUNTO 3
#dfTitanic.groupby("Pclass").size().plot(kind = "bar", title = "Numero de personas por clase")
#ELIMINAMOS EL TITULO DEL EJE Y
#plt.ylabel(" ")
#plt.show()

#4. Gráfico de barras con el número de personas fallecidas y supervivientes en cada clase
#dfTitanic.groupby(["Pclass","Survived"]).size().unstack().plot(kind="bar", title="Numero de personas fallecidas y supervivientes de cada clase")
##ELIMINAMOS EL TITULO DEL EJE Y
#plt.ylabel(" ")
#plt.show()

#5. Gráfico de barras con el número de personas fallecidas y supervivientes acumuladas en cada clase
dfTitanic.groupby(["Pclass","Survived"]).size().unstack().plot(kind = "bar", stacked=True, title = "Numero de personas fallecidas y supervivientes acumuladas de cada clase")
#ELIMINAMOS EL TITULO DEL EJE Y
plt.ylabel(" ")
plt.show()