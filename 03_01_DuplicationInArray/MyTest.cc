#include <iostream>
#include <stdio.h>

void printcurrentarry(int numbers[], int length) {
  for (int i = 0; i < length; i++) {
    std::cout << numbers[i] << "";
  }

  std::cout << std::endl;
}

bool duplicate(int numbers[], int length, int *duplication) {
  if (numbers == nullptr || length < 0) {
    return false;
  }

  for (int index = 0; index < length; index++) {
    if (numbers[index] > length - 1 || numbers[index] < 0) {
      std::cout << "data " << numbers[index] << " out of range";
      *duplication = -1;
      return false;
    }
  }

  printcurrentarry(numbers, length);

  for (int index = 0; index < length; index++) {
    int index_value = numbers[index];

    while (index_value != index) {
      int value_index_value = numbers[index_value];
      if (index_value == value_index_value) {
        *duplication = index_value;
        return true;
      } else {
        // switch this two value
        numbers[index_value] = index_value;
        numbers[index] = value_index_value;
        index_value = value_index_value;
      }
      printcurrentarry(numbers, length);
    }
  }

  *duplication = -1;
  return false;
}

// ====================测试代码====================
bool contains(int array[], int length, int number) {
  for (int i = 0; i < length; ++i) {
    if (array[i] == number)
      return true;
  }

  return false;
}

void test(char *testName, int numbers[], int lengthNumbers, int expected[],
          int expectedExpected, bool validArgument) {
  printf("%s begins: ", testName);

  int duplication;
  bool validInput = duplicate(numbers, lengthNumbers, &duplication);

  std::cout << validInput << " " << duplication << std::endl;

  if (validArgument == validInput) {
    if (validArgument) {
      if (contains(expected, expectedExpected, duplication))
        printf("Passed.\n");
      else
        printf("FAILED.\n");
    } else
      printf("Passed.\n");
  } else
    printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1() {
  int numbers[] = {2, 1, 3, 1, 4};
  int duplications[] = {1};
  test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2() {
  int numbers[] = {2, 4, 3, 1, 4};
  int duplications[] = {4};
  test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3() {
  int numbers[] = {2, 4, 2, 1, 4};
  int duplications[] = {2, 4};
  test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4() {
  int numbers[] = {2, 1, 3, 0, 4};
  int duplications[] = {-1}; // not in use in the test function
  test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5() {
  int numbers[] = {2, 1, 3, 5, 4};
  int duplications[] = {-1}; // not in use in the test function
  test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications,
       sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6() {
  int *numbers = nullptr;
  int duplications[] = {-1}; // not in use in the test function
  test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int),
       false);
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();

  return 0;
}
