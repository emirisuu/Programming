# Write your solution here:
class Stopwatch:
    def __init__(self):
        self.seconds = 0
        self.minutes = 0

    def __str__(self):
        return f"{self.minutes:02}:{self.seconds:02}"

    def tick(self):
        if self.minutes == 59 and self.seconds == 59:
            self.minutes = 0
            self.seconds = 0
            return
        elif self.seconds > 58:
            self.minutes += 1
            self.seconds = 0
            return
        self.seconds += 1

if __name__ == "__main__":
    watch = Stopwatch()
    print(f"{watch.minutes:01}:{watch.seconds:01}")