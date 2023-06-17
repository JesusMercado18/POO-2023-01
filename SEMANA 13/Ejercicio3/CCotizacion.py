import pandas as pd

class CCotizacion():
    def __init__(self, archivo):
        self.__archivo = archivo

    def resumenCotizacion(self):
        df = pd.read_csv(self.__archivo, decimal=",", thousands=".",index_col=0, delimiter=";")
        return pd.DataFrame([df.min(),df.max(),df.mean()], index=["Minimo","Maximo","Media"])