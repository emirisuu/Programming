class Task:
    id = 0
    def __init__(self, description: str, name: str, estimate_hours: int):
        self.description = description
        self.programmer = name
        self.workload = estimate_hours
        self.__finished = "NOT FINISHED"
        self.id = Task.id + 1
        Task.id += 1

        
    def is_finished(self):
        if "NOT" in self.__finished:
            return False
        return True
    
    def mark_finished(self):
        self.__finished = "FINISHED"

    def __str__(self):
        return f"{self.id}: {self.description} ({self.workload} hours), programmer {self.programmer} {self.__finished}"

class OrderBook:
    def __init__(self):
        self.orders = []

    def add_order(self, description: str, programmer: str, workload: int):
        self.orders.append(Task(description, programmer, workload))

    def all_orders(self):
        return self.orders
    
    def programmers(self):
        names = []
        for order in self.orders:
            names.append(order.programmer)
        return list(set(names))

    def mark_finished(self, id: int):
        for order in self.orders:
            if id == order.id:
                order.mark_finished()
                return
        raise ValueError
    
    def finished_orders(self):
        finished = []
        for order in self.orders:
            if order.is_finished():
                finished.append(order)
        return finished
    
    def unfinished_orders(self):
        unfinished = []
        for order in self.orders:
            if order.is_finished() == False:
                unfinished.append(order)
        return unfinished

    def status_of_programmer(self, programmer: str):
        finished_tasks = 0
        unfinished_tasks = 0
        finished_workloads = 0
        unfinished_workloads = 0
        if programmer not in self.programmers():
            raise ValueError
        for order in self.finished_orders():
            if order.programmer == programmer:
                finished_tasks += 1
                finished_workloads += order.workload
        for order in self.unfinished_orders():
            if order.programmer == programmer:
                unfinished_tasks += 1
                unfinished_workloads += order.workload
        return finished_tasks, unfinished_tasks, finished_workloads, unfinished_workloads
    
class OrderBookApplication:
    def __init__(self):
        self.__OrderBook = OrderBook()

    def help(self):
        print("commands:")
        print("0 exit")
        print("1 add order")
        print("2 list finished tasks")
        print("3 list unfinished tasks")
        print("4 mark task as finished")
        print("5 programmers")
        print("6 status of programmer")



    def execute(self):
        self.help()
        while True:
            print()
            command = int(input("command:"))
            if command == 0:
                break
            elif command == 1:
                description = input("description:")
                temp = input("programmer and workload estimate:")
                try:
                    temp = temp.split()
                    programmer = temp[0]
                    workload = int(temp[1])
                except:
                    print("erroneous input")
                    continue
                self.__OrderBook.add_order(description, programmer, workload)
                print("added!")
            elif command == 2:
                list = self.__OrderBook.finished_orders()
                if len(list) == 0:
                    print("no finished tasks")
                else:
                    for item in list:
                        print(item)
            elif command == 3:
                list = self.__OrderBook.unfinished_orders()
                if len(list) == 0:
                    print("no unfinished tasks")
                else:
                    for item in list:
                        print(item)
            elif command == 4:
                try:
                    id = int(input("id:"))
                except:
                    print("erroneous input")
                    continue
                try:
                    self.__OrderBook.mark_finished(id)
                    print("marked as finished")
                except ValueError: 
                    print("erroneous input")
                    continue
            elif command == 5:
                list = self.__OrderBook.programmers()
                for item in list:
                    print(item)
            elif command == 6:
                programmer = input("programmer:")
                try:
                    status = self.__OrderBook.status_of_programmer(programmer)
                    print(f"tasks: finished {status[0]} not finished {status[1]}, hours: done {status[2]} scheduled {status[3]}")
                except ValueError:
                    print("erroneous input")

application = OrderBookApplication()
application.execute()