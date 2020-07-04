# -*- coding: utf-8 -*-

Second = int(input("Second를 입력 해주세요 : "))

Minute = Second // 60
RESecond = Second % 60

print(Minute,'Min')
print(RESecond,'Sec', end='')