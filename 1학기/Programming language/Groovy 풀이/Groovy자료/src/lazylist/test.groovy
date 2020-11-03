package lazylist;

def lazylist = LazyList.nil().cons(4).cons(3).cons(2).cons(1)

println lazylist

assert lazylist.car() == 1
assert lazylist.cdr().car() == 2

assert lazylist.caddr() == 3

println LazyList.integers(10).take(10)

def lmn = LazyList.nil().cons('N').cons('M').cons('L')
def almnz = LazyList.nil().cons('Z').cons(lmn).cons('A')
assert almnz.cadadr() == 'M'

ArrayList.metaClass.lazy = {
    -> delegate.reverse().inject(LazyList.nil()) {list, item -> list.cons(item)}
}
def lazyfied = ['A', ['L','M','N'].lazy(), 'Z'].lazy()
assert lazyfied.cadadr() == 'M'

println ([1,2,3,4,5].lazy())
assert [1,2,3,4,5].lazy().foldAll(0){ acc, i -> acc + i } == 15
assert [1,2,3,4,5].lazy().fold(3, 1){ acc, i -> acc * i } == 6

assert [1,2,3,4,5].lazy().takeAll() == [1,2,3,4,5]
assert [1,2,3,4,5].lazy().take(3) == [1,2,3]
println ([1,2,3,4,5].lazy().takeAll())

assert [1,2,3,4,5].lazy().map{ 2 * it }.take(3) == [2,4,6]


assert [1,2,3,4,5].lazy().filter{ 2 < it }.take(2) == [3,4]


assert [1,2,3,0,6].lazy().map{ 6 / it }.take(3) == [6,3,2]

try {
    [1,2,3,0,6].lazy().map{ 6 / it }.takeAll()
}
catch (Exception e) {
    assert e instanceof ArithmeticException
}


def naturals = LazyList.naturals()
assert naturals.take(3) == [1,2,3]

def evens = naturals.map { 2 * it }
assert evens.take(3) == [2,4,6]

def odds = naturals.filter { it % 2 == 1 }
assert odds.take(3) == [1,3,5]

assert naturals.cadddddddddr() == 10

def nonnegatives = naturals.cons(0)
assert nonnegatives.cadr() == 1

assert LazyList.zipWith(evens, odds){ x, y -> x * y }.take(4) == [2,12,30,56]