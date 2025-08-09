#include<bits/stdc++.h>
using namespace std;

long double factorial (int a) {
if (a==0) return 1.0L;
long double  ans =1.0L;
for (long i = 1; i <= a; i++){
ans *= i;
}
return ans;
}
int main() {
printf("n= ");
int n; cin >> n; 
long double e = 0.0L;
for (int i = 0; i <= n; i++) {
e+=(1.0L/factorial(i));
}
cout << e << '\n';
return 0;
}