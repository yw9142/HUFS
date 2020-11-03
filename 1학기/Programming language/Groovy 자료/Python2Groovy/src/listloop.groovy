
magicians = ['alice', 'david', 'carolina']
for (ma in magicians) {
	print(ma+" ")
}
println ()

magicians.each {
	print "$it "
} // closure in Groovy
println ()

for (value in 1..5) { // 5 가 포함됨
	print(value+" ")
}
println()

squares = []
for (value in 1..10) {
	square = value**2
	squares.add(square)
	println(squares)
}

digits = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]

println digits.min()
//0
println digits.max()
//9
println digits.sum()
//45

players = ['charles', 'martina', 'michael', 'florence', 'eli']
println (players[0..3]) // [3]을 포함

my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = (List)my_foods.clone()
println my_foods
println friend_foods

my_foods.add("cannoli")
friend_foods.add("ice cream")
println my_foods
println friend_foods

new_foods = my_foods
println new_foods
new_foods.add("ice cream")
my_foods.add('pasta')
println new_foods
println my_foods


