# -*- coding: utf-8 -*-


def upper_lower(a):
	i = 0
	global upper
	upper = 0
	global lower
	lower = 0
	length = len(a)
	while i < length:
		alpha = ord(a[i])
		if 65 <= alpha <= 90:
			upper += 1
		elif 97 <= alpha <= 122:
			lower += 1
		i += 1
	print(upper, lower)


a = input()
upper_lower(a)
