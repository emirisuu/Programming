# Write your solution here
def find_words(search_term: str):
    words = []
    with open("words.txt") as new_file:
        if "." in search_term:
            indexes = []
            for letter in search_term:
                if letter == ".":
                    indexes.append(0)
                else:
                    indexes.append(letter)
            for line in new_file:
                line = line.replace("\n", "")
                k = 0
                if len(line) == len(indexes):
                    for i in range(len(line)):
                        if indexes[i] == 0:
                            continue
                        else:
                            if indexes[i] != line[i]:
                                k = 1
                                break
                else:
                    continue
                if k == 0:
                    words.append(line)
            return words
        if "*" in search_term:
            if search_term[0] == "*":
                temp = search_term[1:]
                for line in new_file:
                    line = line.replace("\n", "")
                    if line.endswith(temp):
                        words.append(line)
            else:
                temp = search_term[:-1]
                for line in new_file:
                    line = line.replace("\n", "")
                    if line.startswith(temp):
                        words.append(line)
            return words
        else:
            for line in new_file:
                line = line.replace("\n", "")
                if search_term == line:
                    words.append(line)
            return words
