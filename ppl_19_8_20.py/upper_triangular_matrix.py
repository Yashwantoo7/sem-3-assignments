matrix=[[3,2,1],
        [1,1,1],
        [2,2,1]]

rows=len(matrix)
cols=len(matrix[0])
for i in range(rows):
    r=i+1
    while r<rows:
        element=matrix[r][i]
        for j in range(i,cols):
            if matrix[i][i]==0:
                temp=matrix[i][j]+matrix[i][i]
                temp=temp*element
                matrix[r][j]=matrix[r][j]-temp
            else:
                temp=matrix[i][j]/matrix[i][i]
                temp=temp*element
                matrix[r][j]=matrix[r][j]-temp
        r+=1
print(matrix)
        