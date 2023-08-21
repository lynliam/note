## Angular Velocities

Examining the body frame at times **t**  and **t + $\Delta t$ **  , the rotation of angle $\Delta \theta$ about some uint axis $\widehat w$ passing through the origin. 

* The ratio $\vec \theta =  \frac{\Delta \theta}{\Delta t}$ is the rate of rotation $ \theta $
* $ \widehat w $  --------  instantaneous **axis** of rotation

**angular velocity** : 
$$
w = \widehat w \vec \theta
$$
<img src="MR.assets/image-20230527231326656.png" alt="image-20230527231326656" style="zoom: 67%;" />

These three equations can be rearranged into the following single 3 × 3 matrix equation:
$$
\vec R = [...]=w_s × R
$$

> <img src="MR.assets/image-20230528111034048.png" alt="image-20230528111034048" style="zoom:80%;" />
>
> <img src="MR.assets/image-20230527231556186.png" alt="image-20230527231556186" style="zoom: 80%;" />
>
> <img src="MR.assets/image-20230528111143315.png" alt="image-20230528111143315" style="zoom:80%;" />

<img src="MR.assets/image-20230528111236801.png" alt="image-20230528111236801" style="zoom:80%;" />





## Exponential Coordinate Representation of Rotation

parametrize a rotation matrix in terms of a rotation

* $\widehat w \theta$  exponential coordinate representation 
* $\widehat w$ and $\theta$ individually is the **axis-angle** representation

S



### Essential Results from Linear Differential Equations 

* The linear differential equation:
  * $\vec x(t) = Ax(t)$            
    * A $\in$ $R^{n*n}$ 
    * $\vec x(t)\in R^n$ 
* Initial condition :
  * $x(0)=x_0$

<img src="MR.assets/image-20230527224727559.png" alt="image-20230527224727559" style="zoom:67%;" />

* Solution:
  * $x(t) = e^{At}x_0$ 

### Exponential Coordinates of Rotation

### 		                                                   <img src="MR.assets/image-20230527225048029.png" alt="image-20230527225048029" style="zoom:67%;" />

This rotation can be achieved by imagining that p(0) rotates at a constant rate of 1 rand/s from time $t = 0$ to $t = \theta$ 

The velocity of p(t) :
$$
\vec p = \widehat w × p\\
=[w]p
$$
Then $\vec P$ is tangent to the path with magnitude ||p||sin φ.

The solution of this equation($[w]^3$=$-[w]$ ):
$$
p(t) = e^{[x]t}p(0)
$$

the matrix exponential of $[\widehat ω]θ = [\widehat ωθ] ∈ so(3)$ is
$$
e^{[\widehat w]\theta} = I+[\widehat w]\theta+[\widehat w]^2\frac{\theta^2}{2!}+[\widehat w]^3\frac{\theta}{3!}+...\\
=I+(\theta - \frac{\theta^3}{3!}+\frac{\theta^5}{5!}-...)[\widehat w]+(\frac{\theta^2}{2!}-\frac{\theta^4}{4!}+..)[\widehat w]^2 \\
=I+\sin\theta[\widehat w]+(1-cos\theta)[\widehat w]^2
$$

==Rodrigues’ formula for rotations==:

<img src="MR.assets/image-20230528105404132.png" alt="image-20230528105404132" style="zoom:67%;" />

$R' = e^{[\widehat w]\theta }R = Rot(\widehat w , \theta)R$    Orientation achieved by rotation R by $\theta $  in the fixed frame

$R''=R e^{[\widehat w]\theta}  = RRot(\widehat w , \theta)$  Orientation achieved by rotation R by $\theta $ in the body frame



The orientation of the frame {b} can be represented by

* R
* unit axis $\widehat w$ and angle $\theta$
* $\widehat w \theta$

### Matrix Logarithm of Rotation

The matrix logarithm is the inverse of the matrix exponential. Just as the matrix exponential “**integrates**” the matrix representation of an angular velocity $[ˆω]θ ∈ so(3)$ for one second to give an orientation R ∈ SO(3), the matrix logarithm “**differentiates**” an R ∈ SO(3) to find the matrix representation of a constant angular velocity [ˆω]θ ∈ so(3) which, if integrated for one second, rotates a frame from I to R. In other words:
$$
EXP: [\widehat w]\theta \in so(3)   \rightarrow R\in SO(3)  \\
LOG: R \in so(3)   \rightarrow [\widehat w]\theta \in SO(3)
$$


* **$\widehat ω$θ ∈ R** 3 represents the exponential coordinates of a rotation matrix R
* the skew-symmetric matrix $[\widehat ωθ] = [\widehat ω]θ$ is the ==matrix logarithm== of the rotation R.



