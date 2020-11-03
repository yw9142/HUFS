# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import collections

print(f"정수형 숫자 여러 개를 입력하세요.\n숫자와 숫자 사이는 space로 구분하세요.")
ins = input(f"정수형 문자열 입력 : ")
listA = ins.split()

listNum = []

for i in listA:
    listNum.append(int(i))

print(f"out - each element : ", end="")
for i in listNum:
    print(i, end=" ")

listNum.sort()
print(f"\nsort - ascending : {listNum}")

print(f"{listNum} min : {min(listNum)}")
print(f"{listNum} max : {max(listNum)}")
print(f"{listNum} sum : {sum(listNum)}")

collections.Counter
