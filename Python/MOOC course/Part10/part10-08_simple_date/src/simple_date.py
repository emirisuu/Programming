class SimpleDate:
    def __init__(self, day: int, month: int, year: int):
        self._day = day
        self._month = month
        self._year = year

    def __str__(self):
        return f"{self._day}.{self._month}.{self._year}"

    def __setvalue(self):
        return self._day + self._month * 30 + self._year * 360
    
    def __lt__(self, another):
        return self.__setvalue() < another.__setvalue()
    
    def __gt__(self, another):
        return self.__setvalue() > another.__setvalue()
    
    def __eq__(self, another):
        return self.__setvalue() == another.__setvalue()
    
    def __ne__(self, another):
        return self.__setvalue() != another.__setvalue()
    
    def __add__(self, another):
        new = self.__setvalue() + another
        years = new // 360
        months = (new - years * 360) // 30
        days = new - years * 360 - months * 30
        new_object = SimpleDate(days, months, years)
        return new_object

    def __sub__(self, another):
        return abs(self.__setvalue() - another.__setvalue())











if __name__ == "__main__":
    d1 = SimpleDate(4, 10, 2020)
    d2 = SimpleDate(28, 12, 1985)

    d3 = d1 + 3
    d4 = d2 + 400

    print(d1)
    print(d2)
    print(d3)
    print(d4)