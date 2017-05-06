n,l,r = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

d = [0 for _ in range(100005)]
for i in range(l-1, r):
    d[A[i]] += 1
    d[B[i]] -= 1

truth = True
for i in d:
    if i != 0:
        truth = False
        break

for i in range(l-1):
    if A[i] != B[i]:
        truth = False
        break

for i in range(r, n):
    if A[i] != B[i]:
        truth = False
        break

if truth: print('TRUTH')
else: print('LIE')
