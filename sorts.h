#include <vector>
#include <iostream>

using namespace std;

// Intitializes support functions
void MergeSort(vector<int>& vec, int first, int last);
void merge(vector<int>& vec, int first, int mid, int last);
void IterativeMerge(vector<int>& vec, vector<int>& tmp, int left, int mid, int right);
void QuickSort(vector<int>& vec, int first, int last);

void BubbleSort(vector<int>& vec)
{
    int size = vec.size(), tmp;
    for(int n = 1; n < size; n++)
    {
        for(int i = 0; i < size - n; i++)
        {
            if(vec[i] > vec[i + 1])
            {
                tmp = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = tmp;
            }
        }
    }
}

void InsertionSort(vector<int>& vec)
{
    int size = vec.size();
    for(int n = 1; n < size; n++)
    {
        int i = n, tmp = vec[i];
        while(i > 0 && vec[i - 1] > tmp)
        {
            vec[i] = vec[i - 1];
            i--;
        }
        vec[i] = tmp;
    }
}

void MergeSort(vector<int>& vec)
{
    int first = 0;
    int last = vec.size() - 1;
    MergeSort(vec, first, last);
}
void MergeSort(vector<int>& vec, int first, int last)
{
    if(first < last)
    {
        int mid = first + (last - first) / 2;
        // Sorts each half of vector
        MergeSort(vec, first, mid);
        MergeSort(vec, mid + 1, last);
        // Merges vecotr back together again
        merge(vec, first, mid, last);
    }
}
void merge(vector<int>& vec, int first, int mid, int last)
{
    vector<int> tmp(vec.size());
    // Initializes necessary start points
    int first1 = first;
    int first2 = mid + 1;
    int last1 = mid;
    int last2 = last;

    // Set starting index
    int index = first1;
    while(first1 <= last1 && first2 <= last2)
    {
        // Compare fronts of both lists
        if(vec[first1] <= vec[first2])
        {
            tmp[index] = vec[first1];
            first1++;
        }
        else
        {
            tmp[index] = vec[first2];
            first2++;
        }
        index++;
    }
    // Adds remaining integers from longer list
    while(first1 <= last1)
    {
        tmp[index] = vec[first1];
        first1++;
        index++;
    }
    while(first2 <= last2)
    {
        tmp[index] = vec[first2];
        first2++;
        index++;
    }
    // Set old vector to equal new vector
    for(index = first; index <= last; index++)
    {
        vec[index] = tmp[index];
    }
}

void IterativeMergeSort(vector<int>& vec) // figure out where 42 went
{
    int size = vec.size();
    vector<int> tmp(size);

    for(int current_size = 1; current_size < size; current_size *= 2)
    {
        for(int i = 0; i < size; i += 2 * current_size)
        {
            int left = i;
            int mid = min(left + current_size - 1, size - 1);
            int right = min(left + 2 * current_size - 1, size - 1);
            if(mid <= right) IterativeMerge(vec, tmp, left, mid, right);
        }
        vec = tmp;
    }
    vec = tmp;
}
void IterativeMerge(vector<int>& vec, vector<int>& tmp, int left, int mid, int right)
{
    int first1 = left;
    int first2 = mid + 1;
    int last1 = mid;
    int last2 = right;

    // Set starting index
    int index = first1;
    while(first1 <= last1 && first2 <= last2)
    {
        // Compare fronts of both lists
        if(vec[first1] <= vec[first2])
        {
            tmp[index] = vec[first1];
            first1++;
        }
        else
        {
            tmp[index] = vec[first2];
            first2++;
        }
        index++;
    }
    // Adds remaining integers from longer list
    while(first1 <= last1)
    {
        tmp[index] = vec[first1];
        first1++;
        index++;
    }
    while(first2 <= last2)
    {
        tmp[index] = vec[first2];
        first2++;
        index++;
    }
}

void QuickSort(vector<int>& vec)
{
    int first = 0;
    int last = vec.size() - 1;
    QuickSort(vec, first, last);
}
void QuickSort(vector<int>& vec, int first, int last)
{
    if(last - first < 4) InsertionSort(vec);
    else
    {
        int mid = (first + last) / 2;
        // Find ideal pivot of first, mid, and last
        if(vec[first] > vec[last]) swap(vec[first], vec[last]);
        if(vec[first] > vec[mid]) swap(vec[first], vec[mid]);
        else if(vec[mid] > vec[last]) swap(vec[mid], vec[last]);
        // Intitializes required values
        int pivot = vec[mid];
        int indexFromLeft = first + 1;
        int indexFromRight = last - 2;
        bool done = false;

        while(!done)
        {
            while(vec[indexFromLeft] < pivot) indexFromLeft++;
            while(vec[indexFromRight] > pivot) indexFromRight--;
            if(indexFromLeft < indexFromRight)
            {
                swap(vec[indexFromLeft], vec[indexFromRight]);
                indexFromLeft++;
                indexFromRight--;
            }
            else 
            {
                QuickSort(vec, first, indexFromLeft - 1);
                QuickSort(vec, indexFromLeft + 1, last);
                done = true;
            }
        }
    }
}

void ShellSort(vector<int>& vec)
{
    int size = vec.size();
    for(int gap = size / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < size; i++)
        {
            int tmp = vec[i];
            int j = i;
            for(; j >= gap && tmp < vec[j - gap]; j -= gap)
            {
                vec[j] = vec[j - gap];
            }
            vec[j] = tmp;
        }
    }
}