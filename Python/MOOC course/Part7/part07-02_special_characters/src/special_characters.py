# Write your solution here
import string
def separate_characters(my_string: str):
    str1 = ""
    str2 = ""
    str3 = ""
    for letter in my_string:
        if letter in string.ascii_letters:
            str1 += letter
            my_string = my_string.replace(letter, "")
    for letter in my_string:
        if letter in string.punctuation:
            str2 += letter
            my_string = my_string.replace(letter, "")
    str3 = my_string
    return str1, str2, str3
