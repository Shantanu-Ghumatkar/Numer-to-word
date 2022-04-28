// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

/* A function that prints given number in words */
void convert_to_words(char *num)
{
    int len = strlen(num); // Get number of digits in given number

    /* Base cases */
    if (len == 0)
    {
        cout << "empty string" << endl;
        return;
    }
    if (len > 18)
    {
        cout << "length of number is large" << endl;
        return;
    }

    /* to skip starting zeros*/
    while (*num != '\0')
    {
        if (*num == '0')
        {
            len--;
            ++num;
        }
        else
        {
            break;
        }
    }
 /*for value zero with more than one zero*/
    len = strlen(num);
    if (len ==0)
    {
        cout << "zero";
    }
    /* The first string is not used, it is to make
            array indexing simple */
    char *single_digits[] = {"zero", "one", "two ", "three ", "four",
                             "five ", "six", "seven", "eight ", "nine "};

    /* The first string is not used, it is to make
            array indexing simple */
    char *two_digits[] = {"", "ten", "eleven", "twelve",
                          "thirteen", "fourteen", "fifteen", "sixteen",
                          "seventeen", "eighteen", "nineteen"};

    /* The first two string are not used, they are to make
            array indexing simple*/
    char *tens_multiple[] = {"", "", "twenty ",
                             "thirty", "forty", "fifty",
                             "sixty", "seventy", "eighty ",
                             "ninety "};

    char *tens_power[] = {" hundred ", " thousand ", " million ", " billion ", " trillion ", "quadrillion"};

    /* Used for debugging purpose only */
    cout << endl;
    cout << num << ": ";

    /* For single digit number */
    if (len == 1)
    {
        cout << single_digits[*num - '0'] << endl;
        return;
    }
    int k;
    int j = 0; // for count of zero

    /*deviding in to group of 4
     Iterate while num is not '\0' */
    while (*num != '\0')
    {
        /* handeling in between zeros*/
        if (*num == '0')
        {
            k = len / 3;
            if (len % 3 == 0)
            {
                j++;
            }
            else if (len % 3 == 1 && j < 1)
            {
                cout << tens_power[k];
            }
            num++;
            len--;
            continue;
        }
        /* Code path for fisrt 2 digits */
        else if (len % 3 == 1)
        {
            k = (len - 1) / 3;
            if (*num - '0' != 0)
            {
                cout << single_digits[*num - '0'];
                cout << tens_power[k];
            }
            --len;
        }
        else if (len % 3 == 0)
        {
            if (*num - '0' != 0)
            {
                cout << single_digits[*num - '0'];
                cout << tens_power[0];
            }
            --len;
        }
        /* Code path for next 2 digits */
        else
        {
            /* Need to explicitly handle 10-19. Sum of the
                    two digits is used as index of "two_digits"
                    array of strings */
            if (*num == '1')
            {
                int sum = *num - '0' + *(num + 1) - '0';
                cout << two_digits[sum] << endl;
                ++num;
            }

            /* Need to explicitly handle 20 */
            else if (*num == '2' && *(num + 1) == '0')
            {
                cout << "twenty" << endl;
            }

            /* Rest of the two digit numbers i.e., 21 to 99*/
            else
            {
                int i = *num - '0';
                if (i > 0)
                    cout << tens_multiple[i] << " ";
                else
                    cout << "";
                ++num;
                if (*num != '0')
                    cout << single_digits[*num - '0'];
            }
            len = len - 2;
            k = len / 3;
            if (k != 0)
            {
                cout << tens_power[k];
                k--;
            }
        }
        ++num;
    }
   
}

// Driver Code
int main()
{
    string s;
    int i;
    cout << "Enter No:\n";
    cin >> s;
    int n = s.length();
    char ch[n + 1];
    /*converting string to charecter array since
     function take input as a charecter array*/
    strcpy(ch, s.c_str());
    while (i < n)
    {
        if ((ch[i] >= '0') && (ch[i] <= '9'))
        {
            i++;
        }
        else
        {
            cout << "Enter Valid Number";
            break;
        }
    }
	if(i==n)
    convert_to_words(ch);
}
