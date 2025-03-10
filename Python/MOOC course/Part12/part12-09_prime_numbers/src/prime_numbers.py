def prime_numbers():
    number = 2
    i = number
    yield i
    i += 1
    while True:
        k = 0
        for item in range(number, i):
            if i % item == 0:
                k = 1
                break
        if k == 0:
            yield i
        i += 1