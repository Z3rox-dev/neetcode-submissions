class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> _set;
        for(string& email : emails){
            int i = 0;
            string cur = "";
            while(i < email.size() && email[i] != '@'){
                if(email[i] != '.'){
                    if(email[i] != '+'){
                        cur += email[i];
                        i++;
                    } 
                }
                else if(email[i] == '.'){
                    i++;
                    continue;
                }

                if(email[i] == '+'){
                    while(i < email.size() && email[i] != '@'){
                        i++;
                    }
                }
            }
            string temp = cur + email.substr(i);
            _set.insert(temp);
        }

        return _set.size();
    }
};