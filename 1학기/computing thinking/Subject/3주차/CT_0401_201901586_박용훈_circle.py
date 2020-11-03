# -*- coding: utf-8 -*-
def aoc(R):
    return PI * R * R


def cir(R):
    return PI * 2 * R


def vol(R):
    return (PI * 4 * R * R * R) / 3


def sur(R):
    return PI * 4 * R * R


Radius = int(input("input radius(integer): "))
PI = 3.141592

print(f"Radius: {Radius}")
print(f"Area of circle: {aoc(Radius):.4f}")
print(f"Circumference: {cir(Radius):.5f}")
print(f"Volume of sphere: {vol(Radius)}")
print(f"Sphere surface area: {sur(Radius):.4f}")
