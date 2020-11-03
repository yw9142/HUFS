# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import math as m

x=1.2
k=0
N=25
s=0
sign=1.0

while k<N:
    term=sign*x**(k)/m.factorial(k)
    s=s+term
    k += 2
    sign = -sign

print(s)