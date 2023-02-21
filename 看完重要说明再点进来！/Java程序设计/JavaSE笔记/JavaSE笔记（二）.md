# Java对象和多态 （面向对象）

## 面向对象基础

面向对象程序设计(Object Oriented Programming)

对象基于类创建，类相当于一个模板，对象就是根据模板创建出来的实体（就像做月饼，我们要做一个月饼首先需要一个模具，模具就是我们的类，而做出来的月饼，就是类的实现，也叫做对象），类是抽象的数据类型，并不能代表某一个具体的事物，类是对象的一个模板。类具有自己的属性，包括成员变量、成员方法等，我们可以调用类的成员方法来让类进行一些操作。

```java
Scanner sc = new Scanner(System.in);
String str = sc.nextLine();
System.out.println("你输入了："+str);
sc.close();
```

所有的对象，都需要通过`new`关键字创建，基本数据类型不是对象！Java不是纯面对对象语言！

不是基本类型的变量，都是引用类型，引用类型变量代表一个对象，而基本数据类型变量，保存的是基本数据类型的值，我们可以通过引用来对对象进行操作。（最好不要理解为引用指向对象的地址，初学者不要谈内存，学到JVM时再来讨论）

对象占用的内存由JVM统一管理，不需要手动释放内存，当一个对象不再使用时（比如失去引用或是离开了作用域）会被JVM自动清理，内存管理更方便！

***

## 类的基本结构

为了快速掌握，我们自己创建一个自己的类，创建的类文件名称应该和类名一致。

### 成员变量

在类中，可以包含许多的成员变量，也叫成员属性，成员字段(field)通过`.`来访问我们类中的成员变量，我们可以通过类创建的对象来访问和修改这些变量。成员变量是属于对象的！

```java
public class Test {
    int age;
    String name;
}

public static void main(String[] args) {
    Test test = new Test();
    test.name = "奥利给";
    System.out.println(test.name);
}
```

成员变量默认带有初始值，也可以自己定义初始值。

### 成员方法

我们之前的学习中接触过方法(Method)吗？主方法！

```java
public static void main(String[] args) {
  //Body
}
```

方法是语句的集合，是为了完成某件事情而存在的。完成某件事情，可以有结果，也可以做了就做了，不返回结果。比如计算两个数字的和，我们需要得到计算后的结果，所以说方法需要有返回值；又比如，我们只想吧数字打印在控制台，只需要打印就行，不用给我结果，所以说方法不需要有返回值。

#### 方法的定义和使用

在类中，我们可以定义自己的方法，格式如下：

```java
[返回值类型] 方法名称([参数]){
  //方法体
  return 结果;
}
```

* 返回值类型：可以是引用类型和基本类型，还可以是void，表示没有返回值
* 方法名称：和标识符的规则一致，和变量一样，规范小写字母开头！
* 参数：例如方法需要计算两个数的和，那么我们就要把两个数到底是什么告诉方法，那么它们就可以作为参数传入方法
* 方法体：方法具体要干的事情
* 结果：方法执行的结果通过return返回（如果返回类型为void，可以省略return）

非void方法中，`return`关键字不一定需要放在最后，但是一定要保证方法在任何情况下都具有返回值！

```java
int test(int a){
  if(a > 0){
    //缺少retrun语句！
  }else{
    return 0;
  }
}
```

`return`也能用来提前结束整个方法，无论此时程序执行到何处，无论return位于哪里，都会立即结束个方法！

```java
void main(String[] args) {
   for (int i = 0; i < 10; i++) {
       if(i == 1) return;   //在循环内返回了！和break区别？
   }
   System.out.println("淦");   //还会到这里吗？
}
```

传入方法的参数，如果是基本类型，会在调用方法的时候，对参数的值进行复制，方法中的参数变量，不是我们传入的变量本身！

```java
public static void main(String[] args) {
    int a = 10, b = 20;
  	new Test().swap(a, b);
  	System.out.println("a="+a+", b="+b);
}

public class Test{
 	void swap(int a, int b){  //传递的仅仅是值而已！
  		int temp = a;
  		a = b;
 			b = temp;
	} 
}
```

传入方法的参数，如果是引用类型，那么传入的依然是该对象的引用！（类似于C语言的指针）

```java
public class B{
 	String name;
}

public class A{
 	void test(B b){  //传递的是对象的引用，而不是值
    System.out.println(b.name);
  }
}

public static void main(String[] args) {
    int a = 10, b = 20;
  	B b = new B();
  	b.name = "lbw";
  	new A().test(b);
  	System.out.println("a="+a+", b="+b);
}
```

方法之间可以相互调用

```java
void a(){
  //xxxx
}

void b(){
  a();
}
```

当方法在自己内部调用自己时，称为递归调用（递归很危险，慎重！）

```java
int a(){
  return a();
}
```

成员方法和成员变量一样，是属于对象的，只能通过对象去调用！

***

### 对象设计练习

* 学生应该具有以下属性：名字、年龄
* 学生应该具有以下行为：学习、运动、说话

***

### 方法的重载

