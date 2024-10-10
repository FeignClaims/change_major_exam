************************************************************************************************************************
4.
************************************************************************************************************************

.. admonition:: 点击查看考点
  :class: dropdown, keyword

  生命周期, 类层次

.. code-block:: cpp
  :linenos:

   #include <iostream>

   class A {
   public:
     static int count;

     A() {
       ++count;
     }
     A(A const& /*other*/) {
       ++count;
     }

     virtual ~A() {
       --count;
     }
   };

   int A::count = 0;

   class B : public A {
   public:
     static int count;

     B() {
       ++count;
     }
     B(B const& other) : A(other) {
       ++count;
     }

     ~B() override {
       --count;
     }
   };

   int B::count = 0;

   class C : public A {
   public:
     static int count;

     C() {
       ++count;
     }
     C(C const& other) : A(other) {
       ++count;
     }

     ~C() {
       --count;
     }
   };

   int C::count = 0;

   void print_count() {
     std::cout << '(' << A::count << ", " << B::count << ", " << C::count << ")\n";
   }

   template <typename T>
   void function() {
     static T c1;
     B c2;
     A c3 = c2;
   }

   A c0;

   auto main() -> int {
     print_count();

     C c1;
     B c2;
     A();
     function<A>();
     print_count();

     static C c3;
     A* c4 = new B;
     A c5  = c1;
     print_count();

     function<A>();
     static_cast<B*>(c4);
     delete c4;
     print_count();

     function<B>();
     static_cast<A>(c2);
     print_count();
   }

.. admonition:: 点击查看答案
  :class: dropdown, solution

  :godbolt:`KT7xffrvq`

  .. code-block:: bash
    :linenos:

    (1, 0, 0)
    (4, 1, 1)
    (7, 2, 2)
    (6, 1, 2)
    (7, 2, 2)