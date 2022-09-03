#include <stdlib.h>
#include <stdio.h>

/*
scenarios:
1. nums[i] is less than target.  looking for complement, target - nums[i]
2. nums[i] is greater than target, complement is still target - nums[i]? yes

so there is only one scenario lol

but the thing you are looking for in the hash map may differ. the complement can be positive or negative.

if there are negative targets we will have to write another section.  
this and other things are not accounted for in the function description,
including the max size of target

*/

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *arr_ret;
    int *mtrx;
    int *n_mtrx;
    int cmp;
    int j;
    int i;
    int temp; 

    arr_ret = (int*)malloc(sizeof(int) * 3);    
    mtrx= (int*)malloc((sizeof(int)*target)+96);
    n_mtrx = (int*)malloc((sizeof(int)*target)+96);
    j = 0;
    i = 0;
    temp = 0;
    cmp = 0;
    
    
    returnSize[0] = 2; //leetcode needs this line to run their tests
    for (j=0; j<=(target); j++)
        mtrx[j]=0;
        n_mtrx[j] = 0;
    j = 0;
    for (i = 0; i < numsSize; i++)
    {
      cmp = target - nums[i];
      (nums[i] >= 0) ? (mtrx[nums[i]] +=1) : (n_mtrx[abs(nums[i])] += 1); 
        if(cmp >= 0 && mtrx[cmp]) {   //if compliment is positive
            
            (cmp == nums[i] && mtrx[cmp] <2) ? (cmp=42): (cmp=0);
            if (cmp != 42)
            {
            arr_ret[0] = i;
            //temp = target - nums[i];
            for (j=0; j<numsSize; j++)   //find the index for the complement
                if (nums[j] == target - nums[i])
                    break;
            arr_ret[1] = j;
            free(mtrx);
            free(n_mtrx);
            return(arr_ret);
            }
            
        }
        else if (cmp < 0 && n_mtrx[abs(cmp)]) {
            for (j = 0; j < numsSize; j++)
                if (nums[j] == cmp)
                    break;
            arr_ret[0] = i;
            arr_ret[1] = j;
            free(mtrx);
            free(n_mtrx);
            return(arr_ret);
        }
    }
    free(mtrx);
    return(arr_ret);
    

}


int main (void)

{         
         
int one = 1;
int *test = NULL;
int *rtrn = NULL;

test = malloc(16);
test[0] = 0;
test[1] = 4;
test[2] = 3;
test[3] = 0; 
rtrn = (int*)malloc(12);
rtrn = twoSum(test,4, 0,rtrn); 
    
    
printf("%d, %d\n", rtrn[0], rtrn[1]);
return(0);


}