package exp

def add(x, y) { // x, y type이 정해지지 않음(type variable -- 원래의 Polymorphism)
	x + y
}
def a=10, b=20
println "a+b=${a+b}"
a="Hello "
b="World"
println "a+b=${a+b}"
a=[1,2,3]
b=[4,5]
println "a+b=${a+b}"
a=10 // int
b=1.5 // double
println "a+b=${a+b}" // Coercion
b="World"
println "a+b=${a+b}" // Coercion
b=[4,5]
//println "a+b=${a+b}" // 10+[4,5] Type Error 