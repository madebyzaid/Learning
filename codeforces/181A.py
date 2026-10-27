import numpy as np

n, m = input().split()
n, m = int(n), int(m)

grid = np.array([list(input()) for i in range(n)])

stars = np.argwhere(grid == "*")

X = [stars[i][0] for i in range(3)]
Y = [stars[i][1] for i in range(3)]

x = [k for k in X if X.count(k) == 1][0]
y = [k for k in Y if Y.count(k) == 1][0]

print(x + 1, y + 1)