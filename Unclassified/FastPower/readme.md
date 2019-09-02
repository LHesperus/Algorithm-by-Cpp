### 快速幂和矩阵快速幂
快速幂算法：<br>
思想：将幂写成二进制，分别计算 1 2 4 8 16 ...次幂，这些幂都是上一次计算值的平方，
所以可以节省很多次幂运算，算法时间复杂度为O(logN)
为了避免结果过大溢出，常常快速幂取模。

矩阵快速幂：
将底数换为矩阵即矩阵快速幂<br>
注意算法中有一步初始化是单位阵，不是全为1

### Example1
求斐波那契序列较大的某位值 <br>
$f(1)=0,f(2)=1$ <br>
递推公式：<br>
$$f(n)=f(n-1)+f(n-2)$$<br>
矩阵表示：<br>
$  \left[\begin{matrix} f(n)\\f(n-1) \end{matrix} \right] $=$\left[ \begin{matrix} 1 & 1\\ 1& 0 \end{matrix}  \right]$ $ \left[ \begin{matrix} f(n-1)\\f(n-2)\end{matrix}  \right]  $<br>
如果网页无法显示公式，则用Cmd Markdown查看。