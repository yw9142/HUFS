package shape

class Circle extends Point {

	double radius = 0;
	
	public Circle() {
		super();
		radius = 5; // default value
	}
	public Circle(int x, int y) {
		super(x, y);
		radius = 5;
	}
	public Circle(int x, int y, double r) {
		super(x, y);
		radius = r;
	}
	@Override
	String toString() {
		return "Center=${super.toString()}, Radius=${radius}";
	}
	@Override
	public double getArea() {
		return Math.PI * radius * radius;
	}

	@Override
	public void printValue() {
		
		println "Circle $this";

	}

}
