import random


def dice_roll(N, total):
    for i in range(1, N + 1):
        i = random.randint(1, 100)
        total += i
    print(N)
    print(total)
    print(total // N)


total = 0
N = int(input())

dice_roll(N, total)
