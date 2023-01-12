string s;
int n=s.size();
vector<int> kmp(n*2,-1);
int ans=0;
for(int i=1;i<2*n;i++){
    int x=kmp[i-ans-1];
    while(x!=-1 && s[i%n]!=s[(ans+x+1)%n]){
        if(s[i%n]<s[(ans+x+1)%n]) ans=i-x-1;
        x=kmp[x];
    }
    if(x==-1 && s[i%n]!=s[ans%n]){
        if(s[i%n]<s[ans%n]) ans=i;
        kmp[i-ans]=-1;
    }
    else kmp[i-ans]=x+1;
}