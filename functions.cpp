//Function Definition
//ECE 2514 E.Chen
using namespace std;
#include <string>
#include <iostream>


//helper function to convert string inputs into integers
int char_int (string input)
{
    int value = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        int digit = input[i] - '0';                  //turn the character into an integer
            if (digit < 0 || digit > 9)
            {
                return -1;
            }
        value = value * 10 + digit;
    }
    return value;
}

//Converting decimal to binary
string dec_bin (string input)
{
    int value = char_int(input);
    string ans;

    if (value == 0)
    {
        return "0";
    }

    while (value > 0)                       //continue executing as long as there is a value
    {
        int remainder = value % 2;          //find the remainders
    
        if (remainder == 1)
        {
            ans = '1' + ans;                //builds the string from the most sig bit to least by apending the previous answer to the end
        }
        if (remainder == 0)
        {
            ans = '0' + ans;
        }
        value = value / 2;
    }
    return ans;
}

int toPower (int base, int expo)
{
    int answer = 1;
    for (int i = 0; i < expo; i++)
        {
            answer = answer * base;
        }
    return answer;
}

//Converting binary to decimal
int bin_dec (string input)
{
    if (input.empty())
    {
        return 0;
    }

    int answer = 0;
    int expo = 0;

    for (size_t i = input.size(); i-- > 0;)  //read from right to left, read from least significant to most significant
    {
        if (input[i] == '1')
        {
            int term = toPower(2, expo);
            answer = answer + term;
        }
        else if (input[i] != '0')
        {
            return -1;                      //invalid character
        }
        expo ++;                            //power needs to be outside the loop, to ensure that even if the digit is '0', it increments
    }
    return answer;
}

//Converting decimal to hexal
string dec_hex (string input)
{
    if (input.empty())
    {
        return "0";
    }

    int value = char_int(input);
    if (value == 0)
    {
        return "0";
    }

    string possibleRemainders = "0123456789ABCDEF";
    string answer;
    while (value > 0)
    {
       int remainder = value % 16;
       answer = possibleRemainders [remainder] + answer;
       value = value / 16;
    }
    return answer;
}
