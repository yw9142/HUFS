package reverse;


def reverseList(List list) {
	if (list.size()==0)
		[]
	else
		reverseList(list.tail())+[list.first()]
}
// Todo Tail Recursive List Reverse
li = [1,2,3,4]
println "reverse $li = ${reverseList(li)}"