//EKG sequence This is a code, written for my discrete mathematics (KAIST CS204B, FALL 2020) essay.



#include <iostream>
#include <algorithm>
using namespace std;
main(){
	int n = 30;
	int m = 70;
	cout << "enter amount of sequences, and number of members of each sequence" << endl;
	cin>> n >> m;
	n+= 2;
	m++;
	int a[m + 1][n + 2];
	int b[m + 1];
	int c[m + 1];
	int cnt = 2;
	int answer[n][n];
	bool inList = 0;
	for(int i = 2; i < n; i++){
		a[1][i] = i;
		cout << 1 << " " << i << " ";
		for(int j = 2; j < m; j++){
			while(1){
				if(__gcd(cnt, a[j-1][i]) > 1){
					for(int k = 1; k<j; k++){
						if(cnt == a[k][i]){
							inList = 1;
							break;
						}
					}
					if(!inList){
						a[j][i] = cnt;
						cout << cnt << " ";
						break;
					}
					inList = 0;
				}
				cnt++;
			}
			cnt = 2;
		}
		cout<<"\n";
	}
	bool same = 1;
	int c1, c2;
	while(1){
		cout << "input 2 numbers in descending order, 0 0 to return" << endl;
	cin >> c1 >> c2;
	if(c1 == 0) return 0;
	for(int i1 = 3; i1 < n; i1++){
		for(int i2 = 2; i2 < i1; i2++){
			for(int j = m - 1; j >= 1; j--){
				if(a[j][i1] != a[j][i2]){
					for(int k = j; k > 0; k--){
						b[k] = a[k][i1];
						c[k] = a[k][i2];
					}
					sort(b + 1, b + j + 1);
					sort(c + 1, c + j + 1);
					for(int k = j; k > 0; k--){
						if(b[k] != c[k]){
							same = 0;
							break;
						}
					}
					if(same){
						//cout << i1 << " and " << i2 << " are same from " << j + 1 << endl;
						answer[i1][i2] = j + 1;
					}
					else{
						//cout << i1 << " and " << i2 << " are not same in first " << m << " parts" << endl;
						answer[i1][i2] = 0;
					}
					same = 1;
					break;
				}
			}
		}
	}
	if(answer[c1][c2]){
		cout << c1 << " and " << c2 << " are same from " << answer[c1][c2] << endl;
	}
	else{
		cout << c1 << " and " << c2 << " are not same in first " << m << " parts" << endl;
	}
	}
	
}
