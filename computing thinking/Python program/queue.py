# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
lists = []

while True:
    a = input(f"어떤 작업을 진행하시겠습니까? 끝내길 원하신다면 '종료'를 입력하세요: ")
    if a == "종료":
        print(f"종료합니다")
        break
    elif a == "입력":
        subcompany = input("자회사 이름: ")
        curasset = input("유동자산: ")
        inventory = input("재고자산: ")
        curlia = input("유동부채: ")
        lists.append([subcompany, curasset, inventory, curlia])
        print(lists)
    elif a == "추출":
        if len(lists) == 0:
            print(f"정보가 없습니다")
        else:
            print(f"{lists[0][0]} 자회사의 유동자산은 {lists[0][1]}만원, 재고자산은 {lists[0][2]}만원, 유동부채는 {lists[0][3]}만원입니다.")
            lists.remove(lists[0])
    else:
        print(f"잘못된 입력입니다")
