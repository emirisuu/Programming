# Write your solution here
def longest_series_of_neighbours(list):
    longest = 0
    temp = 1
    for i in range(len(list)):
        if i != len(list) - 1:
            if list[i] == list[i + 1] - 1 or list[i] == list[i + 1] + 1:
                temp += 1
            else:
                if temp > longest:
                    longest = temp
                temp = 1
        else:
            if temp > longest:
                longest = temp
    return longest
        
if __name__ == "__main__":
    print(longest_series_of_neighbours([5, 3, 4, 2, 3, 1, 2, 3, 9, 8, 7, 8, 7, 6, 7, 6]))