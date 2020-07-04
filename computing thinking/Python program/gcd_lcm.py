# -*- coding: utf-8 -*-

def swap(a, b):
    temp = a
    a = b
    b = temp


def find_gcd(a, b):
    if b > a:
        swap(a, b)
    while b != 0:
        (a, b) = (b, a % b)
    return a


def find_lcm(a, b):
    return a * b / find_gcd(a, b)


# lcd == 최저공통분모 최소공분모

a, b = map(int, input().split())
if a < 0 and b < 0:
    print(f"({int(find_lcm(a, b))}, {find_gcd(a, b)})")
else:
    print(f"({find_gcd(a, b)}, {int(find_lcm(a, b))})")
