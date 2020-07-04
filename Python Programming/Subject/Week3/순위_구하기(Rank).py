# -*- coding: utf-8 -*-

a = int(input())
b = int(input())
c = int(input())

if a > b:
	if b < c:
		if c < a:
			print(c)
		else:
			print(a)
	else:
		print(b)
else:
	if b > c:
		if c < a:
			print(a)
		else:
			print(c)
	else:
		print(b)