bicycles = ['trek', 'cannondale', 'redline', 'specialized']
println bicycles
println (bicycles.getClass())
println (bicycles[0])
println(bicycles[1])
println(bicycles[3])
println(bicycles[bicycles.size()-1])
println(bicycles[-1])

motorcycles = ['honda', 'yamaha', 'suzuki']
println (motorcycles)
motorcycles[0] = 'ducati'
println (motorcycles)

motorcycles << 'ducati' // Groovy list append operator
println (motorcycles)
motorcycles.add('dugati')
println (motorcycles)

motorcycles = ['honda', 'yamaha', 'suzuki']
motorcycles.addAll(0, 'ducati') // insert
println (motorcycles)

motorcycles.remove(0)
println (motorcycles)

cars = ['bmw', 'audi', 'toyota', 'subaru']
cars.sort()
println cars

println cars.size()

