import matplotlib

print("COLLATZ CONJECTURE")
n=int(input("Enter number of times you want to repeat:"))
for i in range(n):
    count=0
    x=int(input("\n\nEnter a sample number: "))
    print("Steps:", end = "  ")
    while x!=1:
        if x%2==0:
            x=x/2
        else:
            x=3*x+1
        count+=1
        print(int(x), end="  ")

