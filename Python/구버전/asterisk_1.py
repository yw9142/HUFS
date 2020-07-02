def blank(a):
    b = ""
    for i in range(a):
        b = b + " "

    return b


def asterisk(a):
    b = ""
    for i in range(a):
        b = b + "*"

    return b


level = 9
i = 0
# 5 3 1 0
# 5 6 7 8
# 0 3 6 9
# 10 12 14 16
# -5 -9 -13 -17
n = 5
while i < level:
    if i >= 5:  # i = 5
        b = blank(level + i - 9)  # blank 2개 9 - 5 4
        b = b + '*'
        b = b + blank((i*2) - n)

        if i != 8:
            b = b + "*"
        print(b)

        i = i + 1
        n += 4
        continue

    b = blank(level - i - 1)  # blank 5개
    b = b + "*"  # + *
    b = b + blank((i * 2) - 1)  # +

    if i != 0:
        b = b + "*"

    print(b)
    i = i + 1
