#include "header.h"
void TrueOrFalse(int kol){
SetNode ht(kol);
    int begins, ends;
    for(int i=0; i< kol; i++){
        cin>>begins>>ends;
        if(begins+ends==(kol-1)){
            ht.AddSet(to_string(begins));
        }
    }
    int maxs=0;
    for(int i=0; i < kol; i++){
        if(ht.much[i]!= nullptr){
            maxs++;
        }
    }
    cout<<maxs<<endl;
}
