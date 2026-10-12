class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;
        int n = tickets.size();
        int time = 0;

        for(int i = 0;i<n;i++){
            q.push(i);
        }

        while(!q.empty()){
            int i = q.front();
            q.pop();
            tickets[i]--;
            time++;

            if(tickets[i]>0) q.push(i);
            if(i == k && tickets[i] == 0){
                return time;
            }
        }
        return time;
    }
};