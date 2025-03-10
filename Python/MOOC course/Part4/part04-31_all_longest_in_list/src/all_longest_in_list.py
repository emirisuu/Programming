# Write your solution here
def all_the_longest(list):
    longest = list[0]
    new_list = []
    for word in list:
        if len(word) >= len(longest):
            longest = word
    for word in list:
        if len(word) == len(longest):
            new_list.append(word)
    return new_list