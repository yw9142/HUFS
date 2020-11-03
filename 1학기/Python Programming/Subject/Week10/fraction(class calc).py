# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean


class fraction(object):

    def __init__(self, numer, denom):
        self.numer = numer
        self.denom = denom

    def __str__(self):
        return str(self.numer) + '/' + str(self.denom)

    def getNumer(self):
        return self.numer

    def getDenom(self):
        return self.denom

    def gcd(self, other):
        if self < other:
            (self, other) = (other, self)
        while other != 0:
            (self, other) = (other, self % other)
        return self

    def __add__(self, other):
        numerNew = abs(other.getDenom() * self.getNumer() \
                       + other.getNumer() * self.getDenom())
        denomNew = abs(other.getDenom() * self.getDenom())
        ggcd = fraction.gcd(numerNew, denomNew)
        numerNew //= ggcd
        denomNew //= ggcd
        return fraction(numerNew, denomNew)

    def __sub__(self, other):
        numerNew = abs(other.getDenom() * self.getNumer() \
                       - other.getNumer() * self.getDenom())
        denomNew = abs(other.getDenom() * self.getDenom())
        ggcd = fraction.gcd(numerNew, denomNew)
        numerNew //= ggcd
        denomNew //= ggcd
        return fraction(numerNew, denomNew)

    def __mul__(self, other):
        numerNew = abs(other.getNumer() * self.getNumer())
        denomNew = abs(other.getDenom() * self.getDenom())
        ggcd = fraction.gcd(numerNew, denomNew)
        numerNew //= ggcd
        denomNew //= ggcd
        return fraction(numerNew, denomNew)

    def __truediv__(self, other):
        numerNew = abs(other.getDenom() * self.getNumer())
        denomNew = abs(other.getNumer() * self.getDenom())
        ggcd = fraction.gcd(numerNew, denomNew)
        numerNew //= ggcd
        denomNew //= ggcd
        return fraction(numerNew, denomNew)


enter = map(int, input().split())
enter = list(enter)

oneHalf = fraction(enter[0], enter[1])
twoThirds = fraction(enter[2], enter[3])

add = oneHalf + twoThirds
sub = oneHalf - twoThirds
mul = oneHalf * twoThirds
div = oneHalf / twoThirds

print(add)
print(sub)
print(mul)
print(div)
