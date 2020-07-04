f = open('data/test.txt','r')

data = f.read()

f.close

di = {}
i = 33
while i < 127:
	frequency = data.count(chr(i))
	if frequency > 0:
		di[chr(i)] = frequency
	i += 1

lists = []
for i,j in di.items():
	lists.append((i, j))
print(sorted(lists))