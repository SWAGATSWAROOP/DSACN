// Code : Remove Min
// Send Feedback
// Implement the function RemoveMin for the min priority queue class.
// For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
// Note : main function is given for your reference which we are using internally to test the code.

#include <vector>
#include <utility>
class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() { // mine
        if(isEmpty()){
            return -1;
        }
        int p = pq[0];
        int s = pq.size();
        pq[0] = pq[s - 1];
        pq.pop_back();
        s--;
        int i = 0;
        while(i < s){
            int childIndex1 = 2*i + 1;
            int childIndex2 = 2*i + 2;
            int minIndex = i;
            if (childIndex1 < s && childIndex2 < s) {
              minIndex = pq[childIndex1] > pq[childIndex2] ? childIndex2 : childIndex1;
              if(pq[i] > pq[minIndex]){
                  swap(pq[i],pq[minIndex]);
              }
              else{
                  break;
              }
            }
            else if(childIndex1 < s && pq[i]>pq[childIndex1]){
                minIndex = childIndex1;
                swap(pq[i], pq[minIndex]);
            }
            else if(childIndex2 < s && pq[i]>pq[childIndex2]){
                minIndex = childIndex2;
                swap(pq[i], pq[minIndex]);
            }
            else{
                break;
            }
            i = minIndex;
        }
        return p; 
    }
};

