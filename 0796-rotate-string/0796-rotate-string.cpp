class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        string next = s+s;
        if(next.find(goal) != string::npos){
            return true;
        }
        return false;
    }
};