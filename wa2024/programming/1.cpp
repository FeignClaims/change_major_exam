#include <algorithm>
#include <iostream>
#include <ostream>
#include <random>
#include <tuple>
#include <vector>

auto is_leap_year(int year) -> bool {
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

auto is_valid_year(int year) -> bool {
  return 1970 <= year && year <= 2023;
}

auto is_valid_month(int month) -> bool {
  return 1 <= month && month <= 12;
}

class Year_month_day {
 public:
  explicit Year_month_day(int year = 1970, int month = 1, int day = 1)
      : year_(year), month_(month), day_(day) {}

  auto year() const -> int {
    return year_;
  }
  auto month() const -> int {
    return month_;
  }
  auto day() const -> int {
    return day_;
  }

  auto is_valid() const -> bool {
    return is_valid_year(year_) && is_valid_month(month_)
           && (1 <= day_ && day_ <= last_day());
  }

  auto last_day() const -> int {
    if (month_ == 2 && is_leap_year(year_)) {
      return 29;
    }
    int const last_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return last_days[month_ - 1];
  }

  friend auto operator<(Year_month_day const& lhs,
                        Year_month_day const& rhs) -> bool {
    // 你也可以一个个比较年、月、日, 但更简单地: (当然还有更简单的方法, 但下面展示的方法我认为是老师认知的极限了)
    return std::tie(lhs.year_, lhs.month_, lhs.day_)
           < std::tie(rhs.year_, rhs.month_, rhs.day_);
  }

  friend auto operator<<(std::ostream& ostream,
                         Year_month_day const& ymd) -> std::ostream& {
    ostream << ymd.year_ << '/' << ymd.month_ << '/' << ymd.day_;
    return ostream;
  }

 private:
  int year_;
  int month_;
  int day_;
};

// 插入排序的思路是:
// - 在最左边维护一个已有序的部分.
// - 对于右边还未有序的部分, 取其中第一个元素, 将其插入到左边有序部分的对应位置.
//
// 例如:
//   ...
//   1 2 5 8 | 3 9 6 7 5
//   1 2 3 5 8 | 9 6 7 5
//   1 2 3 5 8 9 | 6 7 5
//   ...
//
// 应该都会写, 所以我就用 <algorithm> 简单写一下了……是的, 插入排序就只需三四行代码
// 范围、迭代器和算法: https://question-board.readthedocs.io/faq/range_iterator_and_algorithm
template <typename Iter>
void insertion_sort(Iter first, Iter last) {
  for (Iter iter = first; iter != last; ++iter) {
    // 1     2 5 8 3 9 6 7 5
    // ↑           ↑         ↑
    // first       iter      last
    //
    // [first, iter) 构成已经排序的部分: 1 2 5 8
    // [iter, last)  构成还没排序的部分: 3 9 6 7 5
    //------------------------------------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------------------------------------
    auto insertion_point = std::upper_bound(first, iter, *iter);
    // 1     2 5 8             3 9 6 7 5
    // ↑       ↑               ↑         ↑
    // first   insertion_point iter      last
    //
    // upper_bound 在 [first, iter) 中二分查找到第一个大于 *iter 的元素的位置
    // 如果想要线性查找呢? 把 std::upper_bound 改为 std::find
    //------------------------------------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------------------------------------
    // 1 2 5 8             3    9 6 7 5
    //     ↑               ↑    ↑
    //     insertion_point iter std::next(iter)
    //
    // [insertion_point, iter): 5 8
    // [iter, std::next(iter)): 3
    std::rotate(insertion_point, iter, std::next(iter));
    // rotate 将 [iter, std::next(iter)) 旋转到 [insertion_point, iter) 前面
    // 即 [5, 8, ) | [3, ) 变成 [3, ) | [5, 8, )
    //------------------------------------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------------------------------------
    // 最终得到:
    // 1     2 3 5 8 3 9 6 7 5
    // ↑           ↑           ↑
    // first       iter        last
  }
}

// 随机数的生成: https://question-board.readthedocs.io/faq/generate_random_number
auto generate_random_year_month_day() -> Year_month_day {
  static std::mt19937 gen{std::default_random_engine{}()};
  return Year_month_day{std::uniform_int_distribution<>{1970, 2023}(gen),
                        std::uniform_int_distribution<>{1, 12}(gen),
                        std::uniform_int_distribution<>{1, 31}(gen)};
}

auto main() -> int {
  std::vector<Year_month_day> ymds;
  for (int i = 0; i < 10; ++i) {
    ymds.push_back(generate_random_year_month_day());
  }

  insertion_sort(ymds.begin(), ymds.end());

  for (auto const& ymd : ymds) {
    if (ymd.is_valid()) {
      std::cout << ymd << '\n';
    }
  }
}