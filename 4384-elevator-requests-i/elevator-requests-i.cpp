class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int totalTime = 0;
        int currentFloor = 0;
        
        for (int floor : requests) {
            totalTime += abs(floor - currentFloor);
            currentFloor = floor;
        }
        
        return totalTime;
    }
};