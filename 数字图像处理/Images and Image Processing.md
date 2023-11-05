



## Images and Image Processing 

### Spatial Operations

#### Nonparameteric Local Transforms

We can apply a local transform to the image and template before matching.

##### Census transform

* Choosing a 3x3 or 5x5 matrix. If a pixel is greater than the center pixel , its correspinding bit is set to one, else it is zero. For a w × w widows the string will be x<sup>2</sup>-1 bits long. 
* The two bit strings will be compared by Hamming Distance

> Hamming distance:
>
> 假如一组二进制数据为101，另外一组为111，那么显然把第一组的第二位数据0改成1就可以变成第二组数据111，所以两组数据的汉明距离就为1
>
> 简单点说，汉明距离就是一组二进制数据变成另一组数据所需的步骤数（它表示两个相同长度的字符串对应位置的不同字符的数量），显然，这个数值可以衡量两张图片的差异，汉明距离越小，则代表相似度越高。汉明距离为0，即代表两张图片完全一样

Advantages:

* Few arithmetic operations
* invariant only applied by intensities changing.

##### Rank transform 

​	The only difference between them is it is the sum of the bits strings.

##### Example:

![image-20230425220733610](C:\Users\Quan2\AppData\Roaming\Typora\typora-user-images\image-20230425220733610.png)

​	Example of census and rank  transform for a 3 × 3 window.  Pixels are marked red or blue if they are less than or greater than or equal to the center  pixel respectively. These boolean values are then packed into  a binary word, in the direction  shown, from least signifi cant bit  upwards. The census value is  101011012 or decimal 173. The  rank transform value is the total  number of one bits and is 5



#### Nonlinear Operation



