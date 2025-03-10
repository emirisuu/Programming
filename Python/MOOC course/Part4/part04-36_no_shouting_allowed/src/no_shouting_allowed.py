# Write your solution here
def no_shouting(list):
    new_list = []
    for i in list:
        if i.isupper() == False:
            new_list.append(i)
    return new_list