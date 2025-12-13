class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, 
                                   vector<string>& businessLine, 
                                   vector<bool>& isActive) {
        int n = code.size();
        vector<pair<int, string>> validCoupons; // (businessOrder, code)
        
        unordered_map<string, int> businessOrder = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        
        for (int i = 0; i < n; i++) {
            // Check if active
            if (!isActive[i]) continue;
            
            // Check business line
            auto it = businessOrder.find(businessLine[i]);
            if (it == businessOrder.end()) continue;
            
            // Check code validity
            if (code[i].empty()) continue;
            bool validCode = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    validCode = false;
                    break;
                }
            }
            if (!validCode) continue;
            
            validCoupons.push_back({it->second, code[i]});
        }
        
        // Sort by business order, then by code
        sort(validCoupons.begin(), validCoupons.end());
        
        vector<string> result;
        for (auto& [order, codeStr] : validCoupons) {
            result.push_back(codeStr);
        }
        
        return result;
    }
};