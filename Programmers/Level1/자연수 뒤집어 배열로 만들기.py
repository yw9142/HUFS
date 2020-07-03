def solution(n):
    lists = []
    for i in range(len(str(n))):
        value = n % 10
        lists.append(value)
        n //= 10
    return lists
