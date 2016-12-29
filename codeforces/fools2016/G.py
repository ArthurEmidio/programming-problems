F,I,T = map(int,input().split())
y=[0]*15
for i in range(0,F):
    v=input()
    for j in range(0,I):
        y[j]+=v[j]=='Y'
a=0
for x in y:
    a+=(x >= T)
print(a)
#kitten