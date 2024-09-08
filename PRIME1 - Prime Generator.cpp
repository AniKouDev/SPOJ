#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Logic:-
/*
    max value = 1000000000, it will take a lot of time to find prime till 10^9. so will check till
    sqrt(10^9) <= 10^5.
    Now, as we can have multiple queries, calculating with 10^5 again and again, is time wastage, 
    so we will find all prime number till 10^5 in once and save it in a global array and will 
    use that for every query
*/

#define max_size 100000
int seiveArr[max_size+1] = {0}; // state of every number 0 if prime 1 if not
vector<int> primes; // array of all prime numbers till 10^5

void get_all_prime(){
    // mark 0&1 as not prime
    seiveArr[0] = 1;
    seiveArr[1] = 1;

    // if state is 0, i.e. number is prime, mark all it multiple as 1(non-prime)
    for(long long i = 2; i <= max_size; i++){
        if(seiveArr[i] == 0){
            primes.push_back(i);
            for(long long j = i*i; j<= max_size; j+=i)
                seiveArr[j] = 1;
        }
    }
}

void solve(int m, int n){
    for(long long i = m; i <= n; i++){
        // if i is already checked under seiveArr, check its state and print as per
        if(i<=max_size){
            if(!seiveArr[i])
                cout << i << endl;
        }
        // if i is not in seive check whether its divisible by any prime number or not
        else{
            int flag = 0;
            for(long long j : primes){
                // sqrt(i) is divisible of i, so no need to check with all the prime numbers
                if(j>sqrt(i)){
                    break;
                }
                // if divisible set flag and break;
                if(i%j==0){
                    flag = 1;
                    break;
                }
            }
            // if flag is not set, i.e. i is prime number print that
            if(!flag)
                cout << i << endl;
        }
    }
}

int main(){
    int t;
    cin >> t;
    get_all_prime();
    while(t--){
        int n,m;
        cin >> m >> n;
        solve(m,n);
        cout << endl;
    }
}