## 问题描述： 在一个包含一个不重复数和其他全是重复两次的数组中找到不重复的那个数

例如： arr = { 1, 2, 3, 5, 5, 3, 1,1001, 1001, 2, 9 } 中找到 9


#### 方法1： 异或
```
int xor(int arr[], int size) {
	int res = arr[0];
	for (int i = 1; i < size; ++i) {
		res ^= arr[i];
	}
	return res;
}
```
