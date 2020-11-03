package chapter4;

printf("%-10s%-10s%-10s%-10s%-10s\n", "Degrees", "Radians", "Sine", "Cosine", "Tangent");

int degrees = 30;
double radians = Math.toRadians(degrees);

printf("%-10d%-10.4f%-10.4f%-10.4f%-10.4f\n", 
	degrees, radians, Math.sin(radians), Math.cos(radians), Math.tan(radians));
