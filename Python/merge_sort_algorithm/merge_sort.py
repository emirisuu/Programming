import random
import time

def merge_sort(numbers: list, left_index: int, right_index: int):
    if left_index < right_index:
        middle = (left_index + (right_index - 1)) // 2
        merge_sort(numbers, left_index, middle)
        merge_sort(numbers, middle + 1, right_index)
        merge(numbers, left_index, middle, right_index)
    
def merge(numbers: list, left_index: int, middle: int, right_index: int):
    first_half_length = middle - left_index + 1
    second_half_length = right_index - middle
    first_half = [0] * first_half_length
    second_half = [0] * second_half_length

    for index in range(first_half_length):
        first_half[index] = numbers[left_index + index]
    
    for index in range(second_half_length):
        second_half[index] = numbers[middle + 1 + index]
    
    first_half_index = 0
    second_half_index = 0
    numbers_index = left_index

    while first_half_index < first_half_length and second_half_index < second_half_length:
        if first_half[first_half_index] <= second_half[second_half_index]:
            numbers[numbers_index] = first_half[first_half_index]
            first_half_index += 1
        else:
            numbers[numbers_index] = second_half[second_half_index]
            second_half_index += 1
        numbers_index += 1
    
    while first_half_index < first_half_length:
        numbers[numbers_index] = first_half[first_half_index]
        first_half_index += 1
        numbers_index += 1
    
    while second_half_index < second_half_length:
        numbers[numbers_index] = second_half[second_half_index]
        second_half_index += 1
        numbers_index += 1

def test(list_length: int):
    numbers = random.choices(range(1, 1000), k=list_length)
    #print("Pradinis masyvas:", numbers)
    start_time = time.process_time()
    merge_sort(numbers, 0, len(numbers) - 1)
    end_time = time.process_time()
    total_time = end_time - start_time
    #print("Surikiuotas masyvas:", numbers)
    print("Algoritmo laikas:", total_time)

if __name__ == "__main__":

    for length in range(1,11):
        test(length * 10000)
    