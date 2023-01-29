#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int partition(vector<int>& arr, int low, int high) {
    int flag = arr[low];
    while (low < high) {
      while (low < high && arr[high] >= flag) high--;
      arr[low] = arr[high];
      while (low < high && arr[low] <= flag) {
        low++;
      }
      arr[high] = arr[low];
    }
    arr[low] = flag;
    return low;
  }

 public:
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    if (low < high) {
      int pos = partition(arr, low, high);
      cout << "pos=" << pos << endl;
      for (int n : arr) {
        cout << n << "  ";
      }
      cout << endl;
      // if (pos == k) return;
      while (pos != k - 1) {
        if (pos > k - 1) {
          pos = partition(arr, low, pos - 1);
          cout << "pos=" << pos << endl;
          for (int n : arr) {
            cout << n << "  ";
          }
          cout << endl;
        } else if (pos < k - 1) {
          pos = partition(arr, pos + 1, high);
          cout << "pos=" << pos << endl;
          for (int n : arr) {
            cout << n << "  ";
          }
          cout << endl;
        }
      }
    }
    return vector<int>(arr.begin(), arr.begin() + k);
  }
};

int main() {
  vector<int> arr = {0, 0, 1, 2, 4, 2, 2, 3, 1, 4};
  Solution S;
  vector<int> temp = S.getLeastNumbers(arr, 8);
  for (int n : arr) {
    cout << n << "  ";
  }
  return 0;
}