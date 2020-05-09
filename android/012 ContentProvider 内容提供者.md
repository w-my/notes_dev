## ContentProvider 内容提供者

#### 获取短信数据

```java
Uri uri = Uri.parse("content://sms/");
Cursor cursor = getContentResolver().query(uri, new String[]{}, null, null, null);
while (cursor.moveToNext()) {
    String address = cursor.getString(0);
    String date = cursor.getString(1);
    String body = cursor.getString(2);
    System.out.println("body: " + body);
}
```



#### 插入短信

```java
Uri uri = Uri.parse("content://sms");
ContentValues values = new ContentValues();
values.put("address", "110");
values.put("body", "赶紧帮下忙吧");
values.put("date", System.currentTimeMillis());
getContentResolver().insert(uri, values);
System.out.println("插入短信成功");
```



#### 读取并备份短信

```java
public class SmsXmlActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sms_xml);

        try {
            File file = new File(Environment.getExternalStorageDirectory().getPath(), "sms.xml");
            FileOutputStream fos = new FileOutputStream(file);

            XmlSerializer serializer = Xml.newSerializer();
            serializer.setOutput(fos, "utf-8");
            serializer.startDocument("utf-8", true);
            serializer.startTag(null, "smss");

            Uri uri = Uri.parse("content://sms/");
            Cursor cursor = getContentResolver().query(uri, new String[]{}, null, null, null);
            while (cursor.moveToNext()) {
                String address = cursor.getString(0);
                String date = cursor.getString(1);
                String body = cursor.getString(2);

                serializer.startTag(null, "sms");

                serializer.startTag(null, "address");
                serializer.text(address);
                serializer.endTag(null, "address");

                serializer.startTag(null, "date");
                serializer.text(date);
                serializer.endTag(null, "date");

                serializer.startTag(null, "body");
                serializer.text(body);
                serializer.endTag(null, "body");

                serializer.endTag(null, "sms");

            }

            serializer.endTag(null, "smss");
            serializer.endDocument();

            System.out.println("完成");

        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
```











