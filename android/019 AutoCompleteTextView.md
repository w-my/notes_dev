## AutoCompleteTextView

```java
<AutoCompleteTextView
    android:id="@+id/actv"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:completionThreshold="1" />
```

```java
public class MainActivity extends AppCompatActivity {
    private String[] COUNTRIES = new String[] {
            "aaa", "aab", "abb", "bbb", "ccc", "ddd"
    };
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        AutoCompleteTextView actv = findViewById(R.id.actv);
        ArrayAdapter<String> adapter = new ArrayAdapter<>(this,
                R.layout.support_simple_spinner_dropdown_item,
                COUNTRIES);
        actv.setAdapter(adapter);
    }
}
```

