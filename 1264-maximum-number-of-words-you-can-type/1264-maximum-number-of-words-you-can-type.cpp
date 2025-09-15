class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> ch(26,0);
        for(char c: brokenLetters){
            ch[c-'a']=1;
        }
        int cnt=0,ans=0;
        for(int i=0;i<text.length();i++){
            if(text[i]==' '){
                if(cnt==0) ans++;
                cnt=0;
            }else if(ch[text[i]-'a']==1){
                    cnt++;
            }
        }
        if(cnt==0) ans++;
        return ans;
    }
};