list0 = input()

a = []

listA = list0.split()

for i in listA:
    print(i, end=" ")

listA.sort()
print(f"\n{listA}")