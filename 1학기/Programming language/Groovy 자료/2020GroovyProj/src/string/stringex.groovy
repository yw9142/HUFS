package string

s1 = "Hello "
s2 = "World!"
s3 = "Earth!"
s4 = s1+s2
println "s4=$s4"
s2 = s3
println "s4=$s4" // s2�� s3�� �ٲ㵵 s4�� ������ �ʴ´� 
s4 = s1+s3
println "s4=$s4"
println "|$s1| |$s2| ${s1.compareTo(s2)} ${s2.compareTo(s1)}"


s1 = new StringBuilder("Hello ")
s2 = new StringBuilder("World!")
println "s1=${s1.toString()}"
println "s2=${s2.toString()}"

s3 = s1
s1.append(s2);
println "s1=${s1.toString()}"
println "s3=${s3.toString()}"// s1�� ���ϸ� s3�� ���Ѵ� 

s1 = 9.toString();
s2 = 100.toString();
println "|$s1| |$s2| ${s1.compareTo(s2)} ${s2.compareTo(s1)}"



