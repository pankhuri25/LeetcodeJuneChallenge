class Solution {
public:
    string validIPAddress(string IP) {
        
        if(ipv4(IP))
            return "IPv4";
        else if(ipv6(IP))
            return "IPv6";
        else
            return "Neither"; 
    }
    
    vector<string> splitString(string IP, const char ch)
    {
        vector<string> res;
        string t("");
        for(char p : IP)
        {
            if(p==ch)
            {
                res.push_back(t);
                t.clear();
            }
            else
                t.push_back(p);
        }
        res.push_back(t);
        return res;
    }
    
    bool ipv4(string IP)
    {
        if(IP.find('.')!=string::npos && count(IP.begin(), IP.end(), '.')==3)
        {
            vector<string> v = splitString(IP, '.');
            if(v.size()!=4) return false;
            
            for(auto s : v)
            {
                if(s.length()>3 || s.length()==0 || (s.length()!=1 && s[0]=='0') || s > "255")
                    return false;
                for(char ch : s)
                {
                    if(ch < '0' || ch >'9')
                        return false;
                }
            }
            return true;
        }
        return false;
    }
    bool ipv6(string IP)
    {
        if(IP.find(':')!= string::npos && count(IP.begin(), IP.end(), ':')==7)
        {
            vector<string> v = splitString(IP, ':');
            if(v.size()!=8)
                return false;
            
            for(auto s : v)
            {
                if(s.length()>4 || s.length() <1)
                    return false;
                for(auto ch : s)
                {
                    if((ch >= '0' && ch <='9') || (ch >='a' && ch <='f') || (ch >='A' && ch <='F'))
                        continue;
                    else
                        return false;
                }
            }
            return true;
        }
        return false;
    }    
};
