import random
import collections


def drawing_integers(lb, ub, trials):
    rand = [random.randint(lb, ub) for i in range(trials)]
    print(rand)
    return rand


def average_integers(num_list):
    sum = 0
    for i in num_list:
        sum += i
    return sum / len(num_list)


def count_integers(num_list):
    count = collections.Counter(num_list)
    count = count.most_common()
    count = sorted(count)
    return count


lb = int(input())
ub = int(input())
trials = int(input())

num_list = drawing_integers(lb, ub, trials)
print(average_integers(num_list))
print(count_integers(num_list))
