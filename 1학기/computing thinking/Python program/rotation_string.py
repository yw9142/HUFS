# -*- coding: utf-8 -*-

a = input()

for rotation in range(1, len(a) + 1):
    print(a[rotation:] + a[:rotation])