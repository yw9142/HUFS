# -*- coding: utf-8 -*-

# PAGE 16
print("=======================================================================")
## upper / lower
title = "Python is Fun"
title.upper()
print(title.upper())
title.lower()
print(title.lower())

## title / capitalize
title.title()
print(title.title())
title.capitalize()
print(title.capitalize())

# PAGE 17
print("=======================================================================")
## count / isdigit / startswith
title = "Python is fun!! No. 1"
title.count('o')
print(title.count('o'))

title.upper().count('o')
print(title.upper().count('o'))

title.isdigit()
print(title.isdigit())

title.startswith('p')
print(title.startswith('p'))

# PAGE 18
print("=======================================================================")
## ordFunction
ch = 'a'
print(ord(ch))
print(chr(98))
print(ord('A'))

print(ord('a') - ord('A'))
print(ord('d') - ord('D'))

## convert upper <--> lower
offset = ord('a') - ord('A')
lowercaseLetter = 'h'
uppercaseLetter = chr(ord(lowercaseLetter) - offset)
print(uppercaseLetter)

# PAGE 20
print("=======================================================================")
## str function
s = str(3.4)
print(s)

s = str(3)
print(s)

# PAGE 21
print("=======================================================================")
## + operator
message = "Welcome " + "to " + "Python"
print(message)

chapterNo = 3
s = "Chapter " + str(chapterNo)
print(s)

message = "Welcome to Python"
print(message)

message = message + " and Python is fun"
print(message)

print("=======================================================================")