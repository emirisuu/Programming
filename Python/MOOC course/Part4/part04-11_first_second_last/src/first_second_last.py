# Write your solution here
def first_word(sentence):
    index = sentence.find(" ")
    return sentence[:index]

def second_word(sentence):
    index = sentence.find(" ")
    sentence = sentence[index + 1:]
    index = sentence.find(" ")
    if index < 0:
        return sentence
    return sentence[:index]

def last_word(sentence):
    while True:
        index = sentence.find(" ")
        if index < 0:
            return sentence
        else:
            sentence = sentence[index + 1:]
# You can test your function by calling it within the following block
if __name__ == "__main__":
    sentence = "once upon a time there was a programmer"
    print(first_word(sentence))
    print(second_word(sentence))
    print(last_word(sentence))