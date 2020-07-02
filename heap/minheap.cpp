#include<bits/stdc++.h>
using namespace std;


/*
    Methods Created:
    1.int parent(int i)
    2.int left(int i)
    3.int right(int i)
    4. void minheapify(int i)
    5. void buildHeap() //It is used in consctructor when data passed to heap instance is in array
    6. void insert(int x) // for single element
    7. int getMin()
    8. int ExtractMIn()
    9. void decreaseKey(int i)
    10. void deleteKey(int i)

*/
class minheap{
    private:

        int size;
    
    public:
        vector<int> vec;
        int parent(int i){
            return (i-1)/2;
        }

        int left(int i){
            return 2*i+1;
        }

        int right(int i){
            return 2*i+2;
        }

        int siz(){ 
            return this->size;
        }

        void minheapify(int i){
            int lt=left(i), rt=right(i),smallest=i;
            if(lt<size)
            {
                if(rt<size && vec[rt]<vec[i])
                    smallest=rt;
                if(vec[lt]<vec[smallest])
                    smallest=lt;
            }
            if(smallest!=i)
            {
                swap(vec[i],vec[smallest]);
                minheapify(smallest);
            }
        }

        void buildHeap(int arr[], int n)               //This buildHeap is solely used for constructor only
        {
            for(int i=0;i<n;i++)
                vec.push_back(arr[i]);
            size=vec.size();

            for(int i=(size-2)/2;i>=0;i--)
                minheapify(i);
        }

        minheap(){
            size=0;
        }

        minheap(int arr[], int n)
        {
            buildHeap(arr,n);
        }

        void insert(int x){                                         //INSERT SINGLE ELEMENT
            vec.push_back(x);
            size++;
            int index=size-1;

            while(index>0 && vec[index]<vec[parent(index)]){
                swap(vec[index],vec[parent(index)]);
                index=parent(index);
            }
        }
        
        int getMin(){
            if(size==0)
                return INT_MAX;
            return vec[0];
        }

        int extractMin(){
            if(size==0)
                return INT_MAX;
            if(size==1)
            {
                size--;
                return vec[0];
            }
            swap(vec[0],vec[size-1]);
            size--; 
            minheapify(0); 
            return vec[size];
        }
        void decreaseKey(int index, int val){
            vec[index]=val;
            while(index>0 && vec[index]<vec[parent(index)]){
                swap(vec[index],vec[parent(index)]);
                index=parent(index);
            }
        }
        void deleteKey(int index){
            decreaseKey(index,getMin()-1);
            extractMin();
            
        }
        void printheap(){
            for(int i=0;i<size;i++){
                cout<<vec[i]<<" ";
            }
            cout<<endl;
        }
        
};


int main(){
    int arr[]={1,10,8,2,5,7,12};
    minheap mh(arr,7);
    return 0;
}