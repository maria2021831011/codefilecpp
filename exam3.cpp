#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t > 0) {
        int n;
        cin>>n;
        long tmp, nimsum = 0;
        for(int i = 0; i < n; i++) {
            cin>>tmp;

            int numprimefactors = 0;
            if(tmp == 1) {
                numprimefactors = 0;
            } else if(((tmp != 0) && !(tmp & (tmp - 1)))) {

                numprimefactors = tmp/2;
            } else {

                while(tmp > 1) {
                    bool foundfactor = false;
                    for(long j = 2; j*j <= tmp; j++) {
                        if(tmp%j == 0) {
                            numprimefactors++;
                            tmp /= j;
                            foundfactor = true;
                            break;
                        }
                    }
                    if(!foundfactor) {

                        numprimefactors++;
                        break;
                    }
                }
            }
            nimsum ^= numprimefactors;
        }
        if(nimsum != 0) {
            cout<<"1\n";
        } else {
            cout<<"2\n";
        }
        t--;
    }
    return 0;
}
