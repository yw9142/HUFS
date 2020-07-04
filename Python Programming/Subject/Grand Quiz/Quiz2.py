# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean


def fibonacci(num):
	if num < 2:
		return num
	else:
		return fibonacci(num-1) + fibonacci(num-2)
	
def factorial(num):
	if num < 2:
		return 1
	else:
		return num * factorial(num - 1)

num = int(input())
assert num >= 0, "Wrong Number"
lists = []

for i in range(0, num+1):
	tup = (fibonacci(i), factorial(i))
	lists.append(tup)
	
print(lists)