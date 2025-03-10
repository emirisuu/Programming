class WeatherStation:
    def __init__(self, name: str):
        self.__name = name
        self.__observation = []
        self.__counter = 0

    def add_observation(self, observation: str):
        self.__observation.append(observation)
        self.__counter += 1

    def latest_observation(self):
        if self.__counter != 0:
            return self.__observation[-1]
        return ""
    
    def number_of_observations(self):
        return self.__counter
    
    def __str__(self):
        return f"{self.__name}, {self.__counter} observations"