N=int(input("Enter N: "))
L=[]
for k in range(2,N+1):
    s=0
    for i in range(2,int(k**0.5)+1):
        if k%i==0:
            s+=i
            s+=k/i
    s+=1
    if s==k:
        L.append(k)
print(L)