class Person:
    def __init__(self, name: str, numbers = None, address = None):
        self.__name = name
        if numbers is None:
            self.__numbers = []
        else: 
            self.__numbers = numbers
        self.__address = address

    def name(self):
        return self.__name

    def numbers(self):
        return self.__numbers
    
    def address(self):
        return self.__address
    
    def add_number(self, number: str):
        self.__numbers.append(number)

    def add_address(self, address: str):
        self.__address = address

    def __iter__(self):
        self.n = 0
        return self
    
    def __next__(self):
        if self.n < len(self.__numbers):
            number = self.__numbers[self.n]
            self.n += 1
            return number
        else:
            raise StopIteration

class PhoneBook:
    def __init__(self):
        self.__persons = {}

    def add_number(self, name: str, number: str):
        if not name in self.__persons:
            self.__persons[name] = Person(name)
        self.__persons[name].add_number(number)

    def add_address(self, name: str, address: str):
        if not name in self.__persons:
            self.__persons[name] = Person(name)
        self.__persons[name].add_address(address)

    def get_entry(self, name: str):
        if not name in self.__persons:
            return None
        return self.__persons[name]

    def all_entries(self):
        return self.__persons

class PhoneBookApplication:
    def __init__(self):
        self.__phonebook = PhoneBook()

    def help(self):
        print("commands: ")
        print("0 exit")
        print("1 add number")
        print("2 search")
        print("3 add address")

    def add_number(self):
        name = input("name: ")
        number = input("number: ")
        self.__phonebook.add_number(name, number)

    def add_address(self):
        name = input("name: ")
        address = input("address: ")
        self.__phonebook.add_address(name, address)

    def search(self):
        name = input("name: ")
        person = self.__phonebook.get_entry(name)
        if person == None:
            print("number unknown")
            print("address unknown") 
            return 
        if len(person.numbers()) == 0:
            print("number unknown")
            print(person.address())
            return
        if person.address() == None:
            for number in person.numbers():
                print(number)
            print("address unknown")
            return
        for number in person.numbers():
            print(number)
        print(person.address())   
            

    def execute(self):
        self.help()
        while True:
            print("")
            command = input("command: ")
            if command == "0":
                break
            elif command == "1":
                self.add_number()
            elif command == "2":
                self.search()
            elif command == "3":
                self.add_address()
            else:
                self.help()

if __name__ == "__main__":
    phonebook = PhoneBook()
    phonebook.add_number("Eric", "02-123456")
    print(phonebook.get_entry("Eric"))
    print(phonebook.get_entry("Emily"))
# when testing, no code should be outside application except the following:
application = PhoneBookApplication()
application.execute()
