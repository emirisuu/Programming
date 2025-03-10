# Write your solution here
def list_sum(list1, list2):
    new_list = []
    for i in range(len(list1)):
        temp = list1[i] + list2[i]
        new_list.append(temp)
    return new_list