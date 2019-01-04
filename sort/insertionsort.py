def insertionsort(arr):
    length = len(arr)
    if length == 1:
        return arr[0]
    for i in range(1, length):
        for j in range(i,0,-1):
            if arr[j] < arr[j - 1]:#最右边跟其左边的进行比较
                arr[j],arr[j-1] = arr[j-1],arr[j]#利用python的逗号直接进行交换
    return arr

print(insertionsort([3,2,1,4,5]))

