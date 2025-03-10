# Write your solution here
def histogram(string):
    dictionary = {}
    for item in string:
        if item not in dictionary:
            dictionary[item] = 0
        dictionary[item] += 1
    star = "*"
    for key, value in dictionary.items():
        print(f"{key} {star * value}")