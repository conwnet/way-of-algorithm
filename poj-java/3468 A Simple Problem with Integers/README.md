# POJ 3468 A Simple Problem with Integers

## 题目链接

* [POJ](http://poj.org/problem?id=3468)
* [百练](http://bailian.openjudge.cn/practice/3439/)
* [百练](http://bailian.openjudge.cn/practice/3243/)

## 题目描述

给定一个数组，包含 N 个元素 A1, A, ..., AN。定义两种操作：

* `C a b c` => 把区间 [a, b] 中的所有元素都加上 x
* `Q a b` => 查询区间 [a, b] 中所有元素的和）

共有 Q 次操作，输出每次查询操作的结果。

## 数据规模

1 ≤ N,Q ≤ 100000

-1000000000 ≤ Ai ≤ 1000000000

-10000 ≤ c ≤ 10000

## 解题思路

N, Q 可达 100000，直接更新数组每一个元素的话，最坏情况是十万次更新每次都更新整个数组，显然超时。所以：

1. 线段树使用 Lazy 标记实现区间更新
2. 改造树状数组区间更新

这里使用的是改造树状数组实现的区间更新。