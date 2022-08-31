# spring validation 使用



优雅的实现请求参数校验



## 引入依赖

springboot-2.3.1 之后

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-validation</artifactId>
</dependency>
```



## 使用

Model 中使用

```java
@Data
@ApiModel("用户基本信息")
public class User {
    @ApiModelProperty("姓名")
    @Size(max = 20, message = "姓名最长20个字符")
    private String name;
    @ApiModelProperty("年龄")
	  @Max(value = 150, message = "年龄不能大于150")
    @Min(value = 1, message = "年龄不能小于1")
    private Integer age;
    @NotBlank(message = "地址不能为空")
    private String address;
    @Pattern(regexp = "^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\\.[a-zA-Z0-9_-]+)+$")
    private String email;
}
```

Controller 中使用，请求方法添加 `@Validated`

```java
@Api(tags="用户管理")
@RestController
public class UserController {
    @ApiOperation("创建用户")
    @PostMapping("/users")
    public User create(@RequestBody @Validated User user) {
        return user;
    }
}
```



## 全局异常处理

添加全局异常拦截，返回格式化错误信息。

```java
@RestControllerAdvice
public class BaseExceptionHandler {

    // 处理通用异常
    @ExceptionHandler(Exception.class)
    public Result<String> error(Exception e){
        e.printStackTrace();
        return Result.error(Codes.SYSTEM_ERROR, e.getMessage());
    }

    // 处理 form data 方式调用接口校验失败抛出的异常
    @ExceptionHandler(BindException.class)
    public Result<List<String>> bindExceptionHandler(BindException e) {
        e.printStackTrace();
        List<FieldError> fieldErrors = e.getBindingResult().getFieldErrors();
        List<String> collect = fieldErrors.stream()
                .map(DefaultMessageSourceResolvable::getDefaultMessage)
                .collect(Collectors.toList());
        return Result.error(Codes.BAD_REQUEST, collect);
    }

    // 处理 json 请求体调用接口校验失败抛出的异常
    @ExceptionHandler(MethodArgumentNotValidException.class)
    public Result<List<String>> methodArgumentNotValidExceptionHandler(MethodArgumentNotValidException e) {
        e.printStackTrace();
        List<FieldError> fieldErrors = e.getBindingResult().getFieldErrors();
        List<String> collect = fieldErrors.stream()
                .map(DefaultMessageSourceResolvable::getDefaultMessage)
                .collect(Collectors.toList());
        return Result.error(Codes.BAD_REQUEST, collect);
    }

    // 处理单个参数校验失败抛出的异常
    @ExceptionHandler(ConstraintViolationException.class)
    public Result<List<String>> constraintViolationExceptionHandler(ConstraintViolationException e) {
        e.printStackTrace();
        Set<ConstraintViolation<?>> constraintViolations = e.getConstraintViolations();
        List<String> collect = constraintViolations.stream()
                .map(ConstraintViolation::getMessage)
                .collect(Collectors.toList());
        return Result.error(Codes.BAD_REQUEST, collect);
    }

}
```



## 分组校验

1. 定义一个分组类（或接口）
2. 在校验注解上添加 groups 属性指定分组
3. Controller 方法的 @Validated 注解添加分组类

```java
import javax.validation.groups.Default;

