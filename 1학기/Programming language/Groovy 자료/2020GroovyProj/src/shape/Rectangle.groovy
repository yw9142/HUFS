package shape

class Rectangle extends Point {

	double height = 0;
	double width = 0;
	
	public Rectangle() {
		super();
		height = 5; // default value
		width = 10;
	}
	public Rectangle(int x, int y) {
		super(x, y);
		height = 5; // default value
		width = 10;
	}
	public Rectangle(int x, int y, double w, double h) {
		super(x, y);
		height = h; // default value
		width = w;
	}
	@Override
	String toString() {
		return "Center=${super.toString()}, Width=$width, Height=$height";
	}
	@Override
	public double getArea() {
		return width * height;
	}

	@Override
	public void printValue() {
		
		println "Rectangle $this";

	}

}
