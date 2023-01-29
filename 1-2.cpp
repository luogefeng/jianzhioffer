#include <iostream>
#include<cstring>
using namespace std;

int get_sum(int order, int len)
{
	int sum = 0;
	if (len == 1) {
		return 1;
	}
	else {
		for (int i = order+1; i < 26; i++) {
			sum += get_sum(i, len - 1);
		}
	}

	return sum;
}




int range(char* str)
{
	int len = strlen(str);
	int i,j;
	int sum=0;
	for (i = 1; i < len; i++) {
		for (j = 0; j < 26; j++) {
			sum += get_sum(j, i);
			//cout << "*1*" << sum << endl;
		}
	}

	for (i = 0; i < str[0] - 'a'; i++) {
		sum += get_sum(i, len);
		//cout << "*2*" << sum << endl;
	}

	for (i = len-1; i >= 1; i--) {
		j = len - i;
		for (int m = str[j - 1] - 'a' + 1; m < str[j]-'a'; m++) {
			sum += get_sum(m, i);
			//cout << "*3*" << sum << endl;
		}
	}
	sum += 1;
	return sum;
}


int main()
{
	int n,sum;
	char str[10];
	cout << "请输入一个正整数n，代表一共有n个字符串：";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "请输入第" << i + 1 << "个字符串，要求长度不小于6且为升序字符串：";
		cin >> str;
		sum = range(str);
		cout << "第" << i + 1 << "个升序字符串的编码为：";
		cout << sum << endl;
		
	}

	return 0;
}