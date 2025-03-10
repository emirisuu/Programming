class Person:
    def __init__(self, name: str, height: int):
        self.name = name
        self.height = height

    def __str__(self):
        return self.name

class Room:
    def __init__(self):
        self.room = []

    def add(self, person: Person):
        self.room.append(person)
    
    def is_empty(self):
        if len(self.room) != 0:
            return False
        return True
    
    def print_contents(self):
        height = 0
        for person in self.room:
            height += person.height
        print(f"There are {len(self.room)} persons in the room, and their combined height is {height} cm")
        for person in self.room:
            print(f"{person.name} ({person.height} cm)")

    def shortest(self):
        if self.room is not None:
            for person in self.room:
                min_height = person.height
            for person in self.room:
                if person.height < min_height:
                    min_height = person.height
            for person in self.room:
                if person.height == min_height:
                    min_height = person
                    return min_height
        return None
    
    def remove_shortest(self):
        if self.is_empty():
            return None
        person = self.shortest()
        self.room.remove(person)
        return person

if __name__ == "__main__":
    room = Room()

    print("Is the room empty?", room.is_empty())
    print("Shortest:", room.shortest())

    room.add(Person("Lea", 183))
    room.add(Person("Kenya", 172))
    room.add(Person("Nina", 162))
    room.add(Person("Ally", 166))

    print()

    print("Is the room empty?", room.is_empty())
    print("Shortest:", room.shortest())

    print()

    room.print_contents()