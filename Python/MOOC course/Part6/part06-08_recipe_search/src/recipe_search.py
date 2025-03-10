# Write your solution here
def search_by_name(filename: str, word: str):
    recipes = []
    with open(filename) as new_file:
        recipe = []
        for line in new_file:
            if line == "\n":
                recipes.append(recipe)
                recipe = []
                continue
            line = line.replace("\n", "")
            recipe.append(line)
        recipes.append(recipe)
    found_recipes = []
    length = len(recipes)
    for i in range(length):
        if word in recipes[i][0].lower():
            found_recipes.append(recipes[i][0])
    return found_recipes

def search_by_time(filename: str, prep_time: int):
    recipes = []
    with open(filename) as new_file:
        recipe = []
        for line in new_file:
            if line == "\n":
                recipes.append(recipe)
                recipe = []
                continue
            line = line.replace("\n", "")
            recipe.append(line)
        recipes.append(recipe)
    found_recipes = []
    length = len(recipes)
    for i in range(length):
        if int(recipes[i][1]) <= prep_time:
            found_recipes.append(f"{recipes[i][0]}, preparation time {recipes[i][1]} min")
    return found_recipes

def search_by_ingredient(filename: str, ingredient: str):
    recipes = []
    with open(filename) as new_file:
        recipe = []
        for line in new_file:
            if line == "\n":
                recipes.append(recipe)
                recipe = []
                continue
            line = line.replace("\n", "")
            recipe.append(line)
        recipes.append(recipe)
    found_recipes = []
    length = len(recipes)
    for i in range(length):
        if ingredient in recipes[i][2:]:
            found_recipes.append(f"{recipes[i][0]}, preparation time {recipes[i][1]} min")
    return found_recipes