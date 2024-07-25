// Problem Statement
// Write a function to find the longest common subsequence of two given strings.
// Sample Test Case
// Input: str1 = "abcde", str2 = "ace" Output: 3 (The LCS is "ace")


#include <iostream>
#include <string>
#include <vector>
using namespace std;


pair<int,string> logComsub(const string &str1, const string &str2){
        int m = str1.size();
        int n = str1.size();
       

        vector<vector<int>> dp(m +1, vector<int>(n+1,0));


        for (int i = 1; i <= m; i++){
            for (int j = 1; i <= n; j++)
            {
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                } 
            }
           
         
        }

    //    cout << "Dp Table" <<endl;
    //     for (int i = 0; i <= m; i++){
    //         for (int j = 0; j <= n; j++){
    //             cout << dp[i][j] << " ";
    //          }
    //     }
        int i = m, j = n;
        string lcs = "";
        while(i > 0 && j > 0){

            if (str1[i-1] == str2[j-1])
            {
                lcs = str1[i-1] + lcs;
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j - 1]){
                i--;
            }else
            {
                j--;
            }
        }
        

        return {dp[m][n],lcs};
        
}

int main()
{       string str1 = "abcde";
        string str2 = "ace";
        
        auto lcs = logComsub(str1,str2);
    
        string lcss = lcs.second;
        
        cout<<"The LCS is "<<lcss<<endl;


    return 0;
}
