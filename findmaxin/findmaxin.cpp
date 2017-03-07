#include "findmaxin.h"

static bool gt(const int a, const int b)
{
  return a > b;
}

static void swap(int* buff, const int i, const int j)  
{
  assert(buff);
  int temp = buff[i];
  buff[i] = buff[j];
  buff[j] = temp;
}

void findmaxin(int *buff, const int k, const int size, const int delta)
{
  if (!buff || delta <= 0 || delta > k || k <= 0 || size <= 0 || k > size - k) {
    cout << "bad parameters." << endl;
    return;
  }
  
  int minElemIdx, zoneBeginIdx;

  sort(buff, buff + k, gt); // 首先对前k个数进行排序
  minElemIdx = k - 1; // 最小的数是第k - 1个数，数组下标从0开始计算
  zoneBeginIdx = minElemIdx; // 将标记范围的变量也指向第k - 1个数，主要用于后续的排序

  for (int i = k; i < size; i++) // 从第k个数开始循环
  {
    if (buff[i] > buff[minElemIdx]) // 从后size - k个数中找到比前k个数中最小的数大的数
    {
      swap(buff, i, minElemIdx); // 交换
      if (minElemIdx == zoneBeginIdx)
      {
        zoneBeginIdx--; // 标记范围的变量往前移动
        if (zoneBeginIdx < k - delta) // 无序的范围已经超过阈值了
        {
          sort(buff, buff + k, gt); // 再次排序
          zoneBeginIdx = minElemIdx = k - 1; // 复位
          continue;
        }
      }

      int idx = zoneBeginIdx;
      int j = idx + 1;
      // 在标记范围内查找最小的数
      for (; j < k; j++)
      {
        if(buff[idx] > buff[j])
          idx = j;
      }
      
      minElemIdx = idx; // 将指向最小数的标志置成找到的最小数的索引
    }
  }
}

