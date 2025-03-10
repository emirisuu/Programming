from random import randint
def word_generator(characters: str, length: int, amount: int):
    for i in range(amount):
        word = ""
        for j in range(length):
            word += characters[randint(0, len(characters) - 1)]
        yield word

if __name__ == "__main__":
    wordgen = word_generator("abcdefg", 3, 5)
    for word in wordgen:
        print(word)