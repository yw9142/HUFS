def solution(x):
    num = x
    lists = []
    for i in range(len(str(x))):
        value = x % 10
        lists.append(value)
        x //= 10
    if num % sum(lists) == 0:
        return True
    else:
        return False
