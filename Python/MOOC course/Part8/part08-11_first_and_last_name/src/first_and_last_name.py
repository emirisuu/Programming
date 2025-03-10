# Write your solution here:
class Person:
    def __init__(self, name: str):
        self.name = name

    def return_first_name(self):
        temp = self.name
        temp1 = temp.split()
        return temp1[0]

    def return_last_name(self):
        temp = self.name
        temp1 = temp.split()
        return temp1[1]