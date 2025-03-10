class Series:
    def __init__(self, title: str, no_seasons: int, genre_list: list):
        self.title = title
        self.no_seasons = no_seasons
        self.genre_list = ", ".join(genre_list)
        self.rating_count = 0
        self.rating = 0
    
    def rate(self, rating: int):
        self.rating += rating
        self.rating_count += 1
        self.average = self.rating / self.rating_count
    
    def __str__(self):
        if self.rating_count == 0:
            return f"{self.title} ({self.no_seasons} seasons)\ngenres: {self.genre_list}\nno ratings"
        return f"{self.title} ({self.no_seasons} seasons)\ngenres: {self.genre_list}\n{self.rating_count} ratings, average {self.average:.1f} points"

def minimum_grade(rating: float, series_list: list):
        titles = []
        for series in series_list:
            if series.average >= rating:
                titles.append(series)
        return titles

def includes_genre(genre: str, series_list: list):
        titles = []
        for series in series_list:
            if genre in series.genre_list:
                titles.append(series)
        return titles


if __name__ == "__main__":
    s1 = Series("Dexter", 8, ["Crime", "Drama", "Mystery", "Thriller"])
    s1.rate(5)

    s2 = Series("South Park", 24, ["Animation", "Comedy"])
    s2.rate(3)

    s3 = Series("Friends", 10, ["Romance", "Comedy"])
    s3.rate(2)

    series_list = [s1, s2, s3]

    print("a minimum grade of 4.5:")
    for series in minimum_grade(4.5, series_list):
        print(series.title)

    print("genre Comedy:")
    for series in includes_genre("Comedy", series_list):
        print(series.title)