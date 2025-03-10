# Write your solution here
# Remember the import statement
# from datetime import date
from datetime import date
def list_years(dates: list):
    new_list = []
    for year in dates:
        temp = year.year
        new_list.append(temp)
    return sorted(new_list)