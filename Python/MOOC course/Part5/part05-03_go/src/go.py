# Write your solution here
def who_won(game_board: list):
    counter1 = 0
    counter2 = 0
    for row in game_board:
        for item in row:
            if item == 1:
                counter1 += 1
            elif item == 2:
                counter2 += 1
    if counter1 == counter2:
        return 0
    elif counter1 > counter2:
        return 1
    else:
        return 2