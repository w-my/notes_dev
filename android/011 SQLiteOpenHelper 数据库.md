## SQLiteOpenHelper 数据库

#### 数据库基本操作

1、创建数据库类

```java
public class MyOpenHelper extends SQLiteOpenHelper {
    public MyOpenHelper(Context context) {
        super(context, "Account.db", null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("create table info(_id integer primary key autoincrement, name varchar(20),money varchar(20))");
        db.execSQL("insert into info(name,money) values(?,?)", new String[]{"张三","2000"});
        db.execSQL("insert into info(name,money) values(?,?)", new String[]{"李四","1000"});
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
}
```

2、创建数据库并拿去数据

```java
MyOpenHelper myOpenHelper = new MyOpenHelper(getApplicationContext());
SQLiteDatabase db = myOpenHelper.getReadableDatabase();
Cursor cursor = db.query("info", null, null, null, null, null, null);
if (cursor != null && cursor.getCount() > 0) {
    while (cursor.moveToNext()) {
        String name = cursor.getString(1);
        String phone = cursor.getString(2);
        System.out.print("name:" + name + " -- " + "phone:" + phone);
    }
}
```



#### 利用ContentProvider读取其他应用的数据

1、创建内容提供者

```java
public class AccountProvider extends ContentProvider {
    // 定义路径匹配器
    private static final UriMatcher sURIMatcher = new UriMatcher(UriMatcher.NO_MATCH);
    private static final int QUERYSUCCESS = 0;
    private MyOpenHelper myOpenHelper;

    // 定义静态代码块 添加匹配规则
    static {
        sURIMatcher.addURI("com.test.provider", "query", QUERYSUCCESS);
    }

    @Override
    public boolean onCreate() {
        myOpenHelper = new MyOpenHelper(getContext());
        return false;
    }

    @Override
    public Cursor query(Uri uri, String[] projection, String selection, String[] selectionArgs, String sortOrder) {
        int code = sURIMatcher.match(uri);
        if (code == QUERYSUCCESS) {
            SQLiteDatabase db = myOpenHelper.getReadableDatabase();
            Cursor cursor = db.query("info", projection, selection, selectionArgs, null, null, sortOrder);
            return cursor;
        }else {
            throw new IllegalArgumentException("路径不匹配");
        }
    }

    @Override
    public String getType(Uri uri) {
        return null;
    }

    @Override
    public Uri insert(Uri uri, ContentValues values) {
        int code = sURIMatcher.match(uri);
        if (code == INSERTSUCCESS) {
            SQLiteDatabase db = myOpenHelper.getReadableDatabase();
            long insert = db.insert("info", null, values);
            Uri uri2 = Uri.parse("com.test.insert/" + insert);
            return uri2;
        }else {
            throw new IllegalArgumentException("路径不匹配");
        }
    }

    @Override
    public int delete(Uri uri, String selection, String[] selectionArgs) {
        int code = sURIMatcher.match(uri);
        if (code == DELETESUCCESS) {
            SQLiteDatabase db = myOpenHelper.getReadableDatabase();
            int delete = db.delete("info", selection, selectionArgs);
            return delete;
        }else {
            throw new IllegalArgumentException("路径不匹配");
        }
    }

    @Override
    public int update(Uri uri, ContentValues values, String selection, String[] selectionArgs) {
        int code = sURIMatcher.match(uri);
        if (code == UPDATESUCCESS) {
            SQLiteDatabase db = myOpenHelper.getReadableDatabase();
            int update = db.update("into", values, selection, selectionArgs);
            return update;
        }else {
            throw new IllegalArgumentException("路径不匹配");
        }
    }
}
```

2、添加配置

```java
<provider
    android:name=".Provider.AccountProvider"
    android:authorities="com.test.db.AccountProvider" />
```

3、另一个应用操作数据

获取数据

```java
// 配置路径，和要读取应用UriMatcher配置的路径一致
Uri uri = Uri.parse("content://com.test.provider/query");
Cursor cursor = getContentResolver().query(uri, null, null, null, null);
if (cursor != null && cursor.getCount() > 0) {
    while (cursor.moveToNext()) {
        String name = cursor.getString(1);
        String phone = cursor.getString(2);
        System.out.print("name:" + name + " -- " + "phone:" + phone);
    }
}
```

插入数据

```java
Uri uri = Uri.parse("content://com.test.provider/insert");
ContentValues values = new ContentValues();
values.put("name", "xiaoming");
values.put("money", "100");
Uri insert = getContentResolver().insert(uri, values);
System.out.println("insert: " + insert);
```

删除数据

```java
Uri uri = Uri.parse("content://com.test.provider/delete");
int delete = getContentResolver().delete(uri, "name=?", new String[]{"xiaoming"});
System.out.println("删除了" + delete + "行");
```

修改数据

```java
Uri uri = Uri.parse("content://com.test.provider/update");
ContentValues values = new ContentValues();
values.put("money", 10);
getContentResolver().update(uri, values, "name=?", new String[]{"xiaoming"});
```

