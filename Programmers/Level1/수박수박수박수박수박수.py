def solution(n):
    lists = []
    for i in range(n):
        if i % 2 != 0:
            lists.append("박")
        else:
            lists.append("수")

    lists = "".join(map(str, lists))
    return lists
