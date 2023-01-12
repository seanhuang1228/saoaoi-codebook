int bit[MAXN+1]={0};
void modify(int pos,int val){
    while(pos<=n){
	bit[pos]+=val;
	pos+=pos&-pos;
    }
}
int prefix_sum(int pos){
    int ans=0;
    while(pos>=1){
	ans+=bit[pos];
	pos-=pos&-pos;
    }
    return ans;
}