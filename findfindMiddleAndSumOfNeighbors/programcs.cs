using System;
using System.Linq;

public class Solution
{
	public int findMiddleAndSumOfNeighbors(int[] arr) {

		int length = arr.Length;
		
		if (length < 3)
		{
			return -1;
		}
		
		int middleIndex = length / 2;
		
		if (length % 2 == 0)
		{
			int middleElement = arr[middleIndex - 1];
			int leftNeighbor = arr[middleIndex - 2];
			int rightNeighbor = arr[middleIndex];
			
			return leftNeighbor + rightNeighbor;
		}
		else
		{
			int middleElement = arr[middleIndex];
			int leftNeighbor = arr[middleIndex - 1];
			int rightNeighbor = arr[middleIndex + 1];
			
			return leftNeighbor + rightNeighbor;
		}
	}
}