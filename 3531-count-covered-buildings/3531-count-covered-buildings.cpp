// class Solution {
// public:
//     int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
//         // Create 2D grid representation - n x n grid
//         vector<vector<bool>> grid(n, vector<bool>(n, false));
        
//         // Mark building positions with bounds checking
//         for (auto& building : buildings) {
//             int x = building[0];
//             int y = building[1];
            
//             // Validate coordinates are within grid bounds
//             if (x >= 0 && x < n && y >= 0 && y < n) {
//                 grid[x][y] = true;
//             }
//         }
        
//         int count = 0;
        
//         // Check each building
//         for (auto& building : buildings) {
//             int x = building[0];
//             int y = building[1];
            
//             // Skip if coordinates are invalid
//             if (x < 0 || x >= n || y < 0 || y >= n) {
//                 continue;
//             }
            
//             bool hasLeft = false, hasRight = false;
//             bool hasAbove = false, hasBelow = false;
            
//             // Check left (decreasing x)
//             for (int i = x - 1; i >= 0; i--) {
//                 if (grid[i][y]) {
//                     hasLeft = true;
//                     break;
//                 }
//             }
            
//             // Check right (increasing x)
//             for (int i = x + 1; i < n; i++) {
//                 if (grid[i][y]) {
//                     hasRight = true;
//                     break;
//                 }
//             }
            
//             // Check above (decreasing y)
//             for (int j = y - 1; j >= 0; j--) {
//                 if (grid[x][j]) {
//                     hasAbove = true;
//                     break;
//                 }
//             }
            
//             // Check below (increasing y)
//             for (int j = y + 1; j < n; j++) {
//                 if (grid[x][j]) {
//                     hasBelow = true;
//                     break;
//                 }
//             }
            
//             if (hasLeft && hasRight && hasAbove && hasBelow) {
//                 count++;
//             }
//         }
        
//         return count;
//     }
// };
// class Solution {
// public:
//     int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
//         // Convert 1-indexed to 0-indexed
//         vector<vector<int>> grid(n, vector<int>(n, 0));
        
//         // Mark building positions (convert from 1-indexed to 0-indexed)
//         for (auto& building : buildings) {
//             int x = building[0] - 1;  // Convert to 0-indexed
//             int y = building[1] - 1;  // Convert to 0-indexed
//             if (x >= 0 && x < n && y >= 0 && y < n) {
//                 grid[x][y] = 1;
//             }
//         }
        
//         int count = 0;
        
//         // Check each building (using 0-indexed coordinates)
//         for (auto& building : buildings) {
//             int x = building[0] - 1;  // Convert to 0-indexed
//             int y = building[1] - 1;  // Convert to 0-indexed
            
//             if (x < 0 || x >= n || y < 0 || y >= n) continue;
            
//             bool left = false, right = false, up = false, down = false;
            
//             // Check left
//             for (int i = x - 1; i >= 0 && !left; i--) {
//                 if (grid[i][y]) left = true;
//             }
            
//             // Check right
//             for (int i = x + 1; i < n && !right; i++) {
//                 if (grid[i][y]) right = true;
//             }
            
//             // Check up (smaller y)
//             for (int j = y - 1; j >= 0 && !up; j--) {
//                 if (grid[x][j]) up = true;
//             }
            
//             // Check down (larger y)
//             for (int j = y + 1; j < n && !down; j++) {
//                 if (grid[x][j]) down = true;
//             }
            
//             if (left && right && up && down) {
//                 count++;
//             }
//         }
        
//         return count;
//     }
// };
// Using hash map/sets
// 
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // Convert to 0-indexed
        vector<pair<int, int>> pts;
        for (auto& b : buildings) {
            pts.push_back({b[0] - 1, b[1] - 1});
        }
        
        // Organize buildings by row and column
        unordered_map<int, vector<int>> rowMap;  // row -> list of columns
        unordered_map<int, vector<int>> colMap;  // column -> list of rows
        
        for (auto& [x, y] : pts) {
            rowMap[x].push_back(y);
            colMap[y].push_back(x);
        }
        
        // Sort all lists for binary search
        for (auto& [row, cols] : rowMap) {
            sort(cols.begin(), cols.end());
        }
        for (auto& [col, rows] : colMap) {
            sort(rows.begin(), rows.end());
        }
        
        int count = 0;
        
        for (auto& [x, y] : pts) {
            // Check if there's a building to the left
            bool hasLeft = false;
            if (rowMap.count(x)) {
                auto& cols = rowMap[x];
                // Find first column less than y
                auto it = lower_bound(cols.begin(), cols.end(), y);
                if (it != cols.begin()) {
                    hasLeft = true;
                }
            }
            
            // Check if there's a building to the right
            bool hasRight = false;
            if (rowMap.count(x)) {
                auto& cols = rowMap[x];
                // Find first column greater than y
                auto it = upper_bound(cols.begin(), cols.end(), y);
                if (it != cols.end()) {
                    hasRight = true;
                }
            }
            
            // Check if there's a building above
            bool hasAbove = false;
            if (colMap.count(y)) {
                auto& rows = colMap[y];
                // Find first row less than x
                auto it = lower_bound(rows.begin(), rows.end(), x);
                if (it != rows.begin()) {
                    hasAbove = true;
                }
            }
            
            // Check if there's a building below
            bool hasBelow = false;
            if (colMap.count(y)) {
                auto& rows = colMap[y];
                // Find first row greater than x
                auto it = upper_bound(rows.begin(), rows.end(), x);
                if (it != rows.end()) {
                    hasBelow = true;
                }
            }
            
            if (hasLeft && hasRight && hasAbove && hasBelow) {
                count++;
            }
        }
        
        return count;
    }
};