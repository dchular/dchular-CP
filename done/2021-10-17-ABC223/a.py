from sys import stdin
import math
s = input().split()
r = int(s[0])
x = int(s[1])
y = int(s[2])

d = math.sqrt(x*x + y*y)

print(-(-d/r // 1))
