# Write your solution here
while True:
    print("1 - Add word, 2 - Search, 3 - Quit")
    function = int(input("Function:"))
    if function == 1:
        with open("dictionary.txt", "a") as new_file:
            finnish_word = input("The word in Finnish:")
            english_word = input("The word in English:")
            line = f"{finnish_word} {english_word}"
            new_file.write(line + "\n")
            print("Dictionary entry added")
    elif function == 2:
        with open("dictionary.txt") as new_file:
            search_term = input("Search term:")
            for line in new_file:
                line = line.replace("\n", "")
                parts = line.split(" ")
                if search_term in parts[0] or search_term in parts[1]:
                    print(f"{parts[0]} - {parts[1]}")
    else:
        print("Bye!")
        break
