class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        //Alice
        int mA = stoi(arriveAlice.substr(0,2));
        int mL = stoi(leaveAlice.substr(0,2));
        int i=1, startA=0, leaveA=0;
        while(i < mA){
            if(i==1 || i==3 || i==5 || i==7  || i==8 || i==10 || i==12) startA += 31;
            else if(i == 2) startA += 28;
            else startA += 30;
            i += 1;
        }
        int dA = stoi(arriveAlice.substr(3,2));
        startA += dA ;
        i=1;
        while(i < mL){
            if(i==1 || i==3 || i==5 || i==7  || i==8 || i==10 || i==12) leaveA += 31;
            else if(i == 2) leaveA += 28;
            else leaveA += 30;
            i += 1;
        }
        int lA = stoi(leaveAlice.substr(3,2));
        leaveA += lA ;
        //bob
        int mAB = stoi(arriveBob.substr(0,2));
        int mLB = stoi(leaveBob.substr(0,2));
        int  startAB=0, leaveAB=0;
        i=1;
        while(i < mAB){
            if(i==1 || i==3 || i==5 || i==7  || i==8 || i==10 || i==12) startAB += 31;
            else if(i == 2) startAB += 28;
            else startAB += 30;
            i += 1;
        }
        int dAB = stoi(arriveBob.substr(3,2));
        startAB += dAB ;
        i=1;
        while(i < mLB){
            if(i==1 || i==3 || i==5 || i==7  || i==8 || i==10 || i==12) leaveAB += 31;
            else if(i == 2) leaveAB += 28;
            else leaveAB += 30;
            i += 1;
        }
        int lAB = stoi(leaveBob.substr(3,2));
        leaveAB += lAB ;
        int k,m;
        int start = max(startAB, startA);
        int end = min(leaveA, leaveAB);
        if(start <= end) return end-start+1;
        return 0;
    }
};