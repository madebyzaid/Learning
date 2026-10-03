import math

def f(x):
    return math.log
 

def derivativeat(a,h=0.00000001):
    return(((f((a+h))-f(a))/h))

print(derivativeat(5))