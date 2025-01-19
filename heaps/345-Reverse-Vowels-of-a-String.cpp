class Solution {
public:
    string reverseVowels(string s) {
        set<int> sett;
        sett.insert('a');
        sett.insert('e');
        sett.insert('i');
        sett.insert('o');
        sett.insert('u');

        int p1 = 0;
        int p2 = s.size()-1;
        while(p1<p2){
            if(!sett.count(tolower(s[p1]))){
                p1++;
            }
            if(!sett.count(tolower(s[p2]))){
                p2--;
            }
            if(sett.count(tolower(s[p1])) && sett.count(tolower(s[p2]))){
                swap(s[p1],s[p2]);
                p1++;
                p2--;
            }
        }
        return s;
    }
};