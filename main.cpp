
#include<iostream>
#include<fstream>
#include <algorithm>
#include<iomanip>
#include <windows.h>
using namespace std;

const int S = 100;
const int N = 4;
void BubbleSort(double *A,int n,int r,double **a);

int main()
{


	int i,j;
	int M = 0;
	char infilename[S];
    cout<<"Enter name of input file:\n";
    cin.getline(infilename, S);
    ifstream ifs(infilename);
    if(!ifs.is_open())
        {
          perror("open file error:");
          exit(EXIT_FAILURE);
        }

    static int e=0;
    double d=0;
    while(!ifs.eof())
    {
       ifs>>d;
        ++e;
    }
   ifs.close();
   cout << e <<endl;

    if(e < 4)
    {
        cout<<"文件"<<infilename<<"不足1行，请检查输入文件"<<endl;
        Sleep(3000);
        exit(EXIT_FAILURE);
    }else
    M = e/4;




	//打开文件
//    char infilename[S];
//    cout<<"Enter name of input file:\n";
  //  cout<<endl;
//    cin.getline(infilename, S);

	ifstream fin(infilename);

	if(!fin.is_open())
	{
	    perror("open file error:");
	    exit(1);
	}

    //动态申请二维数组
	double **a;
	a=new double*[M];
	for(i=0;i<M;i++)
		a[i]=new double[N];

    //读入数组
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
            fin>>a[i][j];
	fin.close();

double b[M],c[M];
//	//对第三列排序

	for(i = 0;i < M;i++)
		b[i] = a[i][2];
	BubbleSort(b,M,0,a);

//	//对第二列排序

    static int k = 0;
    while(k < (M-1))
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

            BubbleSort(cc,count,r,a);
			delete [] cc;
        }else k++;

    }

//对第一列排序
	for(i = 0;i < M;i++)
		c[i] = a[i][1];
    static int f = 0;
    while(f < (M-1))
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
    while(q < (count - 1))
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

			BubbleSort(dd,count1,r,a);
			delete [] dd;
        }else q++;

    }
    }else f++;

    }


	//排序完毕输出到文件，可在此更改输出文件
	char outfilename[S];
	cout<<endl;
    cout<<"Enter name of output file:\n";
    cout<<endl;
    cin.getline(outfilename, S);
	ofstream fout(outfilename ,ios::out | ios::trunc);
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
void BubbleSort(double *A,int n,int r,double **a)
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

