# Write your solution here
import string

def change_case(orig_string: str):
    new_string = ""
    for letter in orig_string:
        if letter.isupper():
            new_string += letter.lower()
            continue
        elif letter.islower():
            new_string += letter.upper()
            continue
        new_string += letter
    return new_string

def split_in_half(orig_string: str):
    if len(orig_string) % 2 == 0:
        first_half = orig_string[:len(orig_string) // 2]
        second_half = orig_string[len(orig_string) // 2:]
        return first_half, second_half
    else:
        first_half = orig_string[:len(orig_string) // 2]
        second_half = orig_string[len(orig_string) // 2:]
        return first_half, second_half

def remove_special_characters(orig_string: str):
    str = ""
    for letter in orig_string:
        if letter not in string.ascii_letters and letter not in string.digits and letter not in string.whitespace:
            continue
        str += letter
    return str

if __name__ == "__main__":
    print(change_case("Well hello there!"))
    p1, p2 = split_in_half("abcd")
    print(p1)
    print(p2)
    m2 = remove_special_characters("This is a test, lets see how it goes!!!11!")
    print(m2)