public interface Update extends Default {
}
```

```java
public class UserVO {
    @NotBlank(message = "name 不能为空", groups = Update.class)
    private String name;
    // 省略其他代码...
}
```

```java
@PostMapping("update")
public Result update(@Validated({Update.class}) UserVO userVO) {
    return new Result.success(userVO);
}
```

>  自定义的 `Update` 分组接口继承了 `Default` 接口。校验注解(如：`@NotBlank` )和 `@validated` 默认都属于 `Default.class` 分组

在编写`Update`分组接口时，如果继承了`Default`，下面两个写法就是等效的：

```java
@Validated({Update.class})
@Validated({Update.class,Default.class})
```



## 递归校验

如果 `UserVO` 类中增加一个 `OrderVO` 类的属性，而 `OrderVO` 中的属性也需要校验，就用到递归校验了，只要在相应属性上增加`@Valid`注解即可实现（对于集合同样适用）

OrderVO 类：

```java
public class OrderVO {
    @NotNull
    private Long id;
    @NotBlank(message = "itemName 不能为空")
    private String itemName;
    // 省略其他代码...
}
```

在 `UserVO` 类中增加一个 `OrderVO` 类型的属性

```java
public class UserVO {
    @NotBlank(message = "name 不能为空", groups = Update.class)
    private String name;
    // 需要递归校验的OrderVO
    @Valid
    private OrderVO orderVO;
    // 省略其他代码...
} 
```



## 自定义校验

Spring Validation允许用户自定义校验，实现分两步：

1. 自定义校验注解
2. 编写校验类

```java
@Target({METHOD, FIELD, ANNOTATION_TYPE, CONSTRUCTOR, PARAMETER})
@Retention(RUNTIME)
@Documented
@Constraint(validatedBy = {HaveNoBlankValidator.class}) // 标明由哪个类执行校验逻辑
public @interface HaveNoBlank {
    
    // 校验出错时默认返回的消息
    String message() default "字符串中不能含有空格";

    Class<?>[] groups() default { };

    Class<? extends Payload>[] payload() default { };

    /**
     * 同一个元素上指定多个该注解时使用
     */
    @Target({ METHOD, FIELD, ANNOTATION_TYPE, CONSTRUCTOR, PARAMETER, TYPE_USE })
    @Retention(RUNTIME)
    @Documented
    public @interface List {
        NotBlank[] value();
    }
}
```

```java
public class HaveNoBlankValidator implements ConstraintValidator<HaveNoBlank, String> {
    @Override
    public boolean isValid(String value, ConstraintValidatorContext context) {
        // null 不做检验
        if (value == null) {
            return true;
        }
        if (value.contains(" ")) {
            // 校验失败
            return false;
        }
        // 校验成功
        return true;
    }
}
```

自定义校验注解使用起来和内置注解无异，在需要的字段上添加相应注解即可。



## 注解说明

| 注解             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| @AssertFalse     | 必须为false                                                  |
| @AssertTrue      | 必须为true                                                   |
| @DecimalMax      | 必须是一个数字，其值必须小于或等于指定的最大值，支持的类型：BigDecimal、BigInteger、CharSequence、byte、short、int、long及其包装类 |
| @DecimalMin      | 必须是一个数字，其值必须大于或等于指定的最小值               |
| @Digits          | 必须是可接受范围内的数字                                     |
| @Email           | 字符串必须是格式正确的电子邮件地址                           |
| @Future          | 必须是将来的瞬间，日期或时间                                 |
| @FutureOrPresent | 必须是现在或将来的一个瞬间，日期或时间                       |
| @Max             | 必须是一个数字，其值必须小于或等于指定的最大值               |
| @Min             | 必须是一个数字，其值必须大于或等于指定的最小值               |
| @Negative        | 必须是严格的负数（即0被认为是无效值）                        |
| @NegativeOrZero  | 必须为负数或0                                                |
| @NotBlank        | 不能为null，并且必须至少包含一个非空白字符                   |
| @NotEmpty        | 不能为null也不能为空                                         |
| @NotNull         | 不能为null                                                   |
| @Null            | 必须为null                                                   |
| @Past            | 必须是过去的瞬间，日期或时间                                 |
| @PastOrPresent   | 必须是过去或现在的瞬时，日期或时间                           |
| @Pattern         | 必须与指定的正则表达式匹配。 正则表达式遵循Java正则表达式约定 |
| @Positive        | 必须是严格的正数（即0被视为无效值）                          |
| @PositiveOrZero  | 必须为正数或0                                                |
| @Size            | 大小必须在指定的边界（包括在内）之间                         |


