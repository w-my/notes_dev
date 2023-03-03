# .bash_profile

- ～/.bash_profile 配置环境变量失效问题解决

**分析问题：**

当我们在 ~/.bash_profile 中配置环境变量, 但每次在IDE或者终端，重新开启新的窗口或者重启终端后，配置的环境变量都不生效了，还需要重新执行以下命令才会重新生效:

```sh
source ~/.bash_profile
```

**问题原因：**

1. 我们是在bash中配置的环境变量，而当前系统是使用的是shell。
2. 查看当前使用的shell：

```sh
echo $SHELL
```

输出是 `/bin/zsh`， 说明使用的是 zsh

**解决方法：**

.zshrc文件加中添加source ~/.bash_profile

```sh
cd ~
ls -a
```

`i` 编辑，添加：

```sh
source ~/.bash_profile

```

```sh
:wq
```

# vim 命令

MAC 终端编辑完成后如何保存
 如果是vi，则：输入 `i` 表示开始输入，`Esc` 退出编辑模式，输入以下命令：
 :wq 保存后退出vi，若为:wq!则为强制储存后退出（常用）
 :w 保存但不退出（常用）
 :w! 若文件属性为『只读』时，强制写入该档案
 :q 离开 vi （常用）
 :q! 若曾修改过档案，又不想储存，使用!为强制离开不储存档案。
 :e! 将档案还原到最原始的状态！



# 



