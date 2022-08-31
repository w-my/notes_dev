# JavaWeb - Maven

Maven 是一个项目管理工具，它包含了一个项目对象模型 (POM:Project Object Model)，一组标准集合，一个项目生命周期(Project Lifecycle)，一个依赖管理系统 (Dependency Management System)，和用来运行定义在生命周期阶段(phase)中插件(plugin)目标(goal)的逻辑。

## Maven 作用

构建工程，管理 jar 包，编译代码，自动运行单元测试，打包，生成报表，部署项目，生成 Web 站点...

### 依赖管理

maven 工程不直接将 jar 包导入到工程中，而是通过 `pom.xml` 文件添加所需 jar 包的坐标，用一个 maven 仓库统一管理 jar 包。

### 构建项目

maven 将项目构建的过程进行标准化，每个阶段使用一个命令完成。

> 清理  ->  编译  ->  测试  ->  报告  ->  打包  -> 部署

运行：`tomcat:run`



## Maven 使用

### Maven 安装

[maven下载页面](https://maven.apache.org/download.cgi)

[ apache-maven-3.8.1-bin.zip](https://mirrors.bfsu.edu.cn/apache/maven/maven-3/3.8.1/binaries/apache-maven-3.8.1-bin.zip)

下载好后解压，文件目录如下：

> bin: 存放了 maven 的命令，比如我们前面用到的 `mvn tomcat:run`
>
> boot: 存放了一些 maven 本身的引导程序，如类加载器等 
>
> conf: 存放了 maven 的一些配置文件，如 `setting.xml` 文件 
>
> lib: 存放了 maven 本身运行所需的一些 jar 包

至此 maven 软件就可以使用了，前提是电脑上之前已经安装并配置好了 JDK。

### Maven 仓库

##### 仓库的分类

###### 本地仓库

> 用来存储从远程仓库或中央仓库下载的插件和 jar 包，项目使用一些插件或 jar 包， 优先从本地仓库查找。
>
> 默认本地仓库位置在 `${user.dir}/.m2/repository`，`${user.dir}` 表示windows用户目录。

###### 远程仓库

> 如果本地需要插件或者 jar 包，本地仓库没有，默认去远程仓库下载。 远程仓库可以在互联网内也可以在局域网内。

###### 中央仓库

> 在 maven 软件中内置一个远程仓库地址 http://repo1.maven.org/maven2 ，它是中 央仓库，服务于整个互联网，它是由 Maven 团队自己维护，里面存储了非常全的 jar 包，它包含了世界上大部分流行的开源项目构件。

##### 本地仓库配置

1. 将 jar 包放置在一个目录下
2. 配置 `MAVE_HOME/conf/settings.xml` 文件 `<localRespository>jar包目录</localRespository>`

##### 全局 setting 与用户 setting

`conf/setting.xml` 文件用于 maven 的所有 project 项目，它作为 maven 的全局配置。

个性配置需要在用户配置中设置，用户配置的 `setting.xml` 文件默认在： `${user.dir}/.m2/setting.xml` 目录中，`${user.dir}` 指 windows 中的用户目录。

maven 会先找用户配置，找不到则使用全局配置文件。

### Maven 工程

#### Maven 工程目录结构

- .settings  工具生成的文件
- src - 源代码
  - main 
    - java - 放项目的源码
    - resources - 配置文件
    - webapp - 页面素材
  - test
    - java - 测试远吗
    - resources - 测试配置文件
- target - 编译生成的文件
- .classpath
- .project
- .tern-project
- pom.xml - maven工程的配置文件，如jar包坐标信息

> 普通java项目，没有 webapp 目录。

#### Maven 工程的运行

进入 maven 工程目录，运行 tomcat:run 命令。



## Maven 常用命令

### compile

`mvn compile` 是 maven 工程的编译命令，作用是将 src/main/java 下的文件编译为 class 文件输出到 target 目录下。

### test

`mvn test` 是 maven 工程的测试命令，会执行 src/test/java 下的单元测试类。

### clean

`mvn clean` 是 maven 工程的清理命令，执行 clean 会删除 target 目录及内容。

### package

`mvn package` 是 maven 工程的打包命令，对于 java 工程执行 package 打成 jar 包，对于 web 工程打成 war 包。

### install

`mvn install` 是 maven 工程的安装命令，执行 install 将 maven 打成 jar 包或 war 包发布到本地仓库。 

从运行结果中，可以看出：当后面的命令执行时，前面的操作过程也都会自动执行。

### Maven 指令的生命周期

`Clean Lifecycle` 在进行真正的构建之前进行一些清理工作。 

`Default Lifecycle` 构建的核心部分，编译，测试，打包，部署等等。 

`Site Lifecycle` 生成项目报告，站点，发布站点。

### maven 的概念模型

Maven 包含了一个项目对象模型 (Project Object Model)，一组标准集合，一个项目生命周期(Project Lifecycle)，一个依赖管理系统(Dependency Management System)，和用来运行定义在生命周期阶段 (phase)中插件(plugin)目标(goal)的逻辑。

- 项目对象模型 (Project Object Model)

一个 maven 工程都有一个 pom.xml 文件，通过 pom.xml 文件定义项目的坐标、项目依赖、项目信息、 插件目标等。

- 依赖管理系统(Dependency Management System)

通过maven的依赖管理对项目所依赖的jar 包进行统一管理。

- 一个项目生命周期(Project Lifecycle)

使用 maven 完成项目的构建，项目构建包括:清理、编译、测试、部署等过程，maven 将这些过程规范为一个生命周期，如下所示是生命周期的各各阶段:

> 清理 -> 编译 -> 测试 -> 报告 -> 打包 -> 部署

maven 通过执行一些简单命令即可实现上边生命周期的各各过程，比如执行 `mvn compile` 执行编译、执行 `mvn clean` 执行清理。

- 一组标准集合

maven 将整个项目管理过程定义一组标准，比如:通过 maven 构建工程有标准的目录结构，有标准的生命周期阶段、依赖管理有标准的坐标定义等。

- 插件(plugin)目标(goal)

maven 管理项目生命周期过程都是基于插件完成的。



## IDEA 开发 Maven 项目

### IDEA 的 Maven 配置

#### 配置 Maven 路径

Preferences -> Build, Execution, Deployment -> Build Tools -> Maven

- Maven home directory ：指定本地 maven 安装目录
- User setting file ：指定 settings 配置文件路径
- Local responsitory ：自动检测本地仓库位置

#### IDEA 创建 Maven 的 web 工程

New Project -> Maven -> 勾选 Create from archetype -> 选择 maven-archetype-webapp -> next



## pom 基本配置
在 `pom.xml` 中定义坐标，内容包括:groupId、artifactId、version，详细内容如下:

```xml
<!--项目名称，定义为组织名+项目名，类似包名--> 
<groupId>cn.xxx.maven</groupId>
<!-- 模块名称 -->
<artifactId>maven-first</artifactId>
<!-- 当前项目版本号，snapshot为快照版本即非正式版本，release为正式发布版本 --> 
<version>0.0.1-SNAPSHOT</version>
<packaging > :打包类型
		jar:执行 package 会打成 jar 包
		war:执行 package 会打成 war 包
		pom :用于 maven 工程的继承，通常父工程设置为 pom
```

 `pom.xml` 是 Maven 项目的核心配置文件，位于每个工程的根目录，基本配置如下:

```xml
<project > :文件的根节点
<modelversion > : pom.xml 使用的对象模型版本
<groupId > :项目名称，一般写项目的域名
<artifactId > :模块名称，子项目名或模块名称
<version > :产品的版本号
<packaging > :打包类型，一般有 jar、war、pom 等 
<name > :项目的显示名，常用于 Maven 生成的文档。 
<description > :项目描述，常用于 Maven 生成的文档 
<dependencies> :项目依赖构件配置，配置项目依赖构件的坐标 
<build> :项目构建配置，配置编译、运行插件等。
```



