# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import math


class Shape(object):
    def __init__(self, x1, y1, x2, y2):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2


class Triangle(Shape):
    def __init__(self, x1, y1, x2, y2):
        Shape.__init__(self, x1, y1, x2, y2)

    def area(self):
        if self.y1 == self.y2:
            return 0
        area = abs((self.x2 - self.x1)) * abs((self.y2 - self.y1)) * 0.5
        return float(area)


class Rectangle(Shape):
    def __init__(self, x1, y1, x2, y2):
        Shape.__init__(self, x1, y1, x2, y2)

    def area(self):
        if self.y1 > self.y2:
            area = abs((self.x2 - self.x1)) * self.y2
            return float(area)
        else:
            area = abs((self.x2 - self.x1)) * self.y1
            return float(area)

    def round(self):
        if self.y1 == self.y2:
            round1 = abs((self.x2 - self.x1) * 2) + (self.y1 * 2)
            return round1
        elif y1 > y2:
            round1 = round(abs((self.x2 - self.x1) * 2) + (self.y2 * 2) + abs(y2 - y1) + (
                    math.sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2)) - abs(x2 - x1)), 2)
            return round1
        else:
            round1 = round(abs((self.x2 - self.x1) * 2) + (self.y1 * 2) + abs(y2 - y1) + (
                    math.sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2)) - abs(x2 - x1)), 2)
            return round1


x1, y1, x2, y2 = map(int, input().split())

R = Rectangle(x1, y1, x2, y2)
T = Triangle(x1, y1, x2, y2)

print(R.area() + T.area(), R.round())
