class Solution {
public:
    int transform (int num) {
        string ck = to_string(num);
        for (int i = 0; i < ck.size(); i++) {
            switch (ck[i]){
                case '0':
                case '1':
                case '8':
                    break;
                case '2':
                    ck[i] = '5';
                    break;
                case '5':
                    ck[i] = '2';
                    break;
                case '6':
                    ck[i] = '9';
                    break;
                case '9':
                    ck[i] = '6';
                    break;
                default:
                    return -1;
            }

        }
        return stoi(ck);
    }

    int rotatedDigits(int n) {
        // 规律：数位必须包含1、2、5、6、9、0
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            // 检查并转换
            int tmp = transform(i);
            if (tmp != -1 && tmp != i) ans++;
        }
        return ans;
    }
};