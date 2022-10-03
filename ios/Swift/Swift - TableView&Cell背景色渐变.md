## Swift - TableView&Cell背景色渐变

```swift
import UIKit

class TableViewCell: UITableViewCell {
    
    let gradientLayer = CAGradientLayer()
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }
    
    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)
        // Configure the view for the selected state
    }
    
    override init(style: UITableViewCell.CellStyle, reuseIdentifier: String?) {
        super.init(style: style, reuseIdentifier: reuseIdentifier)
        
        selectionStyle = .none
        textLabel?.textColor = .white
        textLabel?.backgroundColor = .clear
        textLabel?.font = UIFont(name: "Avenir Next", size: 18)
        
        let color1 = UIColor(white: 1.0, alpha: 0.2).cgColor
        let color2 = UIColor(white: 1.0, alpha: 0.1).cgColor
        let color3 = UIColor.clear.cgColor
        let color4 = UIColor(white: 1.0, alpha: 0.05).cgColor
        
        contentView.layer.insertSublayer(gradientLayer, at: 0)
        gradientLayer.frame = self.bounds
        gradientLayer.colors = [color1, color2, color3, color4]
        gradientLayer.locations = [0.0, 0.04, 0.95, 1.0]
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func layoutSubviews() {
        super.layoutSubviews()
        gradientLayer.frame = self.bounds
    }
}
```

```swift
import UIKit

class ViewController: UIViewController {
    
    let tableData = ["Read 3 article on Medium", "Cleanup bedroom",
                     "Go for a run", "Hit the gym",
                     "Build another swift project",
                     "Movement training", "Fix the layout problem of a client project",
                     "Write the experience of #30daysSwift", "Inbox Zero",
                     "Booking the ticket to Chengdu", "Test the Adobe Project Comet",
                     "Hop on a call to mom"]
    
    lazy var tbView: UITableView = {
        let tb = UITableView(frame: view.bounds, style: .plain)
        tb.separatorStyle = .none
        tb.register(TableViewCell.self, forCellReuseIdentifier: "cellid")
        tb.delegate = self
        tb.dataSource = self
        return tb;
    }()

    override func viewDidLoad() {
        super.viewDidLoad()
        view.addSubview(tbView)
    }

}

extension ViewController: UITableViewDelegate, UITableViewDataSource {
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return tableData.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cellid") as! TableViewCell
        cell.textLabel?.text = tableData[indexPath.row]
        return cell
    }
    
    func tableView(_ tableView: UITableView, willDisplay cell: UITableViewCell, forRowAt indexPath: IndexPath) {
        cell.backgroundColor = colorforIndex(index: indexPath.row)
    }
    
    func colorforIndex(index: Int) -> UIColor {
        let itemCount = tableData.count - 1
        let color = (CGFloat(index) / CGFloat(itemCount)) * 0.6
        return UIColor(red: 1.0-color, green: color, blue: 1.0, alpha: 1.0)
    }
}
```
