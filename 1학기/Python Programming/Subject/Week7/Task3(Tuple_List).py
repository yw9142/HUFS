# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

a = ()
b = ()
c = ('',)
d = ('a', 'b')
e = ('a', 'b', 'c')
f = ('d')

lists = [a, b, c, d, e, f]

if not a:
	lists.remove(a)
if not b:
	lists.remove(b)
if not c:
	lists.remove(c)
if not d:
	lists.remove(d)
if not e:
	lists.remove(e)
if not f:
	lists.remove(f)

print(lists)