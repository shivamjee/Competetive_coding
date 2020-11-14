#include<iostream>
#include<vector>
#include<string>
using namespace std; 


void subSeq(string str,vector<string> &ans)
{
    if(str.length() ==0)
        return;
    int n = ans.size();
    for(int i=0;i<n;i++)
    {
        string temp = ans[i]+str[0];
        ans.push_back(temp);
    }
    subSeq(str.substr(1),ans);
}
int main() {
    string strMain;
    cin>>strMain;

    //first put "" as first element
    vector<string> ans;
    ans.push_back("");
    subSeq(strMain,ans);
    unique(ans.begin(),ans.end());


    int n = ans.size();

    //check
    /*for(int i=1;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl; */
    
    //cuz first element of ans is ""
    for(int i=1;i<n;i++)
    {
        sort(ans[i].begin(),ans[i].end());
        bool val = true;
        while(val)
        {
            cout<<ans[i]<<" ";
            val = next_permutation(ans[i].begin(),ans[i].end());
        }
        cout<<endl; 
    }
    
    return 0;
}