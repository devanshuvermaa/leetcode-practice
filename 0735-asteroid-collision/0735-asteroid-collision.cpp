class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for(int ast : asteroids){
            bool destroyed = false;

            while(!s.empty() && ast<0 && s.back()>0 ){
                if(s.back() < abs(ast)){
                    s.pop_back();
                    continue;
                }
                else if(s.back() == abs(ast)){
                    s.pop_back();
                    destroyed = true;
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                s.push_back(ast);
            }
        }
        return s;
    }
};