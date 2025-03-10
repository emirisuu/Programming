from string import punctuation

def most_common_words(filename: str, lower_limit: int):
    with open(filename) as new_file:
        file = new_file.read()
    file = file.replace('\n', " ")
    for letter in punctuation: file = file.replace(letter, "")
    file = file.split()
    return {word : file.count(word) for word in file if file.count(word) >= lower_limit}
    