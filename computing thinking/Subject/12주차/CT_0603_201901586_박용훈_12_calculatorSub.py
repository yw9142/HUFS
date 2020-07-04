# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import sys


class ColorPrint:

    @staticmethod
    def print_fail(message, end='\n'):
        sys.stderr.write('\x1b[1;31m' + message.strip() + '\x1b[0m' + end)

    @staticmethod
    def print_pass(message, end='\n'):
        sys.stdout.write('\x1b[1;32m' + message.strip() + '\x1b[0m' + end)

    @staticmethod
    def print_warn(message, end='\n'):
        sys.stderr.write('\x1b[1;33m' + message.strip() + '\x1b[0m' + end)

    @staticmethod
    def print_info(message, end='\n'):
        sys.stdout.write('\x1b[1;34m' + message.strip() + '\x1b[0m' + end)

    @staticmethod
    def print_bold(message, end='\n'):
        sys.stdout.write('\x1b[1;37m' + message.strip() + '\x1b[0m' + end)


def main():
    num1, num2, op = inputSub()
    result = cal(num1, num2, op)
    printSub(num1, num2, op, result)


def inputSub():
    num1 = int(input(f"정수형 숫자 입력: "))
    num2 = int(input(f"정수형 숫자 입력: "))
    op = input(f"연산자 입력(+, -, *, /): ")
    return num1, num2, op


def cal(num1, num2, op):
    if op == "+":
        return add(num1, num2)
    elif op == "-":
        return sub(num1, num2)
    elif op == "*":
        return mul(num1, num2)
    elif op == "/":
        return div(num1, num2)
    else:
        return "연산자 입력이 잘 못 되었습니다."


def printSub(num1, num2, op, result):
    ColorPrint.print_info(f"{num1} {op} {num2} = {result}")


def add(num1, num2):
    return num1 + num2


def sub(num1, num2):
    return num1 - num2


def mul(num1, num2):
    return num1 * num2


def div(num1, num2):
    if num2 == 0:
        return "impossible divide by 0"
    else:
        return num1 / num2


main()
