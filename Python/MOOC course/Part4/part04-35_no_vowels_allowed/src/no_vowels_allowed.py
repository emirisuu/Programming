# Write your solution here
def no_vowels(string):
    new_string = string.replace("a", "")
    new_string = new_string.replace("i", "")
    new_string = new_string.replace("e", "")
    new_string = new_string.replace("u", "")
    new_string = new_string.replace("o", "")
    return new_string
