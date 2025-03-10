class Item:
    def __init__(self, name: str, weight: int):
        self.__name = name
        self.__weight = weight
    
    def name(self):
        return self.__name
    
    def weight(self):
        return self.__weight
    
    def __str__(self):
        return f"{self.name()} ({self.weight()} kg)"

class Suitcase:
    def __init__(self, max_weight: int):
        self.max_weight = max_weight
        self.items = []

    def add_item(self, item: Item):
        self.item = item
        temp = self.weight()
        if temp + self.item.weight() <= self.max_weight:
            self.items.append(self.item)

    def __str__(self):
        if len(self.items) == 1:
            return f"{len(self.items)} item ({self.weight()} kg)"
        return f"{len(self.items)} items ({self.weight()} kg)"

    def print_items(self):
        for item in self.items:
            print(item)

    def weight(self):
        weight = 0
        for item in self.items:
            weight += item.weight()
        return weight

    def heaviest_item(self):
        if self.items is not None:
            heaviest = self.items[0]
            for item in self.items:
                if item.weight() > heaviest.weight():
                    heaviest = item
            return heaviest
        return None

class CargoHold:
    def __init__(self, max_weight: int):
        self.max_weight = max_weight
        self.items = []
        self.combined_weight = 0
    
    def add_suitcase(self, suitcase: Suitcase):
        self.suitcase = suitcase
        if self.combined_weight + self.suitcase.weight() <= self.max_weight:
            self.items.append(suitcase)
            self.combined_weight += self.suitcase.weight()

    def __str__(self):
        if len(self.items) == 1:
            return f"{len(self.items)} suitcase, space for {self.max_weight - self.combined_weight} kg"
        return f"{len(self.items)} suitcases, space for {self.max_weight - self.combined_weight} kg"

    def print_items(self):
        for suitcase in self.items:
            for item in suitcase.items:
                print(item)


if __name__ == "__main__":
    book = Item("ABC Book", 2)
    phone = Item("Nokia 3210", 1)
    brick = Item("Brick", 4)

    adas_suitcase = Suitcase(10)
    adas_suitcase.add_item(book)
    adas_suitcase.add_item(phone)

    peters_suitcase = Suitcase(10)
    peters_suitcase.add_item(brick)

    cargo_hold = CargoHold(1000)
    cargo_hold.add_suitcase(adas_suitcase)
    cargo_hold.add_suitcase(peters_suitcase)

    print("The suitcases in the cargo hold contain the following items:")
    cargo_hold.print_items()