def total(student):  # list student = [name, korean, english, math, total, average, point]
    return student[1] + student[2] + student[3]


def ave(student):
    return student[4] / 3


def grade(student):
    if student[5] >= 90:
        return 'A'
    elif student[5] >= 80:
        return 'B'
    elif student[5] >= 70:
        return 'C'
    elif student[5] >= 60:
        return 'D'
    else:
        return 'F'


def output(student):
    lists = ["이름", "국어점수", "영어점수", "수학점수", "총점", "평균", "학점"]
    for i in range(0, 7):
        print(f"학생의 {lists[i]} = {student[i]}")


def max_student(*student):
    maxi = 0
    for i in range(len(student)):
        if maxi < student[i][4]:
            maxi = i
    return student[maxi]
