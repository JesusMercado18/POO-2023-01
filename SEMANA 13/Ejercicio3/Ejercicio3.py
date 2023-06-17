import CCotizacion as cc
import pandas as pd

archivo = open("cotizacion.csv", encoding="UTF-8")
objCotizacion = cc.CCotizacion(archivo)

print(objCotizacion.resumenCotizacion())