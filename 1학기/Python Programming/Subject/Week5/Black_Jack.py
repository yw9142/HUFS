# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import random

repeat = 0
person1 = 0
person2 = 0

for i in range(1, 4):
	person1 += random.randint(1, 10)
	person2 += random.randint(1, 10)
	
if person1 == 21 and person2 != 21:
	print("p1 wins")
elif person2 == 21 and person1 != 21:
	print("p2 wins")
elif person1 >= 21 and person2 >= 21:
	print("draw")
elif person1 > 21 and person2 < 21:
	print("p2 wins")
elif person1 < 21 and person2 > 21:
	print("p1 wins")
elif person1 < 21 and person2 < 21:
	person1 = 21 - person1
	person2 = 21 - person2
	if person1 > person2:
		print("p2 wins")
	else:
		print("p1 wins")