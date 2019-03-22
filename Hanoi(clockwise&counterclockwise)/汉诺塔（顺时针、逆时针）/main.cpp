#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	char order[2][68];
	char pos[64]; 
	order[0]['A'] = 'B';
	order[0]['B'] = 'C';
	order[0]['C'] = 'A';
	order[1]['A'] = 'C';
	order[1]['B'] = 'A';
	order[1]['C'] = 'B';
	//确定轨迹的顺序还是逆序
	int i, j, m;
	//0是顺序 1是逆序
	int index[2];
	if (n % 2 == 0) {
		index[1] = 0;
		index[0] = 1;
	}
	else {
		index[1] = 1;
		index[0] = 0;
	}
	memset(pos, 'A', sizeof(pos));
	// 总共运行了2^n-1次
	for (i = 1; i < pow(2,n); i++) {
		//当i为奇数的时候，m的值为1,direction为1。
		for (m = 0, j = i; j % 2 == 0; j /= 2, m++) 
		{
			;
		}
		cout << "times = " << i << ",direction = " << (m+1) % 2 << " : " << pos[m] << " --> " << order[index[(m+1) % 2]][pos[m]] << endl;
		pos[m] = order[index[(m+1) % 2]][pos[m]];
	}
	return 0;
}
