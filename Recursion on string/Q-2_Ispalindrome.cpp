#include <iostream>
using namespace std;
bool f(int num, int *temp)
{
    if (num >= 0 and num <= 9)
    {
        int lastDisgitOfTemp = (*temp) % 10;
        (*temp) /= 10;
        return (num == lastDisgitOfTemp);
    }
    bool result = (f(num / 10, temp) and (num % 10) == ((*temp) % 10));
    (*temp) /= 10;
    return result;
}
int main()
{
    int num=66;
    int anotherNum=num;
    int *temp=&anotherNum;
    cout<<f(num,temp);
    return 0;
}