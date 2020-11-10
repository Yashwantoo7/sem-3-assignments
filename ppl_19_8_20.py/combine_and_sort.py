#O(nlog(n))
def merge(A,B):
    C,m,n=[],len(A),len(B)
    i,j=0,0
    while i+j<m+n:
        if i==m:
            C.append(B[j])
            j+=1
        elif j==n:
            C.append(A[i])
            i+=1
        elif A[i]<=B[j]:
            C.append(A[i])
            i+=1
        elif A[i]>B[j]:
            C.append(B[j])
            j+=1
    return C

def mergeSort(arr,left,right):
    if right-left<=1:
        return arr[left:right]
    elif right-left>1:
        mid=(right+left)//2
        l=mergeSort(arr,left,mid)
        r=mergeSort(arr,mid,right)
        return merge(l,r)


arr1=[1,3,6,2,7,4,9,10]
arr2=[5,3,7,4,8,22,32,10]
arr3=arr1+arr2
print(arr3)

print(mergeSort(arr3,0,len(arr3)))