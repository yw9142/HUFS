x = int(input())
n = int(input())


def facto(n):
    return n * facto(n - 1) if n > 1 else 1


l = [1]


def q6(n):
    for i in range(1, n + 1):
        if i == 1:
            l.insert(i, x)
        else:
            l.insert(i, (x ** i) / facto(i))
    a = sum(l)
    return round(a, 2)


print(q6(n))