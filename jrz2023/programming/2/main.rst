************************************************************************************************************************
2.
************************************************************************************************************************

.. admonition:: 点击查看考点
  :class: dropdown, keyword

  排序, 去除重复值

.. admonition:: 点击查看往年相同题目
  :class: dropdown, alike

  与 :doc:`计软智 2020 年第 4 题 </jrz2020/4/main>` 极为相似, 也是计算机大类实验手册上某道题的考点. 但注意这题没有提到 :cpp:`set`, 所以我们可以直接用 :cpp:`set` 实现; 而那题直接说了是要实现 :cpp:`set`, 直接用 :cpp:`set` 很可能不给分.

.. warning::

  以下内容考试中是用英文写在纸上, 也就是代码需要自己抄一遍到电脑里, 所以 **要学会正确使用键盘, 加快打字速度!**

.. include:: question.irst

.. admonition:: 点击查看解答参考
  :class: dropdown, solution

  :godbolt:`GecrPoqYT`

  题目代码虽然给出了指针, 暗示需要 :cpp:`new` 一个动态数组, 但其实可以在实现时用 :cpp:`std::set` 取巧简化. 简化后最复杂的代码反而是笔者无聊加上的输出格式要求.

  不使用 :cpp:`std::set` 地, 你可以用 :cpp:`std::vector` 和 STL 算法 :cpp:`std::sort`、:cpp:`std::unique` 简单实现: :godbolt:`njE6qdfKM`.

  另可参考我针对别人问的类似问题, 完全自己实现这些的方案:

  - :godbolt:`待补充程序 <q1sT6Yrbv>`
  - :godbolt:`参考解答 <9axcTncjM>`