package lazylist

interface LispList {
	
    LispList cons(head);
    def car();
    LispList cdr();
    def methodMissing(String name, args);
    boolean isEmpty();
    def fold(n, acc, f);
    def foldAll(acc, f);
    def take(n);
    def takeAll(); 
    List toList();
    LispList map(f);
	LispList filter(p);
	def size();
}
