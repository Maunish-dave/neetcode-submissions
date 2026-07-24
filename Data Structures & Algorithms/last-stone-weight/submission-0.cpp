class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;


        // max is at the top
        for(int num:stones){
            pq.push(num);
        }


        while(pq.size() > 1){
            int first_stone = pq.top();
            pq.pop();
            int second_stone = pq.top();
            pq.pop();

            if(first_stone != second_stone){
                pq.push(abs(first_stone-second_stone));
            }
        }

        return pq.size() > 0 ? pq.top() : 0;
    }
};
