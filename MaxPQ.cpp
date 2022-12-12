// Code : Max Priority Queue
// Send Feedback
// Implement the class for Max Priority Queue which includes following functions -
// 1. getSize -
// Return the size of priority queue i.e. number of elements present in the priority queue.
// 2. isEmpty -
// Check if priority queue is empty or not. Return true or false accordingly.
// 3. insert -
// Given an element, insert that element in the priority queue at the correct position.
// 4. getMax -
// Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
// 5. removeMax -
// Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
// Note : main function is given for your reference which we are using internally to test the class.


#include <vector>
#include <utility>

class PriorityQueue {
    vector<int> pq;

   public:
    PriorityQueue() {}

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        pq.push_back(element);
        int currIndex = pq.size()-1;
        while(currIndex > 0){
        int parentIndex = (currIndex - 1) / 2;
        if (pq[parentIndex] < pq[currIndex]) {
            swap(pq[parentIndex], pq[currIndex]);
        }
        else{
            break;
        }
            currIndex = parentIndex;
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(pq.size()==0){
            return 0;
        }
        return pq[0];
    }

    int removeMax() {
        if(pq.size() == 0){
            return 0;
        }
        int ans = pq[0];
        int parentIndex = 0;
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int childIndex1 = 2*parentIndex + 1;
        int childIndex2 = 2*parentIndex + 2;
        int s = pq.size();
        while(childIndex1 < s){
            int minIndex = parentIndex;
            if(pq[childIndex1] > pq[minIndex]){
                minIndex = childIndex1;
            }
            if(childIndex2<s && pq[childIndex2] > pq[minIndex]){
                minIndex = childIndex2;
            }
            if(minIndex == parentIndex){
                break;
            }
            swap(pq[parentIndex],pq[minIndex]);
            parentIndex = minIndex;
            childIndex1 = 2 * parentIndex + 1;
            childIndex2 = 2 * parentIndex + 2;
        }
        return ans;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size() == 0;
    }
};