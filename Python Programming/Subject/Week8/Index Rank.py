# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

participants = int(input())
judge_one = map(int, input().split())
judge_two = map(int, input().split())

judge_one = list(judge_one)
judge_two = list(judge_two)

judge_one_sort = judge_one[:]
judge_two_sort = judge_two[:]
judge_one_sort.sort()
judge_two_sort.sort()

rank_one = []
rank_two = []

i = 0;
while i < participants:
	j = 0
	while j < participants:
		if judge_one[i] == judge_one_sort[j]:
			rank_one.append(participants-j)
		j += 1
	i += 1

i = 0
while i < participants:
	j = 0
	while j < participants:
		if judge_two[i] == judge_two_sort[j]:
			rank_two.append(participants-j)
		j += 1
	i += 1
	
# print(rank_one)
# print(rank_two)

if rank_one == rank_two:
	print("agree")
else:
	none = []
	for r in range(participants):
		if rank_one[r] != rank_two[r]:
			none.append(rank_one[r])
	# print(none)
	none.sort()
	print(min(none))

# ===================================================
# 80 60 40 20 10 30 50 70 // 5 3 1 2 4
# 07 05 03 01 00 02 04 06

# 160 100 120 80 20 60 90 135
# 07  04  05  02 00 01 03 06

# 1 3 5 7 8 6 4 2 //  3 5 7 6 4 
# 1 4 3 6 8 7 5 2
# print(3)