// use:
// reads in addition and subtraction opperations from input.txt then prints answer in console
// doesn't convert ints/doubles to their respectives types but keeps everything as strings

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
// #include <array>
// #include <utility>
using namespace std;

vector<string> buildInput()
{
    vector<string> allLines;
    ifstream fs("input.txt");
    if (fs.is_open())
    {
        string line;
        while (getline(fs, line)) 
        {
            allLines.push_back(line);
        }
        fs.close();
    } else {
        cout << "error reading from file" << endl;
    }
    return allLines;
}

vector<string> cleanInput(string line)
{
    vector<string> cleanedNums;
    stringstream ss(line);
    string num;
    
    while (getline(ss, num, ' '))
    {
        if (num.empty()) continue;
        
        bool isValid = true;
        bool hasDecimal = false;
        
        // Check first character can only be digit, + or -
        if (!isdigit(num[0]) && num[0] != '+' && num[0] != '-')
        {
            isValid = false;
        }
        
        // Check rest of characters must be digits or one decimal point
        for (size_t i = 1; i < num.length(); i++)
        {
            if (num[i] == '.')
            {
                if (hasDecimal) { // Second decimal point found
                    isValid = false;
                    break;
                }
                hasDecimal = true;
            }
            else if (!isdigit(num[i]))
            {
                isValid = false;
                break;
            }
        }
        
        if (!isValid)
        {
            cout << "Number pair invalid; Number pair skipped" << endl;
            cleanedNums.clear();
            return cleanedNums;
        }
        
        string clean = num;
        if (num[0] == '+')
        {
            clean = num.substr(1);
        }
        
        // Handle decimal numbers by padding them to the same decimal places
        if (hasDecimal)
        {
            size_t decimalPos = clean.find('.');
            string decimals = clean.substr(decimalPos + 1);
            clean = clean.substr(0, decimalPos); // Keep only the integer part for now
            cleanedNums.push_back(clean + "." + decimals); // Store with decimal point
        }
        else
        {
            cleanedNums.push_back(clean);
        }
    }
    
    // Must have exactly two numbers
    if (cleanedNums.size() != 2)
    {
        cout << "Number pair invalid; Number pair skipped" << endl;
        cleanedNums.clear();
        return cleanedNums;
    }
    
    // Normalize decimal places for both numbers
    size_t maxDecimals = 0;
    for (const string& num : cleanedNums)
    {
        size_t pos = num.find('.');
        if (pos != string::npos)
        {
            maxDecimals = max(maxDecimals, num.length() - pos - 1);
        }
    }
    
    // Pad numbers with zeros to match decimal places
    for (string& num : cleanedNums)
    {
        size_t pos = num.find('.');
        if (pos == string::npos)
        {
            if (maxDecimals > 0)
            {
                num += "." + string(maxDecimals, '0');
            }
        }
        else
        {
            size_t currentDecimals = num.length() - pos - 1;
            if (currentDecimals < maxDecimals)
            {
                num += string(maxDecimals - currentDecimals, '0');
            }
        }
    }
    
    return cleanedNums;
}

string add(string a, string b) {
    bool a_negative = false, b_negative = false;
    
    // Handle negative numbers
    if (a[0] == '-') {
        a_negative = true;
        a = a.substr(1);
    }
    if (b[0] == '-') {
        b_negative = true;
        b = b.substr(1);
    }

    // Both negative: add and prepend minus
    if (a_negative && b_negative) {
        string result = add(a, b);
        return "-" + result;
    }
    
    // One negative: subtract the smaller absolute value from the larger
    if (a_negative || b_negative) {
        // For this version, we'll just return 0 for negative numbers
        // TODO: Implement subtraction
        return "0";
    }

    // Find decimal points and remove them
    size_t a_decimal = a.find('.');
    size_t b_decimal = b.find('.');
    size_t decimal_places = 0;
    
    if (a_decimal != string::npos) {
        decimal_places = a.length() - a_decimal - 1;
        a.erase(a_decimal, 1);
    }
    if (b_decimal != string::npos) {
        b.erase(b_decimal, 1);
    }

    // Ensure a is the longer number
    if (b.length() > a.length()) {
        swap(a, b);
    }

    // Pad shorter number with zeros
    string zeros(a.length() - b.length(), '0');
    b = zeros + b;

    string result;
    int carry = 0;

    // Add digits from right to left
    for (int i = a.length() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;
    }

    // Add final carry if exists
    if (carry > 0) {
        result = "1" + result;
    }

    // Insert decimal point if needed
    if (decimal_places > 0) {
        if (result.length() <= decimal_places) {
            result = string(decimal_places - result.length() + 1, '0') + result;
        }
        result.insert(result.length() - decimal_places, ".");
    }

    return result;
}

int main()
{
    auto all = buildInput();
    for (size_t i = 0; i < all.size(); i++)
    {
        auto clean = cleanInput(all[i]);
        if (clean.size() == 2) {
            string result = add(clean[0], clean[1]);
            cout << clean[0] << " + " << clean[1] << " = " << result << endl;
        }
    }

    return 0;
}