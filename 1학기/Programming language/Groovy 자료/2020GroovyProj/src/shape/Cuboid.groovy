package shape

class Cuboid extends Rectangle {

	double depth = 0;
	
	public Cuboid() {
		super();
		depth = 5; // default value
	}
	public Cuboid(int x, int y) {
		super(x, y);
		depth = 5; // default value
	}
	public Cuboid(int x, int y, double w, double h, double d) {
		super(x, y, w, h);
		depth = d; // default value
	}
	@Override
	String toString() {
		return "${super.toString()}, Depth=$depth";
	}
	@Override
	public double getArea() {
		return 2 * width * height +
			   2 * height * depth +
			   2 * width * depth;
	}

	@Override
	public double getVolume() {
		return super.getArea() * depth;
	}

	@Override
	public void printValue() {
		
		println "Cuboid $this";

	}

}
