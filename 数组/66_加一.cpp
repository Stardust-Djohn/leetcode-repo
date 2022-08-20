class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        int flag;
        if(++digits[len-1]>9){
            flag=1;
            digits[len-1]=0;
        }else return digits;
        
        for(int i=len-2;i>=0;i--){
            if(digits[i]==9 && flag==1){
                digits[i]=0;
            }else if(flag==1){
                digits[i]++;
                flag=0;
                break;
            }
        }
        if(flag==1){
            digits.insert(digits.begin(),1);
        }

        return digits;


    }
};

/*
        int sum=0;
        int len=digits.size();
        vector<int> ans;
        for(int i=0;i<len;i++){
            sum=sum*10+digits[i];
        }
        sum++;
        while(sum!=0){
            int temp=sum%10;
            sum/=10;
            ans.push_back(temp);
        }
        int len2=ans.size();
        for(int i=0;i<len2-1-i;i++){
            ans[i]^=ans[len2-1-i];
            ans[len2-1-i]^=ans[i];
            ans[i]^=ans[len2-1-i];
        }
        return ans;
    */