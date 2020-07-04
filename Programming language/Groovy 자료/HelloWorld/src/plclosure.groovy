d = 1
def incd(x) {
	x+d
}
println incd(10)
d=2
println incd(10)

incx = {x->x+d}
def fun(x, clo) {
	clo(x)
}
println fun(10,incx)
d=3
println fun(9,incx)

println fun(1, {it+d})
println fun(1, {x->x+d})
println fun(10) {it+d}
println fun(10) {x->x+d}

def li = [1,2,3,4,5,6]
def filter(lis, pre) {
	def res = []
	for (e in lis) {
		if (pre(e))
			res.add(e)
	}
	res
}
println filter(li,  {x-> x >4 })
