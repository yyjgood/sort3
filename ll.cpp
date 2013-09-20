
#include<iostream>
#include<fstream>
#include <algorithm>
#include<iomanip>
using namespace std;

const int M = 18522;
const int N = 4;
static double a[M][N];
void BubbleSort(double *A,int n,int r);

int main()
{


	int i,j;
	//打开文件，可在此更改输入文件
	ifstream fin("p");

	if(!fin.is_open())
		perror("open file error:");
    //读入数组
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
            fin>>a[i][j];
	fin.close();

double b[M],c[M];
//	//对第三列排序

	for(i = 0;i < M;i++)
		b[i] = a[i][2];
	BubbleSort(b,M,0);

//	//对第二列排序

    static int k = 0;
    while(k < M)
    {
        int count = 1;
        while(b[k] == b[k+1])
        {
            count++;
            k++;
        }

    /*cout << k <<endl;*/
       if(count > 1)
        {
            int p = (k - count + 1 ) ;
            int r = p;
            double *cc = new double [count];
            for(i = 0;i < count;i++,p++)
                cc[i] = a[p][1];

            BubbleSort(cc,count,r);
			delete [] cc;
        }else k++;

    }

//对第一列排序
	for(i = 0;i < M;i++)
		c[i] = a[i][1];
    static int f = 0;
    while(f < M)
    {
       int count = 1;
        while(b[f] == b[f+1])
        {
            count++;
            f++;
        }

    if(count > 1)
    {
    static int q = 0;
    while(q < count)
    {
        int count1 = 1;
        while(c[q] == c[q+1])
        {
            count1++;
            q++;
        }

    if(count1 > 1)
        {
            int p = (q - count1 +1 ) ;
            int r = p;
            int s;
            double *dd = new double [count1];
            for(s = 0;s < count1;s++,p++)
                dd[s] = a[p][0];

			BubbleSort(dd,count1,r);
			delete [] dd;
        }else q++;

    }
    }else f++;

    }


	//排序完毕输出到文件，可在此更改输出文件
	ofstream fout("p.txt" ,ios::out | ios::trunc);
	if(!fout.is_open())
	{
		cerr << "open fail" << endl;
		exit(EXIT_FAILURE);
	}
	for (i=0;i<M;i++)
	{

		for (j=0;j<N;j++,fout<<' ')
		{
			fout << setw(15)<<a[i][j];
			fout << ' ';
		}
		fout << endl;
	}
cout << "运算完毕\n";
}

//冒泡排序
void BubbleSort(double *A,int n,int r)
{

	int flag=1;
	for(int i=1;i<n;i++)
	{
		flag=0;
		for(int j=n-1;j>=i;j--)
			if(A[j]<A[j-1])
			{
				double t;
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t; flag=1;
				swap(a[j+r],a[j+r-1]);
			}
			if(flag==0)
				return;
	}
}

