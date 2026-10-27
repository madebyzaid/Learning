y=input("Enter Function:")
def f(x):
    return y
def I(a,b,dx=0.0001):
    sum=0
    for i in range(int((b-a)/dx)):
        x=a+i*dx
        sum+=f(x)*dx
    return(sum)
print(I(0,10))

