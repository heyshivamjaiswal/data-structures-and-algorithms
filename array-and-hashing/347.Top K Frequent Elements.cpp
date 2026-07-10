//Approach 1
//Using Min-Heap

class Solution {
public:
   typedef pair<int ,int>P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>mp;

        for(int &num: nums){
            mp[num]++;
        }

        //Define Min Heap
        priority_queue<P, vector<P> , greater<P>>pq;

        //push elements in min heap
        //maintain only size of k only
        for( auto it: mp){
            pq.push({it.second , it.first});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

//Approach 2 
//Using bucke sort

//hint
//• Use Bucket Sort when sorting by a value with a small known range.
//• In Top K Frequent, frequency ranges from 1 to n.
//• Bucket index = frequency, bucket value = list of numbers with that frequency.
//• Traverse buckets from highest frequency to collect the top k elements.
//Clue 1: You're sorting by - Frequency  , marks  score , Rating, Age . We are sorting these instead of actual element
//Clue 2: You only need higest , Lowest , Top k

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Count frequencies
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets
        vector<vector<int>> bucket(nums.size() + 1);

        // Step 3: Place numbers into buckets
        for (auto it : freq) {

            int number = it.first;
            int frequency = it.second;

            bucket[frequency].push_back(number);
        }

        // Step 4: Collect top k frequent elements
        vector<int> ans;

        for (int i = bucket.size() - 1; i >= 0; i--) {

            for (int num : bucket[i]) {

                ans.push_back(num);

                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};