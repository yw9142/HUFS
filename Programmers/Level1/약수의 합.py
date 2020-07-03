def solution(s):
    lists = []
    for i in range(1, s + 1):
        if s % i == 0:
            lists.append(i)
    return sum(lists)
