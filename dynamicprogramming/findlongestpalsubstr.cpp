/**
 * @file findlongestpalsubstr.cpp 寻找最大回文子字符串
 * @author Raymond Zuo (raymond.zuo@live.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-22
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <string>
#include <iostream>
#include <cstring>
using std::string;
using std::cout;

bool isPalString(string s)
{
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        int j = n - i - 1;
        if(j < i)
            break;
        if(s[i] != s[j])
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Brute force
 * 
 * @param s 
 * @return string 
 */
string findlongestpalsubstr1(string s)
{
    int start = 0, end = 0;
    for(int i = 0; i < s.length(); i++)
    {
        char tempi = s[i];
        for(int j = 0; j < s.length(); j++)
        {
            char tempj = s[j];
            if(tempi == tempj)
            {
                if(!isPalString(s.substr(i, j - i + 1)))
                    continue;
                int curLen = j - i;
                int longest = end - start;
                if(curLen > longest)
                {
                    start = i;
                    end = j;
                }
            }
        }
    }

    return s.substr(start, end - start + 1);
}

/**
 * @brief Find longest palindromic substring by DP(dynamic programming)
 * 
 * @param s 
 * @return string 
 */
string findLPSS(string s)
{
    int maxlen = 1;
    int start = 0;
    int n = s.length();
    int table[n][n];
    memset(table, 0, sizeof(table));

    //every single char is palindromic
    for(int i = 0; i < n; i++)
        table[i][i] = 1;
    //two chars are palindromic if they are equal
    for(int i = 0; i < n - 1; i++)
    {
        if(s[i] == s[i+1])
        {
            table[i][i+1] = 1;
            maxlen = 2;
        }
    }

    for(int k = 3; k <= n; k++)
    {
        for(int i = 0; i < n - k + 1; i++)
        {
            int j = i + k -1;
            if(table[i + 1][j - 1] && s[i] == s[j])
            {
                table[i][j] = 1;
                if(k > maxlen)
                {
                    maxlen = k;
                    start = i;
                }
                    
            }
        }
    }
    
    return s.substr(start, maxlen);
}

int main()
{
    cout << findlongestpalsubstr1("assbsscdcceeeecc") << std::endl;
    cout << findLPSS("cbbd");
    return 0;
}