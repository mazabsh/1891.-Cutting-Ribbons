#include<iostream> 
#include<vector> 
#include<algorithm> 

using namespace std; 

class Solution{
public: 
      int maxLength(vector<int>& ribbons, int k){
        int low=1; 
        int high = *max_element(ribbons.begin(), ribbons.end()); 
        int res= 0; 
        while(low<=high){
          int mid = low + (high-low)/2; 
          if(canCut(ribbons, k, mid)){
            res = mid; 
            low = mid+1; 
          }else high = mid-1; 
        }
        return res; 
      }
      bool canCut(vector<int>& ribbons, int k, int length){
        int count =0; 
        for(int r:ribbons){
          count +=r/length; 
        }
        return count >=k; 
      }
};
int main(){
  vector<int> ribbons = {7,5,9}; 
  int k=4; 
  Solution sol; 
  cout << sol.maxLength(ribbons, k) <<endl; 
  return 0; 
}
