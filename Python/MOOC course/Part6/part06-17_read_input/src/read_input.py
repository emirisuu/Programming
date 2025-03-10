# Write your solution here
def read_input(string: str, bound1: int, bound2: int):
    while True:
        try:
            number = int(input(string))
            if number >= bound1 and number <= bound2:
                return number
        except ValueError:
            pass
        print(f"You must type in an integer between {bound1} and {bound2}")
        
