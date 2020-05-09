## Contacts

#### 联系人工具类

```java
public class ContactsUtils {
    public static List<Contacts> readContacts(Context context) {
        List<Contacts> contactsList = new ArrayList<>();

        Uri uri = Uri.parse("content://com.android.contacts/raw_contacts/raw_contacts");
        Uri dataUri = Uri.parse("content://com.android.contacts/data");
        Cursor cursor = context.getContentResolver().query(uri, new String[]{"contact_id"}, null, null, null);
        while (cursor.moveToNext()) {
            String contact_id = cursor.getString(0);
            if (contact_id == null) {
                continue;
            }

            Contacts contacts = new Contacts();
            contacts.setId(contact_id);

            Cursor dataCursor = context.getContentResolver().query(dataUri, new String[]{"data1", "mimetype"}, "raw_contact_id=?", new String[]{contact_id}, null);
            while (dataCursor.moveToNext()) {
                String data1 = dataCursor.getString(0);
                String mimetype = dataCursor.getString(1);

                if ("vnd.android.cursor.item/name".equals(mimetype)) {
                    contacts.setName(data1);
                }
                else if ("vnd.android.cursor.item/phone_v2".equals(mimetype)) {
                    contacts.setPhone(data1);
                }
                else if ("vnd.android.cursor.item/email_v2".equals(mimetype)) {
                    contacts.setEmail(data1);
                }
            }

            contactsList.add(contacts);
        }

        return contactsList;
    }

    public static void insertContacts(Context context, Contacts contacts) {
        Uri uri = Uri.parse("content://com.android.contacts/raw_contacts/raw_contacts");
        Uri dataUri = Uri.parse("content://com.android.contacts/data");

        Cursor cursor = context.getContentResolver().query(uri, null, null,null, null);
        int count = cursor.getCount();
        int contact_id = count + 1;

        ContentValues values = new ContentValues();
        values.put("content_id", contact_id);

        context.getContentResolver().insert(uri, values);

        ContentValues nameValues = new ContentValues();
        nameValues.put("data1", contacts.getName());
        nameValues.put("raw_contact_id", contact_id);
        nameValues.put("mimetype", "vnd.android.cursor.item/name");
        context.getContentResolver().insert(dataUri, nameValues);

        ContentValues phoneValues = new ContentValues();
        phoneValues.put("data1", contacts.getPhone());
        phoneValues.put("raw_contact_id", contact_id);
        phoneValues.put("mimetype", "vnd.android.cursor.item/phone_v2");
        context.getContentResolver().insert(dataUri, phoneValues);

        ContentValues emailValues = new ContentValues();
        emailValues.put("data1", contacts.getEmail());
        emailValues.put("raw_contact_id", contact_id);
        emailValues.put("mimetype", "vnd.android.cursor.item/email_v2");
        context.getContentResolver().insert(dataUri, emailValues);

    }
}
```



#### 查询

```java
List<Contacts> contactsList = ContactsUtils.readContacts(getApplicationContext());
for (Contacts contacts : contactsList) {
    System.out.println("context: " + contacts);
}
```



#### 插入

```java
Contacts contacts = new Contacts();
contacts.setName("aaa");
contacts.setPhone("110");
contacts.setEmail("aaa@163.com");
ContactsUtils.insertContacts(getApplicationContext(), contacts);
```





















