package bnf

tokens = [];
tindex = 0;
tok = '$';

def exp() {
	def t1 = term();
	while (tok.equals('+')) {
		getNext()
		t1 = t1 + term();
	}
	return t1;
}
def term() {
	def f1 = factor();
	while (tok.equals('*')){
		getNext()
		f1 = f1 * factor()
	}
	return f1;
}
def factor() {
	def temp;
	if (tok.equals('(')) {
		getNext()
		temp = exp();
		if (tok.equals(')')) {
			getNext();
		}
		else {
			println "Error tok=$tok"
		}
	}
	else if (tok.isInteger()) {
		temp = Integer.parseInt(tok);
		getNext();
	}
	else {
		println "Error tok=$tok"
	}
	return temp;
}
def getNext() {
	tok = tokens[tindex];
	tindex++;
}

def str1 = '12 + 3 * ( 4 + 5 ) $'
tokens = str1.split(' ');
println tokens;
tindex = 0;
getNext();
println "Eval Result=${exp()}";

