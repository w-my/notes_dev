## Swift - URLSessionTask
网络请求实例

```swift
class func faceForPerson(_ person: String, size: CGSize, completion:@escaping (_ image: UIImage? ,_ imageFound: Bool) -> ()) throws {
    
    let escapedString = person.addingPercentEncoding(withAllowedCharacters: CharacterSet.urlHostAllowed)
    let pixelsForAPIRequest = Int(max(size.width, size.height)) * 2
    
    let url = URL(string: "https://en.wikipedia.org/w/api.php?action=query&titles=\(escapedString!)&prop=pageimages&format=json&pithumbsize=\(pixelsForAPIRequest)")
    
    let task: URLSessionTask = URLSession.shared.dataTask(with: url!, completionHandler: {
        (data: Data?, response: URLResponse?, error: Error?) in
        if error == nil {
            let wikiDict = try! JSONSerialization.jsonObject(with: data!, options: JSONSerialization.ReadingOptions.allowFragments) as! NSDictionary
    
            if let query = wikiDict.object(forKey: "query") as? NSDictionary {
                if let pages = query.object(forKey: "pages") as? NSDictionary {
                    if let pageContent = pages.allValues.first as? NSDictionary {
                        if let thumbnail = pageContent.object(forKey: "thumbnail") as? NSDictionary {
                            if let thumbURL = thumbnail.object(forKey: "source") as? String {
                                let faceImage = UIImage(data: try! Data(contentsOf: URL(string: thumbURL)!))
                                completion(faceImage, true)
                            }
                        }else{
                            completion(nil, false)
                        }
                    }
                }
            }
        }
    })
    task.resume()
    
}
```

