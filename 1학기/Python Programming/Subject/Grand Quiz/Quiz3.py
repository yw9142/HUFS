# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean


def fibonacci(num):
	if num < 2:
		return num
	else:
		return fibonacci(num-1) + fibonacci(num-2)
	
def nagtive_fibonacci(num):
	if num < 2:
		return num
	else:
		return (-1 ** (num + 1)) * nagtive_fibonacci(num-1) + nagtive_fibonacci(num-2)
	

num = int(input())
assert num >= 0 or num.isdigit() == True, "don't input string or negative number"

lists = []

for i in range(1, num+1):
	lists.append(nagtive_fibonacci(i))
lists.reverse()
for i in range(0, num+1):
	lists.append(fibonacci(i))

print(lists)