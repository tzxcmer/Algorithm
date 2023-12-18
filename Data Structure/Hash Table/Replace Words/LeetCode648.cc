class Solution {
public:
    vector<string> split(string& str,char ch)
    {
        int pos = 0;
        int start = 0;
        string s(str);
        vector<string> ret;
        while(pos < s.size())
        {
            while(pos < s.size() && s[pos] == ch)
                pos++;
            start = pos;
            while(pos<s.size() && s[pos] != ch)
                pos++;
            if(start < s.size())
                ret.emplace_back(s.substr(start,pos-start));
        }

        return ret;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> hash;
        for(auto& root : dictionary)
            hash.emplace(root);
        vector<string> words = split(sentence,' ');
        for(auto& word : words)
        {
            for(int i=0;i<word.size();i++)
            {
                if(hash.count(word.substr(0,1+i)))
                {
                    word = word.substr(0,1+i);
                    break;
                }
            }
        }
        string ans;
        for(int i=0;i<words.size()-1;i++)
        {
            ans.append(words[i]);
            ans.append(" ");
        }
        ans.append(words.back());
        return ans;
    }
};
