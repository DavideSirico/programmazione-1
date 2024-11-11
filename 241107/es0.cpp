#include <iostream>
using namespace std;
void test(char s[], int &t)
{
    int j = 0;
    t = 0;
    char c;
    for (int i = 1; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            c = s[i];
            s[i] = s[j];
            s[j] = c;
            j++;
            t++;
        }
        else
        {
            c = s[i - 1];
            s[i - 1] = s[i];
            s[i] = c;
        }
    }
}
int main()
{
    char str[] = "beicemr";
    int n = 0;
    test(str, n);
    cout << str << n << endl;
    str[0] = str[0] - 'A' + 'a';
    test(str, n);
    cout << str << n << endl;
    return 0;
}