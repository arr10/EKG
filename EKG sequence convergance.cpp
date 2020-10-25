//EKG sequence This is a code, written for my discrete mathematics (KAIST CS204B, FALL 2020, 20190760) essay.



#include <iostream>
#include <algorithm>
using namespace std;
main(){
	int n = 2;
	int m = 500;
	int c1, c2;
	int a[m + 1][n + 2];
	int b[m + 1];
	int c[m + 1];
	int cnt = 2;
	int answer;
	bool inList = 0;
	bool same = 1;
	
	while(1){
		cout << "input 2 numbers i and j, 0 0 to return" << endl;
	cin >> c1 >> c2;
	int temp[2];
	temp[0] = c1;
	temp[1] = c2;
	if(c1 == 0) return 0;
	
	
	for(int i = 2; i < 4; i++){
		a[1][i] = temp[i-2];
		cout << 1 << " " << temp[i-2] << " ";
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
						if(j <= 70) cout << cnt << " ";
						
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
	
	
			for(int j = m - 1; j >= 1; j--){
				if(a[j][2] != a[j][3]){
					for(int k = j; k > 0; k--){
						b[k] = a[k][2];
						c[k] = a[k][3];
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
						answer = j + 1;
					}
					else{
						//cout << i1 << " and " << i2 << " are not same in first " << m << " parts" << endl;
						answer = 0;
					}
					same = 1;
					break;
				}
			}

	if(answer){
		cout << "a" << c1 << " and " << "a" << c2 << " converge at " << answer << "   (only first 70 terms are shown above)" <<endl;
	}
	else{
		cout << "a" << c1 << " and " << "a" << c2 << " converge at x > " << m << endl;
	}
	}
	
}
