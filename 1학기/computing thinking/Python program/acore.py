import score

ban = []
student = []

for i in range(0, 5):
    name = input('이름 :')
    korean = int(input('국어점수 :'))
    english = int(input('영어점수 :'))
    math = int(input('수학점수 :'))
    student = [name, korean, english, math]
    ban.append(student)
    print("\n")

for i in range(0, 5):
    total = score.total(ban[i])
    ban[i].append(total)
    average = score.ave(ban[i])
    ban[i].append(average)
    point = score.grade(ban[i])
    ban[i].append(point)

for i in range(0, 5):
    score.output(ban[i])
    print("\n")

print('2명 성적 비교하여 더 좋은 점수의 학생 찾기')
score.output(ban[2])
print("\n")
score.output(ban[4])
print("\n")
print('성적이 더 좋은 학생')
max_student = score.max_student(ban[2], ban[4])
score.output(max_student)

print("\n")

print('3명 성적 비교하여 더 좋은 점수의 학생 찾기')
score.output(ban[1])
print("\n")
score.output(ban[2])
print("\n")
score.output(ban[3])
print("\n")
print('성적이 가장 좋은 학생')
max_student = score.max_student(ban[1], ban[2], ban[3])
score.output(max_student)
