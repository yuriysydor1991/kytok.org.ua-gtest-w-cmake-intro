//
// Created by cc on 02.11.23.
//

#include <locale> /* корисні функції разом з std::toupper */
#include <algorithm> /* sort for_each set_intersection і інші */
#include <set> /* std::set */
#include <iterator>

#include <gtest/gtest.h>

/*
 * Приклад перевірки функції std::isdigit
 * Опис розміщеній у статті за адресою
 * http://www.kytok.org.ua/post/cplusplus-std-isdigit
 * */
TEST(isdigitTest, isdigit_simple_test_success)
{
  std::locale loc ("uk_UA.UTF-8") ;

  // перевіряємо чи isdigit поверне true
  // для усіх наявних цифр ASCII
  // за допомогою GTest макросу EXPECT_TRUE
  for (auto iter='0'; iter<='9'; ++iter) {
    EXPECT_TRUE (std::isdigit(iter, loc));
  }

  // перевіряємо чи isdigit поверне false
  // на деяких символах алфавіту
  // за допомогою GTest макросу EXPECT_FALSE
  EXPECT_FALSE (std::isdigit(L'ї', loc));
  EXPECT_FALSE (std::isdigit(L'Ї', loc));
  EXPECT_FALSE (std::isdigit(L'г', loc));
  EXPECT_FALSE (std::isdigit(L'Ґ', loc));
}

/*
 * Приклад перевірки функції std::toupper
 * Опис розміщеній у статті за адресою
 * http://www.kytok.org.ua/post/cplusplus-std-toupper
 * */
TEST(toupperTest, toupper_simple_test_success)
{
  std::locale loc ("uk_UA.UTF-8") ;

  // перевіряємо чи toupper поверне символ
  // верхнього регістру
  // через оператор == і за допомогою
  // GTest макросу EXPECT_EQ
  EXPECT_EQ (std::toupper(L'ґ', loc), L'Ґ');
  EXPECT_EQ (std::toupper(L'ї', loc), L'Ї');
}

/*
 * Приклад перевірки функції std::tolower
 * Опис розміщеній у статті за адресою
 * http://www.kytok.org.ua/post/cplusplus-std-tolower
 * */
TEST(tolowerTest, tolower_simple_test_success)
{
  std::locale loc ("uk_UA.UTF-8") ;

  // перевіряємо чи toupper поверне символ
  // нижнього регістру
  // через оператор == і EXPECT_EQ
  EXPECT_EQ (std::tolower(L'Ґ', loc), L'ґ');
  EXPECT_EQ (std::tolower(L'Ї', loc), L'ї');
}

/*
 * Приклад перевірки функції std::set_intersection
 * Опис розміщеній у статті за адресою
 * http://www.kytok.org.ua/post/cplusplus-std-set_intersection-pereriz-mnozhyn
 * */
TEST(set_intersectionTest, set_intersection_simple_test_success)
{
  // створюємо піддослідні множини
  const std::set<int> numset1 {0, 2, 4, 6, 8, 10, 11} ;
  const std::set<int> numset2 {0, 1, 3, 5, 7, 9, 11} ;

  // очікуваний результат
  const std::set<int> expected {0, 11} ;

  std::set<int> setsIntersection ;

  // виклик функції обчислення перерізу множин
  std::set_intersection(
    numset1.begin(), numset1.end(),
    numset2.begin(), numset2.end(),
    std::inserter(setsIntersection, setsIntersection.begin())
  );

  // перевіряємо чи результуючий і очікуваний
  // контейнери рівні
  ASSERT_EQ(expected, setsIntersection);
}