#### When the $\theta \neq k\pi$ 

Expend each entry for  $e^{[\widehat w]\theta}$ in Equation (3.51):

![image-20230528134156293](MR.assets/image-20230528134156293.png)

> $\widehat w = (\widehat w_1,\widehat w_2,\widehat w_3)\\s\theta =sin\theta   \\ c\theta =  \cos\theta$

Setting the above matrix equal to the given R ∈ SO(3) and subtracting the transpose from both sides leads to the following:

![image-20230528134916373](MR.assets/image-20230528134916373.png)

Therefore, as long as sin $θ \neq 0$ (or, equivalently, θ is not an integer multiple of π), we can write:

![image-20230528135044003](MR.assets/image-20230528135044003.png)

The above equations can also be expressed in skew-symmetric matrix form a

<img src="MR.assets/image-20230528135126605.png" alt="image-20230528135126605" style="zoom:80%;" />

If any $\theta$ satisfying :

![image-20230528135307537](MR.assets/image-20230528135307537.png)

such that $\theta$ is not an integer multiply  of $\pi$



#### When the $\theta = k\pi$ 

When k is an odd integer (corresponding to θ = ±π, ±3π, . . ., which in turn implies tr R = −1), the exponential formula (3.51) simplifies to:
$$
R= e^{[\widehat w]\pi} = I+2[\widehat w]^2  \tag{3.55}
$$
The three diagonal terms of Equation (3.55) can be manipulated to give：
$$
\widehat w_i = \sqrt{\frac{r_{ii}+1}{2}} \ \ , i=1,2,3  \tag{3.56}
$$
The off-diagonal terms lead to the following three equations:
$$
2\widehat w_1 \widehat w_2 = r_{12} \\
2\widehat w_2 \widehat w_3 = r_{23} \\
2\widehat w_4 \widehat w_3 = r_{13}
\tag{3.57}
$$
![image-20230528140634429](MR.assets/image-20230528140634429.png)

![image-20230528141602431](MR.assets/image-20230528141602431.png)



------

## Rigid-Body Motions and twists



### Homogeneous Transformation Matrices

**Definition 3.13:  ** The special Euclidean group SE(3), also known as the group of rigid-body motions or homogeneous transformation matrices in $R^3$, is the set of all **4 × 4** real matrices T of the form
$$
^AP=
\begin{bmatrix}
^AR_B & t\\
0_{1×2} & 1
\end{bmatrix}
\ ^BP\\
=^AT_B\ ^BP \\
=
\begin{bmatrix}
r_{11} && r_{12} && r_{13} && p_1  \\
r_{21} && r_{22} && r_{23} && p_2  \\
r_{31} && r_{32} && r_{33} && p_3  \\
0 && 0 && 0 && 1  
\end{bmatrix}
$$

where $R ∈ SO(3)$ and $p ∈ R^3$ is a column vector.



### Properties of Transformation Matrices

#### Proposition 3.15. 

The inverse of a transformation matrix T ∈ SE(3) is also a transformation matrix, and it has the following form:
$$
T^{-1} = \begin{bmatrix}
R && p \\
0 && 1
\end{bmatrix}
=  
\begin{bmatrix}
R^T && -R^Tp \\
0 && 1
\end{bmatrix}
$$

#### Rroposition 3.16. 

The product of two transformation matrices is also a transformation matrix.

#### Proposition 3.17.

 The multiplication of transformation matrices is associative, so that $(T_1T_2)T_3 = T_1(T_2T_3)$, but generally not commutative: $T_1T_2 \neq T_2T_1$.

#### Proposition 3.18. 

Given T = (R, p) ∈ SE(3) and x, y ∈ R 3 , the following hold:

1. $||T_X-T_Y|| = ||x-y||$ , where $||·||$ denotes the standard Euclidean norm in $R_3$ , i.e. , $||x|| = \sqrt {xTx}$.
> standard Euclidean norm
> 欧几里得范数指得就是通常意义上的距离范数。例如在欧式空间里，它表示两点间的距离(向量x的模长)。
> 欧几里得范数就是三维空间中的距离向欧氏空间的延伸
2. $<T_x-T_y, T y − T z> = <x - z, y − z>$ for all z $\in R^3$, where <.,.> denotes the standard Euclidean inner product $\in R^3, hx, yi = x^Ty$.

### Use of Transformation Matrices

* to represent the configuration (position and orientation) of a rigid body 
*  to change the reference frame in which a vector or frame is represented
*  to displace a vector or frame

