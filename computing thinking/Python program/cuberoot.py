n = float(input('Enter a number: '))
tolerance=0.0001
stepSize=0.0001
loopCount=0
cuberoot = 0

while cuberoot**3 < abs(n) and abs(cuberoot**3-n)>=tolerance:
    cuberoot = cuberoot + stepSize # Ensure the loop ends
    loopCount +=1
    cuberoot2 = round(cuberoot, 4)
if abs(cuberoot**3-n)>=tolerance:
    print(n, 'is not a perfect cube')
    print(f"cube root of {str(n)} is {str(cuberoot2)}")
else:
    if n < 0:
        cuberoot = -cuberoot
        print(f"cube root of {str(n)} is {str(cuberoot2)}")

print('Number of iteration to get answer= ',loopCount)