import pandas as pd
import os
from msvcrt import getch

def menu():
    print("1. Imprimir DF")
    print("2. Mostrar las dimensiones del DataFrame")
    print("3. Mostrar los datos del pasajero con identificador 148")
    print("4. Mostrar las filas pares del DataFrame")
    print("5. Mostrar los nombres de las personas que iban en primera clase ordenadas alfabéticamente")
    print("6. Mostrar el porcentaje de personas que sobrevivieron y murieron")
    print("7. Mostrar el porcentaje de personas que sobrevivieron en cada clase")
    print("8. Eliminar del DataFrame los pasajeros con edad desconocida")
    print("9. Mostrar la edad promedio o media de las mujeres que viajaban en cada clase")
    print("10. Añadir una nueva columna booleana para ver si el pasajero era menor de edad o no",
          "\n  Mostrar el porcentaje de menores y mayores de edad que sobrevivieron en cada clase")


#A) Generar un DataFrame con los datos del archivo
archivo = open("titanic.csv", encoding="utf-8")
dfTitanic = pd.read_csv(archivo, index_col=0)
opcion = 0

while True:
    menu()
    opcion = int(input("Ingrese una opcion: "))

    if opcion == 1:
        print(dfTitanic)
    elif opcion == 2:
        print("Dimensiones: ", dfTitanic.shape)
        print("Numero elementos: ", dfTitanic.size)
        print("Nombres de filas: ", dfTitanic.index)
        print("Nombres de columnas: ", dfTitanic.columns)
        print("Tipo de dato: \n", dfTitanic.dtypes)
        print("Primeras 10 filas: \n", dfTitanic.head(10))
        print("Ultimas 10 filas: \n", dfTitanic.tail(10))
    elif opcion == 3:
        print(dfTitanic.loc[148])
    elif opcion == 4:
        print(dfTitanic.iloc[range(1,dfTitanic.shape[0],2)])
    elif opcion == 5:
        print(dfTitanic[dfTitanic["Pclass"]==1]["Name"].sort_values())
    elif opcion == 6:
        print(dfTitanic["Survived"].value_counts()/ dfTitanic["Survived"].count() * 100)
        #SOLUCION ALTERNA
        print("========SOLUCION ALTERNA========")
        print(dfTitanic["Survived"].value_counts(normalize=True) * 100)
    elif opcion == 7:
        print(dfTitanic.groupby("Pclass")["Survived"].value_counts(normalize=True) * 100)
    elif opcion == 8:
        print(dfTitanic.dropna(subset=["Age"]))
    elif opcion == 9:
        #print(dfTitanic.Sex.value_counts()["female"])
        print(dfTitanic.groupby(["Pclass","Sex"])["Age"].mean().unstack()["female"])
    elif opcion == 10:
        dfTitanic["Young"] = dfTitanic["Age"] < 18
        print(dfTitanic["Young"])
        #SEGUNDA PARTE SOLUCION
        print("========SEGUNDA PARTE SOLUCION========")
        print(dfTitanic.groupby(["Pclass","Young"])["Survived"].value_counts(normalize=True) * 100)

    getch()
    os.system("cls")