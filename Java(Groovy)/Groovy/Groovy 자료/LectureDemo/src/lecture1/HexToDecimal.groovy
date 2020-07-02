package lecture1;

def hexToDecimal(String hex) {
  int decimalValue = 0;
  for (int i = 0; i < hex.length(); i++) {
    char hexChar = hex.charAt(i);
    decimalValue = decimalValue * 16 + hexCharToDecimal(hexChar);
  }
  decimalValue;
}

def hexCharToDecimal(char ch) {
  if (ch >= 'A' && ch <= 'F')
     return 10 + ch - (int)'A';
   else // ch is '0', '1', ..., or '9¡¯
      return ch - (int)'0';
}

Scanner input = new Scanner(System.in);
print "Enter a hex number: "
String hex = input.nextLine();
println "The decimal value for hex number " +
    "$hex is ${hexToDecimal(hex.toUpperCase())}";
