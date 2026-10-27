x, y = input().split()
x = int(x)
y = int(y)

def isPrime(a):
    if a < 2:
        return False
    for i in range(2, int(a ** 0.5) + 1):
        if a % i == 0:
            return False
    return True

for k in range(x+1,y):
    if isPrime(k):
        print("NO")
        break
else:
    print("YES")