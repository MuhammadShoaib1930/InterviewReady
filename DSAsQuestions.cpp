
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> inputVector() {
    vector<int> result;
    for (int i = 0; true; i++) {
        int s;
        cin >> s;
        if (s == -1000) break;
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
int maxProduct(vector<int> arr) {
    int maxsub = INT_MIN;
    int prod = 1;
    for (int i = 0; i < arr.size(); i++) {
        prod *= arr[i];
        maxsub = max(maxsub, prod);
        if (prod == 0) {
            prod = 1;
        }
    }
    return maxsub;
}
int findMin(vector<int> arr) {
    int n = arr.size() - 1;
    if (arr[0] < arr[n - 1]) return arr[0];
    int st = 0, ed = n, mid = 0;
    while (st <= ed) {
        mid = st + (ed - st) / 2;
        if (arr[mid - 1] > arr[mid] && arr[mid] < arr[mid + 1]) {
            return mid;
        } else if (arr[st] < arr[mid]) {
            st = mid + 1;
        } else {
            ed = mid - 1;
        }
    }
    return mid;
}

bool PairSumSortedAndRotated(vector<int> arr, int target) {
    int mid = findMin(arr);
    int st = mid;
    int ed = mid - 1;
    while (st != ed) {
        int temp = arr[st] + arr[ed];

        if (temp == target) {
            return true;
        } else if (temp > target) {
            ed--;
            if (ed < 0) ed = arr.size() - 1;
        } else if (temp < target) {
            st++;
            if (st > arr.size() - 1) st = 0;
        }
    }

    return false;
}
void threeSum(vector<int> nums) {
    vector<vector<int>> res;
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    res.push_back(temp);
                }
            }
        }
    }
    for (int i = 0; i < res.size(); i++) {
        printVector(res[i]);
    }
}
void threeSum2(vector<int> nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> resl;
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                resl.push_back({nums[i], nums[j], nums[k]});
                k--;
                j++;
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    for (int i = 0; i < resl.size() - 1; i++) {
        int freq = 0;
        for (int j = 0; j < resl[i].size(); j++) {
            if (resl[i][j] == resl[i + 1][j]) {
                freq++;
            }
            if (freq == 3) {
                resl.erase(resl.begin() + i);
                i--;
            }
        }
    }

    for (int i = 0; i < resl.size(); i++) {
        printVector(resl[i]);
    }
}
int ContainerWithMostWater(vector<int> height) {
    int i = 0, j = height.size() - 1;
    int maxWater = INT_MIN;
    while (i < j) {
        int area = (j - i) * min(height[i], height[j]);
        maxWater = max(maxWater, area);
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return maxWater;
}
int kthSmallest(vector<int> arr, int k) {
    if (k > arr.size() - 1) return -1;
    if (k == arr.size() - 1) return arr[arr.size() - 1];
    sort(arr.begin(), arr.end());
    return arr[k - 1];
}
int kthSmallest2(vector<int> arr, int k) {
    if (k > arr.size() || k <= 0) return -1;
    priority_queue<int> heap;
    for (int i = 0; i < arr.size(); i++) {
        heap.push(arr[i]);
        if (heap.size() > k) {
            heap.pop();
        }
    }
    return heap.top();
}
vector<vector<int>> input2DVector() {
    int n = 0, m = 0;
    cin >> n;
    vector<vector<int>> inp;
    for (int i = 0; i < n; i++) {
        cin >> m;
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            int s = 0;
            cin >> s;
            temp.push_back(s);
        }
        inp.push_back(temp);
    }
    return inp;
}
void print2DVector(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j];
            if (j + 1 < arr[i].size()) {
                cout << " , ";
            }
        }
        cout << endl;
    }
    cout << endl << endl;
}
vector<vector<int>> mergeOverlappinIntervals(vector<vector<int>> arr) {
    if (arr.size() < 2) return arr;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int i = 1;
    vector<vector<int>> res;
    int f = arr[0][0], l = arr[0][1];
    for (int i = 1; i < n; i++) {
        if (arr[i][0] <= l) {
            l = max(l, arr[i][1]);
        } else {
            res.push_back({f, l});
            f = arr[i][0], l = arr[i][1];
        }
    }
    res.push_back({f, l});

    return res;
}
int FindMinimumNumberOfMergeOperationsToMakeAnArrayPalindrome(vector<int> arr) {
    if (arr.size() < 2) return 0;
    int i = 0, j = arr.size() - 1;
    int opration = 0;
    while (i < j) {
        if (arr[i] == arr[j]) {
            i++;
            j--;
        } else if (arr[i] < arr[i + 1]) {
            opration++;
            arr[i + 1] += arr[i];
            i++;
        } else {
            opration++;
            arr[j - 1] += arr[j];

            j--;
        }
    }
    return opration;
}
bool myCompare(const string& a, const string& b) { return (a + b) > (b + a); }
string CreateLargestConcatenatedNumber(vector<int> arr) {
    if (arr.size() < 1) return "";
    if (arr.size() < 2) return to_string(arr[0]);
    vector<string> starr;
    for (int i = 0; i < arr.size(); i++) {
        starr.push_back(to_string(arr[i]));
    }
    sort(starr.begin(), starr.end(), myCompare);
    if (starr[0] == "0") return "0";
    string res = "";
    for (string item : starr) {
        res += item;
    }
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> input = inputVector();
    cout << CreateLargestConcatenatedNumber(input);

    return 0;
}
