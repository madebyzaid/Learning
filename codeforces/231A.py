n = int(input())
count = 0
for _ in range(n):
    a, b, c = input().split()
    if int(a) + int(b) + int(c) >= 2:
        count += 1
print(count)