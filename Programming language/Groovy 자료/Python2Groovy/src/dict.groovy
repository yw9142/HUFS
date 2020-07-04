
alien_0 = ['color': 'green', 'points': 5]// Python Dictionary -->Java,Groovyø°º≠ Map ¿Ã µ 
println(alien_0['color'])
println(alien_0['points'])

alien_0['x_position'] = 0
alien_0['y_position'] = 25
println alien_0

keys = ['kim', 'lee', 'yun', 'jin']
vals = [100, 200, 300, 400]
map1 = [:] //empty map
for (int i=0; i<keys.size(); ++i) {
	map1[keys[i]]  = vals[i]
}
println map1
println "${map1['kim']}"
println map1['kim']
map1.each {k,v->println "($k, $v)"}
map1.each {println "(${it.key}, ${it.value})"}