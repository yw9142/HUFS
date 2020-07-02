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
        area = abs((self.x2 - self.x1)) * abs((self.y2 - self.y1)) * 0.5
        return area


class Rectangle(Shape):
    def __init__(self, x1, y1, x2, y2):
        Shape.__init__(self, x1, y1, x2, y2)

    def area(self):
        if y1 > y2:
            area = abs((self.x2 - self.x1)) * self.y2
            return area
        else:
            area = abs((self.x2 - self.x1)) * self.y1
            return area

    def round(self):
        if self.x2 == 0 and self.y1 == 0 and self.y2 == 0:
            return self.x1
        elif self.x1 == 0 and self.y1 == 0 and self.y2 == 0:
            return self.x2

        if y1 > y2:
            round = abs((self.x2 - self.x1) * 2) + (self.y2 * 2)
        else:
            round = abs((self.x2 - self.x1) * 2) + (self.y1 * 2)
        return round


x1, y1, x2, y2 = map(int, input().split())

R = Rectangle(x1, y1, x2, y2)
T = Triangle(x1, y1, x2, y2)

trilen = abs(y2 - y1) + math.sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2)) - abs(x2 - x1)
print(trilen)

print(R.area() + T.area(), round(R.round() + trilen, 2))
