# Write your solution here
year = int(input("Year:"))
if year % 4 == 0:
    if year % 100 == 0:
        if year % 400 == 0:
            next_leap = year
            while True:
                next_leap += 4
                if next_leap % 4 == 0:
                    if next_leap % 100 == 0:
                        if next_leap % 400 == 0:
                            print(f"The next leap year after {year} is {next_leap}")
                            break
                    else:
                        print(f"The next leap year after {year} is {next_leap}")
                        break
    else:
        next_leap = year
        while True:
            next_leap += 4
            if next_leap % 4 == 0:
                if next_leap % 100 == 0:
                    if next_leap % 400 == 0:
                        print(f"The next leap year after {year} is {next_leap}")
                        break
                else:
                    print(f"The next leap year after {year} is {next_leap}")
                    break
else:
    next_leap = year
    while True:
        next_leap += 1
        if next_leap % 4 == 0:
            if next_leap % 100 == 0:
                if next_leap % 400 == 0:
                    print(f"The next leap year after {year} is {next_leap}")
                    break
            else:
                print(f"The next leap year after {year} is {next_leap}")
                break