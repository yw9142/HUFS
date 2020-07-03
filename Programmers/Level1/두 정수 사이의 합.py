def solution(a, b):
    sum = 0

    if a > b:
        a, b = b, a

    for i in range(b - a + 1):
        sum += a
        if a < b:
            a += 1
    return sum
