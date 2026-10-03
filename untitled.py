L=[]
s=0
for i in range(1,int(6**0.5)+1):
    if 6%i==0:
        s+=i
        print(i)
if s==6:
    print("yes")


