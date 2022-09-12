class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1=version1.size(),len2=version2.size(),i=0,j=0,sum1=0,sum2=0;
        while(i<len1 || j<len2){
            sum1=0;
            while(i<len1 && version1[i]!='.'){
                sum1=sum1*10 + (version1[i++]-'0');
            }
            ++i;
            sum2=0;
            while(j<len2 && version2[j]!='.'){
                sum2=sum2*10 + (version2[j++]-'0');
            }
            ++j;
            if(sum1!=sum2) return (sum1>sum2)?1:-1;
        }
        return 0;
    }
};

//class Solution {
//public:
//    int calSum(int &id,string str){
//        int sum=0,len=str.size();
//        if(id==len){
//            return 0;
//        }
//        else{
//            if(str[id]=='.') id++;
//            while(str[id]!='.' && id!=len){
//            sum=sum*10+(str[id++]-'0');
//            }
//        }
//        return sum;
//    }
//    int compareVersion(string version1, string version2) {
//        //根据标点拆分数据
//        int sum1=0,sum2=0,i=0,j=0,ans=0;
//        this->len1=version1.size(),this->len2=version2.size();
//        while(i<len1 || j<len2){
//            sum1=calSum(i,version1);
//            sum2=calSum(j,version2);
//            //compare
//            if(sum1>sum2){
//                ans=1;
//                break;
//            }else if(sum1<sum2){
//                ans=-1;
//                break;
//            }
//            //reset
//            sum1=0,sum2=0;
//
//        }
//        return ans;
//    }
//private:
//    int len1,len2;
//};