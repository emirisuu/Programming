# Write your solution here
def squared(text, length):
    temp = ""
    for i in range(0, length):
        while len(temp) < length:
            temp += text
        print(temp[:length])
        temp = temp[length:]

if __name__ == "__main__":
    squared("aybabtu", 5)