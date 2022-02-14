#pragma once
#include "Dictionary.h"

template <typename T> class Cache {
private:
	Dictionary<T, int> dat;
	int cachelength;
	void Removesmallestrequest() {
		if (dat.Count() != 0) {
			int m = std::numeric_limits<int>::max();
			T key = 0;
			for (int i = 0; i < dat.length; i++)
				for (int j = 0; j < dat.length_collisions[i]; j++)
					if (m > dat.data[i].Get(j))
					{
						m = dat.data[i].Get(j);
						key = dat.keys[i].Get(j);
					}

			dat.remove(key);
		}


	}
	void Add(T data) {
		if (dat.ContainsKey(data) == 0) {
			cout<<"\n========\nData Count\n=========\n"<< dat.Count()<<"\n=========\n";
			if (dat.count == cachelength) {
				cout << "\n========\nRemoving smallest request\n=========\n";
				Removesmallestrequest();
				dat.Add(data, 1);
			}
			else {
				dat.Add(data, 1);
			}
			//cachelength++;
		}
		else {
			int q = dat.GetVal(data);
			cout<<"We look here Request is "<< q<<"\n";
			dat.remove(data);
			dat.Add(data, q + 1);
		}
		
		cout << "\nAdd Works\nCount " << dat.count << " Cachelength " << cachelength << "\n";
	}
public:
	Cache() {};
	Cache(Sequence<T>* data, int len) {
		cachelength = len;
		dat = Dictionary<T, int>(len);
		cout << "Select:\n1.Exit\n2.Get\n";
		int usrch = -1;
		while (usrch!=1)
		{
			cin >> usrch;
			if (usrch == 2) {
				int u;
				cin >> u;
				Add(u);
			}
			dat.Print();
			cout << "Select:\n1.Exit\n2.Get\n";
		}
	}
	Cache(int len) {
		cachelength = len;
		dat = Dictionary<T, int>(len);

	}
	int GetRequest(T data1) {
		for (int i = 0; i < dat.length; i++)
			for (int j = 0; j < dat.length_collisions[i]; j++)
				if (dat.keys[i].Get(j) == data1)
					return dat.data[i].Get(j);
	}
	void Enter(T data) {
		Add(data);
	}
	Dictionary<T, int> Get() {
		return dat;
	}
};