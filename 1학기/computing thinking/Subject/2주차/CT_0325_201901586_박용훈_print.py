# -*- coding: utf-8 -*-

Material = (input("학과를 입력 해주세요 : "), input("학번을 입력 해주세요 : "), input("이름을 입력해주세요 : "))

print(Material[0], Material[1], Material[2], sep=', ')
i = 0
while i < 3:
    if i == 2:
        print(Material[i], end='')
        break;
    else:
        print(Material[i])
        i += 1