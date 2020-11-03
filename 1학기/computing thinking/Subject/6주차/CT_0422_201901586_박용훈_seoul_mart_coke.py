# -*- coding: utf-8 -*-

coke = 800

count = int(input("How many would you like to buy? : "))

if count <= 10:
    price = count * coke
elif count <= 20:
    price = (count * coke) * 0.97
else:
    price = (count * coke) * 0.95

print(f"The total price is {price}")
