# -*- coding: utf-8 -*-

str1 = input()
count = 0

str2 = input()

for i in str1:
	for str1 in str2:
		if i in str1:
			count += 1

print(count)