class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());;
        int answer = r;

        while(l<=r){
            int m = l + (r -l) /2;

            long long htf = 0;
            for(int i =0;i<piles.size();i++){
                htf += (piles[i]/m) + (piles[i] % m != 0);
            }

            if(htf <= h){
                answer = min(answer,m);
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return answer;
    }
};
