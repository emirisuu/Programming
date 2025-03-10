# Write your solution here
def distinct_numbers(list):
    new_list = sorted(list)
    n = len(new_list)
    i = 0
    
    while i < n:
        j = i + 1
        while j < n:
            if new_list[i] == new_list[j]:
                new_list.pop(i)
                n -= 1
                i -= 1
                break
            j += 1
        i += 1
    return new_list

if __name__ == "__main__":
    print(distinct_numbers([3, 2, 1, 3, 2, 1, 3, 2, 1]))
    print(distinct_numbers([5, 6, 7, 8, 8, 9, 9, 5]))