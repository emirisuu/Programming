# Write your solution here:
class Clock:
    def __init__(self, hours: int, minutes: int, seconds: int):
        self.hours = hours
        self.minutes = minutes
        self.seconds = seconds

    def tick(self):
        if self.hours == 23 and self.minutes == 59 and self.seconds == 59:
            self.hours = 0
            self.minutes = 0
            self.seconds = 0
            return
        elif self.minutes == 59 and self.seconds == 59:
            self.hours += 1
            self.minutes = 0
            self.seconds = 0
            return
        elif self.seconds > 58:
            self.minutes += 1
            self.seconds = 0
            return
        self.seconds += 1

    def set(self, hours: int, minutes: int):
        self.hours = hours
        self.minutes = minutes
        self.seconds = 0

    def __str__(self):
        return f"{self.hours:02}:{self.minutes:02}:{self.seconds:02}"