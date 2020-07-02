package sort

def rmerge(L1, L2) {
	if (L1.size()==0)
		L2
	else if (L2.size()==0)
		L1
	else {
		def x = L1.head()
		def y = L2.head()
		if (x<y)
			[x]+rmerge(L1.tail(), L2)
		else
			[y]+rmerge(L1, L2.tail())
	}
}

def lmerge (List list1, List list2) {
	int ind1 = 0;
	int ind2 = 0;
	List list = [];
	while (ind1<list1.size() && ind2<list2.size()) {
		if (list1[ind1] < list2[ind2]) {
			list.add(list1[ind1]);
			ind1++;
		}
		else {
			list.add(list2[ind2]);
			ind2++;
		}
	}
	while (ind1<list1.size()) {
		list.add(list1[ind1]);
		ind1++;
	}
	while (ind2<list2.size()) {
		list.add(list2[ind2]);
		ind2++;
	}
	return list;
}

def hmerge (List list1, List list2) {
	final HIGH_VALUE = Integer.MAX_VALUE; // Highest value for toCompare()

	int ind1 = 0;
	int ind2 = 0;
	List list = [];
	list1.add(HIGH_VALUE);
	list2.add(HIGH_VALUE);
	while (!(list1[ind1]==HIGH_VALUE && list2[ind2]==HIGH_VALUE)) {
		if (list1[ind1] < list2[ind2]) {
			list.add(list1[ind1]);
			ind1++;
		}
		else {
			list.add(list2[ind2]);
			ind2++;
		}
	}
	return list;
}

println "rmerge([1,3,5],[2,4,6])=${rmerge([1,3,5],[2,4,6])}"
println "lmerge([1,3,5],[2,4,6])=${lmerge([1,3,5],[2,4,6])}"
println "hmerge([1,3,5],[2,4,6])=${hmerge([1,3,5],[2,4,6])}"

def mergeSort(list) {
	def n = list.size()
	if (n<=1)
		list
	else {
		def n2 = (int)n/2
		def L1 = list[0 .. n2 - 1]
		def L2 = list[n2 .. n - 1]
		hmerge(mergeSort(L1), mergeSort(L2))
	}
}
println "mergeSort([2,4,6,1,3,5,10])=${mergeSort([2,4,6,1,3,5,10])}"
