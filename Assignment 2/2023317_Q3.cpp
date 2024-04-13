#include<iostream>
using namespace std;

void minim(long long &b, long long &s, long long &c, long long &ans){
    if (b<s){
        if (b<c){
            ans+=b;
            s -= b;
            c -= b;
            b -= b;
        }
        else{
            ans+=c;
            b -= c;
            s -= c;
            c -= c;
        }
    }
    else{
        if (s<c){
            ans+=s;
            b -= s;
            c -= s;
            s -= s;
        }
        else{
            ans+=c;
            b -= c;
            s -= c;
            c -= c;
        }
    }
}

int main(){
    
    string recipe;
    cout<<"Input Recipe: ";
    cin>>recipe;
    long long Nb, Ns, Nc;
    cout<<"Input Nb Ns Nc with a space: ";
    cin>>Nb>>Ns>>Nc;
    cout<<"Input Pb Ps Pc with a space: ";
    long long Pb, Ps, Pc;
    cin>>Pb>>Ps>>Pc;
    cout<<"Input r: ";
    long long r;
    cin>>r;
    long long countB=0, countS=0, countC=0;
    for (long long i=0; i<recipe.size(); i++){
        if (recipe[i]=='B'){
            countB++;
        }
        else if (recipe[i]=='S'){
            countS++;
        }
        else{
            countC++;
        }
    }
    long long b= (countB==0? 0:Nb/countB);
    long long s= (countS==0? 0:Ns/countS);
    long long c= (countC==0? 0:Nc/countC);
    long long remB = (countB==0? 0:Nb%countB), remS = (countS==0? 0:Ns%countS), remC = (countC==0? 0:Nc%countC);
    long long ans = 0;
    minim(b, s, c, ans);
    while (true){
        long long cost=0;
        long long iterB=0, iterS=0, iterC=0;
        if (b==0){
            iterB = countB-remB;
            remB = 0;
            if (s>0){
                s--;
            }
            else{
                iterS=countS-remS;
                remS=0;
            }
            if (c>0){
                c--;
            }
            else{
                iterC=countC-remC;
                remC=0;
            }
        }
        else if (s==0){
            iterS = countS-remS;
            remS = 0;
            if (b>0){
                b--;
            }
            else{
                iterB=countB-remB;
                remB=0;
            }
            if (c>0){
                c--;
            }
            else{
                iterC=countC-remC;
                remC=0;
            }
        }
        else{
            iterC = countC-remC;
            remC = 0;
            if (s>0){
                s--;
            }
            else{
                iterS=countS-remS;
                remS=0;
            }
            if (b>0){
                b--;
            }
            else{
                iterB=countB-remB;
                remB=0;
            }
        }
        cost = (iterB*Pb)+(iterC*Pc)+(iterS*Ps);
        r-=cost;
        if (r<0){
            break;
        }
        ans++;
        if (b==0 && s==0 && c==0 && remB==0 && remC==0 && remS==0){
            cost = (countB*Pb)+(countC*Pc)+(countS*Ps);
            ans += (r/cost);
            break;
        }
    }
    cout<<"Output: "<<ans<<endl;

    return 0;
}