一个类中可以包含多个同名的方法，但是需要的形式参数不一样。（补充：形式参数就是定义方法需要的参数，实际参数就传入的参数）方法的返回类型，可以相同，也可以不同，但是仅返回类型不同，是不允许的！

```java
public class Test {
    int a(){   //原本的方法
       return 1;
    }

    int a(int i){  //ok，形参不同
        return i;
    }
    
    void a(byte i){  //ok，返回类型和形参都不同
        
    }
    
    void a(){  //错误，仅返回值类型名称不同不能重载
        
    }
}
```

现在我们就可以使用不同的参数，但是支持调用同样的方法，执行一样的逻辑：

```java
public class Test {
    int sum(int a, int b){   //只有int支持，不灵活！
        return a+b;
    }
    
    double sum(double a, double b){  //重写一个double类型的，就支持小数计算了
        return a+b;
    }
}
```

现在我们有很多种重写的方法，那么传入实参后，到底进了哪个方法呢？

```java
public class Test {
    void a(int i){
        System.out.println("调用了int");
    }

    void a(short i){
        System.out.println("调用了short");
    }

    void a(long i){
        System.out.println("调用了long");
    }

    void a(char i){
        System.out.println("调用了char");
    }

    void a(double i){
        System.out.println("调用了double");
    }

    void a(float i){
        System.out.println("调用了float");
    }
  
  	public static void main(String[] args) {
        Test test = new Test();
        test.a(1);   //直接输入整数
        test.a(1.0);  //直接输入小数

        short s = 2;
        test.a(s);  //会对号入座吗？
        test.a(1.0F);
    }
}
```

### 构造方法

构造方法（构造器）没有返回值，也可以理解为，返回的是当前对象的引用！每一个类都默认自带一个无参构造方法。

```java
//反编译结果
package com.test;

public class Test {
    public Test() {    //即使你什么都不编写，也自带一个无参构造方法，只是默认是隐藏的
    }
}
```

反编译其实就是把我们编译好的class文件变回Java源代码。

```java
Test test = new Test();  //实际上存在Test()这个的方法，new关键字就是用来创建并得到引用的
// new + 你想要使用的构造方法
```

这种方法没有写明返回值，但是每个类都必须具有这个方法！只有调用类的构造方法，才能创建类的对象！

类要在一开始准备的所有东西，都会在构造方法里面执行，完成构造方法的内容后，才能创建出对象！

一般最常用的就是给成员属性赋初始值：

```java
public class Student {
    String name;
    
    Student(){
        name = "伞兵一号";
    }
}
```

我们可以手动指定有参构造，当遇到名称冲突时，需要用到this关键字

```java
public class Student {
    String name;

    Student(String name){   //形参和类成员变量冲突了，Java会优先使用形式参数定义的变量！
        this.name = name;  //通过this指代当前的对象属性，this就代表当前对象
    }
}

//idea 右键快速生成！
```

注意，this只能用于指代当前对象的内容，因此，只有属于对象拥有的部分才可以使用this，也就是说，只能在类的成员方法中使用this，不能在静态方法中使用this关键字。

在我们定义了新的有参构造之后，默认的无参构造会被覆盖！

```java
//反编译后依然只有我们定义的有参构造！
```

如果同时需要有参和无参构造，那么就需要用到方法的重载！手动再去定义一个无参构造。

```java
public class Student {
    String name;

    Student(){

    }

    Student(String name){
        this.name = name;
    }
}
```

成员变量的初始化始终在构造方法执行之前

```java
public class Student {
    String a = "sadasa";

    Student(){
        System.out.println(a);
    }

    public static void main(String[] args) {
        Student s = new Student();
    }
}
```

### 静态变量和静态方法

静态变量和静态方法是类具有的属性（后面还会提到静态类、静态代码块），也可以理解为是所有对象共享的内容。我们通过使用`static`关键字来声明一个变量或一个方法为静态的，一旦被声明为静态，那么通过这个类创建的所有对象，操作的都是同一个目标，也就是说，对象再多，也只有这一个静态的变量或方法。那么，一个对象改变了静态变量的值，那么其他的对象读取的就是被改变的值。

```java
public class Student {
    static int a;
}

public static void main(String[] args) {
	Student s1 = new Student();
	s1.a = 10;
	Student s2 = new Student();
	System.out.println(s2.a);
}
```

不推荐使用对象来调用，被标记为静态的内容，可以直接通过`类名.xxx`的形式访问

```java
public static void main(String[] args) {
   Student.a = 10;
   System.out.println(Student.a);
}
```

#### 简述类加载机制

类并不是在一开始就全部加载好，而是在需要时才会去加载（提升速度）以下情况会加载类：

- 访问类的静态变量，或者为静态变量赋值
- new 创建类的实例（隐式加载）
- 调用类的静态方法
- 子类初始化时
- 其他的情况会在讲到反射时介绍

所有被标记为静态的内容，会在类刚加载的时候就分配，而不是在对象创建的时候分配，所以说静态内容一定会在第一个对象初始化之前完成加载。

