#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int translateNum(int num) {
    if (num < 10 || (num < 100 && num > 25)) {
      return 1;
    }
    if (num >= 10 && num <= 25) return 2;
    int n = int(log10(num));
    cout << "n=" << n << endl;
    int pre_two = num / (int(pow(10, n - 1)));
    cout << "pre_two=" << pre_two << endl;
    int res1 = translateNum(num % (int(pow(10, n))));
    cout << "res1=" << res1 << endl;
    int res2 = pre_two > 25 ? 0 : translateNum(num % (int(pow(10, n - 1))));
    cout << "res2=" << res2 << endl;
    return res1 + res2;
  }

  // 动态规划方法：（与题解上的 方法一：字符串遍历 中的从左到右遍历思想一致）
  int translateNum2(int num) {
    if (num < 10 || (num < 100 && num > 25)) {
      return 1;
    }
    if (num >= 10 && num <= 25) return 2;
    string nums = to_string(num);
    int value1 = 1, value2, value3;
    if (nums[0] == '1' || (nums[0] == '2' && nums[1] <= '5'))
      value2 = 2;
    else
      value2 = 1;

    for (int i = 2; i < nums.length(); i++) {
      value3 = value2 +
               ((nums[i - 1] == '1' || (nums[i - 1] == '2' && nums[i] <= '5'))
                    ? value1
                    : 0);
      value1 = value2;
      value2 = value3;
    }
    return value3;
  }

  // 题解上的 方法二：数字求余 从右到左遍历
  int translateNum3(int num) {
    int value1 = 1, value2 = 1, value3=1;
    int a = num % 10, b, c;
    num /= 10;
    while (num != 0) {
      b = num % 10;
      c = b * 10 + a;
      value3 = value2 + (c <= 25 && c >= 10 ? value1 : 0);
      value1=value2;
      value2=value3;
      num/=10;
      a=b;
    }
    return value3;
  }
};
int main() {
  Solution S;
  cout << S.translateNum3(12258);
  return 0;
}