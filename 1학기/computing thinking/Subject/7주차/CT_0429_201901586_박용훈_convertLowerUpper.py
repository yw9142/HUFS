# -*- coding: utf-8 -*-

while 1:
    ch = input("소문자 입력: ")
    if ch == 'Q':
        break
    elif ch.islower() != 1:
        print("입력값 범위 아님")
        continue
    ch = ord(ch) - 32
    ch = chr(ch)
    print(f"변환된 대문자는 {ch}입니다.")