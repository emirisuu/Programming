import random
def words(n: int, beginning: str):
    word_list = []
    with open("words.txt") as my_file:
        for line in my_file:
            line = line.replace("\n", "")
            if line.startswith(beginning):
                word_list.append(line)
    if len(word_list) < n:
        raise ValueError
    random_words = random.sample(word_list, n)
    return random_words