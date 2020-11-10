#O(n^2)

matrix=[[4,15,14,1],
        [9,6,7,12],
        [5,10,11,8],
        [16,3,2,13]]

n=len(matrix)
lower_right_dia=0
lower_left_dia=0
first_time=True
prev_row=0
prev_col=0
row=0
col=0
magic_square=True
for i in range(n):
    if not magic_square:
        break
    for j in range(n):
        if i-j==0: # if lowe right dia. then diff will be constant
            lower_right_dia+=matrix[i][j]
        if i+j==n-1: # if lowe left dia. then sum will be constant
            lower_left_dia+=matrix[i][j]
        row+=matrix[i][j]
        col+=matrix[i][j]
    if first_time:
        prev_col=col
        prev_row=row
        first_time=False
        row=0
        col=0
    else:
        # print(row,col)
        if prev_row!=row or prev_col!=col:
            magic_square=False
            break
        row=0
        col=0

if lower_left_dia==lower_right_dia and magic_square:
    print(True)
else:
    print(False)