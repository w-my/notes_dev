# Scrapy

先安装 python。



## 安装Scrapy

```sh
xcode-select –install
```

```sh
pip3 install Scrapy
```

安装好后，输入 `scrapy`， 可以看到 Scrapy 信息，说明就安装好了。



**错误：**

**Q:** WARNING: You are using pip version 21.2.4; however, version 23.2.1 is available.

You should consider upgrading via the '/Applications/Xcode.app/Contents/Developer/usr/bin/python3 -m pip install --upgrade pip' command.

**A:** pip 版本过低

```sh
pip3 install --upgrade pip
```



## 使用Scrapy

使用 `scrapy` 命令创建名为 `demo` 的项目

```sh
scrapy startproject demo
```

切换到`demo` 目录，用下面的命令创建名为`douban`的蜘蛛程序

```sh
scrapy genspider douban movie.douban.com
```

**使用实例**

修改 `items.py` :

```python
import scrapy

class MovieItem(scrapy.Item):
    title = scrapy.Field()
    score = scrapy.Field()
    motto = scrapy.Field()
```

修改 `douban.py`:

```python
import scrapy
from scrapy import Selector, Request
from scrapy.http import HtmlResponse

from demo.items import MovieItem


class DoubanSpider(scrapy.Spider):
    name = 'douban'
    allowed_domains = ['movie.douban.com']
    start_urls = ['https://movie.douban.com/top250?start=0&filter=']

    def parse(self, response: HtmlResponse):
        sel = Selector(response)
        movie_items = sel.css('#content > div > div.article > ol > li')
        for movie_sel in movie_items:
            item = MovieItem()
            item['title'] = movie_sel.css('.title::text').extract_first()
            item['score'] = movie_sel.css('.rating_num::text').extract_first()
            item['motto'] = movie_sel.css('.inq::text').extract_first()
            yield item

        hrefs = sel.css('#content > div > div.article > div.paginator > a::attr("href")')
        for href in hrefs:
            full_url = response.urljoin(href.extract())
            yield Request(url=full_url)
```

然后在命令行输入 `scrapy crawl douban` 测试