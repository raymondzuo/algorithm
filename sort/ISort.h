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

#endif