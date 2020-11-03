# -*- coding: utf-8 -*-

print("a", " b", " c")
count = 0
a = 1
while a < 100:
    b = 1
    while b < 100:
        c = 1
        while c < 100:
            if a ** 2 + b ** 2 == c ** 2:
                print(a, b, c)
                count += 1
            c += 1
        b += 1
    a += 1
print(count)