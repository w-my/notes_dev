## Fragments

###### fragment_test.xml

```java
<LinearLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    android:orientation="vertical"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <TextView
        android:text="微信页面"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content" />

    <Button
        android:text="按钮"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content" />

</LinearLayout>
```

######  TestFragment.java

```java
public class TestFragment.java extends Fragment {
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_test, null);
        return view;
    }
}
```



#### 静态添加fragment

直接在 `activity_main.xml` 中添加

```java
<LinearLayout
    android:id="@+id/ll_layout"
    android:orientation="vertical"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

        <fragment
            android:name="com.servyou.fragmenttest.TestFragment"
            android:layout_width="match_parent"
            android:layout_height="match_parent" />

</LinearLayout>
```



#### 动态添加fragment

```java
getSupportFragmentManager()
    .beginTransaction()
    .replace(R.id.ll_layout, new TestFragment())
    .commit();
```





