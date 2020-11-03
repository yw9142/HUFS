package lazylist

EagerList list = EagerList.nil().cons(4).cons(3).cons(2).cons(1)

println list

println list.car() // == 1
println list.cdr().car() // == 2

println list.caddr() // == 3

println EagerList.integers(10,100).take(10)

EagerList lmn = EagerList.nil().cons('N').cons('M').cons('L')
EagerList almnz = EagerList.nil().cons('Z').cons(lmn).cons('A')
println lmn

println almnz.cadadr() // == 'M'

ArrayList.metaClass.eager = {
    -> delegate.reverse().inject(EagerList.nil()) {li, item -> li.cons(item)}
}

println ([1,2,3,4,5].eager())
println ([1,2,3,4,5].eager().foldAll(0){ acc, i -> acc + i }) // == 15
println ([1,2,3,4,5].eager().fold(3, 1){ acc, i -> acc * i }) // == 6

println ([1,2,3,4,5].eager().takeAll()) // == [1,2,3,4,5]
println ([1,2,3,4,5].eager().take(3)) // == [1,2,3]

println ([1,2,3,4,5].eager().map{ 2 * it }.take(3)) // == [2,4,6]

println ([1,2,3,4,5].eager().filter{ 2 < it }.take(2)) // == [3,4]

try {
	println ([1,2,3,0,6].eager().map{ 6 / it }.take(3)) // Division by zero
} catch (e){
	println e
}

def naturals = EagerList.naturals(50)
println (naturals.take(3)) // == [1,2,3]

def evens = naturals.map { 2 * it }
println (evens.take(3)) // == [2,4,6]

def odds = naturals.filter { it % 2 == 1 }
println (odds.take(3)) // == [1,3,5]

println (naturals.cadddddddddr()) // == 10

def nonnegatives = naturals.cons(0)
println (nonnegatives.cadr()) // == 1

println (EagerList.zipWith(evens, odds){ x, y -> x * y }.take(4)) // == [2,12,30,56]

def intTo500 = EagerList.integers(1, 500)
println (intTo500.take(10))
println "intTo500.filter(isPrime).take(100)=${intTo500.filter(EagerList.isPrime).take(100)}"

def primeList = intTo500.filter(EagerList.isPrime)
println "size=${primeList.size()}"
