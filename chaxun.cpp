
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main(int argc, char * argv[])
{

     ifstream ifs("123.txt");
    if(!ifs.is_open())
        perror("open file error:");
    int i=0;
    double d=0;
    while(!ifs.eof())
    {
        ifs>>d;
        ++i;
    }
    cout<<"������"<<i/4<<" ��"<<endl;

    return 0;
}
