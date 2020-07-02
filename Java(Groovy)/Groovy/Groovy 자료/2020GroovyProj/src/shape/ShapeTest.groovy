package shape

class ShapeTest {

	static main(args) {
		Point point = new Point(7,11);
		Circle circle = new Circle(22, 8, 3.5);
		Cylinder cylinder = new Cylinder(20, 30, 3.3, 10.75);
		Rectangle rect= new Rectangle(10, 10, 10.0, 5.0);
		Cuboid cub= new Cuboid(10, 10, 5.0, 3.0, 10.0);
		
		point.printValue();
		circle.printValue();
		cylinder.printValue();
		rect.printValue();
		
		def shapes = [point, circle, cylinder, rect, cub];
		
		println "for loop";
		for (IShape s : shapes) {
			s.printValue(); // Polymorphism
			println "Area=${s.getArea()}, Volume=${s.getVolume()}" // Polymorphism
		}
	}

}
