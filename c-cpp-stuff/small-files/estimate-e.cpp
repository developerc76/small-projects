#include<bits/stdc++.h>
using namespace std;

int factorial (int a) {
if (a==0) return 1;
int ans =1;
for (int i = 1; i <= a; i++){
ans *= i;
}
return ans;
}
int main() {
printf("n= ");
int n; cin >> n; 
double e = 0;
e+=(1.0/(double)factorial(n));
while (n--) e+=(1.00/(double)factorial(n));
cout << e << '\n';
return 0;
}