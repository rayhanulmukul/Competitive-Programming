if((s[i] >= 'i' and s[i] <= 'n') or (s[i] >= 'I' and s[i] <= 'N')){
            int j = i;
            for(j = i+1; j < n; j++){
                if((s[j] >= 'a' && s[j] <= 'z') or (s[j] >= 'A' && s[j] <= 'Z') or (s[j] >= '0' && s[j] <= '9')) continue;
                else{
                    dbg(s[j]);
                    cout << "Invalid Input or Undefined" << en;
                    return;
                }
            }
            cout << s << " = " << "Integer Variable" << en;
            return;
        }