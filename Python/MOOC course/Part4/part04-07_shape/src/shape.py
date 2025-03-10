# Copy here code of line function from previous exercise and use it in your solution
def line(number, string):
    if string == "":
        print("*" * number)
    else:
        print(string[0] * number)

def shape(triangle_length, triangle_character, rectangle_length, rectangle_character):
    for i in range(triangle_length):
        line(i + 1, triangle_character)
    for i in range(rectangle_length):
        line(triangle_length, rectangle_character)
# You can test your function by calling it within the following block
if __name__ == "__main__":
    shape(5, "x", 2, "o")