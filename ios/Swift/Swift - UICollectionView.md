## Swift - UICollectionView

- @ e.g.图片分页浏览

  


#### @ e.g.图片分页浏览
1、数据模型类

```swift
struct Interest {
    var title = ""
    var featuredImg: UIImage!
    
    init(title: String, des: String, featuredImg: UIImage!) {
        self.title = title
        self.featuredImg = featuredImg
    }
    
    static func createInsterests() -> [Interest] {
        return [
            Interest(title: "Hello there, i miss u.",
                     featuredImg: #imageLiteral(resourceName: "hello")),
            Interest(title: "🐳🐳🐳🐳🐳",
                     featuredImg: #imageLiteral(resourceName: "run")),
            Interest(title: "Training like this, #bodyline",
                     featuredImg: #imageLiteral(resourceName: "bodyline")),
            Interest(title: "I'm hungry, indeed.",
                     featuredImg: #imageLiteral(resourceName: "wave")),
            Interest(title: "Dark Varder, #emoji",
                     featuredImg: #imageLiteral(resourceName: "darkvarder")),
            Interest(title: "I have no idea, bitch",
                     featuredImg: #imageLiteral(resourceName: "hhhhh"))
        ]
    }
}
```

2、Item类

```swift
class InterestCell: UICollectionViewCell {
    var interest: Interest! {
        didSet {
            refreshUI()
        }
    }
    
    lazy var imgView: UIImageView = {
        let imgv = UIImageView(frame: contentView.bounds)
        imgv.contentMode = .scaleAspectFill
        imgv.layer.masksToBounds = true
        return imgv
    }()
    lazy var effectView: UIVisualEffectView = {
        let ve = UIVisualEffectView(frame: CGRect(x: 0,
                                                  y: contentView.bounds.height-44,
                                                  width: contentView.bounds.width,
                                                  height: 44))
        ve.effect = UIBlurEffect(style: .light)
        return ve
    }()
    lazy var titleLb: UILabel = {
        let lb = UILabel(frame: CGRect(x: 20,
                                       y: contentView.bounds.height-44,
                                       width: contentView.bounds.width-40,
                                       height: 44))
        lb.numberOfLines = 2
        return lb
    }()
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setup()
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    func setup() {
        contentView.addSubview(imgView)
        contentView.addSubview(effectView)
        contentView.addSubview(titleLb)
    }
    
    func refreshUI() {
        imgView.image = interest.featuredImg
        titleLb.text = interest.title
    }
}
```

3、控制器

```swift
class ViewController: UIViewController {

    lazy var bgImgV: UIImageView = {
        let imgv = UIImageView(image: #imageLiteral(resourceName: "blue"))
        imgv.contentMode = .scaleAspectFill
        imgv.frame = view.bounds
        return imgv
    }()
    
    lazy var effectView: UIVisualEffectView = {
        let ve = UIVisualEffectView(frame: view.bounds)
        ve.effect = UIBlurEffect(style: .light)
        return ve
    }()
    
    lazy var collectionView: UICollectionView = {
        let layout = UICollectionViewFlowLayout()
        layout.scrollDirection = .horizontal
        layout.itemSize = CellStruct.Size
        layout.sectionInset = UIEdgeInsets(top: 0, left: CellStruct.Padding, bottom: 0, right: CellStruct.Padding)
        layout.minimumLineSpacing = CellStruct.Padding
        
        let cv = UICollectionView(frame: CGRect(x: 0,
                                                y: 150,
                                                width: view.bounds.width,
                                                height:CellStruct.Size.height),
                                  collectionViewLayout: layout)
        cv.backgroundColor = .clear
        cv.register(InterestCell.self, forCellWithReuseIdentifier: CellStruct.Identifier)
        cv.delegate = self
        cv.dataSource = self
        return cv
    }()
    
    fileprivate var interests = Interest.createInsterests()
    
    fileprivate struct CellStruct {
        static let Identifier = "InterestCell"
        static let Padding: CGFloat = 20
        static let Size = CGSize(width: UIScreen.main.bounds.width-80,
                                 height: UIScreen.main.bounds.height - 300)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        setup()
        collectionView.reloadData()
    }

    func setup() {
        view.addSubview(bgImgV)
        view.addSubview(effectView)
        view.addSubview(collectionView)
    }
    
}


extension ViewController: UICollectionViewDelegate, UICollectionViewDataSource {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return interests.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: CellStruct.Identifier,
                                                      for: indexPath) as! InterestCell
        cell.interest = interests[indexPath.row]
        return cell
    }
}

extension ViewController: UIScrollViewDelegate {
    func scrollViewWillEndDragging(_ scrollView: UIScrollView, withVelocity velocity: CGPoint, targetContentOffset: UnsafeMutablePointer<CGPoint>) {
        // 实现分页自动复位效果
        let width = CellStruct.Size.width + CellStruct.Padding
        let originPoint = targetContentOffset.pointee
        var index = Int(originPoint.x / width)
        let offset = Int(originPoint.x) % Int(width)
        index += (offset > Int(width / 2) ? 1 : 0)
        targetContentOffset.pointee = CGPoint(x: index * Int(width), y: 0)
    }
}
```

