#include <bits/stdc++.h>

using namespace std;

bool validate( int a, int b, int c){
	return a + b > c && a + c > b && b + c > a;
}

int main(){
	int t;
	cin >> t;
	int n;
	string result[t]; 
	int s3;
	for (int loop = 0; loop < t; loop++){
		bool flag = false;
		cin >> n;
		result[loop] = "";
		s3 = 0;
		for (s3 = 0; s3 <= n && !flag; s3 += 5){
			if ((n-s3) % 3 == 0)
				flag = true;
		}
		
		if (flag){
			s3 -= 5;
			for (int i = 0; i < n-s3; i++)
				result[loop] += '5';
			for (int i = 0; i < s3; i++)
				result[loop] += '3';
		}
		else
			result[loop] = "-1";
	
	}

	for ( int i = 0; i < t; i++ )
		cout << result[i] << endl;

	return 0;
}