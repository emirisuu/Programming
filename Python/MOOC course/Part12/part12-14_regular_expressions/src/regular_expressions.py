import re
def is_dotw(my_string: str):
    if re.search("Mon|Tue|Wed|Thu|Fri|Sat|Sun", my_string):
        return True
    return False

def all_vowels(my_string: str):
    for character in my_string:
        if re.search("[aeiuo]", character):
            continue
        else:
            return False
    return True

def time_of_day(my_string: str):
    my_string = my_string.split(":")
    if re.search("[0-1][0-9]|2[0-4]", my_string[0]) == None:
        return False
    for i in range(1,3):
        if re.search("[0-5][0-9]", my_string[i]) == None:
            return False
    return True


if __name__ == "__main__":
    print(time_of_day("12:43:01"))
    print(time_of_day("AB:01:CD"))
    print(time_of_day("17:59:59"))
    print(time_of_day("33:66:77"))