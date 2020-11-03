# -*- coding: utf-8 -*-

Value = int(input())

if 1 <= Value <= 3:
    print("1st quarter")
elif 4 <= Value <= 6:
    print("2nd quarter")
elif 7 <= Value <= 9:
    print("3rd quarter")
elif 10 <= Value <= 12:
    print("4th quarter")
else:
    print("Error")
