
class Money:
    def __init__(self, euros: int, cents: int):
        self._euros = euros
        self._cents = cents

    def __str__(self):
        return f"{self._euros}.{self._cents:02} eur"

    def __eq__(self, another):
        money1 = self._euros + self._cents / 100
        money2 = another._euros + another._cents / 100
        return money1 == money2

    def __lt__(self, another):
        money1 = self._euros + self._cents / 100
        money2 = another._euros + another._cents / 100
        return money1 < money2

    def __gt__(self, another):
        money1 = self._euros + self._cents / 100
        money2 = another._euros + another._cents / 100
        return money1 > money2

    def __ne__(self, another):
        money1 = self._euros + self._cents / 100
        money2 = another._euros + another._cents / 100
        return money1 != money2

    def __add__(self, another):
        money1 = self._euros + self._cents / 100
        money2 = another._euros + another._cents / 100
        self._new = f"{money1 + money2:.2f} eur"
        return self._new

    def __sub__(self, another):
        money1 = self._euros + self._cents / 100
        money2 = another._euros + another._cents / 100
        if money1 - money2 < 0:
            raise ValueError("a negative result is not allowed")
        self._new = f"{money1 - money2:.2f} eur"
        return self._new



if __name__ == "__main__":
    e1 = Money(4, 5)
    e2 = Money(2, 95)

    e3 = e1 + e2
    e4 = e1 - e2

    print(e3)
    print(e4)

    e5 = e2-e1