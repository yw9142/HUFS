# -*- coding: utf-8 -*-

coffee = int(input())
money = int(input())
num = 0

while money != 0:
	if coffee == 0:
		print("No coffee")
		break
	elif money < 300:
		break
	coffee -= 1
	money -= 300
	num += 1
	if coffee == 0 and money == 0 and num == 0:
		print("No coffee")
		break
	elif money < 300:
		break

print(coffee, money, num)