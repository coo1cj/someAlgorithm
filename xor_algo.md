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


Let's see something interesting !!
使用异或巧妙地交换数字，避免了生成temp临时变量

```
void exchange(int& a, int& b){
	if(a != b){  // 若相等那么会有问题
		a ^= b;  // a = a^b  
		b ^= a;  // b = b^a^b = a
		a ^= b;  // a = a^a^b = b
	}
}

```
