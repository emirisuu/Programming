# Write your solution here
def longest(strings: list):
    longest_string = strings[0]
    for string in strings:
        if len(string) > len(longest_string):
            longest_string = string
    return longest_string