H, W = map(int, input().split())

H = H / 100

bmi = W/H/H

if (bmi >= 25):
    print("Yes")
else:
    print("No")