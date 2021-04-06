#include<bits/stdc++.h>
using namespace std;

long long call_last(long d);
long long f(long d);
long long f_divisor(long n);
long long strange_sum (int L, int R);


long long call_last(long d){
    for(int i=2;i<=d;++i){
        if(d%i==0)
        {
            return (i*f(d/i) + (d/i)*f(i));
        }
    }
    return 0;
}

long long f(long d){
    if(d == 1)
        return 0;
    if(d == 2)
        return 1;
    bool flag = 1;
    for(int i=2;i<=d/2+1;++i)
    {
        if(d%i==0)
            flag = 0;
    }
    if(flag == 1)
        return 1;
    
   // 1<x<=y; x*y = d
    long last = call_last(d);
    return last;
}

long long f_divisor(long n)
{
    long long sum = 0;

    long limit = n/2 + 5;
    if(limit>n)
        limit = n;
    
    for(long i=1;i<=limit;++i)
    {
        if(n%i==0)
        {
            long s_i = f(i);
            sum += s_i;
        }

    }
    return sum;
}

long long strange_sum (int L, int R) {
   long sum = 0;
   for(long i=L; i<=R;++i)
   {
      long f_divisor_i_sum = f_divisor(i);
      sum += f_divisor_i_sum;
   }
   return sum;  
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int L;
        cin >> L;
        int R;
        cin >> R;

        long long out_;
        out_ = strange_sum(L, R);
        cout << out_;
        cout << "\n";
    }
}