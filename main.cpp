#include <iostream>
using namespace std;
struct Side{
public:
    int** array;
    explicit Side (int** array){
        this->array=array;
    }

};
class Cube{
private:
    Side* sides[6];
    void changeSide(int n){
        int temp,temp2;
        temp=sides[n]->array[0][0];
        sides[n]->array[0][0]=sides[n]->array[0][2];
        temp2=sides[n]->array[2][0];
        sides[n]->array[2][0]=temp;
        temp=sides[n]->array[2][2];
        sides[n]->array[2][2]=temp2;
        sides[n]->array[0][2]=temp;

        temp=sides[n]->array[0][1];
        sides[n]->array[0][1]=sides[n]->array[1][2];
        temp2=sides[n]->array[1][0];
        sides[n]->array[1][0]=temp;
        temp=sides[n]->array[2][1];
        sides[n]->array[2][1]=temp2;
        sides[n]->array[1][2]=temp;
    }
    void changeColumn(int n, int n1, int m, int m1){
        sides[n1]->array[m1][0]=sides[n]->array[m][0];
        sides[n1]->array[m1][1]=sides[n]->array[m][1];
        sides[n1]->array[m1][2]=sides[n]->array[m][2];
    }
    int* takeColumn(int n,int m){
        int* result=new int[3];
        result[0]=sides[n]->array[m][0];
        result[1]=sides[n]->array[m][1];
        result[2]=sides[n]->array[m][2];
        return result;
    }
    void writeColumn(int n, int m, int* values){
        sides[n]->array[m]=values;
    }
public:
    void turnCounterclockwise(int n){
        switch (n) {
            case 1: {
                int *tmp = sides[2]->array[2];
                sides[2]->array[2] = sides[1]->array[2];
                int *tmp2 = sides[3]->array[2];
                sides[3]->array[2] = tmp;
                tmp = sides[4]->array[2];
                sides[4]->array[2] = tmp2;
                sides[1]->array[2] = tmp;
                changeSide(n-1);
                break;
            }
            case 2: {
                int *tmp = sides[5]->array[2];
                sides[5]->array[2] = sides[2]->array[2];
                int *tmp2 = sides[4]->array[2];
                sides[4]->array[2] = tmp;
                tmp = sides[0]->array[2];
                sides[0]->array[2] = tmp2;
                sides[2]->array[2] = tmp;
                changeSide(n-1);
                break;
            }
            case 3: {
                int* tmp= takeColumn(1,2);
                changeColumn(5,1,2,2);
                int* tmp2= takeColumn(3,2);
                changeColumn(0,3,2,2);
                writeColumn(5,2,tmp);
                writeColumn(0,2,tmp2);
                changeSide(n-1);
                break;
            }
            case 4: {
                int *tmp = sides[5]->array[0];
                sides[5]->array[0] = sides[2]->array[3];
                int *tmp2 = sides[4]->array[3];
                sides[4]->array[n] = tmp;
                tmp = sides[0]->array[3];
                sides[0]->array[3] = tmp2;
                sides[2]->array[3] = tmp;
                changeSide(n-1);
                break;
            }
        }
    }
    void turnClockwise(int n){
        turnCounterclockwise(n);
        turnCounterclockwise(n);
        turnCounterclockwise(n);
    }
};
int main() {

    return 0;
}
