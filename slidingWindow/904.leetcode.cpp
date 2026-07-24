//METHOD 1  (BRUTE FORCE)
//Declare a map , insert the elements in map , check if frequency.size() > 2 then break, if not cal
//the maximum len and return the ans

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            unordered_map<int ,int>freq;
            for(int j=i; j<n; j++){
             
             //add fruit to basket (add no. to map)
             freq[fruits[j]];

             //check condtion
             if(freq.size() > 2) break;

             ans = max(ans , j-i+1);
            }
        }
        return ans;
    }
};

//METHOD 2 

// • Expand using right.
// • Count fruit frequencies.
// • If distinct fruits > 2, shrink from the left.
// • Erase fruit when its frequency becomes 0.
// • Update the answer only when the window is valid.

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;
        unordered_map<int ,int>freq;
        int left = 0;
        for(int right = 0; right < n; right++){

            //expand the window
            freq[fruits[right]]++;

            //check window validity
            while(freq.size() > 2){
                freq[fruits[left]]--;

                if(freq[fruits[left]] == 0)
                freq.erase(fruits[left]);
                left++;
            }
            ans = max(ans , right - left +1);
        }
        return ans;
    }
};