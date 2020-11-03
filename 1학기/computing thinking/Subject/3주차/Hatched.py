# -*- coding: utf-8 -*-

a = int(input("input a(integer): "))
PI = 3.141592

hatched_square = (a * a) - ((a / 2) ** 2 * PI)
hatched_triangle = ((a * (a / 2)) / 2)

Hatched_area = hatched_square + hatched_triangle

print(f"빗금친 부분의 면적: {Hatched_area:.2f}")