package lecture1

def getGrade(double score) {
  if (score >= 90.0)
    'A';
  else if (score >= 80.0)
    'B';
  else if (score >= 70.0)
    'C';
  else if (score >= 60.0)
    'D';
  else
    'F';
}
println "The grade is ${getGrade(78.5)}"
println "The grade is ${getGrade(59.5)}"
