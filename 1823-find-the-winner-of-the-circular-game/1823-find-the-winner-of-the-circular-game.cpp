class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        int count = 1;
        for(int i=1;i<=n;i++){
            q.push(i);
        }

        while(q.size() > 1){
            int i = q.front();
            q.pop();

            if(count == k){
                count = 1;
                continue;
            }else{
                count++;
                q.push(i);
            }
        }
        return q.front();
    }
};