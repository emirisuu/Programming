# Write your solution after the class ExamSubmission
# Do not make changes to the class!
class ExamSubmission:
    def __init__(self, examinee: str, points: int):
        self.examinee = examinee
        self.points = points

    def __str__(self):
        return f'ExamSubmission (examinee: {self.examinee}, points: {self.points})'

# # WRITE YOUR SOLUTION HERE:
def passed(submissions: list, lowest_passsing: int):
    passes = []
    for student in submissions:
        if student.points >= lowest_passsing:
            passes.append(student)
    return passes