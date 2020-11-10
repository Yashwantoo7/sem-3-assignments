arr=[1,2,2,5,7,5,7,3,3,2,2]
n=len(arr)
duplicates=[]
newArr=[]
asc=[False for  i in range(0,128)]
print(ord(str(3)))
i=0
while i<n:
    if asc[ord(str(arr[i]))]==False: #comparing ascii values
        asc[ord(str(arr[i]))]=True
        newArr.append(arr[i])
    else:
        duplicates.append(arr[i])
        
    i+=1
print(newArr)