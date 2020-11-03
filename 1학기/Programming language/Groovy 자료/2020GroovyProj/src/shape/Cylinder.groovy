package shape

class Cylinder extends Circle {

	double height;
	
	public Cylinder() {
		super();
		height = 10; // default value
	}
	public Cylinder(int x, int y) {
		super(x, y);
		height = 10;
	}
	public Cylinder(int x, int y, double r) {
		super(x, y, r);
		height = 10;
	}
	public Cylinder(int x, int y, double r, double h) {
		super(x, y, r);
		height = h;
	}
	@Override
	String toString() {
		return "${super.toString()}, Height=$height";
	}
	@Override
	public double getArea() {
		return 2 * super.getArea() + 2 * Math.PI * radius * height;
	}

	@Override
	public double getVolume() {
		return super.getArea() * height;
	}

	@Override
	public void printValue() {
		
		println "Cylinder $this";

	}
}
