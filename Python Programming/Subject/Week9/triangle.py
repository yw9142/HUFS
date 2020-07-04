# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

def triangle(a, b, c):
	lists = [a, b, c]
	max_value = max(lists)
	if max_value == 0:
		return ("Not right Triangle")
	lists.remove(max_value)
	# assert lists[0] ** 2 + lists[1] ** 2 == max_value ** 2, "Not right Triangle"
	if lists[0] ** 2 + lists[1] ** 2 == max_value ** 2:
		return ("Right Triangle")
	else:
		return ("Not right Triangle")

one, two, three = map(int, input().split())
print(triangle(one, two, three))