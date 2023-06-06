class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // string ans="",curr="";
        // int n=str1.size();
        // cout<<str2.size()<<endl;
        // for(int i=1;i<=str1.size();i++)
        // {
        //     if(n%i == 0){
        //      string temp = str1.substr(0,i);
        //      cout<<temp<<" ";
        //      int flag=0,flag2=0,size=temp.size();
        //      for(int j=0;j<str2.size();j++)
        //      {
        //          if(str2[j] !=temp[j%size]){
        //              cout<<str2[j]<<" "<<j<<" "<<temp[j%size]<<endl;
        //              flag=1; break;
        //          }
        //      }
        //      for(int j=0;j<n;j++)
        //      {
        //          if(str1[j]!=temp[j%size]){
        //              flag=1;break;
        //          }
        //      }
        //      if(!flag && str2.size()%size == 0) ans=temp;
        //      cout<<ans<<endl;
        //     }
        // }

        string ans="";
        if(str1+str2 == str2+str1){
            return str1.substr(0,gcd(str1.size(),str2.size()));
        }
        return ans; 
    }
};