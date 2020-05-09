## Activity

##### 四种启动模式

`stander` ：默认模式，出入栈

`singletop` ：如果栈顶存在这个要开启的Activity，则不会重新创建Activity

`singletask` ：如果栈中存在此Activity，则不再新创建Activity，并把此Activity放于栈顶，保证栈里只有一个该实例

`singleinstance` ：单独创建任务栈存放此Activity，并栈中仅有一个此Activity，不会创建多次