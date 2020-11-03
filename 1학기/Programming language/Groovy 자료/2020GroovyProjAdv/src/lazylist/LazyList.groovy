package lazylist;

class LazyList implements LispList {

    private Closure list

    private LazyList(list) {
        this.list = list
    }

    static LazyList nil() {
        new LazyList( {-> []} )
    }

    LispList cons(head) {
        new LazyList( {-> [head, list]} )
    }


    def car() {
        def lst = list.call()
        lst ? lst[0] : null
    }

    LispList cdr() {
        def lst = list.call()
        lst ? new LazyList(lst[1]) : nil()
    }


    def methodMissing(String name, args) {
        def matcher = name =~ /^c([ad]+)r$/
        if (matcher) {
            matcher[0][1].reverse().toList().inject(this) {
                del, cr -> del."c${cr}r"()
            }
        } else {
            throw new MissingMethodException(name, this.class, args)
        }
    }

    boolean isEmpty() {
        list.call() == []
    }

    def fold(n, acc, f) {
        n == 0 || isEmpty() ? acc : cdr().fold(n-1, f.call(acc, car()), f)
    }

    def foldAll(acc, f) {
        isEmpty() ? acc : cdr().foldAll(f.call(acc, car()), f)
    }


    def take(n) {
        fold(n, []) {acc, item -> acc << item}
    }

    def takeAll() {
        foldAll([]) {acc, item -> acc << item}
    }
    
    List toList() {
        takeAll()
    }


    LispList map(f) {
        isEmpty() ? nil() : new LazyList( {-> [f.call(car()), cdr().map(f).list]} )

        // doesn't work for infinite lists
        //isEmpty() ? nil() : cdr().map(f).cons(f.call(car()))
    }


    LispList filter(p) {
        isEmpty() ? nil() : p.call(car()) ? new LazyList( {-> [car(), cdr().filter(p).list]} ) : cdr().filter(p)
    }

	String toString() {
		"LazyList(${toList().toString()})"
	}

	def size() {
		toList().size()
	}
	
	private static sequence(int n) {
        {-> [n, sequence(n+1)]}
    }

    static LazyList integers(int n) {
        new LazyList(sequence(n))
    }

    static LazyList naturals() {
        integers(1)
    }


    static def zipWith(alist, blist, f) {
        alist.isEmpty() || blist.isEmpty() ? nil() : new LazyList( {-> [f.call(alist.car(), blist.car()), zipWith(alist.cdr(), blist.cdr(), f).list]} )
    }
	static Random rand = new Random(1111)
	private static  randomsClo() {
		{-> [rand.nextInt(100), randomsClo()]}
	}
	static LazyList randoms() {
		new LazyList(randomsClo())
	}
	static isPrime = {num -> 
		if (num < 2) return false
		if (num == 2) return true
		if (num % 2 == 0) return false
		for (int i = 3; i * i <= num; i += 2)
			if (num % i == 0) return false;
		return true;
	}
	static cycleFun(data) { 
		{->[data, cycleFun(data)]}
	};
	static LazyList cycle(data) {
		new LazyList(cycleFun(data));
	}

}