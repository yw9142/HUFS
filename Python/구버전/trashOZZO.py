# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
n = int(input())
str = list(input())
result = 0

while True:
    if 'O' not in str:
        break
    while True:
        for i in range(n - 1, -1, -1):
            if str[i] == 'O':
                str[i] = 'Z'
                for j in range(i + 1, n, 1):
                    str[j] = 'O'
                result = result + 1
                break
        else:
            break
print(result)
