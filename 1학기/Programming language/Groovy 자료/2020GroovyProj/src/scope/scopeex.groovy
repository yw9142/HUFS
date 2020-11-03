package scope

def foo(a1,b1) {
	println "a1=$a1, b1=$b1"
	def a=100,b=200
	def c=10,d=20
	
	def flag = true
	while (flag){
		def e=5,f=6
		println "a=$a, b=$b, c=$c, d=$d, e=$e, f=$f"
		flag = false
	}
	def e=50,f=60
	println "c=$c, d=$d, e=$e, f=$f"
}
def a=1 // class variable
def b=2 // class variable
println "a=$a, b=$b"

foo(a,b)

