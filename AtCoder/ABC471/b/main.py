N = int(input())

m = dict()

for _ in range(N):
    s = input()
    s = s.upper()
    if (s not in m.keys()):
        m[s] = 1
    else:
        m[s] += 1

print(max(m.values()))