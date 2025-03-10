import json
class Player:
    def __init__(self, name: str, nationality: str, assists: int, goals: int, penalties: int, team: str, games: int):
        self.__name = name
        self.__nationality = nationality
        self.__assists = assists
        self.__goals = goals
        self.__penalties = penalties
        self.__team = team
        self.__games = games

    @property
    def name(self):
        return self.__name
    
    @property
    def team(self):
        return self.__team
    
    @property
    def nationality(self):
        return self.__nationality
    
    @property
    def points(self):
        return self.__assists + self.__goals
    
    @property
    def goals(self):
        return self.__goals
    
    @property
    def games(self):
        return self.__games

    def __str__(self):
        return f"{self.__name:21}{self.__team:5}{self.__goals:>2} + {self.__assists:>2} = {self.points:>3}"

class AllPlayers:
    def __init__(self):
        self.__all_players = []

    def add_player(self, name: str, nationality: str, assists: int, goals: int, penalties: int, team: str, games: int):
        self.__all_players.append(Player(name, nationality, assists, goals, penalties, team, games))

    def search_for_player(self, name: str):
        for player in self.__all_players:
            if player.name == name:
                return player
        print("player not found")

    def teams(self):
        return sorted(list(set(map(lambda item: item.team, self.__all_players))))
    
    def countries(self):
        return sorted(list(set(map(lambda item: item.nationality, self.__all_players))))
    
    def by_points(self, players: list):
        index = 0
        for i in range(len(players)):
            if players[i].points < players[index].points: index = i
            temp = players[i]
            players[i] = players[index]
            players[index] = temp
        return players
    
    def players_in_team(self, team: str):
        players = list(filter(lambda item: item.team == team, self.__all_players))
        return self.by_points(players)
        
    def players_in_country(self, country: str):
        players = list(filter(lambda item: item.nationality == country, self.__all_players))
        return self.by_points(players)
    
    def players_by_points(self, length):
        players = list(map(lambda item: item, self.__all_players))
        def by_goals(players):
            for i in range(len(players)):
                index = i
                for j in range(i + 1, len(players)):
                    if players[j].points > players[index].points: index = j
                    elif players[j].points == players[index].points:
                        if players[j].goals > players[index].goals: index = j
                temp = players[i]
                players[i] = players[index]
                players[index] = temp
            return players
        sorted_players = by_goals(players)
        return sorted_players[:length]
    
    def players_by_goals(self, length):
        players = list(map(lambda item: item, self.__all_players))
        def by_games(players):
            for i in range(len(players)):
                index = i
                for j in range(i + 1, len(players)):
                    if players[j].goals > players[index].goals: index = j
                    elif players[j].goals == players[index].goals:
                        if players[j].games < players[index].games: index = j
                temp = players[i]
                players[i] = players[index]
                players[index] = temp
            return players
        sorted_players = by_games(players)
        return sorted_players[:length]
    
    def all_players(self):
        return self.__all_players

class HockeyStatisticsApplication:
    def __init__(self):
        self.__all_players = AllPlayers()

    def help(self):
        print("commands:")
        print("0 quit")
        print("1 search for player")
        print("2 teams")
        print("3 countries")
        print("4 players in team")
        print("5 players from country")
        print("6 most points")
        print("7 most goals")

    def execute(self):
        filename = input("filename:")
        with open(filename) as new_file:
            data = new_file.read()
        players = json.loads(data)
        for player in players:
            self.__all_players.add_player(player["name"], player["nationality"], player["assists"], player["goals"], player["penalties"], player["team"], player["games"])
        print(f"read the data of {len(self.__all_players.all_players())} players")
        print()
        self.help()
        while True:
            print()
            command = int(input("command:"))
            if command == 0:
                break
            elif command == 1:
                name = input("name:")
                print(self.__all_players.search_for_player(name))
            elif command == 2:
                for team in self.__all_players.teams():
                    print(team)
            elif command == 3:
                for country in self.__all_players.countries():
                    print(country)
            elif command == 4:
                team = input("team:")
                for player in self.__all_players.players_in_team(team):
                    print(player)
            elif command == 5:
                country = input("country:")
                for player in self.__all_players.players_in_country(country):
                    print(player)
            elif command == 6:
                length = int(input("how many:"))
                for player in self.__all_players.players_by_points(length):
                    print(player)
            elif command == 7:
                length = int(input("how many:"))
                for player in self.__all_players.players_by_goals(length):
                    print(player)
            else:
                self.help()
            
            

    

application = HockeyStatisticsApplication()
application.execute()