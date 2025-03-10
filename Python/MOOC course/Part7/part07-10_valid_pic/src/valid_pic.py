# Write your solution here
from datetime import datetime
def is_it_valid(pic: str):
    if len(pic) != 11:
        return False
    control_str = "0123456789ABCDEFHJKLMNPRSTUVWXY"
    birth = pic[:7]
    if birth[6] != "+" and birth[6] != "-" and birth[6] != "A":
        return False
    year = birth[4:6]
    if birth[6] == "+":
        temp = 1800
    elif birth[6] == "-":
        temp = 1900
    else:
        temp = 2000
    year = temp + int(year)
    day = int(birth[:2])
    month = int(birth[2:4])
    try:
        temp = datetime(year, month, day)
    except ValueError:
        return False
    nine_digit = birth[:6] + pic[7:10]
    index = int(nine_digit) % 31
    if pic[-1] != control_str[index]:
        return False
    return True

#print(is_it_valid("230827-906A"))