```java
public class Student {
    static int a = test();  //直接调用静态方法，只能调用静态方法

    Student(){
        System.out.println("构造类对象");
    }

    static int test(){   //静态方法刚加载时就有了
        System.out.println("初始化变量a");
        return 1;
    }
}
```

思考：下面这种情况下，程序能正常运行吗？如果能，会输出什么内容？

```java
public class Student {
    static int a = test();

    static int test(){
        return a;
    }

    public static void main(String[] args) {
        System.out.println(Student.a);
    }
}
```

定义和赋值是两个阶段，在定义时会使用默认值（上面讲的，类的成员变量会有默认值）定义出来之后，如果发现有赋值语句，再进行赋值，而这时，调用了静态方法，所以说会先去加载静态方法，静态方法调用时拿到a，而a这时仅仅是刚定义，所以说还是初始值，最后得到0

### 代码块和静态代码块

代码块在对象创建时执行，也是属于类的内容，但是它在构造方法执行之前执行（和成员变量初始值一样），且每创建一个对象时，只执行一次！（相当于构造之前的准备工作）

```java
public class Student {
    {
        System.out.println("我是代码块");
    }

    Student(){
        System.out.println("我是构造方法");
    }
}
```

静态代码块和上面的静态方法和静态变量一样，在类刚加载时就会调用；

```java
public class Student {
    static int a;

    static {
        a = 10;
    }
    
    public static void main(String[] args) {
        System.out.println(Student.a);
    }
}
```

### String和StringBuilder类

字符串类是一个比较特殊的类，他是Java中唯一重载运算符的类！(Java不支持运算符重载，String是特例)

String的对象直接支持使用`+`或`+=`运算符来进行拼接，并形成新的String对象！（String的字符串是不可变的！）

