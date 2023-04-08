

// Time complexity => O(N^2)  Brute Force approach

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> ans ;
        int n = heights.size() ;

        for(int i =0;i<n;i++){
            int curr = heights[i] ;
            int x = 0;
            int y = n ;
            bool left = false, right = true ;


            for(int j =i+1;j<n;j++){
                if(heights[j]<curr){
                    y = j-1 ;
                    left = true ;
                    break ; 
                }
            }
            for(int j =i-1;j>=0;j--){
                if(heights[j]<curr){
                    x = j+1 ;
                    right = true ;
                    break ;
                }
            }
            if(left&&right){
                ans.push_back(curr*(y-x+1)) ;
            }
            else{
                ans.push_back(curr*(y-x)) ;
            }
            ans.push_back(curr) ;
        }

        sort(ans.begin(),ans.end()) ;
        return ans[ans.size()-1] ;
    }
};
