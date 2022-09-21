class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
		int count = 0,len = arr.size(),i = 0;
		while(i + count < len) {
			if(arr[i++] == 0) count++;
		}
		// 因为循环中i自增到了下一个值，此处i--返回到上一个结束值
		i--;
		int j = len - 1;
		// 特别需要注意的是：若最后一个数字是0，统计需要复制的0时统计了该数，但数组可能越界
		// 此处+1判断，如果越界，则只复制本身
		if(count + i + 1 > len) {
			arr[j--] = arr[i--];
			count--;
		}
		// 遇0则复制两次，非0则复制本身
		// count<=0时，说明前面没有0了，保持不变就行
		while(count > 0) {
			arr[j--] = arr[i];
			if(arr[i] == 0) {
				arr[j--] = arr[i];
				count--;
			}
			i--;
		}

    }
};