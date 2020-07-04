package func
// type variable parameter function 
// original polymorphism concept
def add(x, y) {
	x+y
}
println add(1,2)
println add(1.5, 2.5)
println add("Hello ", "World")
println add([1,2,3], [4,5,6])

def fst (x, y) {
	x
}
def snd (x, y) {
	y
}
println fst(1,2)
println fst(1.5, 2)
println fst("Hello ", 2)
println fst([1,2,3], "World")

println snd([1,2,3],2)
println snd(1.5, 2.5)
println snd(1, "World")
println snd(1.5, [4,5,6])

