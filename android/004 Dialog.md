## Dialog

#### 普通对话框

```java
AlertDialog.Builder builder = new AlertDialog.Builder(this);
builder.setTitle("提示");
builder.setMessage("没有网络");
builder.setPositiveButton("确定", new DialogInterface.OnClickListener() {
    @Override
    public void onClick(DialogInterface dialog, int which) {
        System.out.println("点击了 确定");
    }
});
builder.setNegativeButton("取消", new DialogInterface.OnClickListener() {
    @Override
    public void onClick(DialogInterface dialog, int which) {
        System.out.println("点击了 取消");
    }
});
builder.show();
```



#### 单选对话框

```java
final String[] items = {"iOS", "Android", "C++", "Java"};
AlertDialog.Builder builder = new AlertDialog.Builder(this);
builder.setTitle("请选择");
builder.setSingleChoiceItems(items, -1, new DialogInterface.OnClickListener() {
    @Override
    public void onClick(DialogInterface dialog, int which) {
        System.out.println("选中了 " + items[which]);
        dialog.dismiss();
    }
});
builder.show();
```



#### 多选对话框

```java
final String[] items = {"草莓", "猕猴桃", "香蕉", "无花果", "人参果"};
final boolean[] checkItems = {true, false, false, false, false};

AlertDialog.Builder builder = new AlertDialog.Builder(this);
builder.setTitle("请选择");
builder.setMultiChoiceItems(items, checkItems, new DialogInterface.OnMultiChoiceClickListener() {
    @Override
    public void onClick(DialogInterface dialog, int which, boolean isChecked) {
        checkItems[which] = isChecked;
    }
});
builder.setPositiveButton("确定", new DialogInterface.OnClickListener() {
    @Override
    public void onClick(DialogInterface dialog, int which) {
        System.out.println("结果: " + checkItems[0] + checkItems[1]
                + checkItems[2] + checkItems[3] + checkItems[4]);
    }
});
builder.show();
```



#### 进度条对话框

```java
final ProgressDialog dialog = new ProgressDialog(this);
dialog.setTitle("玩命加载中...");
dialog.setProgressStyle(ProgressDialog.STYLE_HORIZONTAL);
dialog.setMax(100);
dialog.show();

new Thread(){
    @Override
    public void run() {
        for (int i = 0; i <= dialog.getMax(); i++) {
            // 与进度相关的控件，可以在子线程直接更新UI
            dialog.setProgress(i);
            SystemClock.sleep(20);
        }
        dialog.dismiss();
    }
}.start();
```

