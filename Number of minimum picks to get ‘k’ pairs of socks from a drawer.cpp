class Solution {
public int find_min(int[] a, int n, int k) {
// code here.
int opt=0;
int ans=-1;
int possible=0;
for(int i : a){
possible+=(i/2);

if(i%2==0){
opt+=(i-2)/2;
}else{
opt+=(i-1)/2;
}
}
if(possible<k){
return ans;
}
if(k<=opt){
ans=2*(k-1)+n+1;
}
else{
ans=2*opt+n+k-opt;
}
return ans;
}
}
Saumyasakshi
Coder || Android Developer || Ambivert || Dancer

Follow
1


1 