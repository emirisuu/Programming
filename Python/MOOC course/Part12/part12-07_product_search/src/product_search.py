def search(products: list, criterion: callable):
    list = []
    for product in products:
        if criterion(product):
            list.append(product)
    return list