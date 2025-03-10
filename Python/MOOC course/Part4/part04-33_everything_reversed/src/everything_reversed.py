# Write your solution here
def everything_reversed(list):
    new_list = []
    for i in list[::-1]:
        new_list.append(i[::-1])
    return new_list