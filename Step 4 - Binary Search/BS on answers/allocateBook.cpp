#include <bits/stdc++.h>
using namespace std;
/*Brute force
int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size(); // size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            // add pages to current student
            pagesStudent += arr[i];
        }
        else
        {
            // add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    // book allocation impossible:
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int pages = low; pages <= high; pages++)
    {
        if (countStudents(arr, pages) == m)
        {
            return pages;
        }
    }
    return low;
}
*/
/*OPTIMAL BINARY SEARCH*/
int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size();
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            pagesStudent += arr[i];
        }
        else
        {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}
int findPages(vector<int> &arr, int n, int students)
{
    if (students > n)
    {
        return -1;
    }
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (countStudents(arr, mid) > students)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int students = 4;
    int ans = findPages(arr, n, students);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
