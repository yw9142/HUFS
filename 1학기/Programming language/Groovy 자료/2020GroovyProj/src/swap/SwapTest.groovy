package swap

def swap1(int x, int y){
	int t = x;
	x = y;
	y = t;
}
def swap2(int[] p){
	int t = p[0];
	p[0] = p[1];
	p[1] = t;
}
def swap3(int ... p){
	int t = p[0];
	p[0] = p[1];
	p[1] = t;
}
def swap4(Integer x, Integer y) {
	int t = x;
	x = y;
	y = t;
}
int a = 10;
int b = 100;
swap1(a, b);
println "$a $b";

int[] ar = [10, 100];

swap2(ar);
println "${ar[0]} ${ar[1]}";

a = 10;
b = 100;
swap3(a, b);
println "$a $b";

a = 10;
b = 100;
swap4(a, b);
println "$a $b";

