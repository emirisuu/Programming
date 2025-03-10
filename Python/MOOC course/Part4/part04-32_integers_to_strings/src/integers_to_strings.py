# Write your solution here
def formatted(list):
    new_list = []
    for i in list:
        new_list.append(f"{i:.2f}")
    return new_list