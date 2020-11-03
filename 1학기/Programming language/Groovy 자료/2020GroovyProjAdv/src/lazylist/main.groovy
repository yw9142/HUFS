package lazylist

println ({->[]}())
println ({->[]}.call())

nil = {[]}
println nil()
println nil.call()

llist = LazyList.nil().cons(4).cons(3).cons(2).cons(1)
println "${llist} ${llist.class}"
println "${llist.take(10)} ${llist.take(10).class}"
println "${llist.car()} ${llist.car().class}"
println "${llist.cddr()}"
println "${llist.caddr()}"
println "${llist.size()}"
println "${llist.foldAll([]){acc, hd->acc<<hd}} ${llist.foldAll([]){acc, hd->acc<<hd}.class}"

println "LazyList.cycle('hello').take(10) = ${LazyList.cycle('hello').take(10)}"