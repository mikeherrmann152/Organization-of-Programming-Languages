// C# from rosettacode

using System;
using System.Collections.Generic;
 
public class Program
{
    public static IEnumerable<int[]> Combinations(int m, int n)
    {
            int[] result = new int[m];			// creates an array named result with m elements
            Stack<int> stack = new Stack<int>(); 	// creating a new Stack from the pre-existing stack
            stack.Push(0);     	   			// adds 0 to the new stack as a place holder
 
            while (stack.Count > 0) 
           {
                int index = stack.Count - 1;		// index = # of elements in the stack - 1
                int value = stack.Pop();     		// value is set equal to the popped element of the stack
 
                while (value < n) 
               {
                    result[index++] = ++value;		// sets the result at index + 1 to value
                    stack.Push(value);			// adds this value to the new stack
 
                    if (index == m) 
                    {
                        yield return result;		// reutrns the result of the stack
                        break;	     			// breaks the while loop
                    }
                }
            }
    }
 
    static void Main()					// Beginning of the main function
    {
        foreach (int[] c in Combinations(3, 5))		// does the following code for every set of ints in the combination stack
        {
            Console.WriteLine(string.Join(",", c));	// outputs the combination
            Console.WriteLine();	       		// creats a newline
        }
    }
}
