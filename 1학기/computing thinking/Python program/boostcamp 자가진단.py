# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import collections


def solution(arr):
    lists = []
    dont = []
    for i in arr:
        if i in dont:
            continue
        re = arr.count(i)
        dont.append(i)
        if re > 1:
            lists.append(re)

    if len(lists) != 0:
        return lists
    else:
        return [-1]


arr = [3, 2, 4, 4, 2, 5, 2, 5, 5]
print(solution(arr))
