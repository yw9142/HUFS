package factorial

def factorial(n){
	if(n==0)
		1;
	else
		n*factorial(n-1);
}
def sigma(n) {
	if(n==0)
		0;
	else
		n+sigma(n-1);
}
a = [2,4,6,8,10]
def sum(List s) {
	if (s.size()==0)
		0
	else
		s.head() + sum(s.tail())
}
def sum1(List s) {
	def sum = 0
	for (a in s) {
		sum += a
	}
	return sum
}

def afact(int a, int n){ // Tail Recursion --> 자동으로 Loop으로 변형됨
	if (n==0)
		a;
	else
		afact(a*n, n-1); // recursive call은 return에만 온다
}
def fact (int n) {
	afact(1,n);
}

//sigma(10) = 1+2+3+4+...+10
for (int i=1; i<=10; ++i){
	println "${i}!=${factorial(i)}";
	//println "sigma${i}=${sigma(i)}";
	
}
println "sum([2,4,6,8,10])=${sum(a)}"
println "sum1([2,4,6,8,10])=${sum1(a)}"

for (int i=1; i<=10; ++i){
	println "${i}!=${fact(i)}";
}

