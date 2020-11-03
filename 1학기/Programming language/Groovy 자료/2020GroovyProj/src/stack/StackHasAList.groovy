package stack

class StackHasAList<T> implements IStack<T> {

	List<T> stackData;

	StackHasAList() {
		stackData = [];
	}

	static main(args) {
		IStack<String> staff = new StackHasAList<String>();

		staff.push("Cracker, Carl");
		staff.push("Hacker, Harry");
		staff.push("Lam, Larry");
		staff.push("Sandman, Susan");
		println "${staff.top()}";
		println "${staff.pop()}";
		println "${staff.top()}";

		staff.push("Reindeer, Rudolf");
		println "${staff.top()}";
		println "${staff[0]}"; //error

	}

	@Override
	public T pop() {
		assert !empty();
		T result = top();;
		stackData.remove(stackData.size()-1)
		return result;
	}

	@Override
	public void push(T data) {
		stackData.add(data);
	}

	@Override
	public boolean empty() {
		return stackData.size() == 0;
	}

	@Override
	public T top() {
		assert !empty();
		return stackData[stackData.size()-1];
	}

}
