package reverse

def reverse(String str){
	if (str.size() == 0 || str.size() == 1){
		str
	}
	else {
		reverse(str.substring(1))+str[0]
	}
}

def rev(String s1, String s2){ // Tail Recursion
	if (s2.size() == 0)
		s1
	else {
		rev(s2[0]+s1, s2.substring(1));
	}
}
def reverse1(String str){
	rev("", str);
}

String s1 = "Hello World!";
println "s1 length=${s1.size()}";
String s2 = "blah blah blah";

println "rev1 s1 ${reverse(s1)}";
println "rev2 s1 ${reverse1(s1)}";

println "rev1 s2 ${reverse(s2)}";
println "rev2 s2 ${reverse1(s2)}";

