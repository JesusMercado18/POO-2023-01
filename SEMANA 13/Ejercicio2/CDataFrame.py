class dataFrame():
    def __init__(self, df):
        self.__df = df

    #PRIMERA FORMA DE TRABAJAR
    def balance(self, listaMeses):
        self.__df["Balance"] = self.__df.Ventas - self.__df.Gastos
        return self.__df[self.__df.Mes.isin(listaMeses)].Balance.sum()

    #SEGUNDA FORMA DE TRABAJAR
    def balanceB(self, listaMeses):
        self.__df["Balance"] = self.__df.Ventas - self.__df.Gastos
        return self.__df.set_index("Mes").loc[listaMeses,"Balance"].sum()