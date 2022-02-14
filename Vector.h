#pragma once
#include "Dictionary.h"
template<typename R> class Vector
{
private:
	Dictionary<int, R> a;
	int GetInd(R dat) {
		for (int i = 0; i < a.length; i++)
			for (int j = 0; j < a.length_collisions[i]; j++)
				if (dat == a.data[i].Get(j))
					return a.keys[i].Get(j);
	}
	int Maxindex() {
		int m = 0;
		for (int i = 0; i < a.keys.size(); i++)
			for (int j = 0; j < a.keys[i].GetLength(); j++)
				if (m < a.keys[i].Get(j))
					m = a.keys[i].Get(j);
		return m;
	}
public:
	Vector() {
	};
	Vector(R* vector, int length) {
		for (int i = 0; i < length; i++) {
			if(vector[i]!=0)
				a.Add(i, vector[i]);
			
		}
		
		

	}
	Dictionary<int, R> Get() {
		return a;
	}
	Vector operator + (Vector b) {
		//cout << 1;
		//assert(b.a.Count()==this->a.Count());

		R* a1 = new R[Maxindex()];
		for (int i = 0; i < Maxindex(); i++)
			a1[i] = 0;
		R* b1 = new R[b.Maxindex()];
		for (int i = 0; i < b.Maxindex(); i++)
			b1[i] = 0;
		//cout << "Vector 1 size" << a.length<<"\n";
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length_collisions[i]; j++) {
				cout << a.keys[i].Get(j)<<" "<< a.data[i].Get(j)<<"\n";
				a1[a.keys[i].Get(j)] = a.data[i].Get(j);
			}
		}
		cout << "\n=============\n";
		for (int i = 0; i < b.a.data.size(); i++) {
			for (int j = 0; j < b.a.length_collisions[i]; j++) {
				cout << b.a.keys[i].Get(j) << " " << b.a.data[i].Get(j) << "\n";
				b1[b.a.keys[i].Get(j)] = b.a.data[i].Get(j);
			}
		}
		int l = Maxindex();
		int l1 = b.Maxindex();
		cout << "l  l1 " << l << " " << l1<< "\n";
		
		
		int m;
		R* rez;
		if (l >= l1) {
			rez = new R[l];
			m = l;
			for (int i = 0; i <= l; i++) {
				//cout << a1[i] << "+" << b1[i] << "=" << a1[i] + b1[i]<<"\n";
				if (i <= l1)
				{
					if (l1 == 0)
						rez[i] = a1[i];
					else
						rez[i] = a1[i] + b1[i];
					
				}
				else {
					rez[i] = a1[i];
				}
				cout << rez[i] << "\n";
			}
		}
		else {
			rez = new R[l1];
			m = l1;
			for (int i = 0; i <= l1; i++) {
				//cout << "============";

				if (i <= l)
					if (l == 0)
						rez[i] = b1[i];
					else
						rez[i] = a1[i] + b1[i];
				else {
					rez[i] = b1[i];
				}
				//cout << rez[i] << "\n";
			}
		}
		Vector<R> z(rez,m+1);
		
		return z;
	}
	Vector operator - (Vector b) {

		R* a1 = new R[Maxindex()];
		for (int i = 0; i < Maxindex(); i++)
			a1[i] = 0;
		R* b1 = new R[b.Maxindex()];
		for (int i = 0; i < b.Maxindex(); i++)
			b1[i] = 0;
		//cout << "Vector 1 size" << a.length<<"\n";
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length_collisions[i]; j++) {
				cout << a.keys[i].Get(j) << " " << a.data[i].Get(j) << "\n";
				a1[a.keys[i].Get(j)] = a.data[i].Get(j);
			}
		}
		cout << "\n=============\n";
		for (int i = 0; i < b.a.data.size(); i++) {
			for (int j = 0; j < b.a.length_collisions[i]; j++) {
				cout << b.a.keys[i].Get(j) << " " << b.a.data[i].Get(j) << "\n";
				b1[b.a.keys[i].Get(j)] = b.a.data[i].Get(j);
			}
		}
		int l = Maxindex();
		int l1 = b.Maxindex();
		cout << "l  l1 " << l << " " << l1 << "\n";


		int m;
		R* rez;
		if (l >= l1) {
			rez = new R[l];
			m = l;
			for (int i = 0; i <= l; i++) {
				if (i <= l1 && l1!=0)
					rez[i] = a1[i] - b1[i];
				else {
					rez[i] = a1[i];
				}
			}
		}
		else {
			rez = new R[l1];
			m = l1;
			for (int i = 0; i <= l1; i++) {
				//cout << "============";

				if (i <= l && l!=0)
					rez[i] = a1[i] - b1[i];
				else {
					rez[i] = -b1[i];
				}
				//cout << rez[i] << "\n";
			}
		}
		Vector<R> z(rez, m + 1);
		return z;
	}
	R operator * (Vector b) {

		R* a1 = new R[Maxindex()];
		for (int i = 0; i < Maxindex(); i++)
			a1[i] = 0;
		R* b1 = new R[b.Maxindex()];
		for (int i = 0; i < b.Maxindex(); i++)
			b1[i] = 0;
		//cout << "Vector 1 size" << a.length<<"\n";
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length_collisions[i]; j++) {
				//cout << a.keys[i].Get(j) << " " << a.data[i].Get(j) << "\n";
				a1[a.keys[i].Get(j)] = a.data[i].Get(j);
			}
		}
		cout << "\n=============\n";
		for (int i = 0; i < b.a.data.size(); i++) {
			for (int j = 0; j < b.a.length_collisions[i]; j++) {
				//cout << b.a.keys[i].Get(j) << " " << b.a.data[i].Get(j) << "\n";
				b1[b.a.keys[i].Get(j)] = b.a.data[i].Get(j);
			}
		}
		int l = Maxindex();
		int l1 = b.Maxindex();
		//cout << "l  l1 " << l << " " << l1<< "\n";
		int m;
		R rez = 0;
		if (l >= l1) {

			//m = l;
			if (l1 == 0) {
				return 0;
			}
			for (int i = 0; i <= l1; i++) {
				//cout<<a1[i]<<"*"<<b1[i]<<" = "<< a1[i] * b1[i];
				rez = rez + a1[i] * b1[i];

			}
			//cout <<"I am here\n";
		}
		else {
			//cout << "I am here2\n";
			if (l == 0) {
				return 0;
			}
			for (int i = 0; i <= l; i++) {
				rez = rez + a1[i] * b1[i];

			}
		}
		return rez;
	}
	Vector Map(R(*(mapper))(R)) {
		Vector<R>z;

		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length_collisions[i]; j++) {
				cout << a.data[i].Get(j) << mapper(a.data[i].Get(j)) << "\n";
				z.a.Add(a.keys[i].Get(j), mapper(a.data[i].Get(j)));
			}
		}
		return z;
	}
	R reduce(R(*reducer)(R, R), R c) {
		R res = c;
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length_collisions[i]; j++) {
				res = res + a.data[i].Get(j);
			}
		}
		return res;
	}
	Vector Where(bool(*(wherer))(R)) {
		int l = 0;

		Vector<R> z;
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length_collisions[i]; j++) {
				if (wherer(a.data[i].Get(j)))
				{
					//cout<< a.keys[i].Get(j) << " "<< a.data[i].Get(j)<<"\n";
					z.a.Add(a.keys[i].Get(j), a.data[i].Get(j));
				}
			}
		}

		return z;
	}
};
