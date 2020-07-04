# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

participants = int(input())
judge_one = map(int, input().split())
judge_two = map(int, input().split())

judge_one_index = []
judge_two_index = []

for i in range(participants):
    judge_one_index.append(i+1)
    judge_two_index.append(i+1)
tuple(judge_one_index)
tuple(judge_two_index)

judge_one = list(judge_one)
judge_two = list(judge_two)
judge_one.sort()
judge_two.sort()

print(judge_one_index)
print(judge_two_index)
print(judge_one)
print(judge_two)

# 80 40 60 20 10 // input
# 10 20 40 60 80 // sort
# 1  2  3  4  5 // index
# 1  3  2  4  5 // rank
