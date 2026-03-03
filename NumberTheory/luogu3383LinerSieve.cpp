#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=0x3f3f3f3f;
const int N=1e5+10;
void liner_sieve(int n,vector<int>& prime){
    vector<bool> is_prime(n+1,true);
    for(int i=2;i<=n;i++){
        if(is_prime[i]) prime.emplace_back(i);
        for(auto& e:prime){
            if(i*e>n) break;
            is_prime[i*e]=false;
            if(i%e==0) break;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<int> prime;
    liner_sieve(n,prime);
    while(q--){
        int k;
        cin>>k;
        k--;
        cout<<prime[k]<<"\n";
    }
    return 0;
}
/*
原理概述
代码中，外层枚举 i=1→n。对于一个 i，经过前面的腥风血雨，如果它还没有被筛掉，就加到质数数组 Prime[] 中。下一步，是用 i 来筛掉一波数。

内层从小到大枚举 Prime[j]。i×Prime[j] 是尝试筛掉的某个合数，其中，我们期望 Prime[j] 是这个合数的最小质因数 (这是线性复杂度的条件，下面叫做“筛条件”)。它是怎么得到保证的？

j 的循环中，有一句就做到了这一点：

			if(i % Prime[j] == 0)
				break; 

j 循环到 imodPrime[j]==0 就恰好需要停止的理由是：

下面用 s(smaller) 表示小于 j 的数，L(larger) 表示大于 j 的数。

① i 的最小质因数肯定是 Prime[j]。

（如果 i 的最小质因数是 Prime[s] ，那么 Prime[s] 更早被枚举到（因为我们从小到大枚举质数），当时就要break）

既然 i 的最小质因数是 Prime[j]，那么 i×Prime[j] 的最小质因数也是 Prime[j]。所以，j 本身是符合“筛条件”的。

② i×Prime[s] 的最小质因数确实是 Prime[s]。

（如果是它的最小质因数是更小的质数 Prime[t]，那么当然 Prime[t] 更早被枚举到，当时就要break）

这说明 j 之前（用 i×Prime[s] 的方式去筛合数，使用的是最小质因数）都符合“筛条件”。

③ i×Prime[L] 的最小质因数一定是 Prime[j]。

（因为 i 的最小质因数是 Prime[j]，所以 i×Prime[L] 也含有 Prime[j] 这个因数（这是 i 的功劳），所以其最小质因数也是 Prime[j]（新的质因数 Prime[L] 太大了））

这说明，如果 j 继续递增（将以 i×Prime[L] 的方式去筛合数，没有使用最小质因数），是不符合“筛条件”的。

小提示：

当 i 还不大的时候，可能会一层内就筛去大量合数，看上去耗时比较大，但是由于保证了筛去的合数日后将不会再被筛（总共只筛一次），复杂度是线性的。到 i 接近 n 时，每层几乎都不用做什么事。

建议看下面两个并不复杂的证明，你能更加信任这个筛法，利于以后的扩展学习。

正确性（所有合数都会被标记）证明
设一合数 C（要筛掉）的最小质因数是 p 
1
​
 ，令 B=C/p 
1
​
 （C=B×p 
1
​
 ），则 B 的最小质因数不小于 p 
1
​
 （否则 C 也有这个更小因子）。那么当外层枚举到 i=B 时，我们将会从小到大枚举各个质数；因为 i=B 的最小质因数不小于 p 
1
​
 ，所以 i 在质数枚举至 p 
1
​
  之前一定不会break，这回，C 一定会被 B×p 
i
​
  删去。

核心：亲爱的 B 的最小质因数必不小于 p 
1
​
 。

例：315=3×3×5×7，其最小质因数是 3。考虑 i=315/3=105 时，我们从小到大逐个枚举质数，正是因为 i 的最小质因数也不会小于 3（本例中就是 3），所以当枚举 j=1(Prime[j]=2) 时，i 不包含 2 这个因子，也就不会break，直到 Prime[j]=3 之后才退出。

当然质数不能表示成“大于1的某数×质数”，所以整个流程中不会标记。

线性复杂度证明
注意这个算法一直使用“某数×质数”去筛合数，又已经证明一个合数一定会被它的最小质因数 p 
1
​
  筛掉，所以我们唯一要担心的就是同一个合数是否会被“另外某数 × p 
1
​
  以外的质数”再筛一次导致浪费时间。设要筛的合数是 C，设这么一个作孽的质数为 p 
x
​
 ，再令 A=C/p 
x
​
 ，则 A 中一定有 p 
1
​
  这个因子。当外层枚举到 i=A，它想要再筛一次 C，却在枚举 Prime[j]=p 
1
​
  时，因为 imodPrime[j]==0 就退出了。因而 C 除了 p 
1
​
  以外的质因数都不能筛它。

核心：罪恶的 A 中必有 p 
1
​
  这个因子。

例：315=3×3×5×7。首先，虽然看上去有两个 3，但我们筛数的唯一一句话就是

			isPrime[i*Prime[j]] = 0;

所以，315 只可能用 105×3 或 63×5 或 45×7 这三次筛而非四次。然后，非常抱歉，后两个 i=63,i=45 都因为贪婪地要求对应的质数 Prime[j] 为 5 、7，而自己被迫拥有 3 这个因数，因此他们内部根本枚举不到 5 、7，而是枚举到 3 就break了。

以上两个一证，也就无可多说了。
*/