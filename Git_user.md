# 写一个github 仓库的使用
### 第一步 你需要有自己的一个文件夹（创建一个ck的文件夹）：
````
 mkdir ck
````
### 第二步 初始化git
```
  git init 
```
### 第三步 可以新建一个文件进行提交
```
  vim hello.c
```
编辑hello.c

```c
#include <stdio.h>

int main(){
	printf("123456789 \n");
	printf("我做了修改 \n");
	printf("修改了用户名和邮件\n");
	return 0;
}

```
在命令行输入 :wq 保存退出

### 第四部 
在git的仓库目录 的命令行输入：
````
git add .
````
```
git commit 
```
会出现提交失败 
需要输入配置用户信息
配置用户名
```
git config --global user.name
```
配置用户邮箱
```
git config --global user.email
```
配置编辑提交信息的编辑器, 我们熟悉的编辑器是vim.
```
git config --global core.editor vim
```
查看提交信息
```
git log
```
完成配置。

### 第五步 添加远程仓库
```
git remote add origin https://github.com/wangleihd/h5class.git
```

### 第六步 向远程仓库提交
```
git push origin master
```
到此完成提交

### 加入远程仓库被修改 我们可以用把 被修改的文件同步到本地仓库 
```
git pull origin master
```



