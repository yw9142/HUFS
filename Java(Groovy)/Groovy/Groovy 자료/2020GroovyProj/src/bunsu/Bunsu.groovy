package bunsu

class Bunsu  implements Comparable<Bunsu> {

	long bunja;
	long bunmo;

	Bunsu(long t, long b) {
		bunja = t;
		bunmo = b;
		normalize();
	}
	Bunsu() {
		this(0, 1);
		//bunja = 0;
		//bunmo = 1;
	}
	Bunsu(long t) {
		this(t, 1);
		//bunja = t;
		//bunmo = 1;
	}
	String toString() {
		"${bunja}/${bunmo}"
	}
	boolean equals(Bunsu right) {
		compareTo(right) == 0;
	}
	@Override
	int compareTo(Bunsu right) {
		bunja * right.bunmo - bunmo * right.bunja;
	}

	static long gcd(long n, long m) {
		// Euclids Greatest Common Divisor algorithm.
		assert((n > 0) && (m > 0));
		while (n != m) {
			if (n < m)
			m = m - n;
			else
			n = n - m;
		}
		return n;
	}
	def normalize()	{
		// Normalize fraction by
		// (a) moving sign to bunja
		// (b) ensuring bunja and bunmo have no common divisors
		long sign = 1;
		if (bunja < 0) {
			sign = -1;
			bunja = - bunja;
		}
		if (bunmo < 0) {
			sign = - sign;
			bunmo = - bunmo;
		}
		assert(bunmo != 0);
		long d = 1;
		if (bunja > 0) d = gcd(bunja, bunmo);
			bunja = sign * (bunja / d);
		bunmo = bunmo / d;
	}

	Bunsu plus(Bunsu right)	{		
		return new Bunsu(
		bunja * right.bunmo + right.bunja * bunmo,
		bunmo * right.bunmo);
	}

	Bunsu minus(Bunsu right) {
		new Bunsu(
		bunja * right.bunmo - right.bunja * bunmo,
		bunmo * right.bunmo);
	}

	Bunsu multiply(Bunsu right)	{
		new Bunsu(bunja * right.bunja, bunmo * right.bunmo);
	}

	Bunsu div(Bunsu right) {
		new Bunsu(bunja * right.bunmo, bunmo * right.bunja);
	}

	Bunsu negative() {
		new Bunsu(-bunja, bunmo);
	}

	Bunsu next() {
		bunja += bunmo;
		return this;
	}

	static main(args) {

		Bunsu a = new Bunsu(); // Value is 0/1
		Bunsu b = new Bunsu(4); // Value is 4/1
		Bunsu c = new Bunsu(6,8); // Value is 6/8, which is converted to 3/4
		println "Constructed values $a $b $c";
		
		Bunsu d = c; // d reference c(3/4) instance(aliasing)
		c.next();
		println "Value of c is $c";
		println "Value of d is $d";
		
		// Test arithmetic instructions
		d = b + c;
		println "4 + 3/4 is $d";
		d = b - c;
		println "4 - 3/4 is $d";
		Bunsu e = (b + (-c));
		println "Done with negation e = $e";
		
		if (d == e)
			println "Subtraction test successful.";
		else
			println "Subtraction test failed.";
			
		a = new Bunsu(6,8);
		b = new Bunsu(7,8);
		if ((a<=>b) < 0)
			println "Compare successful. a<=>b = ${a<=>b}";
		if (a<=b)
			println "a<=b = ${a<=b}";
			
		Bunsu h = new Bunsu(0);
		for (int i=1; i<=30; ++i){
			h = h + new Bunsu(1,i);
			println " 1/1+...+1/$i = $h";
		}
		println " 1/1+...+1/30 = $h";
	}

}
