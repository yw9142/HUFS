package lecture2

class ScopeTest {
	public static void main(String[] args) {
		System.out.println("i + j is " + i + j);
		int i = 2;
		int k = 3;
		int j = 3;
		System.out.println("i + j is " + i + j);
		k = i + j;
		System.out.println("k is " + k);
		System.out.println("j is " + j);
	}
	private static int i = 0;
	private static int j = 0;
}
public class OuterClass {
	private int data;
	/** A method in the outer class */
	public void m() {
		// Do something
	}
	// An inner class
	class InnerClass {
		/** A method in the inner class */
		public void mi() {
			// Directly reference data and method
			// defined in its outer class
			data++;
			m();
		}
	}
}
