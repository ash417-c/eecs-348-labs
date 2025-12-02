#include <iostream>
#include <vector>

using namespace std;

bool failureLecture(const vector<int>& attendance_Records) {
    int absent_Count = 0;
    for (int i = 1; i < attendance_Records.size(); ++i) { //Error: loop starts at 1, should start at 0 or use a for each loop
        absent_Count += attendance_Records[i] == 0;
    }
    return absent_Count >= 3;
}

int main()
{
    vector<int> noFault{1, 1, 1, 1, 1, 1, 1, 1, 0, 0};
    vector<int> fault{1, 1, 1, 1, 1, 1, 1, 0, 0, 0};
    vector<int> error{0, 1, 1, 1, 1, 1, 1, 1, 1, 0};
    vector<int> fail{0, 1, 1, 1, 1, 1, 1, 1, 0, 0};

    cout << "1: Failed, 0: Passed" << endl;
    cout << "No Fault: " << failureLecture(noFault) << endl;
    cout << "Fault: " << failureLecture(fault) << endl;
    cout << "Error: " << failureLecture(error) << endl;
    cout << "Failure: " << failureLecture(fail) << endl;

    return 0;
}

/*
Question 1:
The Falt is on line 8 (line 3 relative). 
The Loop starts at 1, skipping index 0 when it should be going over every value/index in attendance_Records

Question 2:
vector<int> noFault{1, 1, 1, 1, 1, 1, 1, 1, 0, 0};
This vector doesn't trigger the fault. No 0 in first position and less than 3 total 0s.

Question 3:
vector<int> fault{1, 1, 1, 1, 1, 1, 1, 0, 0, 0};
This doesn't trigger the fault. No 0 in first position, true output since 3 0s in total.

Question 4:
vector<int> error{0, 1, 1, 1, 1, 1, 1, 1, 1, 0};
This triggers the fault. Only one 0 is counted so absent_Count == 1.
Since it's still less than 3 0s total, function output matches expected.

Question 5:
vector<int> fail{0, 1, 1, 1, 1, 1, 1, 1, 0, 0};
This only counts 2 0s when it should count 3, so absent_Count == 2.
Function incorrectly returns false, when it should return true. First 0 is not counted

Fixes:
    Replace 1 in loop with 0:
    for (int i = 0; i < attendance_Records.size(); ++i) { code here }

    Use for each loop:
    for (int records : attendance_Records) { code here } 
    use records instead of attendance_Records[i]
*/
