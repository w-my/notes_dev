# 通过 IDEA 自带 Database 生成文件



1. 使用 IDEA 的 Database 连接数据库。
2. 选择表，右键 Scripted Extensions -> Go To Scripts Directory，在 schema 目录下创建一个 Generate.groovy 文件，复制以下代码并保存。
3. 选择表，右键 Scripted Extensions，选择刚创建的 Generate.groovy 文件，自动执行生成操作。



```groovy
import com.intellij.database.model.DasTable
import com.intellij.database.model.ObjectKind
import com.intellij.database.util.Case
import com.intellij.database.util.DasUtil

import java.io.*
import java.text.SimpleDateFormat

/**
 * 自动生成 dao mapper service dto convert request controller test 等文件
 */

// 自定义需要去除的表头,根据自己的数据库表头自定义。自定义作者名称
// 只有后面紧接着的是"_"下滑线的表头会被处理，比如：tb_column会被处理，tbcolumn不会被处理
tableHeaderRemoved = ["tb"]
classHeaderPre = "Ys"
authorName = "wmy"

// 项目根路径
path_root = "/Users/wmy/Documents/gitdir/github/ystore-java"
// 包路径
path_pkg_main = "/src/main"
path_pkg_test = "/src/test"
path_pkg_root = "/java/cn/com/wmy/ystore"
path_res_mapper = "/resources/mapper"
path_module = "goods"
// 最终生成文件路径
dir_dao             = path_root + "/ystore-pojo" + path_pkg_main + path_pkg_root + "/dao/$path_module"
dir_mapper          = path_root + "/ystore-service-$path_module" + path_pkg_main + path_pkg_root + "/dao"
dir_mapperXml       = path_root + "/ystore-service-$path_module" + path_pkg_main + path_res_mapper
dir_service         = path_root + "/ystore-interface" + path_pkg_main + path_pkg_root + "/service/$path_module"
dir_serviceImpl     = path_root + "/ystore-service-$path_module" + path_pkg_main + path_pkg_root + "/service/impl"
dir_serviceTest     = path_root + "/ystore-service-$path_module" + path_pkg_test + path_pkg_root + "/service"
dir_dto             = path_root + "/ystore-web-manager" + path_pkg_main + path_pkg_root + "/controller/$path_module/dto"
dir_convert         = path_root + "/ystore-web-manager" + path_pkg_main + path_pkg_root + "/controller/$path_module/convert"
dir_pageRequest     = dir_dto
dir_controller      = path_root + "/ystore-web-manager" + path_pkg_main + path_pkg_root + "/controller/$path_module"
dir_controllerTest  = path_root + "/ystore-web-manager" + path_pkg_test + path_pkg_root + "/controller"

// 类型映射
typeMapping = [
        (~/(?i)tinyint|smallint|mediumint|int/)  : "Integer",
        (~/(?i)bigint/)                          : "Long",
        (~/(?i)bool|bit/)                        : "Boolean",
        (~/(?i)float|double|decimal|real/)       : "Double",
        (~/(?i)datetime|date|time/)              : "Date",
        (~/(?i)timestamp/)                       : "TIMESTAMP",
        (~/(?i)blob|binary|bfile|clob|raw|image/): "InputStream",
        (~/(?i)/)                                : "String"
]

//FILES.chooseDirectoryAndSave("Choose directory", "Choose where to store generated files") { dir ->
//    SELECTION.filter { it instanceof DasTable && it.getKind() == ObjectKind.TABLE }.each { generate(it, dir) }
//}

def init() {
    SELECTION.filter { it instanceof DasTable && it.getKind() == ObjectKind.TABLE }.each { generate(it) }
}
init()


def calcFields(table) {
    // 加载当前数据库主键
    def primaryKey = ""
    def prKey = DasUtil.getPrimaryKey(table)
    if (prKey != null) {
        def keyRef = prKey.getColumnsRef()
        if (keyRef != null) {
            def it = keyRef.iterate()
            while (it.hasNext()) {
                // 默认只处理单主键
                primaryKey = it.next()
            }
            primaryKey = javaName(primaryKey, false)
        }
    }
    DasUtil.getColumns(table).reduce([]) { fields, col ->
        def spec = Case.LOWER.apply(col.getDataType().getSpecification())
        def typeStrOrg = spec.toString().replaceAll(/\((.*?)\)/, "")
        if ("int" == typeStrOrg) {
            typeStrOrg = "integer"
        }else if ("text" == typeStrOrg) {
            typeStrOrg = "longvarchar"
        }else if ("datetime" == typeStrOrg) {
            typeStrOrg = "date"
        }
        def typeStr = typeMapping.find { p, t -> p.matcher(spec).find() }.value
        def colName = col.getName()
        def nameTemp = javaName(colName, false)
        // 当前列是否为主键
        def isPrimaryKey = nameTemp.equals(primaryKey)
        def notNull = col.isNotNull()
//        def defaultStr = col.getDefault()
        def comm = [
                colName : colName,
                name :  nameTemp,
                typeOrg  : typeStrOrg,
                type : typeStr,
                commoent: col.getComment(),
                isKey: isPrimaryKey,
                annos: "@Column(name = \""+col.getName()+"\")",
                notNull: notNull
        ]
        fields += [comm]
    }
}

// 去掉自定义的字符串，下面的 javaName 为原始的方法，不去除表头
def javaClassName(str, capitalize) {
    def tempStr = str
    // 去除开头的指定字符串
    tableHeaderRemoved.each(){
        it = it.toLowerCase()
        if (isNotEmpty(it)){
            if (it.size() < tempStr.size()){
                def headTemp = tempStr[0..it.size() - 1]
                def underLineFlag = tempStr[it.size()..it.size()]
                if (it == headTemp.toLowerCase() && underLineFlag == "_") {
                    tempStr = tempStr[it.size()..tempStr.size() - 1]
                    return true
                }
            }
        }
    }
    javaName(tempStr, capitalize)
}

// ab_cd -> AbCd
def javaName(str, capitalize) {
    def s = com.intellij.psi.codeStyle.NameUtil.splitNameIntoWords(str)
            .collect { Case.LOWER.apply(it).capitalize() }
            .join("")
            .replaceAll(/[^\p{javaJavaIdentifierPart}[_]]/, "_")
    capitalize || s.length() == 1 ? s : Case.LOWER.apply(s[0]) + s[1..-1]
}

// 判空
static def isNotEmpty(content) {
      return content != null && content.toString().trim().length() > 0
}

// 首字母转成大写
static String firstCharToUp(String str){
    char r = str[0..0]
    if (Character.isLowerCase(r)) {
        return "${Character.toUpperCase(r)}${str[1..str.length()-1]}"
    }
    return str
}

// 首字母转为小写
static String firstCharToLow(String str){
    char r = str[0..0]
    if (Character.isUpperCase(r)) {
        return "${Character.toLowerCase(r)}${str[1..str.length()-1]}"
    }
    return str
}

// 生成UID
static String genSerialID() {
    return "\tprivate static final long serialVersionUID = " + Math.abs(new Random().nextLong()) + "L;"
}

// 获取包所在文件夹路径
static String getPackageName(dir) {
    return dir.toString()
            .replaceAll("\\\\", ".")
            .replaceAll("/", ".")
//            .replaceAll("^.*src(\\.main\\.java\\.)?", "")
            .replaceAll("^.*src((\\.main|\\.test)\\.java\\.)?", "")
}

// 输出到文件
def print(out, data) {
    data.each() {
        out.println it
    }
}

/*
 * dir_*: 生成文件路径
 * pkgName: 包路径
 * tableName: tb_user
 * tableComment: 表备注
 * className: YsUser
 * daoName：user
 * fields：行数据 [
 *      colName：user_id
 *      name：userId
 *      typeOrg：int
 *      type：Integer
 *      commoent：备注
 *      isKey：true/false 是否主键
 *      annos：@Column(name = "id")
 *      notNull：true/false 是否不能为空
 * ]
 */

def generate(table) {
    def tableName = table.getName()
    def className = classHeaderPre + javaClassName(table.getName(), true)
    def daoName = javaClassName(table.getName(), false)
    def fields = calcFields(table)
    def tableComment = table.getComment()
    if (tableComment == null) {
        tableComment = ""
    }
    tableComment = tableComment.replaceAll("\n"," ")

    // DAO
    new File(dir_dao as String).mkdirs()
    new File(dir_dao as String, "${className}.java").withPrintWriter {
        out -> generateDAO(out, getPackageName(dir_dao), tableName, tableComment, className, fields)
    }

    // Mapper
    new File(dir_mapper as String).mkdirs()
    new File(dir_mapper as String, "${className}Mapper.java").withPrintWriter {
        out -> generateMapper(out, getPackageName(dir_mapper), tableName, tableComment, className, fields)
    }

    // MapperXml
    new File(dir_mapperXml as String).mkdirs()
    new File(dir_mapperXml as String, "${className}Mapper.xml").withPrintWriter {
        out -> generateMapperXml(out, getPackageName(dir_mapperXml), tableName, className, fields)
    }

    // Service
    new File(dir_service as String).mkdirs()
    new File(dir_service as String, "${className}Service.java").withPrintWriter {
        out -> generateService(out, getPackageName(dir_service), tableName, tableComment, className, daoName, fields)
    }

    // ServiceImpl
    new File(dir_serviceImpl as String).mkdirs()
    new File(dir_serviceImpl as String, "${className}ServiceImpl.java").withPrintWriter {
        out -> generateServiceImpl(out, getPackageName(dir_serviceImpl), tableName, tableComment, className, daoName, fields)
    }

    // ServiceTest
    new File(dir_serviceTest as String).mkdirs()
    new File(dir_serviceTest as String, "${className}ServiceTest.java").withPrintWriter {
        out -> generateServiceTest(out, getPackageName(dir_serviceTest), tableName, tableComment, className, daoName, fields)
    }

    // DTO
    new File(dir_dto as String).mkdirs()
    new File(dir_dto as String, "${className}Dto.java").withPrintWriter {
        out -> generateDTO(out, getPackageName(dir_dto), tableName, tableComment, className, fields)
    }
    
    // Convert
    new File(dir_convert as String).mkdirs()
    new File(dir_convert as String, "${className}Convert.java").withPrintWriter {
        out -> generateConvert(out, getPackageName(dir_convert), tableName, tableComment, className, daoName, fields)
    }

    // PageRequest
    new File(dir_pageRequest as String).mkdirs()
    new File(dir_pageRequest as String, "${className}PageReq.java").withPrintWriter {
        out -> generatePageReq(out, getPackageName(dir_pageRequest), tableName, tableComment, className, fields)
    }

    // Controller
    new File(dir_controller as String).mkdirs()
    new File(dir_controller as String, "${className}Controller.java").withPrintWriter {
        out -> generateController(out, getPackageName(dir_controller), tableName, tableComment, className, daoName, fields)
    }

    // ControllerTest
    new File(dir_controllerTest as String).mkdirs()
    new File(dir_controllerTest as String, "${className}ControllerTest.java").withPrintWriter {
        out -> generateControllerTest(out, getPackageName(dir_controllerTest), tableName, tableComment, className, daoName, fields)
    }

}

/**
 * DAO
 */
def generateDAO(out, packageName, tableName, tableComment, className, fields) {
    def data = []
    data.add("package $packageName;" +
            "\n" +
            "\nimport lombok.Data;" +
            "\n" +
            "\nimport javax.persistence.Column;" +
            "\nimport javax.persistence.GeneratedValue;" +
            "\nimport javax.persistence.Id;" +
            "\nimport javax.persistence.Table;" +
            "\nimport java.io.Serializable;"
    )
    Set types = new HashSet()
    fields.each() {
        types.add(it.type)
    }
    if (types.contains("Date")) {
        data.add("import java.sql.Date;")
    }
    if (types.contains("Timestamp")) {
        data.add("import java.sql.Timestamp;")
    }
    if (types.contains("Time")) {
        data.add("import java.sql.Time;")
    }
    if (types.contains("InputStream")) {
        data.add("import java.io.InputStream;")
    }

    data.add("\n/**" +
            "\n * $tableComment($tableName)实体类" +
            "\n *" +
            "\n * @author ${authorName}" +
            "\n * @date ${new SimpleDateFormat("yyyy-MM-dd").format(new Date())}" +
            "\n */"
    )
    data.add("\n@Data" +
            "\n@Table(name = \"$tableName\")" +
            "\npublic class ${className} implements Serializable {" +
            "\n${genSerialID()}"
    )
    i = 0
    fields.each() {
        if(it.commoent == null){
            it.commoent = ""
        }
        it.commoent = it.commoent.replaceAll("\n","").replaceAll("\r","")
        if (isNotEmpty(it.commoent)) {
            data.add("\n\t/**" +
                    "\n\t * ${it.commoent.toString()}" +
                    "\n\t */"
            )
        }
        if (it.isKey) {
            data.add("\t@Id" +
                    "\n\t@GeneratedValue(generator = \"JDBC\")"
            )
        }
        data.add("\t${it.annos}" +
                "\n\tprivate ${it.type} ${it.name};"
        )
        i++
    }
    data.add("\n}")

    print(out, data)
}

/**
 * Mapper
 */
def generateMapper(out, packageName, tableName, tableComment, className, fields) {
    def keyColumnName = ""
    def keyName = ""
    def keyType = ""
    fields.each() {
        if (it.isKey) {
            keyColumnName = it.colName
            keyName = it.name
            keyType = it.type
        }
    }

    def data = []
    data.add("package $packageName;" +
            "\n" +
            "\nimport ${getPackageName(dir_dao)}.${className};" +
            "\nimport org.apache.ibatis.annotations.Param;" +
            "\nimport tk.mybatis.mapper.common.Mapper;" +
            "\n" +
            "\nimport java.util.List;"
    )
    data.add("\n/**" +
            "\n * 数据库访问层 $tableComment(${tableName})" +
            "\n *" +
            "\n * @author ${authorName}" +
            "\n * @date ${new SimpleDateFormat("yyyy-MM-dd").format(new Date())}" +
            "\n */"
    )
    data.add("\npublic interface ${className}Mapper extends Mapper<${className}> {" +
            "\n" +
            "\n\tint batchInsert(@Param(\"list\") List<${className}> list);" +
            "\n" +
            "\n\t/**" +
            "\n\t * 查询指定数据" +
            "\n\t *" +
            "\n\t * @param id ID" +
            "\n\t * @return 结果" +
            "\n\t */" +
            "\n\t${className} selectById(@Param(\"${keyName}\") ${keyType} ${keyName});" +
            "\n" +
            "\n\t/**" +
            "\n\t * 条件查询所有" +
            "\n\t *" +
            "\n\t * @param params 条件" +
            "\n\t * @return 结果列表" +
            "\n\t */" +
            "\n\tList<${className}> selectAllByLimit(${className} params);"
    )
    data.add("\n}")

    print(out, data)
}

/**
 * MapperXml
 */
def generateMapperXml(out, packageName, tableName, className, fields) {
    def data = []
    data.add("<?xml version=\"1.0\" encoding=\"UTF-8\"?>" +
            "\n<!DOCTYPE mapper PUBLIC \"-//mybatis.org//DTD Mapper 3.0//EN\" \"http://mybatis.org/dtd/mybatis-3-mapper.dtd\">" +
            "\n<mapper namespace=\"${getPackageName(dir_mapper)}.${className}Mapper\">"
    )
    /**
     * result map
     */
    data.add("\t<resultMap id=\"BaseResultMap\" type=\"${getPackageName(dir_dao)}.${className}\">")
    fields.each() {
        if (it.isKey) {
            data.add("\t\t<id column=\"${it.colName}\" jdbcType=\"${it.typeOrg.toUpperCase()}\" property=\"${it.name}\" />")
        } else {
            data.add("\t\t<result column=\"${it.colName}\" jdbcType=\"${it.typeOrg.toUpperCase()}\" property=\"${it.name}\" />")
        }
    }
    data.add("\t</resultMap>")
    /**
     * sql fields
     */
    def filesIdStr = ""
    def filesBatchIdStr = ""
    def filesBatchValueStr = ""
    def count = 1
    def keyColumnName = ""
    def keyName = ""
    def keyType = ""
    fields.each() {
        if (it.isKey) {
            keyColumnName = it.colName
            keyName = it.name
            keyType = it.type
        } else {
            if (filesIdStr == "") {
                filesIdStr = it.colName
                filesBatchIdStr = it.colName
                filesBatchValueStr = "#{item.${it.colName},jdbcType=${it.type}}"
            }else {
                filesIdStr = filesIdStr + ", ${it.colName}"
                filesBatchIdStr = filesBatchIdStr + ", ${it.colName}"
                filesBatchValueStr = filesBatchValueStr + ", #{item.${it.colName},jdbcType=${it.typeOrg.toUpperCase()}}"
                if (((count-1) % 10) == 0) {
                    filesIdStr = filesIdStr + "\n\t\t"
                }
                if (((count-1) % 6) == 0) {
                    filesBatchIdStr = filesBatchIdStr + "\n\t\t\t"
                }
                if (((count-1) % 3) == 0) {
                    filesBatchValueStr = filesBatchValueStr + "\n\t\t\t"
                }
            }
        }
        count = count+1
    }
    filesIdStr = "${keyColumnName}, ${filesIdStr}"
    data.add("\t<sql id=\"BaseColumnFields\">" +
            "\n\t\t${filesIdStr}" +
            "\n\t</sql>"
    )
    /**
     * select where
     */
    data.add("\t<sql id=\"selectAllWhere\">")
    fields.each() {
        if ("String" == it.type) {
            data.add("\t\t\t<if test=\"${it.name} != null and ${it.name} != ''\">")
        } else {
            data.add("\t\t\t<if test=\"${it.name} != null\">")
        }
        data.add("\t\t\t\tand ${it.colName} = #{${it.name}}" +
                "\n\t\t\t</if>"
        )
    }
    data.add("\t</sql>")
    /**
     * batch insert
     */
    data.add("\t<!-- batch insert -->" +
            "\n\t<insert id=\"batchInsert\" keyColumn=\"${keyColumnName}\" keyProperty=\"${keyColumnName}\" parameterType=\"map\" useGeneratedKeys=\"true\">" +
            "\n\t\tINSERT INTO $tableName" +
            "\n\t\t\t(${filesBatchIdStr})" +
            "\n\t\tVALUES" +
            "\n\t\t<foreach collection=\"list\" item=\"item\" separator=\",\">" +
            "\n\t\t\t(${filesBatchValueStr})" +
            "\n\t\t</foreach>" +
            "\n\t</insert>"
    )
    /**
     * select by id
     */
    if (keyColumnName != "") {
        data.add("\t<!-- select by id -->" +
                "\n\t<select id=\"selectById\" parameterType=\"${keyType}\" resultMap=\"BaseResultMap\">" +
                "\n\t\tSELECT" +
                "\n\t\t\t<include refid=\"BaseColumnFields\" />" +
                "\n\t\tFROM $tableName" +
                "\n\t\tWHERE ${keyColumnName} = #{${keyName}}" +
                "\n\t</select>"
        )
    }
    /**
     * select all
     */
    data.add("\t<!-- select all -->" +
            "\n\t<select id=\"selectAllByLimit\" resultMap=\"BaseResultMap\">" +
            "\n\t\tSELECT" +
            "\n\t\t\t<include refid=\"BaseColumnFields\" />" +
            "\n\t\tFROM $tableName" +
            "\n\t\t<where>" +
            "\n\t\t\t<include refid=\"selectAllWhere\"/>" +
            "\n\t\t</where>" +
            "\n\t</select>"
    )
    data.add("\n</mapper>")

    print(out, data)
}

/**
 * Service
 */
def generateService(out, packageName, tableName, tableComment, className, daoName, fields) {
    def keyColumnName = ""
    def keyName = ""
    def keyType = ""
    fields.each() {
        if (it.isKey) {
            keyColumnName = it.colName
            keyName = it.name
            keyType = it.type
        }
    }

    def data = []
    data.add("package ${packageName};" +
            "\n" +
            "\nimport cn.com.wmy.ystore.entity.PageReq;" +
            "\nimport cn.com.wmy.ystore.entity.PageResult;" +
            "\nimport ${getPackageName(dir_dao)}.${className};"
    )
    data.add("\n/**" +
            "\n * $tableComment($tableName)接口类" +
            "\n *" +
            "\n * @author ${authorName}" +
            "\n * @date ${new SimpleDateFormat("yyyy-MM-dd").format(new Date())}" +
            "\n */"
    )
    data.add("\npublic interface ${className}Service {" +
            "\n" +
            "\n\t/**" +
            "\n\t * 根据id查询" +
            "\n\t * @param ${keyName} ID" +
            "\n\t * @return 结果" +
            "\n\t */" +
            "\n\t${className} selectById(${keyType} ${keyName});" +
            "\n" +
            "\n\t/**" +
            "\n\t * 根据条件查询" +
            "\n\t * @param page 分页" +
            "\n\t * @param ${daoName} 搜索参数" +
            "\n\t * @return 结果列表" +
            "\n\t */" +
            "\n\tPageResult<${className}> selectByPage(PageReq page, ${className} ${daoName});" +
            "\n" +
            "\n\t/**" +
            "\n\t * 插入" +
            "\n\t * @param ${daoName} 实体" +
            "\n\t * @return 结果" +
            "\n\t */" +
            "\n\t${className} insert(${className} ${daoName});" +
            "\n" +
            "\n\t/**" +
            "\n\t * 更新" +
            "\n\t * @param ${daoName} 实体" +
            "\n\t * @return 结果" +
            "\n\t */" +
            "\n\t${className} update(${className} ${daoName});" +
            "\n" +
            "\n\t/**" +
            "\n\t * 根据id删除" +
            "\n\t * @param ${keyName} ID" +
            "\n\t * @return 结果" +
            "\n\t */" +
            "\n\tBoolean deleteById(${keyType} ${keyName});"
    )
    data.add("\n}")

    print(out, data)
}

/**
 * ServiceImpl
 */
def generateServiceImpl(out, packageName, tableName, tableComment, className, daoName, fields) {
    def keyColumnName = ""
    def keyName = ""
    def keyType = ""
    fields.each() {
        if (it.isKey) {
            keyColumnName = it.colName
            keyName = it.name
            keyType = it.type
        }
    }

    def data = []
    data.add("package $packageName;" +
            "\n" +
            "\nimport ${getPackageName(dir_mapper)}.${className}Mapper;" +
            "\nimport ${getPackageName(dir_dao)}.${className};" +
            "\nimport ${getPackageName(dir_service)}.${className}Service;" +
            "\nimport cn.com.wmy.ystore.entity.PageReq;" +
            "\nimport cn.com.wmy.ystore.entity.PageResult;" +
            "\nimport com.github.pagehelper.PageHelper;" +
            "\nimport com.github.pagehelper.PageInfo;" +
            "\nimport org.apache.dubbo.config.annotation.DubboService;" +
            "\n" +
            "\nimport javax.annotation.Resource;" +
            "\nimport java.util.List;"
    )
    data.add("\n/**" +
            "\n * $tableComment($tableName)接口实现类" +
            "\n *" +
            "\n * @author ${authorName}" +
            "\n * @date ${new SimpleDateFormat("yyyy-MM-dd").format(new Date())}" +
            "\n */"
    )
    data.add("\n@DubboService(version = \"1.0.0\", group = \"DUBBO\")" +
            "\npublic class ${className}ServiceImpl implements ${className}Service {" +
            "\n" +
            "\n\t@Resource" +
            "\n\tprivate ${className}Mapper ${daoName}Mapper;" +
            "\n" +
            "\n\t@Override" +
            "\n\tpublic ${className} selectById(${keyType} ${keyName}) {" +
            "\n\t\treturn ${daoName}Mapper.selectByPrimaryKey(${keyName});" +
            "\n\t}" +
            "\n" +
            "\n\t@Override" +
            "\n\tpublic PageResult<${className}> selectByPage(PageReq page, ${className} ${daoName}) {" +
            "\n\t\tPageHelper.startPage(page.getPageNum(), page.getPageSize());" +
            "\n\t\tList<${className}> list = ${daoName}Mapper.selectAllByLimit(${daoName});" +
            "\n\t\tPageInfo<${className}> pageInfo = PageInfo.of(list);" +
            "\n\t\treturn PageResult.of(pageInfo);" +
            "\n\t}" +
            "\n" +
            "\n\t@Override" +
            "\n\tpublic ${className} insert(${className} ${daoName}) {" +
            "\n\t\t${daoName}Mapper.insertSelective(${daoName});" +
            "\n\t\treturn ${daoName};" +
            "\n\t}" +
            "\n" +
            "\n\t@Override" +
            "\n\tpublic ${className} update(${className} ${daoName}) {" +
            "\n\t\t${daoName}Mapper.updateByPrimaryKeySelective(${daoName});" +
            "\n\t\treturn ${daoName}Mapper.selectByPrimaryKey(${daoName}.get${firstCharToUp(keyName)}());" +
            "\n\t}" +
            "\n" +
            "\n\t@Override" +
            "\n\tpublic Boolean deleteById(${keyType} ${keyName}) {" +
            "\n\t\treturn ${daoName}Mapper.deleteByPrimaryKey(${keyName}) > 0;" +
            "\n\t}"
    )
    data.add("\n}")

    print(out, data)
}

/**
 * ServiceTest
 */
def generateServiceTest(out, packageName, tableName, tableComment, className, daoName, fields) {
    def data = []
    data.add("\npackage $packageName;" +
            "\n" +
            "\nimport cn.com.wmy.ystore.entity.PageReq;" +
            "\nimport cn.com.wmy.ystore.entity.PageResult;" +
            "\nimport ${getPackageName(dir_dao)}.${className};" +
            "\nimport ${getPackageName(dir_service)}.${className}Service;" +
            "\nimport com.google.gson.Gson;" +
            "\nimport lombok.extern.slf4j.Slf4j;" +
            "\nimport org.junit.jupiter.api.Test;" +
            "\nimport org.springframework.boot.test.context.SpringBootTest;" +
            "\n" +
            "\nimport javax.annotation.Resource;"
    )
    data.add("\n/**" +
            "\n * $tableComment($tableName)接口测试类" +
            "\n *" +
            "\n * @author ${authorName}" +
            "\n * @date ${new SimpleDateFormat("yyyy-MM-dd").format(new Date())}" +
            "\n */"
    )
    data.add("\n@Slf4j" +
            "\n@SpringBootTest" +
            "\npublic class ${className}ServiceTest {" +
            "\n" +
            "\n\t@Resource" +
            "\n\tprivate ${className}Service ${daoName}Service;" +
            "\n" +
            "\n\t@Test" +
            "\n\tpublic void selectByIdTest() {" +
            "\n\t\t${className} resp = ${daoName}Service.selectById(0);" +
            "\n\t\tlog.info(new Gson().toJson(resp));" +
            "\n\t}" +
            "\n" +
            "\n\t@Test" +
            "\n\tpublic void selectByPageTest() {" +
            "\n\t\tPageReq page = new PageReq();" +
            "\n\t\tpage.setPageNum(1);" +
            "\n\t\tpage.setPageSize(10);" +
            "\n\t\t${className} req = new ${className}();"
    )
    fields.each() {
        def value = ""
        if ("String" == it.type) { value = "\"\"" }
        else if ("InputStream" == it.type) { value = "new InputStream()" }
        else if ("TIMESTAMP" == it.type) { value = "new Timestamp()" }
        else if ("Date" == it.type) { value = "new Date()" }
        else if ("Boolean" == it.type) { value = "true" }
        else { value = "0" }
        data.add("\t\treq.set${firstCharToUp(it.name)}(${value});")
    }
    data.add("\t\tlog.info(new Gson().toJson(req));" +
            "\n\t\tPageResult<${className}> resp = ${daoName}Service.selectByPage(page, req);" +
            "\n\t\tlog.info(new Gson().toJson(resp));" +
            "\n\t}" +
            "\n" +
            "\n\t@Test" +
            "\n\tpublic void insertTest() {" +
            "\n\t\t${className} req = new ${className}();"
    )
    fields.each() {
        def value = ""
        if ("String" == it.type) { value = "\"\"" }
        else if ("InputStream" == it.type) { value = "new InputStream()" }
        else if ("TIMESTAMP" == it.type) { value = "new Timestamp()" }
        else if ("Date" == it.type) { value = "new Date()" }
        else if ("Boolean" == it.type) { value = "true" }
        else { value = "0" }
        data.add("\t\treq.set${firstCharToUp(it.name)}(${value});")
    }
    data.add("\t\tlog.info(new Gson().toJson(req));" +
            "\n\t\t${className} resp = ${daoName}Service.insert(req);" +
            "\n\t\tlog.info(new Gson().toJson(resp));" +
            "\n\t}" +
            "\n" +
            "\n\t@Test" +
            "\n\tpublic void updateTest() {" +
            "\n\t\t${className} req = new ${className}();"
    )
    fields.each() {
        def value = ""
        if ("String" == it.type) { value = "\"\"" }
        else if ("InputStream" == it.type) { value = "new InputStream()" }
        else if ("TIMESTAMP" == it.type) { value = "new Timestamp()" }
        else if ("Date" == it.type) { value = "new Date()" }
        else if ("Boolean" == it.type) { value = "true" }
        else { value = "0" }
        data.add("\t\treq.set${firstCharToUp(it.name)}(${value});")
    }
    data.add("\t\tlog.info(new Gson().toJson(req));" +
            "\n\t\t${className} resp = ${daoName}Service.update(req);" +
            "\n\t\tlog.info(new Gson().toJson(resp));" +
            "\n\t}" +
            "\n" +
            "\n\t@Test" +
            "\n\tpublic void deleteByIdTest() {" +
            "\n\t\tBoolean resp = ${daoName}Service.deleteById(0);" +
            "\n\t\tlog.info(new Gson().toJson(resp));" +
            "\n\t}"
    )
    data.add("\n}")

    print(out, data)
}

/**
 * DTO
 */
def generateDTO(out, packageName, tableName, tableComment, className, fields) {
    def data = []
    data.add("package $packageName;" +
            "\n" +
            "\nimport cn.com.wmy.ystore.entity.Update;" +
            "\nimport io.swagger.annotations.ApiModel;" +
            "\nimport io.swagger.annotations.ApiModelProperty;" +
            "\nimport lombok.Data;" +
            "\n" +
            "\nimport javax.validation.constraints.NotBlank;" +
            "\nimport javax.validation.constraints.NotNull;" +
            "\nimport javax.validation.constraints.Size;" +
            "\nimport java.io.Serializable;"
    )
    Set types = new HashSet()
    fields.each() {
        types.add(it.type)
    }
    if (types.contains("Date")) {
        data.add("import java.sql.Date;")
    }
    if (types.contains("Timestamp")) {
        data.add("import java.sql.Timestamp;")
    }
    if (types.contains("Time")) {
        data.add("import java.sql.Time;")
    }
    if (types.contains("InputStream")) {
        data.add("import java.io.InputStream;")
    }

    data.add("\n/**" +
            "\n * $className $tableComment" +
            "\n *" +
            "\n * @author ${authorName}" +
            "\n * @date ${new SimpleDateFormat("yyyy-MM-dd").format(new Date())}" +
            "\n */"
    )
    data.add("\n@ApiModel(description= \"${tableComment}\")" +
            "\n@Data" +
            "\npublic class ${className}Dto implements Serializable {" +
            "\n${genSerialID()}" +
            "\n\t// allowableValues = \"Y,N\""
    )
    i = 0
    fields.each() {
        if(it.commoent == null){
            it.commoent = ""
        }
        it.commoent = it.commoent.replaceAll("\n","").replaceAll("\r","")
        data.add("\n\t@ApiModelProperty(value = \"${it.commoent}\")")
        if (it.isKey) {
            data.add("\t@NotNull(message = \"${it.commoent}不能为空\", groups = Update.class)")
        } else if (it.notNull) {
            data.add("\t@NotBlank(message = \"${it.commoent}不能为空\")")
        }
        if ("String" == it.type) {
            data.add("\t@Size(max = 0, message = \"${it.commoent}最长0个字符\")")
        }
        data.add("\tprivate ${it.type} ${it.name};")
        i++
    }
    data.add("\n}")

    print(out, data)
}

/**
 * Convert
 */
def generateConvert(out, packageName, tableName, tableComment, className, daoName, fields) {
    def data = []
    data.add("package $packageName;" +
            "\n" +
            "\nimport ${getPackageName(dir_dto)}.${className}Dto;" +
            "\nimport ${getPackageName(dir_dao)}.${className};" +
            "\nimport lombok.experimental.UtilityClass;"
    )
    data.add("\n/**" +
            "\n * $className & $className 转换" +
            "\n *" +
            "\n * @author ${authorName}" +
            "\n * @date ${new SimpleDateFormat("yyyy-MM-dd").format(new Date())}" +
            "\n */"
    )
    data.add("\n@UtilityClass" +
            "\n\npublic class ${className}Convert {" +
            "\n" +
            "\n\tpublic ${className} to${firstCharToUp(daoName)}(${className}Dto data) {" +
            "\n\t\tif (data == null) {" +
            "\n\t\t\treturn null;" +
            "\n\t\t}" +
            "\n\t\t${className} result = new ${className}();"
    )
    fields.each() {
        data.add("\t\tresult.set${firstCharToUp(it.name)}(data.get${firstCharToUp(it.name)}());")
    }
    data.add("\t\treturn result;" +
            "\n\t}" +
            "\n" +
            "\n\tpublic ${className}Dto to${firstCharToUp(daoName)}Dto(${className} data) {" +
            "\n\t\tif (data == null) {" +
            "\n\t\t\treturn null;" +
            "\n\t\t}" +
            "\n\t\t${className}Dto result = new ${className}Dto();"
    )
    fields.each() {
        data.add("\t\tresult.set${firstCharToUp(it.name)}(data.get${firstCharToUp(it.name)}());")
    }
    data.add("\t\treturn result;" +
            "\n\t}" +
            "\n" +
            "\n}"
    )

    print(out, data)
}

/**
 * PageRequest
 */
def generatePageReq(out, packageName, tableName, tableComment, className, fields) {
    def data = []
    data.add("package $packageName;" +
            "\n" +
            "\nimport cn.com.wmy.ystore.entity.PageReq;" +
            "\nimport io.swagger.annotations.ApiModel;" +
            "\nimport io.swagger.annotations.ApiModelProperty;" +
            "\nimport lombok.Data;"
    )
    data.add("\n/**" +
            "\n * $className $tableComment 分页搜索" +
            "\n *" +
            "\n * @author ${authorName}" +
            "\n * @date ${new SimpleDateFormat("yyyy-MM-dd").format(new Date())}" +
            "\n */"
    )
    data.add("\n@ApiModel(description= \"${tableComment} 分页搜索参数\")" +
            "\n@Data" +
            "\npublic class ${className}PageReq extends PageReq {" +
            "\n${genSerialID()}"
    )
    fields.each() {
        if(it.commoent == null){
            it.commoent = ""
        }
        it.commoent = it.commoent.replaceAll("\n","").replaceAll("\r","")
//        if ("String" == it.type) {
        data.add("\n\t@ApiModelProperty(value = \"${it.commoent}\")" +
                "\n\tprivate ${it.type} ${it.name};"
        )
//        }
    }
    data.add("\n}")

    print(out, data)
}

/**
 * Controller
 */
def generateController(out, packageName, tableName, tableComment, className, daoName, fields) {
    def keyColumnName = ""
    def keyName = ""
    def keyType = ""
    fields.each() {
        if (it.isKey) {
            keyColumnName = it.colName
            keyName = it.name
            keyType = it.type
        }
    }

    def data = []
    data.add("package $packageName;" +
            "\n" +
            "\nimport ${getPackageName(dir_convert)}.${className}Convert;" +
            "\nimport ${getPackageName(dir_dto)}.${className}Dto;" +
            "\nimport ${getPackageName(dir_dto)}.${className}PageReq;" +
            "\nimport cn.com.wmy.ystore.entity.PageReq;" +
            "\nimport cn.com.wmy.ystore.entity.PageResult;" +
            "\nimport cn.com.wmy.ystore.entity.Result;" +
            "\nimport cn.com.wmy.ystore.entity.Update;" +
            "\nimport ${getPackageName(dir_service)}.${className}Service;" +
            "\nimport cn.com.wmy.ystore.utils.ConvertUtil;" +
            "\nimport io.swagger.annotations.Api;" +
            "\nimport io.swagger.annotations.ApiOperation;" +
            "\nimport io.swagger.annotations.ApiParam;" +
            "\nimport org.apache.dubbo.config.annotation.DubboReference;" +
            "\nimport org.springframework.validation.annotation.Validated;" +
            "\nimport org.springframework.web.bind.annotation.*;"
    )
    data.add("\n/**" +
            "\n * $tableComment($tableName)控制层" +
            "\n *" +
            "\n * @author ${authorName}" +
            "\n * @date ${new SimpleDateFormat("yyyy-MM-dd").format(new Date())}" +
            "\n */"
    )
    data.add("\n@Api(tags = \"#-${tableComment}\")" +
            "\n@RestController" +
            "\n@RequestMapping(value = \"/#/${daoName}\")" +
            "\npublic class ${className}Controller {" +
            "\n" +
            "\n\t@DubboReference(version = \"1.0.0\", group = \"DUBBO\", interfaceClass = ${className}Service.class)" +
            "\n\tprivate ${className}Service ${daoName}Service;" +
            "\n" +
            "\n\t@ApiOperation(\"${tableComment}-通过主键查询\")" +
            "\n\t@GetMapping(value = \"/{id}\", produces = {\"application/json\"})" +
            "\n\tpublic Result<${className}Dto> queryById(@PathVariable(\"id\") ${keyType} ${keyName}) {" +
            "\n\t\treturn Result.success(${className}Convert.to${firstCharToUp(daoName)}Dto(${daoName}Service.selectById(${keyName})));" +
            "\n\t}" +
            "\n" +
            "\n\t@ApiOperation(\"${tableComment}-分页筛选查询\")" +
            "\n\t@PostMapping(value = \"/list\", produces = {\"application/json\"})" +
            "\n\tpublic Result<PageResult<${className}Dto>> queryByPage(@RequestBody ${className}PageReq req) {" +
            "\n\t\tPageReq page = new PageReq();" +
            "\n\t\tpage.setPageNum(req.getPageNum());" +
            "\n\t\tpage.setPageSize(req.getPageSize());" +
            "\n\t\t${className}Dto ${daoName} = new ${className}Dto();"
    )
    fields.each() {
        if ("String" == it.type) {
            data.add("\t\t${daoName}.set${firstCharToUp(it.name)}(req.get${firstCharToUp(it.name)}());")
        }
    }
    data.add("\t\treturn Result.success(ConvertUtil.toPageResult(" +
            "\n\t\t\t${daoName}Service.selectByPage(page, ${className}Convert.to${firstCharToUp(daoName)}(${daoName}))," +
            "\n\t\t\t${className}Convert::to${firstCharToUp(daoName)}Dto" +
            "\n\t\t));" +
            "\n\t}" +
            "\n" +
            "\n\t@ApiOperation(\"${tableComment}-添加\")" +
            "\n\t@PostMapping(value = \"/add\", produces = {\"application/json\"})" +
            "\n\tpublic Result<${className}Dto> add(@Validated @RequestBody ${className}Dto ${daoName}) {" +
            "\n\t\treturn Result.success(${className}Convert.to${firstCharToUp(daoName)}Dto(${daoName}Service.insert(${className}Convert.to${firstCharToUp(daoName)}(${daoName}))));" +
            "\n\t}" +
            "\n" +
            "\n\t@ApiOperation(\"${tableComment}-修改\")" +
            "\n\t@PostMapping(value = \"/edit\", produces = {\"application/json\"})" +
            "\n\tpublic Result<${className}Dto> edit(@Validated({ Update.class }) @RequestBody ${className}Dto ${daoName}) {" +
            "\n\t\treturn Result.success(${className}Convert.to${firstCharToUp(daoName)}Dto(${daoName}Service.update(${className}Convert.to${firstCharToUp(daoName)}(${daoName}))));" +
            "\n\t}" +
            "\n" +
            "\n\t@ApiOperation(\"${tableComment}-删除\")" +
            "\n\t@GetMapping(value = \"/delete/{id}\", produces = {\"application/json\"})" +
            "\n\tpublic Result<Boolean> delete(@ApiParam(\"id\") @PathVariable(\"id\") ${keyType} ${keyName}) {" +
            "\n\t\treturn Result.success(${daoName}Service.deleteById(${keyName}));" +
            "\n\t}" +
            "\n" +
            "\n}"
    )

    print(out, data)
}

/**
 * ControllerTest
 */
def generateControllerTest(out, packageName, tableName, tableComment, className, daoName, fields) {
    def data = []
    data.add("package $packageName;" +
            "\n" +
            "\nimport ${getPackageName(dir_controller)}.${className}Controller;" +
            "\nimport ${getPackageName(dir_dto)}.${className}Dto;" +
            "\nimport ${getPackageName(dir_dto)}.${className}PageReq;" +
            "\nimport cn.com.wmy.ystore.entity.PageResult;" +
            "\nimport cn.com.wmy.ystore.entity.Result;" +
            "\nimport com.google.gson.Gson;" +
            "\nimport lombok.extern.slf4j.Slf4j;" +
            "\nimport org.junit.jupiter.api.Test;" +
            "\nimport org.springframework.boot.test.context.SpringBootTest;" +
            "\n" +
            "\nimport javax.annotation.Resource;"
    )
    data.add("\n/**" +
            "\n * $tableComment($tableName)控制层测试类" +
            "\n *" +
            "\n * @author ${authorName}" +
            "\n * @date ${new SimpleDateFormat("yyyy-MM-dd").format(new Date())}" +
            "\n */"
    )
    data.add("\n@Slf4j" +
            "\n@SpringBootTest" +
            "\npublic class ${className}ControllerTest {" +
            "\n" +
            "\n\t@Resource" +
            "\n\tprivate ${className}Controller ${daoName}Controller;" +
            "\n" +
            "\n\t@Test" +
            "\n\tpublic void queryByIdTest() {" +
            "\n\t\tResult<${className}Dto> resp = ${daoName}Controller.queryById(0);" +
            "\n\t\tlog.info(new Gson().toJson(resp));" +
            "\n\t}" +
            "\n" +
            "\n\t@Test" +
            "\n\tpublic void queryByPageTest() {" +
            "\n\t\t${className}PageReq req = new ${className}PageReq();" +
            "\n\t\treq.setPageNum(1);" +
            "\n\t\treq.setPageSize(10);"
    )
    fields.each() {
        def value = ""
        if ("String" == it.type) { value = "\"\"" }
        else if ("InputStream" == it.type) { value = "new InputStream()" }
        else if ("TIMESTAMP" == it.type) { value = "new Timestamp()" }
        else if ("Date" == it.type) { value = "new Date()" }
        else if ("Boolean" == it.type) { value = "true" }
        else { value = "0" }
        data.add("\t\treq.set${firstCharToUp(it.name)}(${value});")
    }
    data.add("\t\tlog.info(new Gson().toJson(req));" +
            "\n\t\tResult<PageResult<${className}Dto>> resp = ${daoName}Controller.queryByPage(req);" +
            "\n\t\tlog.info(new Gson().toJson(resp));" +
            "\n\t}" +
            "\n" +
            "\n\t@Test" +
            "\n\tpublic void insertTest() {" +
            "\n\t\t${className}Dto req = new ${className}Dto();"
    )
    fields.each() {
        def value = ""
        if ("String" == it.type) { value = "\"\"" }
        else if ("InputStream" == it.type) { value = "new InputStream()" }
        else if ("TIMESTAMP" == it.type) { value = "new Timestamp()" }
        else if ("Date" == it.type) { value = "new Date()" }
        else if ("Boolean" == it.type) { value = "true" }
        else { value = "0" }
        data.add("\t\treq.set${firstCharToUp(it.name)}(${value});")
    }
    data.add("\t\tlog.info(new Gson().toJson(req));" +
            "\n\t\tResult<${className}Dto> resp = ${daoName}Controller.add(req);" +
            "\n\t\tlog.info(new Gson().toJson(resp));" +
            "\n\t}" +
            "\n" +
            "\n\t@Test" +
            "\n\tpublic void updateTest() {" +
            "\n\t\t${className}Dto req = new ${className}Dto();"
    )
    fields.each() {
        def value = ""
        if ("String" == it.type) { value = "\"\"" }
        else if ("InputStream" == it.type) { value = "new InputStream()" }
        else if ("TIMESTAMP" == it.type) { value = "new Timestamp()" }
        else if ("Date" == it.type) { value = "new Date()" }
        else if ("Boolean" == it.type) { value = "true" }
        else { value = "0" }
        data.add("\t\treq.set${firstCharToUp(it.name)}(${value});")
    }
    data.add("\t\tlog.info(new Gson().toJson(req));" +
            "\n\t\tResult<${className}Dto> resp = ${daoName}Controller.edit(req);" +
            "\n\t\tlog.info(new Gson().toJson(resp));" +
            "\n\t}" +
            "\n" +
            "\n\t@Test" +
            "\n\tpublic void deleteByIdTest() {" +
            "\n\t\tResult<Boolean> resp = ${daoName}Controller.delete(0);" +
            "\n\t\tlog.info(new Gson().toJson(resp));" +
            "\n\t}" +
            "\n" +
            "\n}"
    )

    print(out, data)

}
```

