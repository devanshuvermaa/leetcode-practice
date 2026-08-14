class Solution {
public:
    bool isPalindrome(int st,int end,string &s){
        int i=st;
        int j=end;
        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void helper(int idx,string &s,int n,vector<vector<string>> &ans,vector<string> &temp){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            if(isPalindrome(idx,i,s)){
                string str = s.substr(idx,i-idx+1);
                temp.push_back(str);
                helper(i+1,s,n,ans,temp);
                temp.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string &s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n = s.length();
        helper(0,s,n,ans,temp);
        return ans;
    }
};