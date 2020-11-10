arr=[1,2,3,4,5,6,7,14,15,8,9,10,11,12,13]
n=len(arr)
arr.sort()
maxNum=0
for i in arr:
    if i>maxNum:
        maxNum=i
print(arr,maxNum)
#now if element*2>maxNum then do not compute the sets of remaining elements

allPossibleSets=[]
for i in range(n):
    for j in range(i+1,n):
        if arr[i]+arr[j]<maxNum:
            allPossibleSets.append((arr[i],arr[j]))
        else:
            break
print(allPossibleSets)