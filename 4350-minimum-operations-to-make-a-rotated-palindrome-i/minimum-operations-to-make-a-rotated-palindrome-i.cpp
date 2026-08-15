class Solution{
public:
int minOperations(string s){
string dorivexalu =s;
int n = dorivexalu.length();
string doubled = dorivexalu+dorivexalu;
int min_total_ops = INT_MAX;
for(int k=0; k<n;++k){
int current_ops =k;
for(int i=0;i<n/2;++i){
int c1= doubled[k+i]-'a';
int c2= doubled[k+n-1-i]  - 'a';
int diff = abs(c1-c2);
current_ops += min(diff, 26- diff);
}
min_total_ops=min(min_total_ops, current_ops);
}
return min_total_ops;
}
};
