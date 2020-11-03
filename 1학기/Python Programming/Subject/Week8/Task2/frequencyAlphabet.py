# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

f = open('data/text.txt', 'r')
data = f.read().lower()
data = data.replace(' ', '')
data = data.replace(',', '')
data = data.replace('.', '')
data = data.replace(';', '')
data = data.replace("'", '')
data = data.replace("\n", '')
f.close()

di = {}
i = 97
while i < 123: # ASCII
	frequency = data.count(chr(i))
	if frequency > 0:
		di[chr(i)] = frequency
	i += 1

lists = []
for i,j in di.items():
	lists.append((i, j))
print(sorted(lists))


# data1 = collections.Counter(data)
# lists = []
# for i,j in data1.items():
#  	lists.append((i, j))

# print(sorted(lists))


# import re
# import collections

# f = open('data/text.txt', 'r')
# data = f.read().lower()
# f.close()

# data = re.sub('[^a-z]','',data)
# data1 = collections.Counter(data)
# lists = []

# for i,j in data1.items():
# 	lists.append((i, j))

# print(sorted(lists))