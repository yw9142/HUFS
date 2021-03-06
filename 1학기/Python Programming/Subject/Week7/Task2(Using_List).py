# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

length = int(input())
str = input()
str = list(str)

count = 0
N = 0
i = 0

while 'O' in str:
	i = length - 1
	while True:    # 가장 오른쪽에 있는 O 찾아서 Z로 변경
		if str[i] == 'O':
			str[i] = 'Z'
			N = i+1
			break
		i -= 1

	i = length - 1
	while True:   # 그리고 그 O의 오른쪽에 있는 모든 Z문자는 O로 변경
		if N > length - 1:
			break
		str[N] = 'O'
		N += 1

	count += 1

print(count)


# 다른 풀이 법 1 (index 슬라이싱)

# n = int(input())
# str = input()
# Lists = list(str)

# count = 0

# while 'O' in Lists:
#     x = str.rfind('O')

#     Lists[x] = 'Z'
#     Lists[x + 1:n] = ['O'] * (n - (x + 1))

#     str = "".join(Lists)
#     count += 1

# print(count)


# 다른 풀이 법 2 (for문)

# n = int(input())
# str = list(input())
# result = 0
# # OZZO OZZZ

# while 'O' in str:

#     for i in range(n-1, -1, -1):
#         if str[i] == 'O':
#             str[i] = 'Z'
#             k = i + 1
#             break

#     for j in range(k, n):
#         if k > n - 1:
#             break
#         str[j] = 'O'

#     result = result + 1

# print(result)

