package shape

class Point implements IShape {

	int x;
	int y;
	Point() {
		x = 0;
		y = 0;
	}
	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	@Override
	String toString() {
		return "($x, $y)"
	}
	@Override
	public double getArea() {
		return 0
	}

	@Override
	public double getVolume() {
		return 0
	}

	@Override
	public void printValue() {
		
		println "Point $this";

	}

}
