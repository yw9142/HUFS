# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import random


def lotto():
    num = int(input(f"게임 수를 입력해주세요 : "))
    print(f"로또 자동 생성기")
    for i in range(num):
        lists = []
        for j in range(num):
            number = random.randint(0, 100)
            lists.append(number)
        print(f"{i} {lists}")


lotto()
