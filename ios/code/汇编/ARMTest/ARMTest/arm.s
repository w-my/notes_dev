
.text  ;声明代码段
.global _test, _add ,_sub  ;声明为全局可访问

_test:  ;test 函数的实现
mov x0, #0x8  ; 最好前面加一个# 不加系统也会默认加
ret  ; 函数返回 return

;add 指令
mov x0, #0x1

