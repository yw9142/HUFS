package lazylist

println ({->[]}())
nil = {[]}
println nil()
println nil.call()

llist = LazyList.nil().cons(4).cons(3).cons(2).cons(1)
println "${llist} ${llist.class}"
println "${llist.take(10)} ${llist.take(10).class}"
println "${llist.car()} ${llist.car().class}"
println "${llist.cddr()}"
println "${llist.caddr()}"

LazyList list = LazyList.nil().cons(4).cons(3).cons(2).cons(1)

println list

println list.car() // == 1
println list.cdr().car() // == 2

println list.caddr() // == 3

println LazyList.integers(10).take(10)

LazyList lmn = LazyList.nil().cons('N').cons('M').cons('L')
LazyList almnz = LazyList.nil().cons('Z').cons(lmn).cons('A')
println lmn

println almnz.cadadr() // == 'M'

ArrayList.metaClass.lazy = {
	-> delegate.reverse().inject(LazyList.nil()) {li, item -> li.cons(item)}
}

println ([1,2,3,4,5].lazy())
println ([1,2,3,4,5].lazy().foldAll(0){ acc, i -> acc + i }) // == 15
println ([1,2,3,4,5].lazy().fold(3, 1){ acc, i -> acc * i }) // == 6

println ([1,2,3,4,5].lazy().takeAll()) // == [1,2,3,4,5]
println ([1,2,3,4,5].lazy().take(3)) // == [1,2,3]

println ([1,2,3,4,5].lazy().map{ 2 * it }.take(3)) // == [2,4,6]

println ([1,2,3,4,5].lazy().filter{ 2 < it }.take(2)) // == [3,4]

try {
	println ([1,2,3,0,6].lazy().map{ 6 / it }.take(3)) // Division by zero
} catch (e){
	println e
}

def naturals = LazyList.naturals()
println (naturals.take(3)) // == [1,2,3]

def evens = naturals.map { 2 * it }
println (evens.take(3)) // == [2,4,6]

def odds = naturals.filter { it % 2 == 1 }
println (odds.take(3)) // == [1,3,5]

println (naturals.cadddddddddr()) // == 10

def nonnegatives = naturals.cons(0)
println (nonnegatives.cadr()) // == 1

println (LazyList.zipWith(evens, odds){ x, y -> x * y }.take(4)) // == [2,12,30,56]

def infi = LazyList.integers(1)
println "${infi.fold(10,1){x,y->x*y}}"

llist = LazyList.nil().cons(4).cons(3).cons(2).cons(1)
println "${llist} ${llist.class}"
println "${llist.take(10)} ${llist.take(10).class}"
println "${llist.car()} ${llist.car().class}"
println "${llist.cddr()}"
println "${llist.caddr()}"
println "${llist.foldAll([]){acc, hd->acc<<hd}} ${llist.foldAll([]){acc, hd->acc<<hd}.class}"

println "${infi.map(){it*it}.take(10)}"
println "${infi.filter(){it%2==0}.take(20)}"

println "${LazyList.rand.nextInt(100)}"
println "${LazyList.randoms().take(10)}"

println "integers(1).filter(isPrime).take(300)=${LazyList.integers(1).filter(LazyList.isPrime).take(300)}"