# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import math

a, b, c, d = map(int, input().split())

tux = (a, c)
tuy = (b, d)

X = b - a
Y = d - c

ANS = round(math.sqrt((X * X) + (Y * Y)), 2)

print(ANS)