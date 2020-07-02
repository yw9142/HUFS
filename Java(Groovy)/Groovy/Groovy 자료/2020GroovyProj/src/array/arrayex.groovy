package array

int[] iarr = [1,2,3,4] // Integer Array

for (def i=0; i<iarr.length; ++i) {
	iarr[i] = iarr[i]+1
}
println "iarr=$iarr type(iarr)=${iarr.getClass()}"

def larr = [1,2,3,4] // ArrayList<Integer>
for (def i=0; i<larr.size(); ++i) {
	larr[i] = larr[i]+1
}
println "larr=$larr type(larr)=${larr.getClass()}"

