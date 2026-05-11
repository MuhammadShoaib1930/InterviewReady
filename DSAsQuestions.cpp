
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> inputVector(int n) {
    vector<int> result;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        result.push_back(s);
    }
    return result;
}
void printVector(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}
vector<int> minMaxValue(vector<int> arr) {
    int minValue = INT_MAX;
    int maxValue = INT_MIN;

    int n = arr.size();
    for (int i = 0; i < n; i++) {
        minValue = min(minValue, arr[i]);
        maxValue = max(maxValue, arr[i]);
    }
    vector<int> result;
    result.push_back(minValue);
    result.push_back(maxValue);
    return result;
}
vector<int> reverseVector(vector<int> arr) {
    int i = 0;
    int j = arr.size() - 1;

    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    return arr;
}
int maxSubArray(vector<int> arr) {
    int n = arr.size();

    int maxValue = INT_MIN;
    int current = 0;
    for (int i = 0; i < n; i++) {
        current += arr[i];
        maxValue = max(maxValue, current);
        if (current < 0) {
            current = 0;
        }
    }
    return maxValue;
}
bool containsDuplicate(vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            return true;
        }
    }
    return false;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 0;
    cin >> n;
    vector<int> input = inputVector(n);
    cout << containsDuplicate(input);

    return 0;
}
