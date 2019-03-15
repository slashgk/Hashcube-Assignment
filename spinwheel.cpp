#include<bits/stdc++.h>
using namespace std;

class Spinwheel
{
    public:
    int giftCount;
    vector<int> gifts;
    vector<float> prob;
    int val=0;

    static bool comparison(const pair<int,float> &a,const pair<int,float> &b){
        return a.second<b.second;
    }

    int randomGenerator() {
        time_t now;
        time(&now);
        srand((unsigned int)time(&now));
        int randomNumber =70+ rand() % 9;
		val+=randomNumber;
		return val%100;
    }

    void input() {
        cout<<"Enter no. of gifts:";
        cin>>giftCount;

        cout<<"Enter gifts and probability respectively:"<<endl;
        for(int i = 0;i<giftCount;i++){
            int gift;
            float probb;
            cin>>gift>>probb;
            gifts.push_back(gift);
            prob.push_back(probb);
        }
    }

    void giveGift(){
        vector< pair<int,float> > bundle;

        for(int i=0; i<giftCount;	i++){
            bundle.push_back(make_pair(gifts[i], prob[i]));
        }

        sort(bundle.begin(),bundle.end(), comparison);

        for(int i=0; i<giftCount;i++){
            gifts[i] = bundle[i].first;
            prob[i] = bundle[i].second;
        }

        int freqArray[100];
        for(int i=0;i<100;i++){
            freqArray[i] = gifts[0];
        }

        int i=0,j=0,item=0;

        while(i<100&&item<giftCount){
            for(j=0;j<ceil(prob[item]*100);j++){
                freqArray[i] = gifts[item];
                i++;
            }
            item++;
        }
		int randomNumber = randomGenerator();

        cout<<freqArray[randomNumber]<<endl;
    }
};

int main() {
    Spinwheel obj1;
    obj1.input();

    for(int i=0;i<10;i++){
        srand(time(NULL));
        obj1.giveGift();
    }

    return 0;
}
