首先要判断有没有安装git
```
git
```
没有则出现如下提示
```
The program 'git' is currently not installed. You can install it by typing:
```
使用下面的命令进行安装git工具.
```
sudo apt-get install git
```


## 写一个大概流程

### 第一步
创建一个本地文件 设置为git仓库
```linux
  mkdir ck
  cd ck
  git init
```
### 第二步
创建文件 并进行提交 设置默认编辑器为 vim
```touch README
im README
git status
git add README
git commit 
git config --global user.name  "自己的姓名"
git config --global user.email “自己邮件”
git config --global core.editor vim
git commit 
```
然后可以查看自己信息
```
git log
git status
```
### 第三步 添加远程仓库
```
git remote add origin https://github.com/wangleihd/h5class.git
```
### 第四部 向远程仓库提交
```
$ git push origin master
$ git push origin branch-name
```
### 第五步 从远程仓库更新到本地
```
git pull origin master
```
