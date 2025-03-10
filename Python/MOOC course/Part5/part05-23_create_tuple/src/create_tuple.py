# Write your solution here
def create_tuple(x: int, y: int, z: int):
    sum = x + y + z
    smallest = min(x, y, z)
    greatest = max(x, y, z)
    tuple = (smallest, greatest, sum)
    return tuple
