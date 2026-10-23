s = input()

distinct = set(s)

if len(distinct) % 2 == 0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")