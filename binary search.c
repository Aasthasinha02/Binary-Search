#include <stdio.h>
//swap function takes integer pointer as its parameters so as to swap the values
//at the original address(pass by reference concept)
void swap(int*n1,int*n2) 
{
    int x=0;
    x=*n2;
    *n2=*n1;
    *n1=x;
}

int binarysearch( int inputArray[],int num,int valuetofind)
{
    /// What/?
    int lo = 0;
    int hi = num-1;
    int found = -1;  // varialbe found signifies the index of value to be found
    
    printf("Searching %d in list\n", valuetofind);
    
    // while loop used to check for the value inserted
    while (1)
    {
        int mid = (hi + lo) / 2;
        printf("Check at index %d\n", mid);
        
        if (inputArray[mid] == valuetofind)
        {
            printf("Found at %d\n", mid);
            found = mid;
            break;
        }
        
        /// this statement signifies that when both high and low value becomes
        /// equal then the operation needs to be stopped as while(1) will keep 
        ///on opereating until we break the loop with this statement.
        if (hi == lo)
        {
            break;
        }
        
        // the values of hi and lo are chnaged as a result of comparing the valuetofind 
        //with the mid value of the array so as to perform binary search operation.
        if (inputArray[mid] < valuetofind)
        {
            lo = mid + 1;
            printf("Checking in 2nd half (%d - %d)\n", lo, hi);
        }
        else
        {
            hi = mid - 1;
            printf("Checking in 1st half (%d - %d)\n", lo, hi);
        }
        
    }// End of while loop
    
    return found;
}

    
void bubblesort( int inputArray[],int num)
{
    while(1)
    {
        int i=0;
        
        int swappingdone=0; //swappingdone variable declared to show whether
                            //swapping is performed in the iteration or not
        
        
        for(i=0;i<num-1;i++) //(num-1) signifies the comparision to take place between
                             //the desired values(as num=6 but the index numbers are till 5)
        {
            if(inputArray[i]>inputArray[i+1])
            {
                swap(&inputArray[i],&inputArray[i+1]);
                swappingdone=1;
            
            }
        }
       
        if(swappingdone==0) //this shows that futher the elements of the array
                           //cannot be swapped hence the operation is stopped
        {
            break;
        }
    }    
    
}
//display fucntion to display the inputArray
void display(int inputArray[], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", inputArray[i]);
    }
    printf("\n");
}

int main()
{
    int inputArray[]={-1,20,40,80,-8,-9,89};
    int num=sizeof inputArray/sizeof inputArray[0];
    int valuetofind= 89;
    
    printf("Input array:\n");
    display(inputArray,num);

    bubblesort(inputArray,num);
    
    printf("Sorted array:\n");
    display(inputArray,num);
    
    int foundIndex = binarysearch(inputArray,num,valuetofind);
    if (foundIndex != -1)
    {
        printf("%d found at index %d in its sorted form\n", valuetofind, foundIndex);
    }
    else
    {
        printf("%d NOT found!\n", valuetofind);
        
    }
    
    return 0;
}