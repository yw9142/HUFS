package sort

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

def quickSort(List list) {
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
