# -*- coding: utf-8 -*-
def hatched_square(diameter):
    return (diameter * diameter) - ((diameter / 2) ** 2 * PI)


def hatched_triangle(diameter):
    return ((diameter * (diameter / 2)) / 2)


a = int(input("input a(integer): "))
PI = 3.141592
Hatched_area = hatched_square(a) + hatched_triangle(a)

print(f"빗금친 부분의 면적: {Hatched_area:.2f}")