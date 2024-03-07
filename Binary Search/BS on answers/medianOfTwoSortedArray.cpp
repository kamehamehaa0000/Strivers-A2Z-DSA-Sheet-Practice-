#include <bits/stdc++.h>
using namespace std;
/*BruteForce
double median(vector<int> &a, vector<int> &b)
{
    int i = 0; //starting index of a
    int j = 0; //starting index of b
    vector<int> arr3;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            arr3.push_back(a[i++]);
        }
        else
        {
            arr3.push_back(b[j++]);
        }
    }
    while (i < a.size())
    {
        arr3.push_back(a[i++]);
    }
    while (j < b.size())
    {
        arr3.push_back(b[j++]);
    }

    // median
    int n = a.size() + b.size();
    if (n % 2 == 1)
    {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
}
*/
/*Better Solution
double median(vector<int> a, vector<int> b)
{
    int n = a.size() + b.size();

    int index2 = (n / 2);    // (n/2)
    int index1 = index2 - 1; // (n/2)-1
    int i = 0;
    int j = 0;
    int count = 0;

    int index1Element = -1;
    int index2Element = -1;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            if (count == index1)
            {
                index1Element = a[i];
            }
            if (count == index2)
            {
                index2Element = a[i];
            }
            count++;
            i++;
        }
        else
        {
            if (count == index1)
            {
                index1Element = b[j];
            }
            if (count == index2)
            {
                index2Element = b[j];
            }
            count++;
            j++;
        }
    }
    while (i < a.size())
    {
        if (count == index1)
        {
            index1Element = a[i];
        }
        if (count == index2)
        {
            index2Element = a[i];
        }
        count++;
        i++;
    }
    while (j < b.size())
    {
        if (count == index1)
        {
            index1Element = b[j];
        }
        if (count == index2)
        {
            index2Element = b[j];
        }
        count++;
        j++;
    }
    if (n % 2 == 1)
    {
        return (double)index2Element;
    }
    else
    {
        return (double)((double)(index1Element + index2Element)) / 2.0;
    }
}*/
double median(vector<int> &a, vector<int> &b)
{
    // Observations
    // equal half banenge
    // only if certain amount of elements are taken from array 1 and certain from arr2 and those element's sum = n/2
    // we check if a symmetry is sorted and valid if left side elements are smaller than right
    // mean will be (max(l1,l2) + min(r1,r2) )/ 2  for even and max(l1,l2) for odd where l1 is arr1 biggest and l2 is arr2 biggest and r1 arr1's smallest on right and r2 arr2's smallest on right
    int n1 = a.size(), n2 = b.size();
    // if n1 is bigger swap the arrays:
    if (n1 > n2)
    {
        return median(b, a);
    }
    int n = n1 + n2;                    // total length
    int leftLength = (n1 + n2 + 1) / 2; // length of left half
    int low = 0, high = n1;

    while (low <= high)
    {
        int mid1 = (low + high) / 2;  // mid1 = elements from arr1
        int mid2 = leftLength - mid1; // mid2 = elements from arr2
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        // assigning l1 l2 r1 r2
        if (mid1 < n1)
        {
            r1 = a[mid1];
        }
        if (mid2 < n2)
        {
            r2 = b[mid2];
        }
        if (mid1 - 1 >= 0)
        {
            l1 = a[mid1 - 1];
        }
        if (mid2 - 1 >= 0)
        {
            l2 = b[mid2 - 1];
        }

        // verifying for the valid symmetery

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
            {
                return max(l1, l2);
            }
            else
            {
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
        }

        // elimination of halves
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}
int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1) << median(a, b) << '\n';
}