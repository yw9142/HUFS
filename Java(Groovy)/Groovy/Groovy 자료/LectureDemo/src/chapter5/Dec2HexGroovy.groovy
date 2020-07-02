package chapter5;

Scanner input = new Scanner(System.in);
print "Enter a decimal number: "
int decimal = input.nextInt();
def hex = "";
while (decimal != 0) {
	int hexValue = decimal % 16;
	String hexDigit = (hexValue <= 9 && hexValue >= 0) ?
			(char)(hexValue + (int)'0') :
			(char)(hexValue - 10 + (int)'A');
	hex = hexDigit + hex;
	decimal = decimal / 16;
}
println "The hex number is $hex"
