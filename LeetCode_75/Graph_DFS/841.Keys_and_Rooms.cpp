// https://leetcode.com/problems/keys-and-rooms/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(int idx, vector<bool>& vis, const vector<vector<int>>& rooms){
        vis[idx] = true;
        for(int r : rooms[idx]){
            if(!vis[r]) dfs(r, vis, rooms);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        dfs(0, vis, rooms);
        for(bool v : vis) if(!v) return false;
        return true;
    }
};

int main(){
    vector<vector<int>> rooms = { {1}, {2}, {3}, {} };
    cout << Solution().canVisitAllRooms(rooms) << endl;
    rooms = { {1,3}, {3,0,1}, {2}, {} };
    cout << Solution().canVisitAllRooms(rooms) << endl;

    return 0;
}

