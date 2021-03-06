#include "ISort.h"

ISort::ISort(int * arrToSort, size_t nSize, const std::string& strSn, SortMode nMode)
{
    arrSortData = arrToSort;
    nSortDataSize = nSize;
    strSortName = strSn;
    mSortMode = nMode;
}

ISort::~ISort()
{ }

void InsertionSort::Sort()
{
    for(int i = 1; i < nSortDataSize; i++)
    {
        int nTmp = arrSortData[i];
        for(int j = i - 1; j >= 0; j--)
        {
            if(nTmp < arrSortData[j])
            {
                arrSortData[j + 1] = arrSortData[j];//往后移动，给nTmp让路
                arrSortData[j] = nTmp; //移动以后，腾出来的位置，就让nTmp哨兵牌，依次往前插
            }
        }
    }
}

void BubbleSort::Sort()
{
    for(int i = 0; i < nSortDataSize; i++)
    {
        int nTmp = arrSortData[i];
        for(int j = i + 1; j < nSortDataSize; j++)
        {
            if(nTmp > arrSortData[j]) 
            {
                arrSortData[i] = arrSortData[j]; 
                arrSortData[j] = nTmp;
            }
        }
    }
}

/*********************
 * QUICK SORT
 * *******************/
void QuickSort::Sort()
{
    QuickSortRecurse(0, nSortDataSize - 1);
}

int QuickSort::QuickSortRecurse(int nBegin, int nEnd)
{
    if(nBegin < nEnd)
    {
        int mid = Partition(nBegin, nEnd);
        QuickSortRecurse(nBegin, mid - 1);
        QuickSortRecurse(mid + 1, nEnd);
    }
}

int QuickSort::Partition(int nBegin, int nEnd)
{
    int nPivot = arrSortData[nEnd];
    int i = nBegin; 

    for(int j = nBegin; j < nEnd; j++)
    {
        if(arrSortData[j] <= nPivot)
        {
            Swap(arrSortData[i], arrSortData[j]);
            i++;
        }
    }

    Swap(arrSortData[i], arrSortData[nEnd]);
    return i;
}
/********************/

/*********************
 * MERGE SORT
 * *******************/
void MergeSort::Sort()
{
    MergePartition(0, nSortDataSize - 1);
}

void MergeSort::MergePartition(int nBegin, int nEnd)
{
    if(nBegin < nEnd)
    {
        int nMid = (nEnd + nBegin) / 2;
        MergePartition(nBegin, nMid);//递归分割,直至最小个数1
        MergePartition(nMid + 1, nEnd);

        Merge(nBegin, nMid, nEnd);
    }
}

void MergeSort::Merge(int nBegin, int nMid, int nEnd)
{
    int i,j,k;
    int lengthLeft = nMid - nBegin + 1;
    int lengthRight = nEnd - nMid;
    int left[lengthLeft], right[lengthRight];
    for(i = 0; i < lengthLeft;i++)
    {
        left[i] = arrSortData[nBegin + i];
    }
    for(j = 0; j < lengthRight;j++)
    {
        right[j] = arrSortData[nMid + 1 + j];
    }

    i = 0, j = 0, k = nBegin; 
    while(i < lengthLeft && j < lengthRight)
    {
        if(left[i] <= right[j])
        {
            arrSortData[k] = left[i];
            i++;
        }
        else
        {
            arrSortData[k] = right[j];
            j++;
        }

        k++;
    }

    while(i < lengthLeft)
    {
        arrSortData[k] = left[i];
        i++;
        k++;
    }
    while(j < lengthRight)
    {
        arrSortData[k] = right[j];
        j++;
        k++;
    }
}
/********************/
//以最大堆为例子,从小到达排列
void HeapSort::Heapify(int start, int end)
{
    int temp = arrSortData[start];
    int j = 2 * start + 1;

    while(j < end)
    {
        if(j + 1 < end && arrSortData[j + 1] > arrSortData[j])
            j++;
        if(arrSortData[j] <= temp) //无需调整
            break;

        //交换父子节点
        arrSortData[start] = arrSortData[j];
        arrSortData[j] = temp;

        start = j;
        j = 2 * start + 1;//继续堆化
    }
}

void HeapSort::Sort()
{
    int i, temp;

    //因为从nSortDataSize / 2 开始的所有数字,已经是叶节点,叶节点无需调整
    for(i = nSortDataSize / 2 - 1; i >= 0; i--)
        Heapify(i, nSortDataSize - 1);
    
    //拿取最大堆的堆顶元素,与最后一位数字进行交换,从而实习堆排序
    for(i = nSortDataSize - 1; i > 0; i--)
    {
        Swap(arrSortData[0], arrSortData[i]);
        //交换后继续堆化
        Heapify(0, i - 1);
    }
}
/********************/