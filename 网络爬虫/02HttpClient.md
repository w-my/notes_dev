# HttpClient



## Get 请求

```java
public class CrawlerFirst {
    public static void main(String[] args) {
        CloseableHttpClient httpClient = HttpClients.createDefault();
        HttpGet httpGet = new HttpGet("http://www.itcast.cn/");
        CloseableHttpResponse response = null;
        try {
            response = httpClient.execute(httpGet);
            if (200 == response.getStatusLine().getStatusCode()) {
                String content = EntityUtils.toString(response.getEntity(), "UTF-8");
                System.out.println(content.length());
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (null != response) {
                try {
                    response.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            try {
                httpClient.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
```



## Post 请求

```java
public class CrawlerFirst {
    public static void main(String[] args) throws IOException {
        CloseableHttpClient httpClient = HttpClients.createDefault();
        HttpPost httpPost = new HttpPost("http://www.itcast.cn/");
        List<NameValuePair> params = new ArrayList<>();
        params.add(new BasicNameValuePair("keys", "java"));
        UrlEncodedFormEntity formEntity = new UrlEncodedFormEntity(params, "UTF-8");
        httpPost.setEntity(formEntity);
        CloseableHttpResponse response = null;
        try {
            response = httpClient.execute(httpPost);
            if (200 == response.getStatusLine().getStatusCode()) {
                String content = EntityUtils.toString(response.getEntity(), "UTF-8");
                System.out.println(content);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (null != response) {
                try {
                    response.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            try {
                httpClient.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
```



## 连接池

```java
public class CrawlerFirst {
    public static void main(String[] args) throws IOException {
        PoolingHttpClientConnectionManager cm = new PoolingHttpClientConnectionManager();
        // 最大连接数
        cm.setMaxTotal(200);
        // 每个主机的并发数
        cm.setDefaultMaxPerRoute(20);

        doGet(cm);
    }

    private static void doGet(PoolingHttpClientConnectionManager cm) {
        CloseableHttpClient httpClient = HttpClients.custom().setConnectionManager(cm).build();
        HttpGet httpGet = new HttpGet("http://www.itcast.cn/");
        CloseableHttpResponse response = null;
        try {
            response = httpClient.execute(httpGet);
            if (200 == response.getStatusLine().getStatusCode()) {
                String content = EntityUtils.toString(response.getEntity(), "UTF-8");
                System.out.println(content);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (null != response) {
                try {
                    response.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            // 不能关闭 HttpClient
            // httpClient.close();
        }
    }
}
```



## 请求参数

有时因为网络或目标服务器原因，需要自定义时间

```java
CloseableHttpClient httpClient = HttpClients.createDefault();
HttpGet httpGet = new HttpGet("http://www.itcast.cn/");
RequestConfig requestConfig = RequestConfig.custom()
        .setConnectTimeout(1000) // 设置创建连接的最长时间
        .setConnectionRequestTimeout(500) // 设置获取连接的最长时间
        .setSocketTimeout(10 * 1000) // 设置数据传输的最长时间
        .build();
httpGet.setConfig(requestConfig);
CloseableHttpResponse response = null;
try {
    response = httpClient.execute(httpGet);
    if (200 == response.getStatusLine().getStatusCode()) {
        String content = EntityUtils.toString(response.getEntity(), "UTF-8");
        System.out.println(content);
    }
} catch (IOException e) {
    e.printStackTrace();
} finally {
    if (null != response) {
        try {
            response.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    httpClient.close();
}
```

