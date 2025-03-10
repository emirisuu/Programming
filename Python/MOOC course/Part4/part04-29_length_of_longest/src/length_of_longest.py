# Write your solution here
def length_of_longest(list):
    longest = list[0]
    for word in list:
        if len(word) >= len(longest):
            longest = word
    return len(longest)