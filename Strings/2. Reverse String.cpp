// METHOD 1 : WITHOUT USING EXTRA SPACE

class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        string curr_word;
        string final_result;

        for (int i = 0; i < s.length(); i++) {
            // Case 1: Alphabet (non-space character)
            if (s[i] != ' ') {
                curr_word += s[i];
            } else if (!curr_word.empty()) {
                // Case 2: Space, and we have a non-empty word in curr_word
                ans.push_back(curr_word);
                curr_word.clear();
            }
        }

        // Handle the last word (if any)
        if (!curr_word.empty()) {
            ans.push_back(curr_word);
        }

        // Now construct the final reversed string
        for (int j = ans.size() - 1; j >= 0; j--) {
            final_result += ans[j];
            if (j > 0) {
                final_result += ' '; // Add a space if not the last word
            }
        }
        return final_result;
    }
};

// METHOD 2 : USING STACK
class Solution {
public:
string reverseWords(string s) {
        if(s.size() == 0) return s;
        stack<string> stack;
        string result;
        for(int i=0; i<s.size(); i++) {
            string word;
            if(s[i]==' ') continue; //skip spaces
            while(i<s.size() && s[i]!=' ' ) { //store continuous letters into word
                word += s[i]; i++;
            }
            stack.push(word); //push word to the stack
        }
        while(!stack.empty()) {
            result += stack.top(); stack.pop();
            if(!stack.empty()) result += " ";
        }
        return result;
    }
};