Approach:
  
 /** Store the Roman Numerals and their integer values. Just Follow the rules in question and continue forming the number **/
  
class Solution {
public:
    unordered_map<char,int> roman = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int romanToInt(string s) 
    {
        int result = 0;
        int i = 0;
        while(i < s.length()-1)
        {
            int a = roman[s[i]];
            int b = roman[s[i+1]];
            if(a < b)
            {
                result += (b-a);
                i += 2;
            }
            else
            {
                result += a;
                i++;  
            }
        }
        if(i != s.length())
        {
            result += roman[s[i]];
        }
        return result;
    }
