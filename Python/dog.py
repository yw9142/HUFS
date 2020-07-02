list = []

for i in range(3):
    dic = {}
    a = input("강아지이름: ")
    b = int(input("강아지 나이: "))
    c = input("강아지 종류: ")

    dic = {"name": a, "age": b, "kind": c}

    list.append(dic)

print("리스트 내용")
for i in range(3):
    print(f"{i} 번째 : {list[i]}")

print("나이가 3살 이상인 강아지")
for i in range(3):
    Ag = (item for item in list if item["age"])
    if Ag >= 3:
        print(list[i])