/*************************************************************************
  > File Name: 6-29.cpp
  > Author: wolf
  > Mail: wolfguidao@163.com 
  > Created Time: 2020年06月15日 星期一 22时05分57秒
 ************************************************************************/

#include "Header.hpp"

#if 0
int max_array(int *a,int n);
int max_matrix(int **a,int m,int n)//int **a 指针数组,m*n矩阵
{   
    int max_sum=0;
    int *b=new int[n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            b[j]=0;
        }
        for(int j=i;j<m;j++)
        {
            for(int k=0;k<n;k++)
                b[k]+=a[j][k];
            int sum=max_array(b,n);
            if(sum>max_sum)
                max_sum=sum;
        }
    }
    return max_sum;
}
int max_array(int *a,int n)
{
    int sum=0;
    int b=0;
    for(int i=0;i<n;i++)
    {
        if(b<0)
            b=a[i];
        else
            b+=a[i];
        if(b>sum)
            sum=b;
    }
    return sum;
}

int main()
{


    //int b[5]={1,-1,0,-3,5};
    //cout<<max_array(b,5)<<endl;//测试max_array方法是否正确
    //getchar();
    //int m,n;
    //cout<<"输入矩阵的行数m:"<<endl;
    //cin>>m;
    //cout<<"输入矩阵的列数n:"<<endl;
    //cin>>n;
    //int **a=new int*[m];
    //for(int i=0;i<m;i++)
    //{
    //	a[i] = new int[n];
    //	for(int j=0;j<n;j++)
    //	{

    //		cin>>a[i][j];
    //	}
    //}
    //cout<<max_matrix(a,m,n);
    int n = 2,m = 4;
    int** a = new int*[m];
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            a[i][j] = random();
        }
    }
    cout<<max_matrix(a,m,n)<<endl;
    return 0;
}
#endif

//a为原矩阵，row，col指a矩阵的行和列，result存储最终得到的子二维矩阵
#if 0
void get_max_22Matrix(int *a,int row,int col,int *result)
{
    int maxsum=0,result_i,result_j,sum;
#define a(i,j) *(a+(i)*col+(j))  //用二维的形式表示一维数组，访问需要一定的代价
#define result(i,j) *(result+(i)*2+(j))

    for(int i=0; i<row-1; i++)
        for(int j=0; j<col-1; j++)
        {
            sum = a(i,j)+a(i+1,j)+a(i,j+1)+a(i+1,j+1); //访问四个元素并相加得到当前的和
            if(maxsum<sum) //更新最大子二维矩阵数据
            {
                maxsum = sum;
                result_i = i;
                result_j = j;
            }
        }

    /* 将结果存储到result二维数组中*/
    result(0,0)=a(result_i,result_j);
    result(1,0)=a(result_i+1,result_j);
    result(0,1)=a(result_i,result_j+1);
    result(1,1)=a(result_i+1,result_j+1);
#undef a
#undef result
}

int main()
{
    int a[] = {1,4,6,8,3,2}; 
    int b[6];
    get_max_22Matrix(a,3,2,b);
    cout<<b[0]<<endl; 
    return 0;
}

#endif
#if 0
#include <iostream>  
#include <algorithm>  
using namespace std;  

#define MAXN 1003  
int A[MAXN][MAXN];  
long long PS[MAXN][MAXN];  

inline long long MatrixSum(int s, int t, int i, int j)  
{  
    return PS[i][j]-PS[i][t-1]-PS[s-1][j]+PS[s-1][t-1];  
}  

int main()  
{  
    int m, n, i, j;  
    cin >> n >> m;  
    for (i=1; i<=n; i++)  
        for (j=1; j<=m; j++)  
            cin >> A[i][j];  

    for (i=0; i<=n; i++)  
        PS[i][0] = 0;  
    for (j=0; j<=m; j++)  
        PS[0][j] = 0;  
    // 计算矩阵的部分和  
    for (i=1; i<=n; i++)  
        for (j=1; j<=m; j++)  
            PS[i][j] = A[i][j]+PS[i-1][j]+PS[i][j-1]-PS[i-1][j-1];  
    int a, c;  
    long long All = A[1][1];  
    for (a=1; a<=n; a++)  
        for (c=a; c<=n; c++)  
        {  
            // 将子矩阵上下边界设为第a行和第c行，在这些子矩阵中取最大值  
            long long Tail = MatrixSum(a, 1, c, 1);  
            for (j=2; j<=m; j++)  
            {  
                Tail = max(MatrixSum(a, j, c, j),   
                        MatrixSum(a, j, c, j)+Tail);   
                All = max(Tail, All);  
            }  
        }  
    cout << All;  
}  
#endif
#if 0
int maxSubmatrixSum(std::vector<std::vector<int>> matrix, int n, int m){
    int base_sum;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            base_sum += matrix[i][j];
        }
    }

    int result = 0;
    for (int i = 0; i + n - 1 < matrix.size(); i++) {
        if(i  > 0){
            for (int y = 0; y < m; y++){
                base_sum += matrix[i + n - 1][y] - matrix[i - 1][y];
            }
        }
        int real_sum = base_sum;
        if (real_sum  > result) {
            result = real_sum;
        }
        for (int j = 0; j + m - 1 < matrix.size(); j++) {
            for (int x = 0; x < n; x++) {
                real_sum += matrix[i+x][j + m - 1] - matrix[i+x][j - 1];
            }
            if (real_sum > result) {
                result = real_sum;
            }
        }
    }
    return result;
}
#endif 

#if 0
int maxSubmatrixSum(std::vector<std::vector<int>> matrix,int n,int m){
    int base_sum = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            base_sum += matrix[i][j];
        }
    }

    int result = 0;
    for(int i=0 ; i+n<matrix.size() ; i++){
        if(i>0){
            for(int y=0 ; y<m ; y++){
                result += matrix[i+n][y] - matrix[i-1][y];
            }
        }
        int real_sum = base_sum;
        if(real_sum > result){
            result = real_sum;
        }
        for(int j=0 ; j+m<matrix.size() ; j++){
            for(int x=0 ; x<n ; x++){
                real_sum += matrix[x][j+m] - matrix[x][j-1];
            }   
            if(real_sum>result){
                result = real_sum;
            }
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> arr {{1,2},{3,4},{-99,999}};
    cout<<maxSubmatrixSum(arr,3,2)<<endl;    
    return 0;
}
#endif

int maxSubmatrixSum(std::vector<std::vector<int>> matrix,
        int n, int m) {
    int base_sum;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            base_sum += matrix[i][j];
        }
    }
    int result = 0;
    for (int i = 0; i + n-1 < matrix.size(); i++) {
        if(i  > 0){
            for (int y = 0; y < m; y++){
                base_sum += matrix[i + n-1][y] - matrix[i - 1][y];
            }
        }
        int real_sum = base_sum;
        if (real_sum  > result) {
            result = real_sum;
        }
        for (int j = 0; j + m < matrix[i].size(); j++) {
            for (int x = i; x < i+n; x++) {
                real_sum += matrix[x][j + m] - matrix[x][j];
            }
            if (real_sum > result) {
                result = real_sum;
            }
        }
    }
    return result;
}
int main()
{
    vector<vector<int>> arr {{1,2},{3,4},{-99,999}};
    cout<<maxSubmatrixSum(arr,0,0)<<endl;    
    return 0;
}
