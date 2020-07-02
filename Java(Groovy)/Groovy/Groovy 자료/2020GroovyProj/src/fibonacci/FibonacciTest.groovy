package fibonacci

int rfib (int n) {// recursive, bad algorithm
	if (n == 0 || n == 1) 
		1;
	else
		rfib(n-1) + rfib(n-2);
}
int lfib (int n) { // loop, good algorithm
	int fold1 = 1;
	int fold2 = 1;
	int fnew;
	for (int i = 2; i <= n; i++) {
		fnew = fold1 + fold2;
		fold2 = fold1;
		fold1 = fnew;
	}
	return fnew;
}

int tfib (int n, int prev, int curr) { // tail recursive, good algorithm
	if (n==0 || n==1) return curr
	return tfib(n-1, curr, prev+curr)
}
int tfib(int n) {
	return tfib(n, 1, 1);
}
def mfib // memoize(중복계산 방지하는 Groovy 기능)
mfib = {n->
	if (n<=1)
		1
	else
		mfib(n-1)+mfib(n-2)
}.memoize()

int num = 30;
int fib;
int count;

long startTime;
long endTime;
double elapsedTime;

startTime = System.nanoTime();
for (count = 1; count <=5000; count++) {
	fib = lfib(num);
}
endTime = System.nanoTime();

println "lfib($num) = $fib";
elapsedTime = (endTime - startTime) / 1E9;      // nano sec to sec
println "Computing Time(Loop) = $elapsedTime sec";

startTime = System.nanoTime();
for (count = 1; count <=5000; count++) {
	fib = rfib(num);
}
endTime = System.nanoTime();

println "rfib($num) = $fib";
elapsedTime = (endTime - startTime) / 1E9;      // nano sec to sec
println "Computing Time(Recursive) = $elapsedTime sec";

startTime = System.nanoTime();
for (count = 1; count <=5000; count++) {
	fib = tfib(num);
}
endTime = System.nanoTime();

println "tfib($num) = $fib";
elapsedTime = (endTime - startTime) / 1E9;      // nano sec to sec
println "Computing Time(Tail Recursive) = $elapsedTime sec";

startTime = System.nanoTime();
for (count = 1; count <=5000; count++) {
	fib = mfib(num);
}
endTime = System.nanoTime();

println "mfib($num) = $fib";
elapsedTime = (endTime - startTime) / 1E9;      // nano sec to sec
println "Computing Time(Memoize) = $elapsedTime sec";
