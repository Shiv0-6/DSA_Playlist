class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<int> offlineUntil(numberOfUsers, -1);
        
        // Group events by timestamp
        unordered_map<int, vector<pair<string, string>>> timeMap;
        
        for (const auto& event : events) {
            int timestamp = stoi(event[1]);
            timeMap[timestamp].push_back({event[0], event[2]});
        }
        
        // Get sorted timestamps
        vector<int> timestamps;
        for (auto& entry : timeMap) {
            timestamps.push_back(entry.first);
        }
        sort(timestamps.begin(), timestamps.end());
        
        // Min-heap for users coming back online
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int timestamp : timestamps) {
            // Bring back users whose offline period ended
            while (!pq.empty() && pq.top().first <= timestamp) {
                int userId = pq.top().second;
                pq.pop();
                offlineUntil[userId] = -1; // Online
            }
            
            // Get all events at this timestamp
            auto& eventsAtTime = timeMap[timestamp];
            
            // First process all OFFLINE events at this timestamp
            for (auto& [type, data] : eventsAtTime) {
                if (type == "OFFLINE") {
                    int userId = stoi(data);
                    offlineUntil[userId] = timestamp + 60;
                    pq.push({timestamp + 60, userId});
                }
            }
            
            // Then process all MESSAGE events at this timestamp
            for (auto& [type, data] : eventsAtTime) {
                if (type == "MESSAGE") {
                    if (data == "ALL") {
                        for (int i = 0; i < numberOfUsers; i++) {
                            mentions[i]++;
                        }
                    }
                    else if (data == "HERE") {
                        for (int i = 0; i < numberOfUsers; i++) {
                            if (offlineUntil[i] == -1) {
                                mentions[i]++;
                            }
                        }
                    }
                    else {
                        istringstream iss(data);
                        string token;
                        while (iss >> token) {
                            int userId = stoi(token.substr(2));
                            if (userId >= 0 && userId < numberOfUsers) {
                                mentions[userId]++;
                            }
                        }
                    }
                }
            }
        }
        
        return mentions;
    }
};