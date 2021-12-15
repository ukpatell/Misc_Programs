// Quick Sort - In Class Program
// Names: Umangkumar Patel
//        Vasilli
// 
#include<iostream>
using namespace std;

void quicksort (int [], int,int);

int main()
{
    int array[10] = {9,13,51,42,77,18,2,67,55,32};
    cout << "Unsorted List : ";
    for(int i = 0; i < 10; i++)
    {
        cout << array[i] << "  ";
    }
    cout << endl;
    quicksort(array, 0, 9);
    cout << "\nSorted List : ";
    for(int i = 0; i < 10; i++)
    {
        cout << array[i] << "  ";
    }
    
    
    return 0;
}


void split (int x[], int first, int last, int &pos)
/*--------------------------------------------------------
   Rearrange x[first], ... , x[last] to position pivot.

   Precondition:   < and == are defined for ElementType;
      first <= pos <= last.  Note that this version
      chooses pivot = x[first]; better pivot choices
      are described later in this section.
   Postcondition: Elements of sublist are rearranged and
      pos modified so x[first], ... , x[pos-1 <= pivot
            and pivot < x[pos + 1]\, ... , x[last].
----------------------------------------------------------*/
{
   int pivot = x[first];            // pivot element
   int left = first,                // index for left search
       right = last;                // index for right search
   while (left < right)
   {
      while (pivot < x[right])      // Search from right for
         right--;                   //    element <= pivot
                                    // Search from left for
      while (left < right &&        // element > pivot
             (x[left] < pivot || x[left] ==  pivot))
         left++;

      if (left < right)             // If searches haven't met
         swap(x[left], x[right]);   //     interchange elements
   }
   // End of searches; place pivot in correct position
   pos = right;
   x[first] = x[pos];
   x[pos] = pivot;
} 

void swap(int num1, int num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

void quicksort (int x[], int first, int last)
/*-------------------------------------------------------
   Quicksort array elements x[first], ..., x[last] so
   they are in ascending order.

   Precondition: < and == are defined for ElementType.
      Note: Client programs call quicksort with first = 1
      and last = n - 1, where n is the list size
   Postcondition: x[first], ..., x[last] is sorted
---------------------------------------------------------*/
{
   int pos;                         // pivot's final position
   if (first < last)                // list size is > 1
   {
      split(x, first, last, pos);   // Split into 2 sublists
      quicksort(x, first, pos - 1); // Sort left sublist
      quicksort(x,pos + 1, last);   // Sort right sublist
   }
   // else list has 0 or 1 element and requires no sorting
} 

