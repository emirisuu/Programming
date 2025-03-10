# Write your solution here
def factorials(n: int):
    factorial = {}
    for number in range(1, n + 1):
        temp = 1
        for i in range(2, number + 1):
            temp *= i
        factorial[number] = temp
    return factorial