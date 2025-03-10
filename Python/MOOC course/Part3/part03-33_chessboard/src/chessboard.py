# Write your solution here
def chessboard(length):
    for i in range(0, length):
        string = ""
        if i % 2 != 0:
            k = 1
        else:
            k = 0
        for j in range(0, length):
            if k == 0:
                string += "1"
                k = 1
            else:
                string += "0"
                k = 0
        print(string)
        

# Testing the function
if __name__ == "__main__":
    chessboard(4)
