package lazylist;

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

infi = LazyList.integers(1)
println "${infi.fold(10,1){x,y->x*y}}"

println "${llist.foldAll([]){acc, hd->acc<<hd}} ${llist.foldAll([]){acc, hd->acc<<hd}.class}"

println "${infi.map(){it*it}.take(10)}"
println "${infi.filter(){it%2==0}.take(20)}"

println "${LazyList.rand.nextInt(100)}"
println "${LazyList.randoms().take(10)}"

println "integers(1).filter(isPrime).take(300)=${LazyList.integers(1).filter(LazyList.isPrime).take(300)}"