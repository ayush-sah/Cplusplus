#include<iostream>
#include<math.h>

using namespace std;

class hashing{
    private:
        int n, size, *arr, input;
        unsigned long int index;
    public:
        hashing(){
            do{
                cout << "Enter the size of the array: ";
                cin >> size;
                cout << "Enter the no. of digits you want to insert: ";
                cin >> n;
            }while(n>size);
            
            arr = new int[size];

            for(int i = 0; i < size; i++)
                arr[i] = -1;
        }

        void fold_shift(){
            cout << endl;
            while(n--){
                cout << "Enter value you want to insert: ";
                cin >> input;
                
                if (input < 0){
                    cout << "Invalid Input. Try Again\n";
                    n++;continue;
                }
                int temp = input;
                index = 0;
                int round = 0;

                while(temp > 0){
                    if((round==0) || (temp<size))
                        index += rev(temp%size);
                    else
                        index += temp%size;
                    temp /= size;
                    round++;
                }
                
                index %= 100;
                 
                if(index>=size)
                    index = index%size;

                linear_probing();

                arr[index] = input;
            }
            display();            
        }
        void linear_probing(){
            while(arr[index]!=-1){
                    if(index < size-2)
                        index++;
                    else
                        index = 0;
                }
        }
        int rev(int num){
            if(num<10)
                return (num*10);
            else
            {
                int reverse = 0;
                while(num>0){
                    reverse = (reverse*10)+(num%10);
                    num /= 10;
                }
                return reverse;

            }
            
        }
        void display(){
            cout << "\n<---Index---><---Values--->\n";
            for(int i = 0; i < size; i++){
                cout << "Index no. " << i << " : \t";
                
                if(arr[i]==-1)
                    cout << "NULL" << endl;
                else
                    cout << arr[i] << endl;
            }
        }
};

int main(){
    hashing ob;
    ob.fold_shift();
}