using System;
using System.Linq;

public class Solution
{
    public int findMiddleAndSumOfNeighbors(int[] arr)
    {
        if (arr == null || arr.Length < 3)
        {
            return -1;
        }

        int middleIndex = arr.Length / 2;
        int sumOfNeighbors = 0;

        if (arr.Length % 2 == 1)
        {
            // Eleman sayısı tek ise, ortadaki elemanı kabul edin
            sumOfNeighbors = arr[middleIndex - 1] + arr[middleIndex + 1];
        }
        else
        {
            // Eleman sayısı çift ise, ortadaki ikiliden solda yer alan elemanı kabul edin
            sumOfNeighbors = arr[middleIndex - 1] + arr[middleIndex];
        }

        return sumOfNeighbors;
    }
}


