#O((y-x)*(y-x))
x,y=map(int,input().split())
table=[[0 for i in range(y-x+1)] for j in range(y-x+1)]
print(table)
n=len(table)

for i in range(n):
    for j in range(n):
        table[i][j]=(x+i)*(x+j)
print(table)