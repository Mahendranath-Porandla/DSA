class Solution {
public:
    string reverseWords(string s) {
        // first - see the follow up below of the problem desc
        reverse(s.begin(),s.end());
        int n = s.size();
        int p1=0, p2=0;
        int i=0;
        while(i<n){
            while(i<n && s[i]!=' '){
                s[p2++]=s[i++];
            }
            if(p1<p2){
                reverse(s.begin()+p1,s.begin()+p2);
                s[p2]=' ';
                p2++;
                p1= p2;
            }
            i++;
        }
        
        s = s.substr(0,p2-1);
        return s; 

    }
};