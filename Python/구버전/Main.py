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


print(f"최대공약수 구하기")
a = int(input("첫 번째 숫자:"))
b = int(input("두 번째 숫자:"))

print(f"최대공약수는 {find_gcd(a, b)}")
