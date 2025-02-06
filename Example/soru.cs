using System;

namespace Solution
{
    class Matrix
    {
        private int[ , ] mat = new int[5, 5];
        
        /*
         * Complete the missing code
         */
        
        public int Sum()
        {
            var sum = 0;
            for (var i = 0; i < 5; i++)
            {
                for (var j = 0; j < 5; j++)
                {
                    sum += mat[i, j];
                }
            }
            
            return sum;
        }
    }
    
    class Solution
    {
        static void Main(string[] args)
        {
            Matrix m = new Matrix();
            
            for (var i = 0; i < 5; i++)
            {
                for (var j = 0; j < 5; j++)
                {
                    m[i, j] = 2 * i + 3 * j;
                }
            }
            
            Console.WriteLine(m.Sum());
        }
    }
}