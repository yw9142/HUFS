# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean


def fibonacci(num):  # 3
	list1 = []
	for i in range(0, num):
		if i == 0:
			list1.append(0)
		elif i < 2:
			list1.append(1)
		else:
			list1.append(list1[i-1] + list1[i-2])
	return list1[num-1]
	
def nagtive_fibonacci(num): # 1~num+1 || 2
	list2 = []
	for i in range(0, num):
		if i == 0:
			list2.append(1)
		elif i == 1:
			list2.append(-1)
		else:
			list2.append((-1 ** (i + 1)) * list2[i-1] + list2[i-2] )
	return list2[num-1]
# 1, 1, 

num = int(input())
assert num >= 0 or num.isdigit() == True, "don't input string or negative number"

lists = []

for i in range(1, num+1):
	lists.append(nagtive_fibonacci(i))
lists.reverse()

for i in range(1, num+2):
	lists.append(fibonacci(i))

print(lists)