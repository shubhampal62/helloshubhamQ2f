#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>
#include <linux/kernel.h>

int main()
{
    int rows = 4;
    int cols = 5;
    float SourceMat[4][5] = {{1, 1, 1, 1, 1}, {2, 2, 2, 2, 2}, {3, 3, 3, 3, 3}, {4, 4, 4, 4, 4}};
    float DestMat[4][5] = {0};
    printf("Desitination Before copy :\n");
    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 5; j++)
        {
            printf("%f\t", DestMat[i][j]);
        }
        printf("\n");
    }
    long sys_call_status;
    sys_call_status = syscall(452, SourceMat, DestMat, 4, 5);
    printf("After copy : \n");
    for (int k = 0; k < 4; k++)
    {
        for (int l = 0; l < 5; l++)
        {
            printf("%f ", DestMat[k][l]);
            printf("\n ");
        }
    }
    if (sys_call_status != EFAULT)
    {
        printf("successfully invoked SYSTEM CALL \n");

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (DestMat[i][j] != SourceMat[i][j])
                {
                    printf("Error Destination Matrix and Source Matrix are not same\n");
                    return 0;
                }
            }
        }
        printf("Destination and Source Matrix are same \n");
    }
    printf("SUCCESS");
}
return 0;
