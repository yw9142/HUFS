# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

start_day = 2  # Tuesday
last_day_in_month = 31

print('  S  M  T  W Th  F  S')
for i in range(start_day):
    print('    ', end='')
for i in range(1, 5):
    print(i, end="  ")
print("5")

for i in range(start_day):
    print(' ', end='')
for i in range(6, 9):
    print(i, end="  ")
print("9", end=" ")
print("10", end=" ")
for i in range(11, 12):
    print(i, end=" ")
print("12")

for i in range(1):
    print(' ', end='')
for i in range(13, 19):
    print(i, end=" ")
print("19")

for i in range(1):
    print(' ', end='')
for i in range(20, 26):
    print(i, end=" ")
print("26")
for i in range(1):
    print(' ', end='')
for i in range(27, 32):
    print(i, end=" ")