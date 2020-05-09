[git文档](https://git-scm.com/book/zh/v2)



## 在Mac 安装Git

在 Mac 上安装 Git 有多种方式。 最简单的方法是安装 Xcode Command Line Tools。 Mavericks (10.9) 或 更高版本的系统中，在 Terminal 里尝试首次运行 git 命令即可。 

**完成后，可以使用Git来获取 Git的升级：**

```
$ git clone git://git.kernel.org/pub/scm/git/git.git
```



## 初次运行 Git 前的配置

#### `git config` 配置用户信息

```
$ git config --global user.name "John Doe"
$ git config --global user.email johndoe@example.com
```

 `--global` 表示在系统全局配置了用户信息。如果想针对特定项目使用不同的用户名称和邮箱地址，可以在目标目录下运行没有 `--global` 选项的命令来配置。

#### `git config --list` 检查配置信息

检查配置信息，列出所有 Git 当时能找到的配置。

还可以通过 `git config <key>`，来检查 Git 的某一项配置：

```
$ git config user.name
```

#### `git help` 查看帮助

三种方式获取 Git 帮助，找到 Git 命令的使用手册：

```
$ git help <verb>
$ git <verb> --help
$ man git-<verb>
```

获取 config 命令手册：

```
$ git help config
```



## 获取 Git 仓库

两种方法可创建 Git 项目。第一种是在现有的项目或目录下导入所有文件到 Git 中；第二种是从一个服务器克隆一个现有的 Git 仓库。

#### `git init` 在现有的目录中初始化仓库

使用 Git 对现有的项目进行管理，只需进入该项目目录并输入：

```
$ git init
```

该命令将创建一个名为 `.git` 的子目录，这个目录含有初始化 Git 仓库中所有的必要文件。同时，这只是一个初始化操作，项目里的文件并没有被跟踪。

如果是在一个已经存在文件的文件夹中初始化 Git 仓库来进行版本控制的话，应该跟踪这些文件并提交。

`git add` 跟踪指定文件，然后 `git commit` 提交：

```
$ git add *.c
$ git add LICENSE
$ git commit -m "initial project version"
```



#### `git clone` 克隆现有的仓库

使用 `git clone [url]` 命令，获得一份已经存在了的 Git 仓库的拷贝。Git 克隆的是该 Git 仓库服务器上的几乎所有数据，保罗每一个文件的每一个版本。

```
$ git clone https://github.com/libgit2/libgit2
```

这会在当前目录下创建一个名为 `libgit2` 的目录，并在这个目录下初始化一个 `.git` 文件夹，从远程仓库拉 取下所有数据放入 `.git` 文件夹，然后从中读取最新版本的文件的拷贝。 

如果想在克隆远程仓库的时候，自定义本地仓库的名字，可以使用如下命令: 

```
$ git clone https://github.com/libgit2/libgit2 mylibgit
```

这将执行与上一个命令相同的操作，不过在本地创建的仓库名字变为 `mylibgit`。 

Git 支持多种数据传输协议。 上面的例子使用的是 https:// 协议，也可以使用 git:// 协议或者使用 SSH 传输协议，比如 user@server:path/to/repo.git 。



## 记录每次更新到仓库

<img src="/Users/caianfang/Downloads/__github/note/Git/01文件的状态变化周期.png" alt="01 文件的状态变化周期" style="zoom:50%;" />



#### `git status` 检查当前文件状态

如果在克隆仓库后立即使用此命令，回看到类似的输出：

```
$ git status
On branch master
nothing to commit, working directory clean
```

这说明工作目录相当干净，所有已跟踪的文件都未被更改过。此外，还表明当前目录下没有处于未跟踪状态的新文件，否则 Git 会在这里列出来。最后，还显示了当前所在分支，告知我们这个分支同远程服务器上对应的分支没有偏离。`master` 是默认分支名。

现在，在项目下创建一个新的 README 文件。如果之前并不存在这个文件，使用 `git status` 命令，将会看到一个新的未跟踪文件：

```
$ echo `My project` > README
$ git status
On branch master
Untracked files:
(use "git add <file>..." to include in what will be committed) README
nothing added to commit but untracked files present (use "git add" to track)
```

可以看到新建的 README 文件出现在 Untracked files 下面。未跟踪的文件意味着 Git 在之前的快照(提交)中没有这些文件，Git 不会自动将之纳入跟踪范围。



#### `git add` 跟踪新文件

使用命令 `git add` 开始跟踪一个文件，要跟踪 README 文件，运行：

```
$ git add README
```

此时再运行 `git status` 命令，会看到 README 文件已经被跟踪，并处于暂存状态：

```
$ git status
On branch master
Changes to be committed:
(use "git reset HEAD <file>..." to unstage) new file: README
```

只要在 Changes to be committed 这行下面的，就说明是已暂存状态。 如果此时提交，那么该文件此时此刻的版本将被留存在历史记录中。注意：在使用 `git init` 后就运行 `git add (files)` 命令，就开始跟踪了当前目录下的文件。`git add` 命令使用文件或目录的路径作为参数，如果参数是目录的路径，该命令将递归地跟踪该目录下的所有文件。 



#### 暂存已修改文件 

现在修改一个名为 `CONTRIBUTING.md` 的已被跟踪的文件，然后运行 `git status` 命令，会看到下面内容: 

```
$ git status
On branch master
Changes to be committed:
	(use "git reset HEAD <file>..." to unstage) 
		new file: README
Changes not staged for commit:
	(use "git add <file>..." to update what will be committed) (use "git checkout -- <file>..." to discard changes in working directory)
		modified: CONTRIBUTING.md
```

文件 `CONTRIBUTING.md` 出现在 `Changes not staged for commit` 这行下面，说明已跟踪文件的内容发生了变化，但还没有放到暂存区。 要暂存这次更新，需要运行 `git add` 命令。 这是个多功能命令：可以用它开始跟踪新文件，或者把已跟踪的文件放到暂存区，还能用于合并时把有冲突的文件标记为已解决状态等。 将这个命令理解为“添加内容到下一次提交中”而不是“将一个文件添加到项目中”要更加合适。 现在运行 `git add` 将 `CONTRIBUTING.md` 放到暂存区，然后再看看 `git status` 的输出: 

```
$ git add CONTRIBUTING.md 
$ git status
On branch master
Changes to be committed:
	(use "git reset HEAD <file>..." to unstage)
		new file: README 
		modified: CONTRIBUTING.md
```

现在两个文件都已暂存，下次提交时就会一并记录到仓库。 假设此时，想要在 `CONTRIBUTING.md` 里再加条 注释， 重新编辑存盘后，准备好提交。 不过且慢，再运行 `git status` 看看: 

```
$ vim CONTRIBUTING.md
$ git status
On branch master
Changes to be committed:
	(use "git reset HEAD <file>..." to unstage)
		new file: README
    modified: CONTRIBUTING.md
Changes not staged for commit:
	(use "git add <file>..." to update what will be committed) (use "git checkout -- <file>..." to discard changes in working directory)
		modified: CONTRIBUTING.md
```

怎么回事? 现在 `CONTRIBUTING.md` 文件同时出现在暂存区和非暂存区。 这怎么可能呢? 好吧，实际上 Git 只不过暂存了你运行 `git add` 命令时的版本， 如果你现在提交，`CONTRIBUTING.md` 的版本是你最后一次运行` git add` 命令时的那个版本，而不是你运行 `git commit` 时，在工作目录中的当前版本。 所以，运行了 `git add` 之后又作了修订的文件，需要重新运行 `git add` 把最新版本重新暂存起来: 

```
$ git add CONTRIBUTING.md 
$ git status
On branch master
Changes to be committed:
	(use "git reset HEAD <file>..." to unstage)
		new file: README 
		modified: CONTRIBUTING.md
```



#### `git status -s` 状态简览

`git status` 命令的输出十分的详细，还可以使用 `git status -s` 命令或 `git status --short` 命令，可以得到更为紧凑的格式输出：

```
$ git status -s 
 M README
MM Rakefile
A  lib/git.rb
M  lib/simplegit.rb 
?? LICENSE.txt
```

`??` 标识新添加的未跟踪文件，`A` 标识新添加到暂存区中的文件，`M` 标识被修改过的文件。 出现在右边的 `M` 表示该文件被修改了但是还没放入暂存区，出现在靠左边的 `M` 表示该文件被修改了并放入了暂存区。



#### `.gitignore` 忽略文件 

一般我们总会有些文件无需纳入 Git 的管理，也不希望它们总出现在未跟踪文件列表。 通常都是些自动生成的文 件，比如日志文件，或者编译过程中创建的临时文件等。 在这种情况下，我们可以创建一个名为 `.gitignore` 的文件，列出要忽略的文件模式。 来看一个实际的例子: 

```
$ cat .gitignore
*.[oa]
*~
```

第一行告诉 Git 忽略所有以 `.o` 或 `.a` 结尾的文件。一般这类对象文件和存档文件都是编译过程中出现的。 第二行告诉 Git 忽略所有以波浪符 `~` 结尾的文件，许多文本编辑软件(比如 Emacs)都用这样的文件名保存副本。 此外，可能还需要忽略 `log`，`tmp` 或者 `pid` 目录，以及自动生成的文档等等。 要养成一开始就设置好 `.gitignore` 文件的习惯，以免将来误提交这类无用的文件。 

文件 `.gitignore` 的格式规范如下: 

​		• 所有空行或者以 `#` 开头的行都会被 Git 忽略。

​		• 可以使用标准的 `glob` 模式匹配。

​		• 匹配模式可以以 `/` 开头防止递归。

​		• 匹配模式可以以 `/` 结尾指定目录。

​		• 要忽略指定模式以外的文件或目录，可以在模式前加上惊叹号 `!` 取反。

所谓的 `glob` 模式是指 `shell` 所使用的简化了的正则表达式。 星号 `*` 匹配零个或多个任意字符；`[abc]` 匹配任何一个列在方括号中的字符(这个例子要么匹配一个 `a`，要么匹配一个 `b`，要么匹配一个 `c`)；问号 `?` 只匹配一个任意字符；如果在方括号中使用短划线分隔两个字符，表示所有在这两个字符范围内的都可以匹配 (比如 `[0-9]` 表示匹配所有 `0` 到 `9` 的数字)。 使用两个星号 `*` 表示匹配任意中间目录，比如 `a/**/z` 可以匹配 `a/z` , `a/b/z` 或 `a/b/c/z` 等。 



再看一个 `.gitignore` 文件的例子: 

```
# no .a files
*.a

# but do track lib.a, even though you're ignoring .a files above 
!lib.a

# only ignore the TODO file in the current directory, not subdir/TODO
/TODO

# ignore all files in the build/ directory
build/

# ignore doc/notes.txt, but not doc/server/arch.txt 
doc/*.txt

# ignore all .pdf files in the doc/ directory 
doc/**/*.pdf 
```

> GitHub 有一个十分详细的针对数十种项目及语言的 `.gitignore` 文件列表，可以在 https://github.com/github/gitignore 找到它. 



#### `git diff` 查看已暂存和未暂存的修改

如果 `git status` 命令的输出过于模糊，你想知道具体修改了什么地方，可以用 `git diff` 命令。 可能通常会用它来回答这两个问题：当前做的哪些更新还没有暂存？有哪些更新已经暂存起来准备好了下次提交？尽管 `git status` 已经通过在相应栏下列出文件名的方式回答了这个问题，`git diff` 将通过文件补丁的格式显示具体哪些行发生了改变。 

假如再次修改 `README` 文件后暂存，然后编辑 `CONTRIBUTING.md` 文件后先不暂存， 运行 `status` 命令将会看到: 

```
$ git status
On branch master
Changes to be committed:
	(use "git reset HEAD <file>..." to unstage) 
		modified: README
Changes not staged for commit:
(use "git add <file>..." to update what will be committed) (use "git checkout -- <file>..." to discard changes in working directory)
		modified: CONTRIBUTING.md
```

要查看尚未暂存的文件更新了哪些部分，不加参数直接输入 `git diff` ，此命令比较的是工作目录中当前文件和暂存区域快照之间的差异：

```
$ git diff
diff --git a/CONTRIBUTING.md b/CONTRIBUTING.md
index 8ebb991..643e24f 100644
--- a/CONTRIBUTING.md
+++ b/CONTRIBUTING.md
@@ -65,7 +65,8 @@ branch directly, things can get messy.
   Please include a nice description of your changes when you submit your
  PR;
if we have to read the whole diff to figure out why you're contributing
in the first place, you're less likely to get feedback and have your change
-merged in.
+merged in. Also, split your changes into comprehensive chunks if your patch is
+longer than a dozen lines.
   If you are starting to work on a particular area, feel free to submit a
  PR
that highlights your work in progress (and note in the PR title that it's
```

若要查看已暂存的将要添加到下次提交里的内容，可以用 `git diff --cached` 命令。(Git 1.6.1 及更高版本 还允许使用 `git diff --staged`，效果是相同的，但更好记些。) 

```
$ git diff --staged
diff --git a/README b/README 
new file mode 100644
index 0000000..03902a1
--- /dev/null
+++ b/README
@@ -0,0 +1 @@
+My Project
```

注意，`git diff` 本身只显示尚未暂存的改动，而不是自上次提交以来所做的所有改动。 所以有时候一下子暂存了所有更新过的文件后，运行 `git diff` 后却什么也没有，就是这个原因。 



#### `git commit` 提交更新 

现在的暂存区域已经准备妥当可以提交了。 在此之前，请一定要确认还有什么修改过的或新建的文件还没有 `git add` 过，否则提交的时候不会记录这些还没暂存起来的变化。 这些修改过的文件只保留在本地磁盘。 所 以，每次准备提交前，先用 `git status` 看下，是不是都已暂存起来了， 然后再运行提交命令 `git commit` ：

```
$ git commit
```

```
$ git commit -m "备注信息"
```



#### `git commit -a` 跳过使用暂存区域

尽管使用暂存区域的方式可以精心准备要提交的细节，但有时候这么做略显繁琐。 Git 提供了一个跳过使用暂存区域的方式， 只要在提交的时候，给 `git commit` 加上` -a` 选项，Git 就会自动把所有已经跟踪过的文件暂存 起来一并提交，从而跳过 `git add` 步骤: 

```
$ git commit -a -m 'added new benchmarks'
```



#### `git rm ` 移除文件

要从 Git 中移除某个文件，就必须要从已跟踪文件清单中移除(确切地说，是从暂存区域移除)，然后提交。 可以用 `git rm` 命令完成此项工作，并连带从工作目录中删除指定的文件，这样以后就不会出现在未跟踪文件清单中了。 

如果只是简单地从工作目录中手工删除文件，运行 `git status` 时就会在 “Changes not staged for commit” 部分(也就是 未暂存清单)看到: 

```
$ rm PROJECTS.md
$ git status
On branch master
Your branch is up-to-date with 'origin/master'. 
Changes not staged for commit:
	(use "git add/rm <file>..." to update what will be committed)
	(use "git checkout -- <file>..." to discard changes in working directory)
		deleted: PROJECTS.md
no changes added to commit (use "git add" and/or "git commit -a")
```

然后再运行 `git rm` 记录此次移除文件的操作: 

```
$ git rm PROJECTS.md
rm 'PROJECTS.md'
$ git status
On branch master
Changes to be committed:
	(use "git reset HEAD <file>..." to unstage) 
		deleted: PROJECTS.md
```

下一次提交时，该文件就不再纳入版本管理了。 如果删除之前修改过并且已经放到暂存区域的话，则必须要用 强制删除选项 `-f` (译注:即 force 的首字母)。 这是一种安全特性，用于防止误删还没有添加到快照的数据， 这样的数据不能被 Git 恢复。 



另外一种情况是，我们想把文件从 Git 仓库中删除(亦即从暂存区域移除)，但仍然希望保留在当前工作目录中。 换句话说，你想让文件保留在磁盘，但是并不想让 Git 继续跟踪。 当你忘记添加 `.gitignore` 文件，不小心把一个很大的日志文件或一堆 `.a` 这样的编译生成文件添加到暂存区时，这一做法尤其有用。 为达到这一目的，使用 `--cached` 选项: 

```
$ git rm --cached README
```

`git rm` 命令后面可以列出文件或者目录的名字，也可以使用glob模式。比方说: 

```
$ git rm log/\*.log
```

注意到星号 `*` 之前的反斜杠 `\`， 因为 Git 有它自己的文件模式扩展匹配方式，所以我们不用 shell 来帮忙展开。 此命令删除 `log/` 目录下扩展名为 `.log` 的所有文件。 类似的比如: 

```
$ git rm \*~
```

该命令为删除以 `~` 结尾的所有文件。 



#### `git mv` 移动文件

不像其它的 VCS 系统，Git 并不显式跟踪文件移动操作。 如果在 Git 中重命名了某个文件，仓库中存储的元数 据并不会体现出这是一次改名操作。

既然如此，当你看到 Git 的 `mv` 命令时一定会困惑不已。 要在 Git 中对文件改名，可以这么做: 

```
$ git mv file_from file_to
```

它会恰如预期般正常工作。 实际上，即便此时查看状态信息，也会明白无误地看到关于重命名操作的说明: 

```
$ git mv README.md README $ git status
On branch master
Changes to be committed:
	(use "git reset HEAD <file>..." to unstage) 
		renamed: README.md -> README
```

其实，运行 `git mv` 就相当于运行了下面三条命令: 

```
$ mv README.md README 
$ git rm README.md
$ git add README
```

如此分开操作，Git 也会意识到这是一次改名，所以不管何种方式结果都一样。 两者唯一的区别是，`mv` 是一条 命令而另一种方式需要三条命令，直接用 `git mv` 轻便得多。 不过有时候用其他工具批处理改名的话，要记得在提交前删除老的文件名，再添加新的文件名。 



## 查看提交历史 

克隆一个项目来练习 `git log`

```
$ git clone https://github.com/schacon/simplegit-progit
```

列出所有更新记录

```
$ git log
```

`-p` 用来显示每次提交的内容差异，`-2` 显示最近两次提交: 

```
$ git log -p -2
```

该选项除了显示基本信息之外，还附带了每次 commit 的变化。 当进行代码审查，或者快速浏览某个搭档提交的 commit 所带来的变化的时候，这个参数就非常有用了。

`--stat` 可以为 `git log` 附带一系列的总结性选项， 比如想看到每次提交的简略的统计信息：

```
$ git log --stat
```

`--stat` 选项在每次提交的下面列出所有被修改过的文件、有多少文件被修改了以及被修改过的文件的哪些行被移除或是添加了。 在每次提交的最后还有一个总结。 

`--pretty` ，可以指定使用不同于默认格式的方式展示提交历史。 这个选项有一些内建的子选项供你使用。 比如用 `oneline` 将每个提交放在一行显示，查看的提交数很大时非常有用。 另外还有 `short`，`full` 和 `fuller` 可以用，展示的信息或多或少有些不同。 

```
$ git log --pretty=oneline
```

但最有意思的是 `format`，可以定制要显示的记录格式: 

```
$ git log --pretty=format:"%h - %an, %ar : %s"
```

`git log --pretty=format` 常用的选项列出了常用的格式占位符写法及其代表的意义。 

**Table 1. git log --pretty=format 常用的选项：**

| 选项 | 说明                                      |
| ---- | ----------------------------------------- |
| %H   | 提交对象（commit）的完整哈希字串          |
| %h   | 提交对象的简短哈希字串                    |
| %T   | 树对象（tree）的完整哈希字串              |
| %t   | 树对象的简短哈希字串                      |
| %P   | 父对象（parent）的完整哈希字串            |
| %p   | 父对象的简短哈希字串                      |
| %an  | 作者（author）的名字                      |
| %ae  | 作者的电子邮件地址                        |
| %ad  | 作者修订日期(可以用 --date= 选项定制格式) |
| %ar  | 作者修订日期，按多久以前的方式显示        |
| %cn  | 提交者(committer)的名字                   |
| %ce  | 提交者的电子邮件地址                      |
| %cd  | 提交日期                                  |
| %cr  | 提交日期，按多久以前的方式显示            |
| %s   | 提交说明                                  |

当 `oneline` 或 `format` 与另一个 `log` 选项 `--graph` 结合使用时尤其有用。 这个选项添加了一些 `ASCII` 字符串来形象地展示你的分支、合并历史: 

```
$ git log --pretty=format:"%h %s" --graph
* 2d3acf9 ignore errors from SIGCHLD on trap
* 5e3ee11 Merge branch 'master' of git://github.com/dustin/grit |\
| * 420eac9 Added a method for getting the current branch.
* | 30e367c timeout code and tests
* | 5a09431 add timeout protection to grit
* | e1193f8 support for heads with slashes in them
|/
* d6016bc require time for xmlschema
* 11d191e Merge branch 'defunkt' into local
```

以上只是简单介绍了一些git log命令支持的选项。git log的常用选项列出了我们目前涉及到的和没涉及到的选项，以及它们是如何影响 log 命令的输出的: 

**Table 2. git log 的常用选项：**

| 选项            | 说明                                                         |
| --------------- | ------------------------------------------------------------ |
| -p              | 按补丁格式显示每个更新之间的差异。                           |
| --stat          | 显示每次更新的文件修改统计信息。                             |
| --shortstat     | 只显示 --stat 中最后的行数修改添加移除统计。                 |
| --name-only     | 仅在提交信息后显示已修改的文件清单。                         |
| --name-status   | 显示新增、修改、删除的文件清单。                             |
| --abbrev-commit | 仅显示 SHA-1 的前几个字符，而非所有的 40 个字符。            |
| --relative-date | 使用较短的相对时间显示(比如，“2 weeks ago”)。                |
| --graph         | 显示 ASCII 图形表示的分支合并历史。                          |
| --pretty        | 使用其他格式显示历史提交信息。可用的选项包括 oneline，short，full，fuller 和 format(后跟指定格式)。 |



#### 限制输出长度 

`-<n>` 只显示最近提交的条数，另外还有按照时间作限制的选项 `--since` 和 `--until`。 例如，下面的命令列出所有最近两周 内的提交: 

```
$ git log --since=2.weeks
```

这个命令可以在多种格式下工作，比如说具体的某一天 `2008-01-15` ，或者是相对地多久以前 `2 years 1 day 3 minutes ago`。 

还可以给出若干搜索条件，列出符合的提交。 用 `--author` 选项显示指定作者的提交，用 `--grep` 选项搜索提 交说明中的关键字。 (请注意，如果要得到同时满足这两个选项搜索条件的提交，就必须用 `--all-match` 选项。否则，满足任意一个条件的提交都会被匹配出来) 

另一个非常有用的筛选选项是 `-S`，可以列出那些添加或移除了某些字符串的提交。 比如想找出添加或移除了某一个特定函数的引用的提交: 

```
$ git log -Sfunction_name
```

最后一个很实用的 `git log` 选项是路径(path)， 如果只关心某些文件或者目录的历史提交，可以在 `git log` 选项的最后指定它们的路径。 因为是放在最后位置上的选项，所以用两个短划线 (--) 隔开之前的选项和后面限定的路径名。 

**Table 3. 限制 git log 输出的选项：**

| 选项              | 说明                               |
| ----------------- | ---------------------------------- |
| -(n)              | 仅显示最近的 n 条提交              |
| --since, --after  | 仅显示指定时间之后的提交           |
| --until, --before | 仅显示指定时间之前的提交           |
| --author          | 仅显示指定作者相关的提交           |
| --committer       | 仅显示指定提交者相关的提交         |
| --grep            | 仅显示含指定关键字的提交           |
| -S                | 仅显示添加或移除了某个关键字的提交 |

来看一个实际的例子，如果要查看 Git 仓库中，2008 年 10 月期间，Junio Hamano 提交的但未合并的测试文 件，可以用下面的查询命令: 

```
$ git log --pretty="%h - %s" --author=gitster --since="2008-10-01" --before="2008-11-01" --no-merges -- t/

5610e3b - Fix testcase failure when extended attributes are in use acd3b9e - Enhance hold_lock_file_for_{update,append}() API
f563754 - demonstrate breakage of detached checkout with symbolic link HEAD
d1a43f2 - reset --hard/read-tree --reset -u: remove unmerged new paths 51a94af - Fix "checkout --track -b newbranch" on detached HEAD
b0ad11e - pull: allow "git pull origin $something:$current_branch" into an unborn branch
```

在近 40000 条提交中，上面的输出仅列出了符合条件的 6 条记录。 



## 撤消操作 

在任何一个阶段，你都有可能想要撤消某些操作。 注意，有些撤消操作是不可逆的。 这是在使用 Git 的过程中，会因为操作失误而导致之前的工作丢失的少有的几个地方之一。 

有时候我们提交完了才发现漏掉了几个文件没有添加，或者提交信息写错了。 此时，可以运行带有 `--amend` 选项的提交命令尝试重新提交: 

```
% git commit --amend
```

这个命令会将暂存区中的文件提交。 如果自上次提交以来还未做任何修改(例如，在上次提交后马上执行了此命令)，那么快照会保持不变，所修改的只是提交信息。 

文本编辑器启动后，可以看到之前的提交信息。 编辑后保存会覆盖原来的提交信息。 

例如，你提交后发现忘记了暂存某些需要的修改，可以像下面这样操作: 

```
$ git commit -m 'initial commit' 
$ git add forgotten_file
$ git commit --amend
```

最终你只会有一个提交——第二次提交将代替第一次提交的结果。 



#### 取消暂存的文件 

接下来的两个小节演示如何操作暂存区域与工作目录中已修改的文件。 这些命令在修改文件状态的同时，也会 提示如何撤消操作。 例如，你已经修改了两个文件并且想要将它们作为两次独立的修改提交，但是却意外地输 入了 git add * 暂存了它们两个。 如何只取消暂存两个中的一个呢? git status 命令提示了你: 

```
$ git add *
$ git status
On branch master
Changes to be committed:
(use "git reset HEAD <file>..." to unstage)
		renamed: README.md -> README
    modified: CONTRIBUTING.md
```

在 “Changes to be committed” 文字正下方，提示使用 `git reset HEAD <file>...` 来取消暂存。 所 以，我们可以这样来取消暂存 `CONTRIBUTING.md` 文件: 

```
$ git reset HEAD CONTRIBUTING.md
Unstaged changes after reset:
M CONTRIBUTING.md
```

这个命令有点儿奇怪，但是起作用了。`CONTRIBUTING.md` 文件已经是修改未暂存的状态了。 

>  NOTE 虽然在调用时加上 `--hard` 选项可以令 `git reset` 成为一个危险的命令(译注:可能导致工作目录中所有当前进度丢失!)。 不加选项地调用 `git reset` 并不危险—它只会修改暂存区域。



#### 撤消对文件的修改 

如果你并不想保留对 `CONTRIBUTING.md` 文件的修改怎么办? 你该如何方便地撤消修改——将它还原成上次提交时的样子(或者刚克隆完的样子，或者刚把它放入工作目录时的样子)?幸运的是，git status也告诉了 你应该如何做。 在最后一个例子中，未暂存区域是这样: 

```
Changes not staged for commit:
	(use "git add <file>..." to update what will be committed) 
	(use "git checkout -- <file>..." to discard changes in working directory)
		modified: CONTRIBUTING.md
```

它非常清楚地告诉了你如何撤消之前所做的修改。 让我们来按照提示执行: 

```
$ git checkout -- CONTRIBUTING.md 
$ git status
On branch master
Changes to be committed:
	(use "git reset HEAD <file>..." to unstage) 
		renamed: README.md -> README
```

可以看到那些修改已经被撤消了。 

>  `git checkout -- [file]` 是一个危险的命令，这很重要。对那个文件做的任何修改都会消失——只是拷贝了另一个文件来覆盖它。 除非确实清楚不想要那个文件了，否则不要使用这个命令。 

记住，在 Git 中任何已提交的东西几乎总是可以恢复的。 甚至那些被删除的分支中的提交或使用 `--amend` 选项覆盖的提交也可以恢复。 然而，任何未提交的东西丢失后很可能再也找不到了。 



## 远程仓库的使用 



