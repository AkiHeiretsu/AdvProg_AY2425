#include <iostream>

using namespace std;

int strlen(char *a)
{
    int n = 0;
    while (a[n] != '\0')
    {
        ++n;
    }
    return n;
}
char *strcpy(char *cpy, char *src)
{
    for (int i = 0; i < strlen(src); i++)
    {
        cpy[i] = src[i];
    }
    cpy[strlen(src)] = '\0';
    return cpy;
}
// ham dao xau
void reverse(char a[])
{
    int n = strlen(a);
    char *left = a;
    char *right = a + n - 1;
    while (left < right)
    {
        swap(*left, *right);
        left++;
        right--;
    }
}

// ham xoa ki tu
void delete_char(char a[], char c)
{
    char *read = a;
    char *write = a;
    while (*read != '\0')
    {
        if (*read != c)
        {
            *write = *read;
            write++;
        }
        read++;
    }
    *write = '\0';
}

// ham don phai
void pad_right(char a[], int n)
{
    int len = strlen(a);
    if (len >= n)
        return;
    for (int i = len; i < n; i++)
    {
        a[i] = ' ';
    }
    a[n] = '\0';
}

// ham don trai
void pad_left(char a[], int n)
{
    int len = strlen(a);
    if (len >= n)
        return;
    int shift = n - len;
    for (int i = len; i >= 0; i--)
    {
        a[i + shift] = a[i];
    }
    for (int i = 0; i < shift; i++)
    {
        a[i] = ' ';
    }
}

// ham cat xau
void truncate(char a[], int n)
{
    int len = strlen(a);
    if (len > n)
    {
        a[n] = '\0';
    }
}

// ham doi guong
bool is_palindrome(char a[])
{
    int len = strlen(a);
    char *left = a;
    char *right = a + len - 1;
    while (left < right)
    {
        if (*left != *right)
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// ham loc trai
void trim_left(char a[])
{
    char *start = a;
    while (*start == ' ')
    {
        start++;
    }
    int len = strlen(start);
    for (int i = 0; i <= len; i++)
    {
        a[i] = start[i];
    }
}

// ham loc phai
void trim_right(char a[])
{
    int len = strlen(a);
    while (len > 0 && a[len - 1] == ' ')
    {
        len--;
    }
    a[len] = '\0';
}

int main()
{
    char str[100];
    char test[100] = "hello";
    strcpy(str, test);
    reverse(str);
    cout << "Reverse: " << str << endl;

    strcpy(str, test);
    delete_char(str, 'l');
    cout << "Delete 'l': " << str << endl;

    strcpy(str, test);
    pad_right(str, 10);
    cout << "Pad right to 10: " << str << endl;

    strcpy(str, test);
    pad_left(str, 10);
    cout << "Pad left to 10: " < < str << endl;

    strcpy(str, test);
    truncate(str, 3);
    cout << "Truncate to 3: " << str << endl;

    strcpy(str, test);
    cout << "Is palindrome: " << (is_palindrome(str) ? "True" : "False") << endl;

    strcpy(str, test);
    trim_left(str);
    cout << "Trim left: " << str << endl;

    strcpy(str, test);
    trim_right(str);
    cout << "Trim right: " << str << endl;

    return 0;
}
