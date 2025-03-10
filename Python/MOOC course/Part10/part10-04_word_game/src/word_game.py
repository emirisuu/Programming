# Write your solution here
import random

class WordGame():
    def __init__(self, rounds: int):
        self.wins1 = 0
        self.wins2 = 0
        self.rounds = rounds

    def round_winner(self, player1_word: str, player2_word: str):
        # determine a random winner
        return random.randint(1, 2)

    def play(self):
        print("Word game:")
        for i in range(1, self.rounds+1):
            print(f"round {i}")
            answer1 = input("player1: ")
            answer2 = input("player2: ")

            if self.round_winner(answer1, answer2) == 1:
                self.wins1 += 1
                print("player 1 won")
            elif self.round_winner(answer1, answer2) == 2:
                self.wins2 += 1
                print("player 2 won")
            else:
                pass # it's a tie

        print("game over, wins:")
        print(f"player 1: {self.wins1}")
        print(f"player 2: {self.wins2}")

class LongestWord(WordGame):
    def __init__(self, rounds: int):
        super().__init__(rounds)

    def round_winner(self, player1_word: str, player2_word: str):
        if len(player1_word) > len(player2_word):
            return 1
        elif len(player2_word) > len(player1_word):
            return 2
    
class MostVowels(WordGame):
    def __init__(self, rounds: int):
        super().__init__(rounds)

    def round_winner(self, player1_word: str, player2_word: str):
        vowels = "aeiuoAEIUO"
        counter1 = 0
        counter2 = 0
        for vowel in vowels:
            counter1 += player1_word.count(vowel)
            counter2 += player2_word.count(vowel)
        if counter1 > counter2:
            return 1
        elif counter2 > counter1:
            return 2
        
class RockPaperScissors(WordGame):
    def __init__(self, rounds: int):
        super().__init__(rounds)
    
    def round_winner(self, player1_word: str, player2_word: str):
        hands = "rockpaperscissors"
        counter1 = 0
        counter2 = 0
        if player1_word not in hands and player2_word in hands:
            counter2 += 1
        elif player1_word in hands and player2_word not in hands:
            counter1 += 1
        if player1_word == "rock" and player2_word == "scissors":
            counter1 += 1
        elif player2_word == "rock" and player1_word == "scissors":
            counter2 += 1
        elif player1_word == "paper" and player2_word == "rock":
            counter1 += 1
        elif player2_word == "paper" and player1_word == "rock":
            counter2 += 1
        elif player1_word == "scissors" and player2_word == "paper":
            counter1 += 1
        elif player2_word == "scissors" and player1_word == "paper":
            counter2 += 1
        if counter1 > counter2:
            return 1
        elif counter2 > counter1:
            return 2