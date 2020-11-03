package bnf

tokens = [];
tindex = 0;
tok = '$';

def getNext() {
	tok = tokens[tindex];
	tindex++;
}
def prefixEval() {
	def result;
	if (tok.isInteger()) {
		result = Integer.parseInt(tok);
		getNext();
		return result;
	}
	else if (tok.equals('+')){
		getNext();
		def t1 = prefixEval();
		def t2 = prefixEval();
		return t1 + t2
	}
	else if (tok.equals('-')){
		getNext();
		def t1 = prefixEval();
		def t2 = prefixEval();
		return t1 - t2
	}
}
def str1 = '+ - 5 2 4 $'
tokens = str1.split(' ');
println tokens;
tindex = 0;
getNext();
println "Eval result=${prefixEval()}";

