#include <bits/stdc++.h>
using namespace std;
/*type 1 */
void generateBinaryStringsHelper(int N, string crntStr, vector<string> &result)
{
    if (crntStr.length() == N)
    {
        result.push_back(crntStr);
        return;
    }

    if (crntStr.empty() || crntStr[crntStr.length() - 1] == '0')
    {
        generateBinaryStringsHelper(N, crntStr + '0', result);
        generateBinaryStringsHelper(N, crntStr + '1', result);
    }
    else
    {
        generateBinaryStringsHelper(N, crntStr + '0', result);
    }
}

vector<string> generateString(int N)
{
    vector<string> result;
    generateBinaryStringsHelper(N, "", result);
    return result;
}

/*Type 2
void generateStringHelper(int N, string &str, int ind, vector<string> &ans)
{

    if (ind == N)
    {
        ans.push_back(str);
        return;
    }

    // If the previous character is '1', then we put only '0' at the end of the string.
    // For example, if str = "01", then the new string would be "010".
    if (str[ind - 1] == '1')
    {
        str[ind] = '0';
        generateStringHelper(N, str, ind + 1, ans);
    }

    // If the previous character is '0', then we put both '1' and '0' at the end of the string.
    // For example, if str = "00", then the new string would be "001" and "000".
    if (str[ind - 1] == '0')
    {
        str[ind] = '0';
        generateStringHelper(N, str, ind + 1, ans);
        str[ind] = '1';
        generateStringHelper(N, str, ind + 1, ans);
    }
}

vector<string> generateString(int N)
{
    vector<string> ans;
    if (N == 0)
    {
        return ans;
    }
    // Create a string with N elements.
    string str(N, '0');

    // First character is '0'.
    str[0] = '0';

    generateStringHelper(N, str, 1, ans);

    // First character is '1'.
    str[0] = '1';

    generateStringHelper(N, str, 1, ans);
    sort(ans.begin(), ans.end());

    return ans;
}
*/