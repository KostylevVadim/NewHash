#include "Dictionary.h"
#include "Indexer.h"
#include "Cache.h"
#include <ctime>
#include "Vector.h"
#include "..\..\Lab1\Lab1\ArraySequence.h"
using namespace std;

//Разреженный вектор, индексирование, кеширование

void Dictest() {
    srand(time(0));
    Dictionary<int, int> a;
    LinkedList<int> keys;
    LinkedList<int> data;
    for (int i = 0; i < 10; i++) {
        keys.Append(rand() % 100);
        data.Append(rand() % 10);
    }
    cout << "\n=======================";
    for (int i = 0; i < 10; i++) {
        cout << "\nKey " << keys.Get(i) << " Data " << data.Get(i) << "\n";
        a.Add(keys.Get(i),data.Get(i));
    }
    a.Print();
    cout << "=======================\nContains:\n";
    for (int i = 0; i < 10; i++) {
        cout << a.ContainsKey(keys.Get(i)) << "\n";
    }
    
    int x = rand() % 10;
    a.remove(keys.Get(x));
    cout << "Removing\n"<<"X "<<x<<" "<<keys.Get(x)<<"\n";
    for (int i = 0; i < 10; i++) {
        cout << a.ContainsKey(keys.Get(i)) << "\n";
    }
    a.Print();
}
int Index_int(int a) {
    return a+1;
}
bool Index_bool(int a) {
    if (a % 2 == 1)
        return 1;
    else
        return 0;
}

void Indextest() {
    srand(time(0));
    //cout << 1;
    ArraySequence<int>* a = new ArraySequence<int>;
    //cout << 2;
    for (int i = 0; i < 10; i++) {
        a->Append(rand() % 10);
    }
    //cout << 3;
    for (int i = 0; i < 10; i++)
        cout << a->Get(i) << " ";;
    Indexer<int,int> C((ArraySequence<int>*)a,Index_int);
    Dictionary<int, int> A = C.ReturnIndexed();
    A.Print();
    
}

int Mapper(int a) {
    return a+1;
}

int Reducer(int a, int b) {
    return a + b;
}

bool Wherer(int a) {
    if (a % 2 == 0)
        return 1;
    else
        return 0;
}

void Vectortest() {
    srand(time(0));
    int* a = new int[10];
    int* b = new int[10];
    for (int i = 0; i < 10; i++)
        a[i] = 0;
    a[9] = rand() % 10;;
    for (int i = 0; i < 10; i++)
        b[i] = rand() % 10;
    Vector<int> l1(a, 10);
    Vector<int> l2(b, 10);
    Vector<int> l3 = l2 + l1;
    Dictionary<int, int> L1 = l1.Get();
    L1.Print();
    Dictionary<int, int> L2 = l2.Get();
    L2.Print();
    Dictionary<int, int> L3 = l3.Get();
    L3.Print();
    
    /*
    int Mult = l1 * l2;
    cout << "MULT\n" << Mult<<"\n";
    Vector<int> f1 = l2.Map(Mapper);
    Dictionary<int, int> F1 = f1.Get();
    F1.Print();
    int A = l2.reduce(Reducer,0);
    cout<<"\nReduce: "<< A<<"\n";
    Vector<int> f2 = l2.Where(Wherer);
    Dictionary<int, int> F2 = f2.Get();
    F2.Print();
    int* y = new int[1000];
    for (int i = 0; i < 1000; i++)
        y[i] = 0;
    y[1] = 768;
    y[465] = 879;
    y[877] = 678;
    Vector<int> l4(y, 1000);
    Dictionary<int, int> L4 = l4.Get();
    L4.Print();*/
}
void Cachetest() {
    srand(time(0));
    ArraySequence<int>* a = new ArraySequence<int>;
    a->Append(41);
    a->Append(467);
    a->Append(334);
    a->Append(500);
    Cache<int> C(2);
    C.Enter(a->Get(0));
    C.Enter(a->Get(0));
    C.Enter(a->Get(1));
    C.Enter(a->Get(2));
    C.Enter(a->Get(2));
    C.Enter(a->Get(0));
    
    Dictionary<int, int> H = C.Get();
    H.Print();
    
}

int main()
{
    Cachetest();
}
