# Write your solution here
import random
def lottery_numbers(amount: int, lower: int, upper: int):
    numbers = list(range(lower, upper + 1))
    weekly_numbers = random.sample(numbers, amount)
    return sorted(weekly_numbers)
