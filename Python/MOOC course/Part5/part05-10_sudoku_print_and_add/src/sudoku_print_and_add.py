# Write your solution here
def print_sudoku(sudoku: list):
    for row in range(9):
        if row == 3 or row == 6:
            print()
        for column in range(9):
            if column == 3 or column == 6:
                print(" ", end = "")
                if sudoku[row][column] == 0:
                    print(f"_ ", end = "")
                else:
                    print(f"{sudoku[row][column]} ", end = "")
            elif column == 8:
                if sudoku[row][column] == 0:
                    print(f"_", end = "")
                else:
                    print(f"{sudoku[row][column]}", end = "")
            else:
                if sudoku[row][column] == 0:
                    print(f"_ ", end = "")
                else:
                    print(f"{sudoku[row][column]} ", end = "")
        print()

def add_number(sudoku: list, row_no: int, column_no: int, number: int):
    sudoku[row_no][column_no] = number

if __name__ == "__main__":
    s = [
  [ 9, 0, 0, 0, 8, 0, 3, 0, 0 ],
  [ 2, 0, 0, 2, 5, 0, 7, 0, 0 ],
  [ 0, 2, 0, 3, 0, 0, 0, 0, 4 ],
  [ 2, 9, 4, 0, 0, 0, 0, 0, 0 ],
  [ 0, 0, 0, 7, 3, 0, 5, 6, 0 ],
  [ 7, 0, 5, 0, 6, 0, 4, 0, 0 ],
  [ 0, 0, 7, 8, 0, 3, 9, 0, 0 ],
  [ 0, 0, 1, 0, 0, 0, 0, 0, 3 ],
  [ 3, 0, 0, 0, 0, 0, 0, 0, 2 ],
    ]
    print_sudoku(s)