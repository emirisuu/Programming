# Write your solution here
def spruce(lines):
    counter = 1
    print("a spruce!")
    whitespace = lines * 2 - 1
    for i in range(lines):
        print(" " * (whitespace // 2 - i) + "*" * counter)
        counter += 2
    print(" " * (whitespace // 2) + "*")
# You can test your function by calling it within the following block
if __name__ == "__main__":
    spruce(5)