个人补充：何为String类型字符串不可变，参考博客([链接](https://www.cnblogs.com/one12138/p/11379840.html))

```java
String a = "dasdsa", b = "dasdasdsa";
String l = a+b;
System.out.println(l);
```

大量进行字符串的拼接似乎不太好，编译器是很聪明的，String的拼接有可能会被编译器优化为StringBuilder来减少对象创建（对象频繁创建是很费时间同时占内存的！）

```java
String result="String"+"and"; //会被优化成一句！
```

```java
String str1="String";
String str2="and";
String result=str1+str2;
//变量随时可变，在编译时无法确定result的值，那么只能在运行时再去确定
```

```java
String str1="String";
String str2="and";
String result=(new StringBuilder(String.valueOf(str1))).append(str2).toString();
//使用StringBuilder，会采用类似于第一种实现，显然会更快！
```

StringBuilder也是一个类，但是它能够存储可变长度的字符串！

```java
StringBuilder builder = new StringBuilder();
builder
       .append("a")
       .append("bc")
       .append("d");   //链式调用
String str = builder.toString();
System.out.println(str);
```

***

## 包和访问控制

### 包声明和导入

包其实就是用来区分类位置的东西，也可以用来将我们的类进行分类，类似于C++中的namespace！

```java
package com.test;

public class Test{
  
}
```

包其实是文件夹，比如com.test就是一个com文件夹中包含一个test文件夹，再包含我们Test类。

一般包按照个人或是公司域名的规则倒过来写 `顶级域名.一级域名.二级域名` `com.java.xxxx`

如果需要使用其他包里面的类，那么我们需要`import`（类似于C/C++中的include）

```java
import com.test.Student;
```

也可以导入包下的全部（一般导入会由编译器自带帮我们补全，但是一定要记得我们需要导包！）

```java
import com.test.*
```

Java默认为我们导入了以下的包，不需要去声明

```java
import java.lang.*
```

### 静态导入

静态导入可以直接导入某个类的静态方法或者是静态变量，导入后，相当于这个方法或是类在定义在当前类中，可以直接调用该方法。

```java
import static com.test.ui.Student.test;

public class Main {
    public static void main(String[] args) {
        test();
    }
}
```

静态导入不会进行类的初始化！

### 访问控制

Java支持对类属性访问的保护，也就是说，不希望外部类访问类中的属性或是方法，只允许内部调用，这种情况下我们就需要用到权限控制符。

![image-20210819160939950](/Users/nagocoler/Library/Application Support/typora-user-images/image-20210819160939950.png)

权限控制符可以声明在方法、成员变量、类前面，一旦声明private，只能类内部访问！

```java
public class Student {
    private int a = 10;   //具有私有访问权限，只能类内部访问
}

public static void main(String[] args) {
    Student s = new Student();
    System.out.println(s.a);  //还可以访问吗？
}
```

和文件名称相同的类，只能是public，并且一个java文件中只能有一个public class！

```java
// Student.java
public class Student {
    
}
class Test{   //不能添加权限修饰符！只能是default
	
}
```

***

## 数组类型

假设出现一种情况，我想记录100个数字，定义100个变量还可行吗？

![img](https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fimgs.itxueyuan.com%2FCgq2xl329g-Adz0uAACwgSFkMho326.png&refer=http%3A%2F%2Fimgs.itxueyuan.com&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=jpeg?sec=1632192902&t=7a6d67fc01d0e3ea7816adf951c49605)

我们可以使用到数组，数组是相同类型数据的有序集合。数组可以代表任何相同类型的一组内容（包括引用类型和基本类型）其中存放的每一个数据称为数组的一个元素，数组的下标是从0开始，也就是第一个元素的索引是0！

```java
int[] arr = new int[10];  //需要new关键字来创建！
String[] arr2 = new String[10];
```

数组本身也是类（编程不可见，C++写的），不是基本数据类型！

```java
int[] arr = new int[10];
System.out.println(arr.length);   //数组有成员变量！
System.out.println(arr.toString());   //数组有成员方法！
```

### 一维数组

一维数组中，元素是依次排列的（线性），每个数组元素可以通过下标来访问！声明格式如下：

```  java
类型[] 变量名称 = new 类型[数组大小];
类型 变量名称n = new 类型[数组大小];  //支持C语言样式，但不推荐！

类型[] 变量名称 = new 类型[]{...};  //静态初始化（直接指定值和大小）
类型[] 变量名称 = {...};   //同上，但是只能在定义时赋值
```

 创建出来的数组每个元素都有默认值（规则和类的成员变量一样，C语言创建的数组需要手动设置默认值），我们可以通过下标去访问：

```java
int[] arr = new int[10];
arr[0] = 626;
System.out.println(arr[0]);
System.out.println(arr[1]);
```

我们可以通过`数组变量名称.length`来获取当前数组长度：

```java
int[] arr = new int[]{1, 2, 3};
System.out.println(arr.length);  //打印length成员变量的值
```

数组在创建时，就固定长度，不可更改！访问超出数组长度的内容，会出现错误！

```java
String[] arr = new String[10];
System.out.println(arr[10]);  //出现异常！

//Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: 11
//	at com.test.Application.main(Application.java:7)
```

思考：能不能直接修改length的值来实现动态扩容呢？

```java
int[] arr = new int[]{1, 2, 3};
arr.length = 10;
```

数组做实参，因为数组也是类，所以形参得到的是数组的引用而不是复制的数组，操作的依然是数组对象本身

```java
public static void main(String[] args) {
    int[] arr = new int[]{1, 2, 3};
    test(arr);
    System.out.println(arr[0]);
}

private static void test(int[] arr){
    arr[0] = 2934;
}
```

### 数组的遍历

如果我们想要快速打印数组中的每一个元素，又怎么办呢？

#### 传统for循环

我们很容易就联想到for循环

```java
int[] arr = new int[]{1, 2, 3};
for (int i = 0; i < arr.length; i++) {
   System.out.println(arr[i]);
}
```

#### foreach

传统for循环虽然可控性高，但是不够省事，要写一大堆东西，有没有一种省事的写法呢？

```java
int[] arr = new int[]{1, 2, 3};
for (int i : arr) {
    System.out.println(i);
}
```

foreach属于增强型的for循环，它使得代码更简洁，同时我们能直接拿到数组中的每一个数字。

### 二维数组

二维数组其实就是存放数组的数组，每一个元素都存放一个数组的引用，也就相当于变成了一个平面。

![img](https://gimg2.baidu.com/image_search/src=http%3A%2F%2Ffile.elecfans.com%2Fweb1%2FM00%2FDD%2F01%2Fo4YBAGASjymAK8QIAADiOdWkSVA342.jpg&refer=http%3A%2F%2Ffile.elecfans.com&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=jpeg?sec=1632204192&t=52381354d190d09899776f9bb868ef3e)

```java
//三行两列
int[][] arr = { {1, 2},
                {3, 4},
                {5, 6}};
System.out.println(arr[2][1]);
```

二维数组的遍历同一维数组一样，只不过需要嵌套循环！

```java
int[][] arr = new int[][]{ {1, 2},
                           {3, 4},
                           {5, 6}};
for (int i = 0; i < 3; i++) {
     for (int j = 0; j < 2; j++) {
          System.out.println(arr[i][j]);
     }
}
```

### 多维数组

不止二维数组，还存在三维数组，也就是存放数组的数组的数组，原理同二维数组一样，逐级访问即可。

### 可变长参数

可变长参数其实就是数组的一种应用，我们可以指定方法的形参为一个可变长参数，要求实参可以根据情况动态填入0个或多个，而不是固定的数量

```java
public static void main(String[] args) {
     test("AAA", "BBB", "CCC");    //可变长，最后都会被自动封装成一个数组
}
    
private static void test(String... test){
     System.out.println(test[0]);    //其实参数就是一个数组
}
```

由于是数组，所以说只能使用一种类型的可变长参数，并且可变长参数只能放在最后一位！

### 实战：三大基本排序算法

现在我们有一个数组，但是数组里面的数据是乱序排列的，如何使它变得有序？

```java
int[] arr = {8, 5, 0, 1, 4, 9, 2, 3, 6, 7};
```

排序是编程的一个重要技能，掌握排序算法，你的技术才能更上一层楼，很多的项目都需要用到排序！三大排序算法：

* 冒泡排序

冒泡排序就是冒泡，其实就是不断使得我们无序数组中的最大数向前移动，经历n轮循环逐渐将每一个数推向最前。

* 插入排序

插入排序其实就跟我们打牌是一样的，我们在摸牌的时候，牌堆是乱序的，但是我们一张一张摸到手中进行排序，使得它变成了有序的！

![img](https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fimg1.jjhgame.com%2Fstatic_data%2Fnewshelp%2F113_5c08e82d2ac8b.jpg&refer=http%3A%2F%2Fimg1.jjhgame.com&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=jpeg?sec=1632208529&t=f3fb9be4dce91c6364f5ec4f9faafc94)

* 选择排序

选择排序其实就是每次都选择当前数组中最大的数排到最前面！

***

## 封装、继承和多态

封装、继承和多态是面向对象编程的三大特性。

### 封装

封装的目的是为了保证变量的安全性，使用者不必在意具体实现细节，而只是通过外部接口即可访问类的成员，如果不进行封装，类中的实例变量可以直接查看和修改，可能给整个代码带来不好的影响，因此在编写类时一般将成员变量私有化，外部类需要同getter和setter方法来查看和设置变量。

设想：学生小明已经创建成功，正常情况下能随便改他的名字和年龄吗？

```java
public class Student {
    private String name;
    private int age;
  
    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public int getAge() {
        return age;
    }

    public String getName() {
        return name;
    }
}
```

也就是说，外部现在只能通过调用我定义的方法来获取成员属性，而我们可以在这个方法中进行一些额外的操作，比如小明可以修改名字，但是名字中不能包含"小"这个字。

```java
public void setName(String name) {
    if(name.contains("小")) return;
    this.name = name;
}
```

单独给外部开放设置名称的方法，因为我还需要做一些额外的处理，所以说不能给外部直接操作成员变量的权限！

封装思想其实就是把实现细节给隐藏了，外部只需知道这个方法是什么作用，而无需关心实现。

封装就是通过访问权限控制来实现的。

### 继承

继承属于非常重要的内容，在定义不同类的时候存在一些相同属性，为了方便使用可以将这些共同属性抽象成一个父类，在定义其他子类时可以继承自该父类，减少代码的重复定义，子类可以使用父类中**非私有**的成员。

现在学生分为两种，艺术生和体育生，他们都是学生的分支，但是他们都有自己的方法：

```java
public class SportsStudent extends Student{   //通过extends关键字来继承父类

    public SportsStudent(String name, int age) {
        super(name, age);   //必须先通过super关键字（指代父类），实现父类的构造方法！
    }

    public void exercise(){
        System.out.println("我超勇的！");
    }
}

public class ArtStudent extends Student{

    public ArtStudent(String name, int age) {
        super(name, age);
    }

    public void art(){
        System.out.println("随手画个毕加索！");
    }
}
```

子类具有父类的全部属性，protected可见但外部无法使用（包括`private`属性，不可见，无法使用），同时子类还能有自己的方法。继承只能继承一个父类，不支持多继承！

每一个子类必须定义一个实现父类构造方法的构造方法，也就是需要在构造方法开始使用`super()`，如果父类使用的是默认构造方法，那么子类不用手动指明。

所有类都默认继承自Object类，除非手动指定类型，但是依然改变不了最顶层的父类是Object类。所有类都包含Object类中的方法，比如：

```java
public static void main(String[] args) {
Object obj = new Object;
System.out.println(obj.hashCode());  //求对象的hashcode，默认是对象的内存地址
System.out.println(obj.equals(obj));  //比较对象是否相同，默认比较的是对象的内存地址，也就是等同于 ==
System.out.println(obj.toString());  //将对象转换为字符串，默认生成对象的类名称+hashcode
}
```

关于Object类的其他方法，我们会在Java多线程中再来提及。

### 多态

多态是同一个行为具有多个不同表现形式或形态的能力。也就是同样的方法，由于实现类不同，执行的结果也不同！

#### 方法的重写

我们之前学习了方法的重载，方法的重写和重载是不一样的，重载是原有的方法逻辑不变的情况下，支持更多参数的实现，而重写是直接覆盖原有方法！

```java
//父类中的study
public void study(){
    System.out.println("学习");
}

//子类中的study
@Override  //声明这个方法是重写的，但是可以不要，我们现阶段不接触
public void study(){
    System.out.println("给你看点好康的");
}
```

再次定义同样的方法后，父类的方法就被覆盖！子类还可以给父类方法提升访问权限！

```java
public static void main(String[] args) {
     SportsStudent student = new SportsStudent("lbw", 20);
     student.study();   //输出子类定义的内容
}
```

思考：静态方法能被重写吗？

当我们在重写方法时，不仅想使用我们自己的逻辑，同时还希望执行父类的逻辑（也就是调用父类的方法）怎么办呢？

```java
public void study(){
    super.study();
    System.out.println("给你看点好康的");
}
```

同理，如果想访问父类的成员变量，也可以使用super关键字来访问，注意，子类可以具有和父类相同的成员变量！而在方法中访问的默认是 形参列表中 > 当前类的成员变量 > 父类成员变量

```java
public void setTest(int test){
    test = 1;
  	this.test = 1;
  	super.test = 1;
}
```

#### 再谈类型转换

我们曾经学习过基本数据类型的类型转换，支持一种数据类型转换为另一种数据类型，而我们的类也是支持类型转换的（仅限于存在亲缘关系的类之间进行转换）比如子类可以直接向上转型：

```java
Student student = new SportsStudent("lbw", 20);  //父类变量引用子类实例
student.study();     //得到依然是具体实现的结果，而不是当前类型的结果
```

我们也可以把已经明确是由哪个类实现的父类引用，强制转换为对应的类型：

```java
Student student = new SportsStudent("lbw", 20);  //是由SportsStudent进行实现的
//... do something...

SportsStudent ps = (SportsStudent)student;  //让它变成一个具体的子类
ps.sport();  //调用具体实现类的方法
```

这样的类型转换称为向下转型。

#### instanceof关键字

那么我们如果只是得到一个父类引用，但是不知道它到底是哪一个子类的实现怎么办？我们可以使用instanceof关键字来实现，它能够进行类型判断！

```java
private static void test(Student student){
    if (student instanceof SportsStudent){
        SportsStudent sportsStudent = (SportsStudent) student;
        sportsStudent.sport();
    }else if (student instanceof ArtStudent){
        ArtStudent artStudent = (ArtStudent) student;
        artStudent.art();
    }
}
```

通过进行类型判断，我们就可以明确类的具体实现到底是哪个类！

思考：`student instanceof Student`的结果是什么？

#### 再谈final关键字

我们目前只知道`final`关键字能够使得一个变量的值不可更改，那么如果在类前面声明final，会发生什么？

```java
public final class Student {   //类被声明为终态，那么它还能被继承吗
  	
}
```

类一旦被声明为终态，将无法再被继承，不允许子类的存在！而方法被声明为final呢？

```java
public final void study(){  //还能重写吗
    System.out.println("学习");
}
```

如果类的成员属性被声明为final，那么必须在构造方法中或是在定义时赋初始值！

```java
private final String name;   //引用类型不允许再指向其他对象
private final int age;    //基本类型值不允许发生改变

public Student(String name, int age) {
    this.name = name;
    this.age = age;
}
```

学习完封装继承和多态之后，我们推荐在不会再发生改变的成员属性上添加final关键字，JVM会对添加了final关键字的属性进行优化！

#### 抽象类

类本身就是一种抽象，而抽象类，把类还要抽象，也就是说，抽象类可以只保留特征，而不保留具体呈现形态，比如方法可以定义好，但是我可以不去实现它，而是交由子类来进行实现！

```java
public abstract class Student {    //抽象类
		public abstract void test();  //抽象方法
}
```

通过使用`abstract`关键字来表明一个类是一个抽象类，抽象类可以使用`abstract`关键字来表明一个方法为抽象方法，也可以定义普通方法，抽象方法不需要编写具体实现（无方法体）但是**必须**由子类实现（除非子类也是一个抽象类）！

抽象类由于不是具体的类定义，因此无法直接通过new关键字来创建对象！

```java
Student s = new Student(){    //只能直接创建带实现的匿名内部类！
  public void test(){
    
  }
}
```

因此，抽象类一般只用作继承使用！抽象类使得继承关系之间更加明确：

```java
public void study(){   //现在只能由子类编写，父类没有定义，更加明确了多态的定义！同一个方法多种实现！
    System.out.println("给你看点好康的");
}
```

#### ==接口==

接口甚至比抽象类还抽象，他只代表某个确切的功能！也就是只包含方法的定义，甚至都不是一个类！接口包含了一些列方法的具体定义，类可以实现这个接口，表示类支持接口代表的功能（类似于一个插件，只能作为一个附属功能加在主体上，同时具体实现还需要由主体来实现）

```java
public interface Eat {
	void eat(); 
}
```

通过使用`interface`关键字来表明是一个接口（注意，这里class关键字被替换为了interface）接口只能包含`public`权限的**抽象方法**！（Java8以后可以有默认实现）我们可以通过声明`default`关键字来给抽象方法一个默认实现：

```java
public interface Eat {
    default void eat(){
        //do something...
    }
}
```

接口中定义的变量，默认为public static final

```java
public interface Eat {
    int a = 1;
    void eat();
}
```

一个类可以实现很多个接口，但是不能理解为多继承！（实际上实现接口是附加功能，和继承的概念有一定出入，顶多说是多继承的一种替代方案）一个类可以附加很多个功能！

```java
public class SportsStudent extends Student implements Eat, ...{
		@Override
    public void eat() {
        
    }
}
```

类通过`implements`关键字来声明实现的接口！每个接口之间用逗号隔开！

实现接口的类也能通过instanceof关键字判断，也支持向上和向下转型！

## 内部类

类中可以存在一个类！各种各样的长相怪异的代码就是从这里开始出现的！

### 成员内部类

我们的类中可以在嵌套一个类：

```java
public class Test {
    class Inner{   //类中定义的一个内部类
        
    }
}
```

成员内部类和成员变量和成员方法一样，都是属于对象的，也就是说，必须存在外部对象，才能创建内部类的对象！

```java
public static void main(String[] args) {
    Test test = new Test();
    Test.Inner inner = test.new Inner();   //写法有那么一丝怪异，但是没毛病！
}
```

### 静态内部类

静态内部类其实就和类中的静态变量和静态方法一样，是属于类拥有的，我们可以直接通过`类名.`去访问:

```java
public class Test {
    static class Inner{

    }
}

public static void main(String[] args) {
    Test.Inner inner = new Test.Inner();   //不用再创建外部类对象了！
}
```

### 局部内部类

对，你没猜错，就是和局部变量一样哒~

```java
public class Test {
    public void test(){
        class Inner{

        }
        
        Inner inner = new Inner();
    }
}
```

反正我是没用过！内部类 -> 累不累 -> 反正我累了！

### 匿名内部类

匿名内部类才是我们的重点，也是实现lambda表达式的原理！匿名内部类其实就是在new的时候，直接对接口或是抽象类的实现：

```java
public static void main(String[] args) {
        Eat eat = new Eat() {
            @Override
            public void eat() {
                //DO something...
            }
        };
    }
```

我们不用单独去创建一个类来实现，而是可以直接在new的时候写对应的实现！但是，这样写，无法实现复用，只能在这里使用！

#### lambda表达式

读作`λ`表达式，它其实就是我们接口匿名实现的简化，比如说：

```java
public static void main(String[] args) {
        Eat eat = new Eat() {
            @Override
            public void eat() {
                //DO something...
            }
        };
    }

public static void main(String[] args) {
        Eat eat = () -> {};   //等价于上述内容
    }
```

lambda表达式（匿名内部类）只能访问外部的final类型或是隐式final类型的局部变量！

为了方便，JDK默认就为我们提供了专门写函数式的接口，这里只介绍Consumer

## 枚举类

假设现在我们想给小明添加一个状态（跑步、学习、睡觉），外部可以实时获取小明的状态：

```java
public class Student {
    private final String name;
    private final int age;
    private String status;
  
  	//...
  
  	public void setStatus(String status) {
        this.status = status;
    }

    public String getStatus() {
        return status;
    }
}
```

但是这样会出现一个问题，如果我们仅仅是存储字符串，似乎外部可以不按照我们规则，传入一些其他的字符串。这显然是不够严谨的！

有没有一种办法，能够更好地去实现这样的状态标记呢？我们希望开发者拿到使用的就是我们定义好的状态，我们可以使用枚举类！

```java
public enum Status {
    RUNNING, STUDY, SLEEP    //直接写每个状态的名字即可，分号可以不打，但是推荐打上
}
```

使用枚举类也非常方便，我们只需要直接访问即可

```java
public class Student {
    private final String name;
    private final int age;
    private Status status;
  
 		//...
  
  	public void setStatus(Status status) {   //不再是String，而是我们指定的枚举类型
        this.status = status;
    }

    public Status getStatus() {
        return status;
    }
}

public static void main(String[] args) {
    Student student = new Student("小明", 18);
    student.setStatus(Status.RUNNING);
    System.out.println(student.getStatus());
}
```

枚举类型使用起来就非常方便了，其实枚举类型的本质就是一个普通的类，但是它继承自`Enum`类，我们定义的每一个状态其实就是一个`public static final`的Status类型成员变量！

```java
// Compiled from "Status.java"
public final class com.test.Status extends java.lang.Enum<com.test.Status> {
  public static final com.test.Status RUNNING;
  public static final com.test.Status STUDY;
  public static final com.test.Status SLEEP;
  public static com.test.Status[] values();
  public static com.test.Status valueOf(java.lang.String);
  static {};
}
```

既然枚举类型是普通的类，那么我们也可以给枚举类型添加独有的成员方法

```java
public enum Status {
    RUNNING("睡觉"), STUDY("学习"), SLEEP("睡觉");   //无参构造方法被覆盖，创建枚举需要添加参数（本质就是调用的构造方法！）

    private final String name;    //枚举的成员变量
    Status(String name){    //覆盖原有构造方法（默认private，只能内部使用！）
        this.name = name;
    }
  
  	public String getName() {   //获取封装的成员变量
        return name;
    }
}

public static void main(String[] args) {
    Student student = new Student("小明", 18);
    student.setStatus(Status.RUNNING);
    System.out.println(student.getStatus().getName());
}
```

枚举类还自带一些继承下来的实用方法

```java
Status.valueOf("")   //将名称相同的字符串转换为枚举
Status.values()   //快速获取所有的枚举
```

## ==基本类型包装类==

Java并不是纯面向对象的语言，虽然Java语言是一个面向对象的语言，但是Java中的基本数据类型却不是面向对象的。在学习泛型和集合之前，基本类型的包装类是一定要讲解的内容！

我们的基本类型，如果想通过对象的形式去使用他们，Java提供的基本类型包装类，使得Java能够更好的体现面向对象的思想，同时也使得基本类型能够支持对象操作！

![img](https://img2018.cnblogs.com/blog/1504650/201901/1504650-20190122173636211-1359168032.png)

* byte  ->  Byte      
* boolean  ->  Boolean   
* short  ->  Short    
* char  ->  Character  
* int -> Integer    
* long ->  Long     
* float -> Float      
* double -> Double   

包装类实际上就行将我们的基本数据类型，封装成一个类（运用了封装的思想）

```java
private final int value;   //Integer内部其实本质还是存了一个基本类型的数据，但是我们不能直接操作

public Integer(int value) {
    this.value = value;
}
```

现在我们操作的就是Integer对象而不是一个int基本类型了！

```java
public static void main(String[] args) {
     Integer i = 1;   //包装类型可以直接接收对应类型的数据，并变为一个对象！
     System.out.println(i + i);    //包装类型可以直接被当做一个基本类型进行操作！
}
```

#### 自动装箱和拆箱

那么为什么包装类型能直接使用一个具体值来赋值呢？其实依靠的是自动装箱和拆箱机制

```java
Integer i = 1;    //其实这里只是简写了而已
Integer i = Integer.valueOf(1);  //编译后真正的样子
```

调用valueOf来生成一个Integer对象！

```java
public static Integer valueOf(int i) {
    if (i >= IntegerCache.low && i <= IntegerCache.high)   //注意，Java为了优化，有一个缓存机制，如果是在-128~127之间的数，会直接使用已经缓存好的对象，而不是再去创建新的！（面试常考）
       return IntegerCache.cache[i + (-IntegerCache.low)];
  	return new Integer(i);   //返回一个新创建好的对象
}
```

而如果使用包装类来进行运算，或是赋值给一个基本类型变量，会进行自动拆箱：

```java
public static void main(String[] args) {
    Integer i = Integer.valueOf(1);
    int a = i;    //简写
    int a = i.intValue();   //编译后实际的代码
  
  	long c = i.longValue();   //其他类型也有！
}
```

既然现在是包装类型了，那么我们还能使用`==`来判断两个数是否相等吗？

```java
public static void main(String[] args) {
    Integer i1 = 28914;
    Integer i2 = 28914;

    System.out.println(i1 == i2);   //实际上判断是两个对象是否为同一个对象（内存地址是否相同）
    System.out.println(i1.equals(i2));   //这个才是真正的值判断！
}
```

注意IntegerCache带来的影响！

思考：下面这种情况结果会是什么？

```java
public static void main(String[] args) {
    Integer i1 = 28914;
    Integer i2 = 28914;

    System.out.println(i1+1 == i2+1);
}
```

在集合类的学习中，我们还会继续用到我们的包装类型！

***

## 面向对象编程实战

虽然我们学习了编程，但是我们不能一股脑的所有问题都照着编程的思维去解决，编程只是解决问题的一种手段，灵活的运用我们所学的知识，才是解决问题的最好办法！比如，求1到100所有数的和：

```java
public static void main(String[] args) {
    int sum = 0;
    for (int i = 1; i <= 100; i++) {   //for循环暴力求解，简单，但是效率似乎低了一些
        sum += i;
    }
    System.out.println(sum);
}

public static void main(String[] args) {
    System.out.println((1 + 100) * 50);  //高斯求和公式，利用数学，瞬间计算结果！
}
```

说到最后，其实数学和逻辑思维才是解决问题的最终办法！

### 对象设计（面向对象、多态运用）

* 设计一个Person抽象类，包含吃饭运动学习三种行为，分为工人、学生、老师三种职业。
* 设计设计一个接口`考试`，只有老师和学生会考试。
* 设计一个方法，模拟让人类进入考场，要求只有会考试的人才能进入，并且考试。

### 二分搜索（搜索算法）

现在有一个有序数组（从小到大，数组长度 0 < n < 1000000）如何快速寻找我们想要的数在哪个位置，如果存在请返回下标，不存在返回`-1`即可。

```java
int[] arr = new int[]{1, 4, 5, 6, 7, 10, 12, 14, 20, 22, 26};   //测试用例

private static int test(int[] arr, int target){
    //请在这里实现搜索算法
}
```

### 快速排序（排序算法、递归分治）

（开始之前先介绍一下递归！）快速排序其实是一种排序执行效率很高的排序算法，它利用**分治法**来对待排序序列进行分治排序，它的思想主要是通过一趟排序将待排记录分隔成独立的两部分，其中的一部分比关键字小，后面一部分比关键字大，然后再对这前后的两部分分别采用这种方式进行排序，通过递归的运算最终达到整个序列有序。

快速排序就像它的名字一样，快速！在极端情况下，会退化成冒泡排序！

### 0/1背包问题（回溯法、剪枝/动态规划优化）

给定 `n `件物品，每一个物品的重量为 `w[n]`，每个物品的价值为 `v[n]`。现挑选物品放入背包中，假定背包能承受的最大重量为 `capacity`，求装入物品的最大价值是多少?

```java
int[] w = {2, 3, 4, 5};
int[] v = {3, 4, 5, 6};
int capacity = 8;
```