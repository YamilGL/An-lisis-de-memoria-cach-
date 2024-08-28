#include <iostream>
#include <thread>
using namespace std;

#define MAX 4


void bucle_1(double A[MAX][MAX], double x[MAX], double y[MAX])
{
      for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            y[i] += A[i][j]*x[j];
        }
        
    }
    cout<<"bucle_1"<<endl;
}
void bucle_2(double A[MAX][MAX], double x[MAX], double y[MAX])
{
      for (int j = 0; j < MAX; j++)
    {
        for (int i = 0; i < MAX; i++)
        {
            y[i] += A[i][j]*x[j];
        }
        
    }
    cout<<"bucle_2"<<endl;
}
int main()
{

    double A[MAX][MAX], x[MAX], y[MAX];

    //inicializamos con valores 0
    for( int i = 0 ; i < MAX;i++)
    {
        for( int j = 0 ; j <MAX;j++)
        {
            A[i][j] = 0;
        }
    }

    for( int i = 0 ; i <MAX;i++)
    {
        x[i] = 0;
        y[i] = 0;
    }

    //iniciamos los bucles con threads
    std::thread hilo1(bucle_1,A,x,y);
    std::thread hilo2(bucle_2,A,x,y);


    hilo1.join();
    hilo2.join();

    return 0;
}