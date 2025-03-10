# Write your solution here!
class  NumberStats:
    def __init__(self):
        self.numbers = 0
        self.sum = 0
        self.mean = 0

    def add_number(self, number:int):
        self.numbers += 1
        self.sum += number

    def count_numbers(self):
        return self.numbers
    
    def get_sum(self):
        return self.sum

    def average(self):
        if(self.numbers != 0):
            return self.sum / self.numbers
        return self.mean

print("Please type in integer numbers:")
stats = NumberStats()
even = NumberStats()
odd = NumberStats()
while True:
    number = int(input())
    if number == -1:
        print("Sum of numbers:", stats.get_sum())
        print("Mean of numbers:", stats.average())
        print("Sum of even numbers:", even.get_sum())
        print("Sum of odd numbers:", odd.get_sum())
        break
    stats.add_number(number)
    if(number % 2 == 0):
        even.add_number(number)
    else:
        odd.add_number(number)