#include<iostream>
#include<math.h>
using namespace std;

class hashing{
    private:
        int n, size, *arr, input, index, *loc, no_of_digits_locations;
    public:
        hashing(){
            do{
                cout << "Enter the size of the array: ";
                cin >> size;
                cout << "Enter the no. of digits you want to insert: ";
                cin >> n;
            }while(n>size);
            arr = new int[size];
            cout << "\nEnter the no. of digits you want to extract: ";
            cin >> no_of_digits_locations;
            loc = new int[no_of_digits_locations];
            for(int i = 0; i < no_of_digits_locations; i++){
                cout << "Enter location no. " << i+1 << " you want to extract: ";
                cin >> loc[i];
            }
            sort_array();

            arr = new int[size];

            for(int i = 0; i < size; i++)
                arr[i] = -1;
        }

        void modulo(){
            cout << endl;
            while(n--){
                index = 0;
                cout << "Enter value you want to insert: ";
                cin >> input;

                if (input < 0){
                    cout << "Invalid Input. Try Again\n";
                    n++;continue;
                }

                for(int i = 0; i < no_of_digits_locations; i++)
                    index += ((input % int(pow(10.0,float(loc[i]))))/(int(pow(10.0,float(loc[i])))/10))*int(pow(10.0,float(i)));
                

                if(index>=size)
                    index = index%size;

                while(arr[index]!=-1){
                    if(index < size-2)
                        index++;
                    else
                        index = 0;
                }
                arr[index] = input;
            }
            display();
        }
        
        void sort_array(){
            for(int i = 0; i < no_of_digits_locations; i++){
                for(int j = 0; j < (no_of_digits_locations-i)-1; j++){
                    if(arr[j]>arr[j+1]){
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
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
    ob.modulo();
}