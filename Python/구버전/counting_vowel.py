# -*- coding: utf-8 -*-

str = input()
n = len(str)
count = 0

vowel = "aeiouAEIOU"
for i in str:
    if i in vowel:
        count += 1

print(count)