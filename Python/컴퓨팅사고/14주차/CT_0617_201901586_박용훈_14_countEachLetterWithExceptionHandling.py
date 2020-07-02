# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean


def main():
    while 1:
        try:
            fname = input(f"Enter a filename : ")
            fname = fname.replace(" ", "")
            fopen = open(fname, 'r')
            break
        except IOError:
            print("except IOError : 파일명이 존재하지 않습니다.")

    counts = [0] * 26
    # a = 0; b = 0; c = 0; d = 0; e = 0; f = 0; g = 0; h = 0; i = 0; j = 0; k = 0; l = 0; m = 0
    # n = 0; o = 0; p = 0; q = 0; r = 0; s = 0; t = 0; u = 0; v = 0; w = 0; x = 0; y = 0; z = 0
    len1 = len(fopen.readlines())
    fopen.seek(0)

    for i in range(0, len1):
        row = fopen.readline().lower()
        counts = countLetter(row, counts)

    for i in range(1, len(counts) + 1):
        if counts[i - 1] > 1 or counts[i - 1] == 0:
            print(f"{i}: {chr(96 + i)} appear {counts[i - 1]} times")
        else:
            print(f"{i}: {chr(96 + i)} appear {counts[i - 1]} time")

    fopen.close()


def countLetter(line, counts):
    for i in line:
        if i.isalpha():
            counts[ord(i) - ord('a')] += 1
    return counts


main()
