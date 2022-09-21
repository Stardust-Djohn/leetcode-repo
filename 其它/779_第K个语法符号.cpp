//从第二行开始，以每行都包含上一行，并且每行个数数量增倍
//前后两排序号2(n1)-1=(n2)相等，2(n)关系的数0/1相反，奇偶关系递推
//尝试tail recursive
class Solution {
public:
    int kthGrammar(int n, int k) {
        //base case
        if(n == 1 || k == 1) return 0;
        if(n == 2) return (k == 1) ? 0 : 1;
        //relation:k is odd or even?
        return (k & 1) ? kthGrammar(n-1, (k+1)/2) : 1-kthGrammar(n-1, k/2);
    }
};