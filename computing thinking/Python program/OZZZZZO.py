# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

n = int(input())
str = list(input())
result = 0
# OZZO OZZZ

while 'O' in str:

    for i in range(n-1, -1, -1):
        if str[i] == 'O':
            str[i] = 'Z'
            k = i + 1
            break

    for j in range(k, n):
        if k > n - 1:
            break
        str[j] = 'O'

    result = result + 1

print(result)
