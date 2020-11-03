package listsort;


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
def quickSort(list, comp) {
	if (list.size()<=1)
		list
	else {
		def piv = list.head()
		def low = filter(list) {comp(it,piv) < 0 }
		def eql = filter(list) {comp(it,piv) == 0 }
		def high = filter(list) {comp(it,piv) > 0 }
		quickSort(low, comp) + eql + quickSort(high, comp)
	}
}
println "quickSort([2,4,6,1,3,5,4]){x,y->x<=>y}=${quickSort([2,4,6,1,3,5,4]){x,y->x<=>y}}"

def listComp
listComp = { xl,yl ->
	if ((xl==null && yl==null)||(xl.size()==0 && yl.size()==0))
		0
	else if (xl==null || xl.size()==0)
		-1
	else if (yl==null || yl.size()==0)
		1
	else {
		xh = xl.head()
		yh = yl.head()
		if (xh==yh) 
			listComp(xl.tail(), yl.tail())
		else
			xh<=>yh
	}
}

def zip(L1, L2, f) {
	if (L1.size()==0 && L2.size()==0)
		[]
	else if (L1.size()!=L2.size())
		throw new Exception("Zip with unequal length list")
	else
		[f(L1.head(), L2.head())]+zip(L1.tail(), L2.tail(), f)
}
def map(list, f) {
	if (list.size()==0)
		list
	else
		[f(list.head())]+map(list.tail(),f)
}

listToSort = [[1,5,4,3,2,1],[1,6,4,3,2,1],[1,6,5,3,2,1],[1,13,12,7,5,1],
	[2,1,4,3,2],[2,13,11,8,6],[2,13,11,8,7],[3,2,1,3],[3,13,12,11],
	[3,13,12,9],[4,1,3,2],[4,13,12,11],[4,13,12,8],[5,1,2],
	[5,13,12],[5,13,11],[6,1,2],[6,13,12],[6,13,1]]

nlist = listToSort.tail()<<listToSort.last()
println nlist
plist = zip(listToSort,nlist){x,y->[x,y]}
println plist
println map(plist) {lp->
	xl = lp[0]
	yl = lp[1]
	listComp(xl,yl)}

println quickSort(listToSort, listComp)

(A,K,Q,J) = [1,13,12,11]
cardList = [[A,2,3,4,5],[A,2,3,4,6],[A,2,3,5,6],[A,5,7,Q,K],
	[A,A,2,3,4],[6,8,J,K,K],[7,8,J, K,K],[A,A,2,2,3],
	[Q,Q,J,K,K],[9,Q,Q,K,K,],[A,A,A,2,3],[Q,J,K,K,K],
	[8,Q,K,K,K],[A,A,A,2,2],[Q,Q,K,K,K],[J,J,K,K,K],
	[A,A,A,A,2],[Q,K,K,K,K],[A,K,K,K,K]]
println cardList

def getPairs(list) {
	if (list.size() < 2)
		[]
	else {
		if (list[0]==list[1])
			[list[0]]+getPairs(list[2..<list.size()])
		else
			getPairs(list[1..<list.size()])
	}
}
println getPairs([1, 1, 2, 2, 3])
println getPairs([1, 1, 2, 3, 3])
println getPairs([1, 2, 2, 3, 3])

println map(cardList) { getPairs(it) }

def isStraightStart(a,list) {
	if (list.size() == 0)
		true
	else if (list.size() == 1)
		list.head() == a+1 
	else {
		hd = list.first()
		tl = list.tail()
		hd == a+1 && isStraightStart(a+1,tl)
	}
}
def isStraight(list) {
	isStraightStart(list.head(), list.tail())
}
cardList = [[A,2,3,4,5],[2,3,4,5,6],[3,4,5,6,7],[9,10,J,Q,K],
	[A,A,2,3,4],[6,7,8,9,10],[K,K,7,8,J],[10,J,Q,K,A]]
println map(cardList) { isStraight(it) }

def swap(arr, i, j) {
	def temp = arr[i]
	arr[i] = arr[j]
	arr[j] = temp
}
def partition(arr, low, high, comp) {
	def pivot = arr[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high- 1; j++){
		// If current element is smaller than or
		// equal to pivot
		if (comp(arr[j],pivot) <= 0) {
			i++;    // increment index of smaller element
			swap(arr, i, j);
		}
	}
	swap(arr, i + 1, high);
	return (i + 1);
}
def quickSortA(arr, low, high, comp) {
	if (low < high)	{
		/* pi is partitioning index, arr[p] is now
		 at right place */
		int pi = partition(arr, low, high, comp);

		// Separately sort elements before
		// partition and after partition
		quickSortA(arr, low, pi - 1, comp);
		quickSortA(arr, pi + 1, high, comp);
	}
}

quickSortA(listToSort, 0, listToSort.size()-1, listComp)
println listToSort

def MAX_SIZE = 1000
def bigList = []
Random rand = new Random(MAX_SIZE)
for (int i =0; i<MAX_SIZE; ++i) {
	int lsize = rand.nextInt(4)+3
	//println lsize
	alist = []
	(1..lsize).each {
		alist << rand.nextInt(13)+1
	}
	bigList << alist
}
println bigList
//println quickSort(bigList, listComp)
quickSortA(bigList, 0, bigList.size()-1, listComp)
println bigList
