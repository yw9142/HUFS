# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
# define main function


def main():
    num1, num2, op = inputSub()
    result = cal(num1, num2, op)
    printSub(num1, num2, op, result)


def inputSub():
    num1 = int(input('정수형 숫자 입력:  '))
    num2 = int(input('정수형 숫자 입력:  '))
    op = input('연산자 입력(+,-,*,/):  ')
    return num1, num2, op


def add(num1, num2):
    return (num1 + num2)


def sub(num1, num2):
    return (num1 - num2)


def mul(num1, num2):
    return (num1 * num2)


def div(num1, num2):
    if num2 == 0:
        return ("impossible divide by 0")
    else:
        return (num1 / num2)


def cal(num1, num2, op):
    if op == '+':
        return add(num1, num2)
    elif op == '-':
        return sub(num1, num2)
    elif op == '*':
        return mul(num1, num2)
    elif op == '/':
        return div(num1, num2)
    else:
        return "연산자 입력이 잘 못 되었습니다."


def printSub(num1, num2, op, result):
    print("{} {} {} = {}".format(num1, op, num2, result))


main()
