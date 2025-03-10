# Write your solution here
password = input("Password:")
while True:
    repeat_password = input("Repeat password:")
    if repeat_password == password:
        print("User account created!")
        break
    else:
        print("They do not match!")