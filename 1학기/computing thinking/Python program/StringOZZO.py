# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

length = int(input())
str = input()
str = list(str)

count = 0
N = 0
i = 0

while 'O' in str:
    i = length - 1
    while True:  # 가장 오른쪽에 있는 O 찾아서 Z로 변경
        if str[i] == 'O':
            str[i] = 'Z'
            N = i + 1
            break
        i -= 1

    i = length - 1
    while True:  # 그리고 그 O의 오른쪽에 있는 모든 Z문자는 O로 변경
        if N > length - 1:
            break
        str[N] = 'O'
        N += 1

    count += 1

print(count)
