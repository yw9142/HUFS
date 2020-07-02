# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean


def main():
    list_main = input(f"정수를 여러 개 입력하시오 : ").split()
    print(f"평균값은 {mean_of_n(list_main)}")
    print(f"최대값은 {max_of_n(list_main)}")
    print(f"최솟값은 {min_of_n(list_main)}")


def mean_of_n(list_sub):
    sum = 0
    index = 0
    for i in list_sub:
        sum += int(i)
        index += 1
    average = sum / index
    return average


def max_of_n(list_sub):
    max = 0
    for i in list_sub:
        if max < int(i):
            max = int(i)
    return max


def min_of_n(list_sub):
    min = 1
    for i in list_sub:
        if min > int(i):
            min = int(i)
    return min


if __name__ == '__main__':
    main()
