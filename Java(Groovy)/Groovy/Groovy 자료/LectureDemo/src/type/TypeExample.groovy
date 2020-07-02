package type

def intOrString(num) {
	if (num < 10)
		return ++num
	else
		return "Num $num > 10"
}
def var1 = intOrString(5)
println "var1=$var1"
var1 = intOrString(15)
println "var1=$var1"
String var2 = intOrString(5)
println "type intOrString(5)=${intOrString(5).getClass()} var2=$var2"
println "type var2=${var2.getClass()} var2=$var2"
double var3 = intOrString(15)
println "type intOrString(15)=${intOrString(15).getClass()} var3=$var3"
println "type var2=${var3.getClass()} var3=$var3"
