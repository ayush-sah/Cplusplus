#include <iostream>
using namespace std;
class sorting
{
public:
    int arr[100], max[100], sort[100], min[100], size, choice;
    sorting()
    {
        cout << "Enter The Size Of Array: ";
        cin >> size;
        for (int i = 0; i < size; i++)
            arr[i] = max[i]= sort[i] = min[i] = 0;
        for (int i = 0; i < size; i++){
            cout << "Enter element no. " << i+1 << ": ";
            cin >> arr[i];
        }
        cout << "Entered values: ";
        display();
        do
        {
            cout << " \n 1) Build Max heap and display \n 2) Build Min heap and display \n 3) Apply heap sort and display \n 4) Exit  \n Enter Your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << endl << "Max Heap Tree";
                MaxHeap();
                break;
            case 2:
                cout << endl << "Min Heap Tree";
                MinHeap();
                break;
            case 3:
                HeapSort();
                break;
            case 4:
                break;
            default:
                break;
            }
        } while (choice != 4);
    }

    void heapify(int n,int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && sort[l] > sort[largest])
            largest = l;
        if (r < n && sort[r] > sort[largest])
            largest = r;
        if (largest != i)
        {
            swap(&sort[i], &sort[largest]);
            heapify(n,largest);
        }
    }

    void HeapSort()
    {
        for (int i = 0; i < size; i++)
            sort[i] = arr[i];

        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(size, i);
            
        for (int i = size - 1; i >= 0; i--) 
        { 
            swap(&sort[0], &sort[i]);
            heapify(i,0); 
        } 
        cout << "\n Sorted Elements : \n";
        for (int i = 0; i < size; ++i)
        {  
            cout << "sort[" << i << "] : " << sort[i] << "\t";
        }
    }
    
    void MaxHeap()
    {
        for (int i = 0; i < size; i++)
            max[i] = arr[i];

        for (int i = (size / 2) + 1; i >= 0; i--)
            maxheapify(i);
        cout << "\n Normal view:\n";
        for (int i = 0; i < size; ++i)
        {  
            cout << "max[" << i << "] : " << max[i] << "\t";
        }
        cout << "\n";
        displayTree(max);
    }

    void maxheapify(int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && max[l] > max[largest])
            largest = l;
        if (r < size && max[r] > max[largest])
            largest = r;
        if (largest != i)
        {
            swap(&max[i], &max[largest]);
            maxheapify(largest);
        }
    }
    void MinHeap()
    {
        
        for (int i = 0; i < size; i++)
            min[i] = arr[i];

        for (int i = (size / 2) - 1; i >= 0; i--)
             minheapify(i);
            
        cout << "\n Normal view:\n";
        for (int i = 0; i < size; ++i)
        {  
            cout << "min[" << i << "] : " << min[i] << "\t";    
        }
        cout << "\n";
        displayTree(min);
    }
    void minheapify(int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && min[l] < min[largest])
            largest = l;
        if (r < size && min[r] < min[largest])
            largest = r;
        if (largest != i)
        {
            swap(&min[i], &min[largest]);
            minheapify(largest);
        }
    }
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void display()
    {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
    void displayTree(int a[])
    {
        for(int i = 0;i<size/2;i++)
            cout<<"Parent: "<<a[i]<<" Left child: "<<a[2*i+1]<<" Right child: "<<a[2*i+2]<<endl;
    }
};

int main()
{
    sorting s;
}