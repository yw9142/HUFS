# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

def palindrome(string):
	string = list(string)
	if len(string) <= 1:
		return True
	if string[0:] == string[::-1]:
		return True
	else:
		return False
	return palindrome(string[1:-1])

string = input()
print(palindrome(string))
