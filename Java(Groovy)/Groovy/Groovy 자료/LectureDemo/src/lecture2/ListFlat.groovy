package lecture2

class ListFlat {
	static String[] tokens = [];
	static tindex = 0;
	static String tok = '$';

	static main(args) {
		def str1 = '[ 1 2 [ 3 4 ] [ ] ] '
		tokens = str1.split(' ');
		println tokens;
		tindex = 0;
		getNext();
		println "FlatList=${flatList()}";
	}
	static flatList() {
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
	static getNext() {
		if (tindex >= tokens.length)
			tok = '$';
		else
			tok = tokens[tindex];
		tindex++;
	}

}
