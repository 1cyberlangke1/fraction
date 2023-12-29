# fraction  

##  前言  

> 这东东只是我一个菜狗闲的没事练习打字的结果  
> 所以可能有很多bug qwq  
> 一个头文件 定义了一个新类型frac  

##  目录  

>[【frac】](#frac)  
>[【getfrac】](#getfrac)  
>[【putfrac】](#putfrac)  
>[【frac_op】](#frac_op)  
>[【frac_cmp】](#frac_cmp)  

##  frac  

frac是一个新的类型, 包含了nume(分子)和denom(分母)  
例如:  

```C
frac a;
a.nume=1;
a.denom=2;
```

##  getfrac  

getfrac是一个函数, 用于从用户输入中获取一个分数  

```C
frac getfrac();
```




##  putfrac  

putfrac是一个函数, 用于输出一个分数  

```C
void putfrac(frac x);
```



##  frac_cmp  

比较两个分数  

```C
frac_cmp(frac a,frac b);
//a>b时返回 2
//a<b时返回 0
//a=b时返回 1
```

##  frac_op  

对两个分数进行运算  

```C
void frac_op(frac a, frac b, frac* c, char op);
//a: 运算的第一个数
//b: 运算的第二个数
//c: 运算结果
//op: 一个字符, 表示运算符, 支持'+' '-' '*' '/' '%'(只能对两个正数求余)
```

