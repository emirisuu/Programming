# tee ratkaisu tänne
# Write your solution here
def get_station_data(filename: str):
    stations = {}
    with open(filename) as new_file:
        for line in new_file:
            line = line.replace("\n", "")
            parts = line.split(";")
            if parts[0] == "Longitude":
                continue
            stations[parts[3]] = (float(parts[0]), float(parts[1]))
    return stations

def distance(stations: dict, station1: str, station2: str):
    import math
    x_km = (stations[station1][0] - stations[station2][0]) * 55.26
    y_km = (stations[station1][1] - stations[station2][1]) * 111.2
    distance_km = math.sqrt(x_km**2 + y_km**2)
    return distance_km

def greatest_distance(stations: dict):
    max_distance = 0
    max_station1 = ""
    max_station2 = ""
    for key in stations:
        for key1 in stations:
            d = distance(stations, key, key1)
            if d > max_distance:
                max_distance = d
                max_station1 = key
                max_station2 = key1
    return max_station1, max_station2, max_distance