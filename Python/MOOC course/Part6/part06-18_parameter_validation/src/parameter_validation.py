# Write your solution here
def new_person(name: str, age: int):
    if name == "":
        raise ValueError
    parts = name.split(" ")
    if len(parts) < 2:
        raise ValueError
    if len(name) > 40:
        raise ValueError
    if age < 0 or age > 150:
        raise ValueError
    return name, age
