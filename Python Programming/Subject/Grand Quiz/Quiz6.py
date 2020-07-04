# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

def factorial(num):
	if num < 2:
		return 1
	else:
		return num * factorial(num - 1)

number1 = int(input()) # X
number2 = int(input()) # N
sum = 1

for i in range(1, number2+1):
	sum += (number1 ** i) / factorial(i)
	
sum = round(sum, 2)
print(sum)
	
