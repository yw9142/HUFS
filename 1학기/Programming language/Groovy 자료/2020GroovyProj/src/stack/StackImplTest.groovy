package stack

class StackImplTest {

	static testStackImpl(IStack stack) {
		try {
			println "Test Stack Implementation of ${stack.class}"
			stack.push("Cracker, Carl");
			stack.push("Hacker, Harry");
			stack.push("Lam, Larry");
			stack.push("Sandman, Susan");
			println "${stack.top()}";
			println "${stack.pop()}";
			println "${stack.top()}";

			stack.push("Reindeer, Rudolf");
			println "${stack.top()}";
			println "${stack[0]}"; //error in StackHasAList
		} catch (e) {
			println e;
		}


	}
	static main(args) {

		testStackImpl(new StackHasAList<String>());
		testStackImpl(new StackIsAList<String>());

	}

}
