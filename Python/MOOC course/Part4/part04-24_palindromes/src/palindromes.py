# Write your solution here
def palindromes(string):
    if string == string[::-1]:
        return True
    return False

while True:
    word = input("Please type in a palindrome:")
    if palindromes(word):
        print(word, "is a palindrome!")
        break
    print("that wasn't a palindrome")
# Note, that at this time the main program should not be written inside
# if __name__ == "__main__":
# block!
