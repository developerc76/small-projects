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
int e = 0;
while (n--) e+=(1/factorial(n));
cout << e << '\n';
return 0;
}