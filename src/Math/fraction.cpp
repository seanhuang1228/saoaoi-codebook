struct Frac{
    ll fz;
    ll fm;
    Frac(){}
    Frac(ll n):fz(n),fm(1){}
};
ll GCD(ll a,ll b){
    if(b==0){
	return a;
    }
    return GCD(b,a%b);
}
Frac Simplify(Frac a){
    Frac ans;
    ll gcd=GCD(abs(a.fz),a.fm);
    ans.fz=a.fz/gcd;
    ans.fm=a.fm/gcd;
    return ans;
}
Frac operator+(Frac a,Frac b){
    Frac ans;
    ans.fz=a.fz*b.fm+b.fz*a.fm;
    ans.fm=a.fm*b.fm;
    return Simplify(ans);
}
Frac operator-(Frac a,Frac b){
    Frac ans;
    ans.fz=a.fz*b.fm-b.fz*a.fm;
    ans.fm=a.fm*b.fm;
    return Simplify(ans);
}
Frac operator*(Frac a,Frac b){
    Frac ans;
    ans.fz=a.fz*b.fz;
    ans.fm=a.fm*b.fm;
    return Simplify(ans);
}
Frac operator/(Frac a,Frac b){
    Frac ans;
    ans.fz=a.fz*b.fm;
    ans.fm=a.fm*b.fz;
    return Simplify(ans);
}
bool operator<(Frac a,Frac b){
    return a.fz*b.fm<b.fz*a.fm;
}
bool operator==(Frac a,Frac b){
    return a.fz==b.fz&&a.fm==b.fm;
}