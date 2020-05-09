## Fragments

#### fragment之间的通信

###### fragment1.xml

```java
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    android:orientation="vertical"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <Button
        android:id="@+id/btn1"
        android:text="修改fragment2里的textview内容"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content" />

</LinearLayout>
```

###### fragment2.xml

```java
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    android:orientation="vertical"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <Button
        android:id="@+id/btn1"
        android:text="修改fragment2里的textview内容"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content" />

</LinearLayout>
```

###### Fragment1.java

```java
public class Fragment1 extends Fragment {
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment1, null);

        view.findViewById(R.id.btn1).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Fragment2 f2 = (Fragment2) getActivity()
                        .getSupportFragmentManager()
                        .findFragmentByTag("f2");
                f2.setTvText("哈哈，改变了");
            }
        });

        return view;
    }
}
```

###### Fragment2.java

```java
public class Fragment2 extends Fragment {
    TextView tv;

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment2, null);
        tv = view.findViewById(R.id.tv2);
        return view;
    }

    public void setTvText(String text) {
        tv.setText(text);
    }
}
```

######  activity_main.xml

```java
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    android:orientation="vertical"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <LinearLayout
        android:id="@+id/ll1"
        android:orientation="vertical"
        android:layout_width="match_parent"
        android:layout_height="wrap_content">
    </LinearLayout>

    <LinearLayout
        android:id="@+id/ll2"
        android:orientation="vertical"
        android:layout_width="match_parent"
        android:layout_height="wrap_content">
    </LinearLayout>

</LinearLayout>
```

###### MainActivity.java

```java
getSupportFragmentManager()
        .beginTransaction()
        .replace(R.id.ll1, new Fragment1())
        .commit();

getSupportFragmentManager()
        .beginTransaction()
        .replace(R.id.ll2, new Fragment2(), "f2")
        .commit();
```







