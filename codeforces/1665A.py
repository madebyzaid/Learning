def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

t=int(input())

n = int(input())

combinations = []

for a in range(1, n):
    for b in range(1, n - a):
        for c in range(1, n - a - b):
            d = n - a - b - c
            combinations.append([a, b, c, d])

for combination in combinations:
    if gcd(combination[0], combination[1]) == lcm(combination[2], combination[3]):
        print(combination)
        break