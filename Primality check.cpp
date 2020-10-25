#include <iostream>
#include <algorithm>
using namespace std;
bool isPrime(int n){
   if (n <= 1)
      return false;
   if (n <= 3)
   return true;
   if (n % 2 == 0 || n % 3 == 0)
      return false;
   for (int i = 5; i * i <= n; i = i + 6)
   if (n % i == 0 || n % (i + 2) == 0)
   return false;
   return true;
}
main(){
	int n = 2;
	int m = 10000;
	int c1, c2;
	int a[m + 1];
	int cnt = 2;
	int answer;
	bool inList = 0;
	bool nonPrimeExists = 0;
	int i = 2;
		a[1] = 2;
		cout << 1 << " " << 2 << " ";
		for(int j = 2; j < m; j++){
			while(1){
				if(__gcd(cnt, a[j-1]) > 1){
					for(int k = 1; k<j; k++){
						if(cnt == a[k]){
							inList = 1;
							break;
						}
					}
					if(!inList){
						a[j] = cnt;
						if(j <= 70) cout << cnt << " ";
						else{
							if(cnt % a[j] == 0 && cnt / a[j-1] == 2 && !isPrime(a[j-1])){
								cout <<"NONPRIME";
								nonPrimeExists = 1;
							} 
							if(a[j-1] % cnt == 0 && a[j-1] / cnt == 2 && !isPrime(cnt)){
								cout <<"NONPRIME";
								nonPrimeExists = 1;
							}
						}
						
						break;
					}
					inList = 0;
				}
				cnt++;
			}
			cnt = 2;
		}
		cout<<"\n";
		if(!nonPrimeExists){
			cout << "No Non-Prime terms found (amongst a(n)=2 * a(n-1); a(n) = a(n-1)/2 types)," << " first " << m << " terms were checked.";
		}
	
	}
