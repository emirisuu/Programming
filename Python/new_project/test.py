import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


def diamonds_heat_map(data):
    price_min = price_input("minimum")
    price_max = price_input("maximum")
    if price_max < price_min:
        print("Maximum price can not be lower than minimum price")
        print()
        price_max = price_input("maximum")
    #print(data)
    print("Possible diamond colors are:")
    print()
    colors = pd.Series(data["color"].unique())
    colors_list = []
    for color in colors:
        colors_list.append(color)
        print(color, end=" ")
    print()
    while True:
        color = input("Enter diamond color from the given list above:")
        if color not in colors_list:
            print("*** There is no such color ***")
            print()
            print()
            continue
        break
    print("Possible diamond clarities are:")
    print()
    clarities = pd.Series(data['clarity'].unique())
    clarities_list = []
    for clarity in clarities:
        clarities_list.append(clarity)
        print(clarity, end=" ")
    print()
    while True:
        clarity = input("Enter diamond clarity from the given list above:")
        if clarity not in clarities_list:
            print("*** There is no such clarity in selected color ***")
            print()
            print()
            continue
        break
    data = data[(data['color'] == color) & (data['clarity'] == clarity)]
    prices = pd.Series(data['price'])
    prices = prices.between(price_min, price_max)
    prices_list = []
    index_list = []
    for index in data.index:
        index_list.append(index)
    for price in prices:
        prices_list.append(price)
    length = len(index_list)
    for i in range(length):
        if prices_list[i] == False:
            data = data.drop(labels = [index_list[i]], axis=0)
    diamonds = data.pivot_table(index="cut", columns="carat", values="price")
    f, ax = plt.subplots(figsize=(9, 6))
    f.suptitle(f"Diamond prices of {clarity} clarity and {color} color from your budget [{price_min},{price_max}]")
    sns.heatmap(diamonds, annot=False, fmt="f", linewidths=.5, ax=ax)
    plt.show()


def price_input(name: str):
    while True:
        try:
            price = int(input(f"Enter {name} price of diamonds:"))
            if price < 0:
                print("*** Please enter a positive number ***")
                print()
                continue
            return price
        except ValueError:
            print("*** Please enter a number ***")
            print()



dataset = sns.load_dataset("diamonds")
diamonds_heat_map(dataset)