class Solution{
private:
    int MOD=1000000;
public:
    int repeatedStringMatch(string a,string b){
        if(a==b)
            return 1;
        int repeatCount=1;
        string repeatedString=a;
        while(repeatedString.size()<b.size()){
            repeatCount++;
            repeatedString+=a;
        }
        if(repeatedString==b)
            return repeatCount;
        if(rabinKarp(repeatedString,b)!=-1)
           return repeatCount;
        if(rabinKarp(repeatedString+a,b)!=-1)
            return repeatCount+1;
        return -1;
    }

    int rabinKarp(string text,string pattern){
        if(text==""||pattern=="")
            return -1;

        int patternLength=pattern.size();
        int power=1;

        for(int i=0;i<patternLength;i++)
            power=(power*31)%MOD;

        int patternHash=0;
        for(int i=0;i<patternLength;i++)
            patternHash=(patternHash*31+pattern[i])%MOD;

        int windowHash=0;

        for(int i=0;i<text.size();i++){
            windowHash=(windowHash*31+text[i])%MOD;

            if(i<patternLength-1)
                continue;

            if(i>=patternLength)
                windowHash=(windowHash-text[i-patternLength]*power)%MOD;

            if(windowHash<0)
                windowHash+=MOD;

            if(windowHash==patternHash){
                if(text.substr(i-patternLength+1,patternLength)==pattern)
                    return i-patternLength+1;
            }
        }

        return -1;
    }
};