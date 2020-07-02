package recursive;

def comb(n, m) {
	if (m==0 || m==n)
		1
	else
		comb(n-1,m)+comb(n-1,m-1)
}

println "comb(4,2)=${comb(4,2)}"

def merge(L1, L2) {
	if (L1.size()==0)
		L2
	else if (L2.size()==0) 
		L1
	else {
		def x = L1.head()
		def y = L2.head()
		if (x<y)
			[x]+merge(L1.tail(), L2)
		else
			[y]+merge(L1, L2.tail())		
	}		
}
println "merge([1,3,5],[2,4,6])=${merge([1,3,5],[2,4,6])}"

def mergeSort(list) {
	def n = list.size()
	if (n<=1)
		list
	else {
		def n2 = (int)n/2
		def L1 = list[0 .. n2 - 1]
		def L2 = list[n2 .. n - 1]
		merge(mergeSort(L1), mergeSort(L2))
	}
}
println "mergeSort([2,4,6,1,3,5,10])=${mergeSort([2,4,6,1,3,5,10])}"

def map(list, f) {
	if (list.size()==0)
		list
	else
		[f(list.head())]+map(list.tail(),f)
}
println "map([1,2,3]){it*it}=${map([1,2,3]){it*it}}"
println "map([1,2,3]){x->x*x}=${map([1,2,3]){x->x*x}}"

def reduce(list, f) {
	if (list.size()==0)
		throw new Exception("Empty List")
	else if (list.size()==1)
		list.head()
	else {
		def x = list.head()
		f(x, reduce(list.tail(), f))		
	}		
} 
println "reduce([1,2,3,4]){x,y->x+y}=${reduce([1,2,3,4]){x,y->x+y}}"

def filter(list, p) {
	if (list.size()==0)
		list
	else {
		if (p(list.head()))
			[list.head()]+filter(list.tail(),p)
		else
			filter(list.tail(),p)
	}
}
println "filter([1,2,3,4]){it%2==0}=${filter([1,2,3,4]){it%2==0}}"

def fold(a, list, f) {
	if (list.size()==0)
		a
	else {
		def x = list.head()
		f(x, fold(a, list.tail(), f))
	}
}
println "fold(0,[1,2,3,4]){x,y->x+y}=${fold(0,[1,2,3,4]){x,y->x+y}}"
println "fold(1,[1,2,3,4]){x,y->x*y}=${fold(1,[1,2,3,4]){x,y->x*y}}"

def zip(L1, L2, f) {
	if (L1.size()==0 && L2.size()==0)
		[]
	else if (L1.size()!=L2.size())
		throw new Exception("Zip with unequal length list")
	else
		[f(L1.head(), L2.head())]+zip(L1.tail(), L2.tail(), f)
}
println "zip([1,3,5],[2,4,6]){x,y->x+y}=${zip([1,3,5],[2,4,6]){x,y->x+y}}"
println "zip([1,3,5],[6,4,2]){x,y->x>y}=${zip([1,3,5],[6,4,2]){x,y->x>y}}"

def remove(list, a) {
	if (list.size()==0)
		[]
	else {
		def hd = list.head()
		if (hd == a)
			list.tail()
		else
			[hd]+remove(list.tail(), a)
	}
}
println "remove([1,2,3,1,2,3], 3)=${remove([1,2,3,1,2,3], 3)}"

def fremove(list, a) {
	filter(list){it!=a}
}
println "fremove([1,2,3,1,2,3], 3)=${fremove([1,2,3,1,2,3], 3)}"

def perms(list) {
	if (list.size()==0) 
		[[]]
	else {
		def res = []
		list.each {a->
			perms(remove(list, a)).each { pe->
				res << [a]+pe
			}
		}
		res
	}
}

println "perms([1,2,3])=${perms([1,2,3])}"

def cart(L1, L2) {
	res = []
	L1.each {x->
		L2.each {y->
			res << [x,y]
		}
	}
	res
}
println "cart([1,3,5],[2,4,6])=${cart([1,3,5],[2,4,6])}"

def minList(list) {
	reduce(list){x,y->Math.min(x,y)}
}
println "minList([2,4,6,1,3,5])=${minList([2,4,6,1,3,5])}"
def delMin(list) {
	def m = minList(list)
	remove(list, m)
}
mylist = [2,4,6,1,3,5]
println "delMin(mylist)=${delMin(mylist)}, mylist=$mylist"

def selSort(list) {
	if (list.size()==0 || list.size()==1)
		list
	else {
		def m = minList(list)
		[m]+selSort(delMin(list))
	}
}
println "selSort([2,4,6,1,3,5])=${selSort([2,4,6,1,3,5])}"

def all(list) {
	//def count = 0
	for (b in list) {
		//println "${++count}"
		if (!b) return false
	}
	true
}
println "all([true, false, true, true, true])=${all([true, false, true, true, true])}"
def isSorted(list) {
	nlist = list.tail()<<list.last()
	all(zip(list,nlist){x,y->x<=y})
}
println "isSorted([1, 2, 3, 4, 5, 6])=${isSorted([1, 2, 3, 4, 5, 6])}"

def badSort(list) {
	filter(perms(list)) {isSorted(it)}
}
println "badSort([2,4,6,1,3,5])=${badSort([2,4,6,1,3,5])}"

def quickSort(list) {
	if (list.size()<=1)
		list
	else {
		def piv = list.head()
		def tl = list.tail()
		def low = filter(tl) {it < piv }
		def high = filter(tl) {!(it < piv)}
		quickSort(low) + [piv] + quickSort(high)
	}
}
println "quickSort([2,4,6,1,3,5])=${quickSort([2,4,6,1,3,5])}"

def partition(piv, left, right, list) {
	if (list.size()==0)
		qsort(left) + [piv] + qsort(right)
	else {
		def hd = list.head()
		def tl = list.tail()
		if (hd<piv) {
			partition(piv, [hd]+left, right, tl)
		}
		else {
			partition(piv, left, [hd]+right, tl)			
		}
	}
}
def qsort(list) {
	if (list.size()<=1)
		list
	else {
		def hd = list.head()
		def tl = list.tail()
		partition(hd, [], [], tl)
	}
}
println "qsort([2,4,6,1,3,5])=${qsort([2,4,6,1,3,5])}"

