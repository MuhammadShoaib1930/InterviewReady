
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
int chocolateDistributionProblem(vector<int> arr, int m) {
    sort(arr.begin(), arr.end());
    int result = INT_MAX;
    for (int i = 0; i <= arr.size() - m; i++) {
        result = min(result, arr[m + i - 1] - arr[i]);
    }
    return result;
}
int searchRotatedSortedArray(vector<int> arr, int target) {
    int st = 0;
    int ed = arr.size();
    while (st <= ed) {
        int mid = st + (ed - st) / 2;

        if (target == arr[mid]) {
            return mid;
        }
        if (arr[st] <= arr[mid]) {
            if (arr[st] <= target && target <= arr[mid]) {
                ed = mid - 1;
            } else {
                st = mid + 1;
            }
        } else {
            if (arr[mid] <= target && target <= arr[ed]) {
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
    }
    return -1;
}
void revers(vector<int>& arr, int st) {
    int ed = arr.size() - 1;
    while (st < ed) {
        int temp = arr[st];
        arr[st] = arr[ed];
        arr[ed] = temp;
        st++;
        ed--;
    }
}
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void nextPermutation(vector<int> arr) {
    int bp1 = -1;
    int bp2 = -1;
    for (int i = arr.size() - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            bp1 = i;
            break;
        }
    }
    if (bp1 == -1) {
        revers(arr, 0);
    } else {
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] > arr[bp1]) {
                bp2 = i;
                break;
            }
        }

        swap(arr, bp1, bp2);
        revers(arr, bp1 + 1);
    }
    printVector(arr);
}
int bestTimeToBuyAndSellStock(vector<int> arr) {
    int bestBuy = arr[0];
    int maxProfit = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        if (bestBuy > arr[i]) {
            bestBuy = arr[i];
        }
        maxProfit = max(maxProfit, arr[i] - bestBuy);
    }
    return maxProfit;
}
void repeatAndMissingValue(vector<int> arr) {
    int n = arr.size();
    int reped, missing = 1;
    sort(arr.begin(), arr.end());
    if (missing == arr[0]) missing++;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] == arr[i]) {
            reped = arr[i];
        }
        if (missing == arr[i]) {
            missing++;
        }
    }

    cout << reped << " " << missing;
}
void findKthLargest(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    cout << arr[arr.size() - k];
}
#include <queue>
void findKthLarget2(vector<int> arr, int k) {
    vector<int> re;
    re.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        if (re[re.size() - 1] < arr[i]) {
            re.push_back(arr[i]);
        }
    }
    cout << re[re.size() - k];
}
int findwatter(int st, int ed, vector<int> hight) {
    int minVInd = (hight[st] < hight[ed]) ? st : ed;
    int res = 0;
    for (int i = st; i <= ed; i++) {
        int s = hight[minVInd] - hight[i];

        if (s >= 0) {
            res += s;
        }
    }
    return res;
}
int trap(vector<int> hight) {
    int maxL = 0, maxR = 0, i = 0, j = hight.size() - 1, result = 0;
    while (i < j) {
        maxL = max(maxL, hight[i]);
        maxR = max(maxR, hight[j]);
        if (maxL < maxR) {
            result += min(maxL, maxR) - hight[i];
            i++;
        } else {
            result += min(maxL, maxR) - hight[j];
            j--;
        }
    }

    return result;
}
vector<int> productExceptSelf1(vector<int> arr) {
    int n = arr.size();
    vector<int> sufix = vector<int>(n, 1);
    vector<int> prefix = vector<int>(n, 1);
    for (int i = 1; i < n; i++) {
        sufix[i] = sufix[i - 1] * arr[i - 1];
    }
    for (int i = n - 1; i > 0; i--) {
        prefix[i - 1] = prefix[i] * arr[i];
    }
    printVector(prefix);
    printVector(sufix);
    vector<int> result;
    for (int i = 0; i < n; i++) {
        result.push_back(prefix[i] * sufix[i]);
    }
    return result;
}
vector<int> productExceptSelf2(vector<int> arr) {
    int n = arr.size();
    vector<int> sufix = vector<int>(n, 1);
    for (int i = 1; i < n; i++) {
        sufix[i] = sufix[i - 1] * arr[i - 1];
    }
    int prefix = 1;
    for (int i = n - 1; i >= 0; i--) {
        sufix[i] *= prefix;
        prefix *= arr[i];
    }
    return sufix;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 0;
    cin >> n;
    vector<int> input = inputVector(n);
    vector<int> outpu = productExceptSelf2(input);
    printVector(outpu);

    return 0;
}
