def solution(s):
    lists = []
    string = ""
    word = s.split(' ')
    print(word)

    for i in word:
        new_word = ""
        for j in range(len(i)):
            if j % 2 == 0:
                new_word += i[j].upper()
            else:
                new_word += i[j].lower()
        lists.append(new_word)
    s1 = ' '.join(lists)
    return s1
