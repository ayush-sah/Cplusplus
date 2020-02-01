#include<iostream>
#include<math.h>
using namespace std;

class Hashing{
    private:
        unsigned long long int n, size, *arr, input, index, technique, no_of_digits_locations, *loc;
    public:
        Hashing(){
            do{
                cout << "Enter the size of the array: ";
                cin >> size;
                cout << "Enter the no. of digits you want to insert: ";
                cin >> n;
            }while(n>size);
            
            arr = new unsigned long long int[size];

            for(int i = 0; i < size; i++)
                arr[i] = '\0';
            cout << "\n1. Modulo Division\n2. Midsquare\n3. Digit Extraction\n4. Fold Boundary\nEnter Hashing technique no. you want to perform: ";
            cin >> technique;
            
            if(technique==3){
                cout << "\nEnter the no. of digits you want to extract: ";
                cin >> no_of_digits_locations;
                loc = new unsigned long long int[no_of_digits_locations];

                for(int i = 0; i < no_of_digits_locations; i++){
                    cout << "Enter location no. " << i+1 << " you want to extract: ";
                    cin >> loc[i];
                }

                sort_array();
            }
            cout << endl;
            while(n--){
                cout << "Enter value you want to insert: ";
                cin >> input;
                
                if (input < 0){
                    cout << "Invalid Input. Try Again\n";
                    n++;continue;
                }
                switch(technique){
                    case 1:
                        modulo();
                        break;
                    case 2:
                        midsquare();
                        break;
                    case 3:
                        digit_extraction();
                        break;
                    case 4:
                        fold_boundary();
                        break;
                    default:
                        cout << "Invalid Input.";
                }
            }
            display();
            cout << endl << endl;

        }
        void modulo();
        void midsquare();
        void digit_extraction();
        void sort_array();
        void linear_probing();
        void fold_boundary();
        void display();
        int rev(int);
};

void Hashing::display(){
    cout << "\n<---Index---><---Values--->\n";
    for(int i = 0; i < size; i++){
        cout << "Index no. " << i << " : \t";
        
        if(arr[i]=='\0')
            cout << "NULL" << endl;
        else
            cout << arr[i] << endl;
    }
}

void Hashing::modulo(){
    index = input % size;
    
    linear_probing();
    arr[index] =  input;
}

void Hashing::midsquare(){
    index = input*input;

    while(int(log10(index)+1)>2){
        index /= 10;
        index %= int(pow(10.0,float(int(log10(index)))));
        if(index<size)
            break;
    }

    if(index>=size)
        index = index%size;

    linear_probing();

    arr[index] = input;
}

void Hashing::digit_extraction(){
    for(int i = 0; i < no_of_digits_locations; i++)
        index += ((input % int(pow(10.0,float(loc[i])))) / (int(pow(10.0,float(loc[i])))/10)) * int(pow(10.0,float(i)));
    

    if(index>=size)
        index = index%size;

    linear_probing();

    arr[index] = input;
}

void Hashing::sort_array(){
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

void Hashing::fold_boundary(){
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

int Hashing::rev(int num){
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

void Hashing::linear_probing(){
    while(arr[index]!='\0'){
        if(index < size-2)
            index++;
        else
            index = 0;
    }
}

/*
void Hashing::quadratic_probing(){
    int num = 0;
    while(arr[index]!=-1){
        index = input;
        index = input    + pow(index, ) 
    }
}
*/

int main(){
    Hashing ob;
}
