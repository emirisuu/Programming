class ListHelper:
    @classmethod
    def greatest_frequency(cls, my_list: list):
        counters = {}
        for number in my_list:
            if number not in counters:
                temp = my_list.count(number)
                counters[number] = temp
        most_common = 0
        for name, value in counters.items():
            if value > most_common:
                most_common = value
                most_common_name = name
        return most_common_name
    
    @classmethod
    def doubles(cls, my_list: list):
        items = []
        for number in my_list:
            if number not in items:
                temp = my_list.count(number)
                if temp >= 2:
                    items.append(number)
        return len(items)