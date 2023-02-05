/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Appraoch:
https://leetcode.com/problems/permutation-in-string/solutions/1762469/c-sliding-window-optimized-well-explained/?orderBy=most_votes

*/
//TC: O(n+m*26)=O(n+m)  SC:O(26)
vector<int> findAnagrams(string s, string p) {
    int n=s.size(), m=p.size();
    vector<int> freq1(26,0), freq2(26,0);

    for(int i=0;i<m;i++)
        freq1[p[i]-'a']++;

    vector<int> ans;
    int i=0, j=0;
    while(j<n){
        freq2[s[j]-'a']++;

        if((j-i+1)<m)
            j++;

        else if((j-i+1)==m){
            if(freq1==freq2)
                ans.push_back(i);

            freq2[s[i]-'a']--;
            i++;
            j++;
        }
    }

    return ans;
}



/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

*/
//TC,SC same as previous
bool checkInclusion(string s1, string s2) {
    if(s2.size()<s1.size()) 
        return false;

    vector<int> freq1(26,0), freq2(26,0);

    for(int i=0;i<s1.size();i++)
        freq1[s1[i]-'a']++;
    
    int i=0, j=0;

    while(j<s2.size()){
        freq2[s2[j]-'a']++;
        if((j-i+1)<s1.size()){
            j++;
        }
        else if((j-i+1)==s1.size()){
            if(freq1==freq2)
                return true;
            else{
                freq2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
    }
    return false;
}