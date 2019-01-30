#ifndef ISORT_H
#define ISORT_H

#include <iostream>

/**
 * @brief 排序抽象类
 * 
 */
class ISort
{
public:
    enum SortMode //排序模式
    {
        Asc, //升序
        Desc, //降序
    };

protected:
    SortMode mSortMode; //降序还是升序
    int * arrSortData; //排序的数据
    size_t  nSortDataSize; //排序数据的大小
    std::string strSortName; //排序的类别

protected:
    /**
     * @brief 交换两个数字
     * 
     * @param a 
     * @param b 
     */
    void Swap(int& a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    };

public:
    ISort(int * arrToSort, size_t nSize, const std::string& strSn, SortMode nMode = SortMode::Asc);
    virtual void Sort() = 0;
    virtual ~ISort() = 0;
};

/**
 * @brief 插入排序
 * 
 */
class InsertionSort : public ISort
{
public:
    InsertionSort(int * arrToSort, size_t nSize, SortMode nMode = SortMode::Asc) 
                : ISort(arrToSort, nSize, "InsertionSort", nMode) {}
    virtual void Sort() override;
};

/**
 * @brief 冒泡排序
 * 
 */
class BubbleSort : public ISort
{
public:
    BubbleSort(int * arrToSort, size_t nSize, SortMode nMode = SortMode::Asc) 
                : ISort(arrToSort, nSize, "BubbleSort", nMode) {}
    virtual void Sort() override;
};

/**
 * @brief 快速排序
 * 
 */
class QuickSort : public ISort
{
public:
    QuickSort(int * arrToSort, size_t nSize, SortMode nMode = SortMode::Asc) 
                : ISort(arrToSort, nSize, "QuickSort", nMode) {}
    virtual void Sort() override;

private:
    int QuickSortRecurse(int nBegin, int nEnd);
    int Partition(int nBegin, int nEnd);
};

/**
 * @brief 归并排序
 * 
 */
class MergeSort : public ISort
{
public:
    MergeSort(int * arrToSort, size_t nSize, SortMode nMode = SortMode::Asc) 
                : ISort(arrToSort, nSize, "MergeSort", nMode) {}
    virtual void Sort() override;

private:
    void MergePartition(int nBegin, int nEnd);
    void Merge(int nBegin, int nMid, int nEnd);
};
#endif