a = 2
b = 1

while a < 10:

    while b < 10:
        print(f"{a} x {b} = {a * b}")
        b += 1

    a -= 1
    b = 1
    while b < 10:
        print(f"{a} x {b} = {a * b}")
        b += 1

    a += 3
    b = 1
