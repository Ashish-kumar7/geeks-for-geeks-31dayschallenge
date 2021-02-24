class Solution {
long smallestpositive(long[] arr, int n){
// Your code goes here
Arrays.sort(arr);
long ans=1;
for(long x :arr){
if(x>ans)
{
return ans;
}
ans+=x;
}
return ans;

}
}