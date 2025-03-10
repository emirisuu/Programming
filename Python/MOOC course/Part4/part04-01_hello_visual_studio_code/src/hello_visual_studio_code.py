# Write your solution here
while True:
    editor = input("Editor:")
    if editor.lower() == "visual studio code":
        print("an excellent choice!")
        break
    elif editor.lower() == "word" or editor.lower() == "notepad":
        print("awful")
    else:
        print("not good")