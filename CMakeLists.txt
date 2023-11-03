# Версія CMake на якій розроблявся проект
cmake_minimum_required(VERSION 3.16.3)

# виномимо довгу назву проекту
# у окрему змінну для зручності
set(PRJ "kytok_org_ua_gtest_w_cmake_intro")

# обов'язкова команда project з назвою проекту
project(
  ${PRJ} 
  VERSION 1.0.0
  DESCRIPTION "Демонстративний проект використання GTest разом з CMake"
  HOMEPAGE_URL "http://www.kytok.org.ua/post/cmake-komanda-project"
  LANGUAGES CXX
)

# встановлюємо використовувану пову і її стандарт
set(CMAKE_CXX_STANDARD 17)

# додаємо джерельні файли до проекту
add_executable(
        ${PRJ}
        tests-examples/GTestsExamples.cpp
)

# виконуємо пошук GTest фреймворку і
# імпортуємо його
find_package(GTest REQUIRED)

# вмикаємо тестування для
# використання програмую ctest
enable_testing()

# компонуємо об'єктні побудовані файли
# проекту з головною функцією main
# яку нам люб'язно проедоставляє GTest
# зазвичай, головний файл проекту не 
# компонується з тестовою main-функцією
target_link_libraries(
        ${PRJ}
        GTest::gtest_main
)

# додаємо зенерований бінарний файл
# проекту у якості тесту для виконання
# командою ctest
add_test(
        NAME ${PRJ}
        COMMAND $<TARGET_FILE:${PRJ}>
)
