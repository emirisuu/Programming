# WRITE YOUR SOLUTION HERE:
class Present:
    def __init__(self, name: str, weight: int):
        self.name = name
        self.weight = weight

    def __str__(self):
        return f"{self.name} ({self.weight})"

class Box:
    def __init__(self):
        self.box = []

    def add_present(self, present: Present):
        self.box.append(present)

    def total_weight(self):
        weight = 0
        for present in self.box:
            weight += present.weight
        return weight