package bnf

tokens = [];
tindex = 0;
tok = '$';

def flatList() {
	def elems = [];
	if (tok.equals('[')) {
		getNext();
		while (tok.isInteger() || tok.equals('[')) {
			if (tok.isInteger()) {
				elems.add(tok)
				getNext();
			}
			else {
				elems.addAll(flatList())
			}
		}
		if (tok.equals(']')) {
			getNext();
		}
	}
	else {
		println "Error tok=$tok";
	}
	return elems;
}
def getNext() {
	tok = tokens[tindex];
	tindex++;
}
def str1 = '[ 1 2 [ 3 4 ] [ ] ] $'
tokens = str1.split(' ');
println tokens;
tindex = 0;
getNext();
println "FlatList=${flatList()}";
