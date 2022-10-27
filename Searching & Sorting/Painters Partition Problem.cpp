int const MOD=1e7+3;
long long maxi(long long a,long long b)
{
    if(a<b)
        return b;
    return a;
}
int find(long long maxi,vector<int> &val)
{
    int sum=0,count=0;
    for(int i=0;i<val.size();i++)
    {
        sum+=val[i];
        if(sum>maxi)
        {
            sum=val[i];
            count++;
        }
    }
    return count+1;
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long l=0,r=0;
    for(int i=0;i<C.size();i++)
    {
        l=maxi(l,C[i]);
        r=(r+C[i])%MOD;
    }
    while(r>l)
    {
        long long mid=(l+r)/2;
        if(find(mid,C)<=A)
            r=mid;
        else
            l=mid+1;
    }
    long long x = B;
    return (l*B)%MOD;
}
