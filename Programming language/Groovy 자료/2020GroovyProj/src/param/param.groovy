package param

def swap(x, y) { // call by assignment
	t = x
	x = y
	y = t
}

a = 10 
b = 100
swap (a, b)
println "a=$a b=$b"
println a.class

a = "Hello"
b = "World"
swap (a, b)
println "a=$a b=$b"
println a.class

def revCopy(List l1, List l2) {
	for (def i=0; i<l1.size(); ++i) {
		l1[i] = l2[l2.size()-i-1]
	}
}
def revCopy1(List l1, List l2) {
	l2 = l2.clone()
	for (def i=0; i<l1.size(); ++i) {
		l1[i] = l2[l2.size()-i-1]
	}
}

li1 = [1,2,3,4]
li2 = [5,6,7,8]
println "l1i=$li1, li2=$li2"
revCopy(li1, li2)
println "l1i=$li1, li2=$li2"

li1 = [1,2,3,4]
revCopy(li1, li1)
println "l1i=$li1"

li1 = [1,2,3,4]
revCopy1(li1, li1)
println "l1i=$li1"

