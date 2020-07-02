package oddeven

def even(int n){
	assert (n>=0);
	if(n==0)
		return true;
	else if (n==1)
		return false;
	else
		return odd(n-1);
}
def odd(int n){
	assert(n>=0);
	if (n==0)
		return false;
	else if(n==1)
		return true;
	else
		return even(n-1);
}

for (int i=0; i<20; ++i){
	if (even(i))
		println "$i is even!";
	else
		println "$i is odd!";
}