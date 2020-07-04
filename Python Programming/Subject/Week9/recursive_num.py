# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

def recursive_num(lists, number):
	if number == 1: # basepoint
		return min(lists)
	else: 	# recursive point
		mini = min(lists)
		lists.remove(mini)
		return recursive_num(lists, number-1)

	
lists = map(int, input().split())
lists = list(lists)
number = int(input())
print(recursive_num(lists, number))