# Write your solution here
import fractions
def fractionate(amount: int):
    fraction = []
    number = fractions.Fraction(1, amount)
    for i in range(amount):
        fraction.append(number)
    return fraction

