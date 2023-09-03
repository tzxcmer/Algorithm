typedef long long ll;
class Automaton{
public:
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    int getc(char c)
    {
        if(isspace(c)) return 0;
        if(c == '+' || c == '-') return 1;
        if(isdigit(c)) return 2;
        return 3;
    }
    int sign = 1;
    ll ans = 0;

    void get(char c)
    {
        state = table[state][getc(c)];
        if(state == "in_number")
        {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min((ll)INT_MAX,ans) : 
            min(-(ll)INT_MIN,ans);
        }
        else if(state == "signed")
            sign = c == '+' ? 1 : -1;
        return ;
    }
};

class Solution {
public:
    int myAtoi(string s) {
        Automaton at;
        for(auto ch : s)
        {
            at.get(ch);
        }

        return at.ans * at.sign;
    }
};
