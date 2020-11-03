package scope

def a=1
def b=2
def foo(a,b) {
	def c=10,d=20
	
	def flag = true
	while (flag){
		//def a=300
		//def b=400
		println "a=$a, b=$b, c=$c, d=$d"
		flag = false
		//def c=100,d=200
	}
	println "a=$a, b=$b, c=$c, d=$d"
}