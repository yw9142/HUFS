def solution(s):
    stri = list(s)

    lists = []
    lists.append(stri[((len(stri) - 1) // 2)])
    lists.append(stri[(len(stri) // 2)])
    lists = ''.join(lists)
    if len(stri) % 2 == 0:
        return lists
    else:
        return stri[(len(stri) - 1) // 2]
