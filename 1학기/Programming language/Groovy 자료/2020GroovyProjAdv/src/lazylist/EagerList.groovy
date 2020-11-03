package lazylist

class EagerList implements LispList {

	static final int MAX_LIMIT = Integer.MAX_VALUE
	private List list

	private EagerList(list) {
		this.list = list
	}

	static EagerList nil() {
		new EagerList( [] )
	}

	LispList cons(head) {
		new EagerList( [head, *list] )
	}

	def car() {
		list ? list[0] : null
	}

	LispList cdr() {
		list ? new EagerList(list.tail()) : nil()
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
		list.isEmpty()
	}

	def fold(n, acc, f) {
		n == 0 || isEmpty() ? acc : cdr().fold(n-1, f(acc, car()), f)
	}

	def foldAll(acc, f) {
		isEmpty() ? acc : cdr().foldAll(f(acc, car()), f)
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
		isEmpty() ? nil() : new EagerList( [f(car()), *(cdr().map(f).list)] )

		// doesn't work for infinite lists
		//isEmpty() ? nil() : cdr().map(f).cons(f.call(car()))
	}


	LispList filter(p) {
		isEmpty() ? nil() : p(car()) ? new EagerList( [car(), *(cdr().filter(p).list)] ) : cdr().filter(p)
	}

	String toString() {
		"EagerList(${list.toString()})"
	}
	
	def size() {
		list.size()
	}
	
	private static sequence(int n, int limit) {
		if (n == limit)
			[n]
		else
			[n, *sequence(n+1, limit)]
	}

	static EagerList integers(int n, int limit) {
		new EagerList(sequence(n, limit))
	}

	static EagerList naturals(int limit) {
		integers(1, limit)
	}


	static def zipWith(alist, blist, f) {
		alist.isEmpty() || blist.isEmpty() ? nil() : 
			new EagerList( [f(alist.car(), blist.car()), *(zipWith(alist.cdr(), blist.cdr(), f).list)] )
	}
	static Random rand = new Random(1111)
	private static  randomsClo() {
		{-> [rand.nextInt(100), randomsClo()]}
	}
	static EagerList randoms() {
		new EagerList(randomsClo())
	}
	static isPrime = {num ->
		if (num < 2) return false
		if (num == 2) return true
		if (num % 2 == 0) return false
		for (int i = 3; i * i <= num; i += 2)
			if (num % i == 0) return false;
		return true;
	}
}
