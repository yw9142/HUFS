# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

def calc(a, b):
	answer = 0
	key = int(input())
	try:
		if key == 1:
			answer = a + b
			return answer
		elif key == 2:
			answer = a - b
			return answer
		elif key == 3:
			answer = a * b
			return answer
		elif key == 4:
			answer = a / b
			answer = round(answer, 2)
			return answer
	except ZeroDivisionError:
		return ("Can't divide by zero")
	
first_num, second_num = map(int, input().split())
print(calc(first_num, second_num))
