class Longest_Palindromic_Substring {

    /*giving a string return the longest substrinvg
    input : azebezkk
    output: zebez
    
    input : tbesseblppm
    output: besseb
    */

public:
    /*
    azebezkk
    the longest substring in this case is an odd palandrom with a length = 5
    when i index of longestPalindrome function equals to 3 and l2=3 and r2=3
    the pointers l and r will expand to the right and left while the string is palandromic
    and finally we will get the length of the palandromic string by calculating length = r -l +1
    the substring that we will get is : zebez and ans = 5;

    same for the even case tbesseblppm
    when i=3 =>l1=3 and r2=4
    and while we have a palandromic substring the l and r pointers will expand  
    */
    int propagation(string s,int *l,int *r){
        int n=s.size() , ans=1;
        while((*l) >=0 && (*r)<n && s[*l]==s[*r])
        {
            ans = (*r)-(*l)+1;
            (*r)++;
            (*l)--;
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int n=s.size(),l=0,r=0;
        string ans="";
        int maxLength = 0;
        if(s.size()==1){
            return s;
        }
        if(s==""){
            return s;
        }
        for(int i=0;i<n-1;i++)
        {
            //if odd
                int l1 =i;
                int r1 =i;
                int len1 = propagation(s,&l1,&r1);
            //if even
                int l2 =i;
                int r2 =i+1;
                int len2 = propagation(s,&l2,&r2);


            //select the right palindrom 

            /*we will save each time the longest substring*/
            if(maxLength< max(len1 , len2)){
                if(len1>len2){
                    maxLength=len1;
                    ans = s.substr(l1+1,len1);
                }else{
                    maxLength = len2;
                    ans = s.substr(l2+1,len2);
                }
            }
        }
        return ans;
    }
};