//Function Definition
//ECE2514 E.Chen
#include <string>
#include <vector>
using namespace std;

//count unique integers
int count_unique(const vector<int>& nums)
{
    bool isUnique = false;
    vector<int> uniqueNums;//do not use a string to store integers, use a vector! strings store characters
    
    if (nums.empty())
    {
        return 0; //return 0, for no unique inputs
    }

    for (int i = 0; i < nums.size(); i++)
    {
        bool isUnique = true;

        for (int j = 0; j < uniqueNums.size(); j++)
        {
            if (nums[i] == uniqueNums[j])
            {
                isUnique = false;
                break; //break exits the inner loop ONLY, not outer or function
            }
            // if (nums[i] != uniqueNums[j])                       //this is logically incorrect and redundant, if the last int nums[i]  = 7 and uniqueNums = 9, but there was 7 earlier, it overwrites the correct result
            // {
            //     isUnique = true;
            // }
        }
        if (isUnique)
        {
            uniqueNums.push_back(nums[i]);
        }
    }
    return static_cast<int>(uniqueNums.size());
}


//remove occurences
//vector.erase(iterator start, iterator end)
void remove_value(vector<int>& nums, int target)
{
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i ++)
    {
        if (nums[i] != target)
        {
            result.push_back(nums[i]);
        }
    }
    nums = result;
}

//odd occurence finder
int odd_occurence(const vector<int>& nums)
{
    for (size_t i = 1; i < nums.size(); i++)
    {
        int count = 0;
        for (size_t j = 1; j < nums.size(); j++)
        {
            if (nums[i] == nums[j])
            {
                count ++;
            }
        }
        if (count % 2 != 0)
       { 
            return nums[i];
       }
    }
    return -1;
}


//remove all vowels
string remove_vowels(const string& s)
{
    string copy = s;
    string vowels = "aeiouAEIOU";
    
    for (int i = 0; i < copy.size(); )
    {
        if (vowels.find(copy[i]) != string::npos)
        {
            copy.erase(i ,1);
        }
        else
        {
            i++; //only advace when keeping the characters
        }
    }
    return copy;
}

//compress repeated characters
//start at index 0
//count how many times s[i] appears consecutively
//append s[i] and the number
//jump forward by that count
//continue until the end
string compress (const string& s)
{
    if (s.empty())
    {
        return 0;
    }

    int count = 1;
    string answer;
    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 <s.size() && s[i] == s[i + 1])          //if the next character is the same, increase the count
        {
            count ++;
        }
        else
        {
            answer += s[i];                                 //end of a run --> apend character + count
            answer += to_string(count);                     //converts the integer to a characer, appends to the answer string
            count = 1;                                      //must reset for the next run
        }
    }
    return answer;
}

//convert string to 2D vector
// vector<vector<char>> to_grid(const string& s, int cols)
// {
//     string copy = s;
//     vector<char> row;
//     vector<vector<char>> answer;
//     for (int i = 0; i < copy.size(); i++)
//     {
//         for (int j = 1; j <= cols; j++)
//         {
//             row.push_back(copy[i]);
//         }
        
//     }
// }

//sum each row
vector<int> row_sums(const vector<vector<int>>& grid)
{
    int sum = 0; //need to INITALIZE the sum!
    vector<int> answer;
    for (int r = 0; r < grid.size(); r++) //iterate through rows
    {
        sum = 0; //need to RESET the sum!
        for (int c = 0; c < grid[r].size(); c++) //iterate through columns
        {
            sum = sum + grid[r][c];
        }
        answer.push_back(sum);
    }
    return answer;
}


//number system conversions
