************************************************************************************************************************
4. :cpp:`Set`
************************************************************************************************************************

.. admonition:: 点击查看考点
  :class: dropdown, keyword

  排序, 去除重复值

.. include:: question.irst

.. admonition:: 点击查看解答参考
  :class: dropdown, solution

  由于题目就给出了 :cpp:`Set`, 此处不能使用 :cpp:`std::set`. (另见可以使用 :cpp:`std::set` 的 :doc:`/jrz2023/index` 最后一题.)

  你可以用 :cpp:`std::vector` 和 STL 算法 :cpp:`std::sort`、:cpp:`std::unique` 简单实现: :godbolt:`nEnKE7q4G`.

  另可参考我针对别人问的类似问题, 完全自己实现这些的方案:

  - :godbolt:`待补充程序 <q1sT6Yrbv>`
  - :godbolt:`参考解答 <9axcTncjM>`
