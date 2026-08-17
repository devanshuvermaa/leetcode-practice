class Solution {
public:
    // Helper function for raw speed over unordered_map
    int getValue(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int total = 0;
        int maxSeen = 0;
        
        // Loop backwards from the end of the string
        for (int i = s.length() - 1; i >= 0; i--) {
            int current = getValue(s[i]);
            
            // If the current number is smaller than the max seen, it's a subtraction
            if (current < maxSeen) {
                total -= current;
            } 
            // Otherwise, it's normal addition (and we update our max)
            else {
                total += current;
                maxSeen = current;
            }
        }
        
        return total;
    }
};