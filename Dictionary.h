#pragma once
#include <iostream>
#include <vector>
#include "..\..\Lab1\Lab1\ArraySequence.h"
#include "..\..\Lab2\Lab2\LinkedList.h"

template <class T, class R> class Pair {
public:
	T key;
	R value;
	Pair() {};
	Pair(T key, R value) {
		this->key = key;
		this->value = value;
	}
	bool operator==(Pair pair) {
		return key == pair.key && value == pair.value;
	}
	bool operator!=(Pair pair) {
		return key != pair.key || value != pair.value;
	}
	bool operator>(Pair pair) {
		return key > pair.key;
	}
	bool operator<(Pair pair) {
		return key < pair.key;
	}
	bool operator>=(Pair pair) {
		return key >= pair.key;
	}
	bool operator<=(Pair pair) {
		return key <= pair.key;
	}
	friend ostream& operator<<(ostream& out, const Pair& pair) {
		out << "key: ";
		out << pair.key;
		out << "; ";
		out << "value: ";
		out << pair.value;
		return out;
	}
};

template<typename T, typename R>class IDictionary {
public:
	virtual size_t Count() = 0;
	virtual void Add(T, R) = 0;
	virtual void remove(T) = 0;
	virtual R GetVal(T) = 0;
	virtual bool ContainsKey(T) = 0;
};

template <typename T, typename R> class Dictionary : public IDictionary<T, R> {
private:
	

	//коеффицент загрузки 
	double koef=0.75;
	int reserver;
	//хешфункция
	int Hashfunction(int key) {
		if(reserved_length !=0)
			return key % reserved_length;
		else {
			return 0;
		}
	}
	
	//Функция переделывания массива, если реальная заполненность больше чем 0.75
public:
	void Rework() {
		int reserved_cells = 0;
		for (int i = 0; i < reserved_length; i++) {
			reserved_cells += reserved_length_collisions[i];
		}
		double cur = (count + 0.0) / reserved_cells;
		if (cur > koef) {
			/*vector<T> all_keys;
			vector<R> all_data;
			for (int i = 0; i < length; i++) {
				for (int j = 0; j < length_collisions[i]; j++) {
					all_keys.push_back(keys[i].Get(j));
					all_data.push_back(data[i].Get(j));
				}
			}
			int newreservedlength = 0;
			while (newreservedlength<all_keys.size())
			{
				newreservedlength += reserver;
			}
			cout << "\nall\n";
			//for (int i = 0; i < all_data.size(); i++)
				//cout << "Key " << all_keys[i] << " Data" << all_data[i] << "\n";
			//cout << newreservedlength;
			vector<LinkedList<T>> newkeys;
			vector<LinkedList<R>> newdata;
			vector<size_t> newreserved_length_collisions;
			vector<size_t> newlength_collisions;
			//cout << 1;
			for (int i = 0; i < newreservedlength; i++) {
				newdata.push_back(LinkedList<T>(reserver));
				newkeys.push_back(LinkedList<R>(reserver));
				newreserved_length_collisions.push_back(reserver);
				//!!!!
				newlength_collisions.push_back(0);
			}
			for (int i = 0; i < all_keys.size(); i++)
				newlength_collisions[i] += 1;
			cout << 2;
			//cout<<" " << all_data.size()<<" "<<newreservedlength<<"\n";
			for (int i = 0; i < all_data.size(); i++) {
				
				newdata[i].Set(0, all_data[i]);
				newkeys[i].Set(0, all_keys[i]);
				//cout << i << " ";

			}
			cout << 3;
			keys.clear();
			data.clear();
			reserved_length_collisions.clear();
			length_collisions.clear();
			keys = newkeys;
			data = newdata;
			length = all_keys.size();
			reserved_length = newreservedlength;
			//cout << "newreservedlength " << reserved_length<<"\n";
			reserved_length_collisions = newreserved_length_collisions;
			//cout << newreserved_length_collisions.size()<<"\n";
			length_collisions = newlength_collisions;*/
			NewRework();
		}
	};
	void NewRework() {
		vector<T> all_keys;
		vector<R> all_data;
		cout << "\n1jhksadhjkhjskad\n";
		for (int i = 0; i < keys.size(); i++) {
			for (int j = 0; j < length_collisions[i]; j++) {
				all_keys.push_back(keys[i].Get(j));
				all_data.push_back(data[i].Get(j));
			}
		}
		cout << "\n2jhksadhjkhjskad\n";
		int newreservedlength = 0;
		while (newreservedlength < all_keys.size())
		{
			newreservedlength += reserver;
		}
		if (newreservedlength == 0)
			newreservedlength = 1;
		Dictionary<T, R> copy(newreservedlength);
		for (int i = 0; i < all_data.size(); i++) {
			copy.Add(all_keys[i], all_data[i]);
		}
		keys = copy.keys;
		data = copy.data;
		//count = count;
		reserved_length = copy.reserved_length;
		length = copy.length;
		reserved_length_collisions = copy.reserved_length_collisions;
		length_collisions = copy.length_collisions;
		/*int newreservedlength = 0;
		while (newreservedlength < all_keys.size())
		{
			newreservedlength += reserver;
		}
		reserved_length = newreservedlength;
		count = 0;
		length = 0;
		reserver = newreservedlength;
		keys.clear();
		data.clear();
		reserved_length_collisions.clear();
		for(int i=0;i<all_keys.size();i++)
			reserved_length_collisions.push_back(reserver);
		length_collisions.clear();
		for (int i = 0; i < all_keys.size(); i++)
			length_collisions.push_back(0);
		cout << all_keys.size() << "===???" << all_data.size();
		for (int i = 0; i < all_keys.size(); i++)
			Add(all_keys[i], all_data[i]);
		cout << "\n3jhksadhjkhjskad\n";*/
		/*
		int newreservedlength = 0;
		while (newreservedlength < all_keys.size())
		{
			newreservedlength += reserver;
		}
		cout << "\nall\n";
		//for (int i = 0; i < all_data.size(); i++)
			//cout << "Key " << all_keys[i] << " Data" << all_data[i] << "\n";
		//cout << newreservedlength;
		vector<LinkedList<T>> newkeys;
		vector<LinkedList<R>> newdata;
		vector<size_t> newreserved_length_collisions;
		vector<size_t> newlength_collisions;
		//cout << 1;
		for (int i = 0; i < newreservedlength; i++) {
			newdata.push_back(LinkedList<T>(reserver));
			newkeys.push_back(LinkedList<R>(reserver));
			newreserved_length_collisions.push_back(reserver);
			//!!!!
			newlength_collisions.push_back(0);
		}
		for (int i = 0; i < all_keys.size(); i++)
			newlength_collisions[i] += 1;
		cout << 2;
		//cout<<" " << all_data.size()<<" "<<newreservedlength<<"\n";
		for (int i = 0; i < all_data.size(); i++) {

			newdata[i].Set(0, all_data[i]);
			newkeys[i].Set(0, all_keys[i]);
			//cout << i << " ";

		}
		cout << 3;
		keys.clear();
		data.clear();
		reserved_length_collisions.clear();
		length_collisions.clear();
		keys = newkeys;
		data = newdata;
		length = all_keys.size();
		reserved_length = newreservedlength;
		//cout << "newreservedlength " << reserved_length<<"\n";
		reserved_length_collisions = newreserved_length_collisions;
		//cout << newreserved_length_collisions.size()<<"\n";
		length_collisions = newlength_collisions;
		*/
	}
public:
	//коллекция списков ключей
	vector<LinkedList<T>> keys;

	//коллекция списков данных
	vector<LinkedList<R>> data;

	//количество заполненных ячеек
	size_t count;

	//зарезервированная длина коллекций
	size_t reserved_length;
	//реальная величина массива
	size_t length;
	//коллекция длин списков коллизий 
	vector<size_t> reserved_length_collisions;

	//коллекция заполненных данных
	vector<size_t> length_collisions;
	//создаём словарь и резервируем данные сразу же
	Dictionary() {
		
		count = 0;
		length = 0;
		reserver = 10;
		reserved_length = reserver;
		for (int i = 0; i < reserver; i++)
		{
			data.push_back(LinkedList<R>(reserver));
			keys.push_back(LinkedList<T>(reserver));
			reserved_length_collisions.push_back(reserver);
			length_collisions.push_back(0);
		}
	};
	Dictionary(int reserver1) {

		count = 0;
		length = 0;
		reserver = reserver1;
		reserved_length = reserver;
		for (int i = 0; i < reserver; i++)
		{
			data.push_back(LinkedList<R>(reserver));
			keys.push_back(LinkedList<T>(reserver));
			reserved_length_collisions.push_back(reserver);
			length_collisions.push_back(0);
		}
	};

	//создаём словарь и резервируем данные сразу же
	
	
	size_t Count() {
		return count;
	};

	void Add(T key, R data1) {
		//Получение индекса
		//if (ContainsKey(key))
		//	return;
		//cout << "I am in ADD";
		//cout << reserved_length << " ";
		int z = Hashfunction(key);
		//cout << z << "\n";
		
		
		//Что делать в случае, если z меньше чем занятая длина
		if (z < length) {
			//cout << "I am in ADD1";
			int current_list_reserved_length = keys[z].GetLength();
			int current_list_length = length_collisions[z];
			if (current_list_length + 1 >= current_list_reserved_length) {
				for (int i = 0; i < reserver; i++) {
					
					keys[z].Append(0);
					data[z].Append(0);
					
				}
				reserved_length_collisions[z] += reserver;

			}
			
			keys[z].Set(length_collisions[z], key);
			data[z].Set(length_collisions[z], data1);
			length_collisions[z] += 1;
			count++;

		}
		//Иначе
		if(z >= length){
			//cout << "I am in ADD2";
			while (z >= length) {
				
				length++;
			}
			keys[z].Set(0, key);
			data[z].Set(0, data1);
			
			length_collisions[z] =1;
			count++;
			
		}
		//cout << "I am in ADD3";
		Rework();
		
	};
	void remove(T key) {
		assert(ContainsKey(key) != 0);
		int z = Hashfunction(key);
		//int index_key_to_find = 0;
		//cout <<"\n===Remove===\n";
		//cout << "\nHashfunction now is " << Hashfunction(key) << "\n";
		//cout << "Length collision before " << length_collisions[z]<< "\n";
		for (int i = 0; i <= length_collisions[z]; i++)
		{
			//cout << "Looking for " << key << " now in is" << keys[z].Get(i)<<"\n";
			if (key == keys[z].Get(i)) {
				keys[z].Shift(i);
				data[z].Shift(i);
				length_collisions[z]--;
				break;
			}
		}
		//cout<<"Length collision after"<< length_collisions[z] <<"\n";
		while (length_collisions[z]<reserved_length_collisions[z]/2)
		{
			//cout << "I am here \n";
			keys[z].DeleteEnd();
			data[z].DeleteEnd();
			reserved_length_collisions[z] = reserved_length_collisions[z]/2;
		}
		//cout << 3;
		if (length_collisions[z] == 0) {
			//cout << "Before Rework \n";
			//Print();
			NewRework();
			//cout << "After Rework \n";
			//Print();
			/*keys.erase(keys.begin()+z);
			data.erase(data.begin() + z);
			reserved_length_collisions.erase(reserved_length_collisions.begin() + z);
			length_collisions.erase(length_collisions.begin()+z);
			length--;
			reserved_length--;*/
		}
		count--;
		
	};
	R GetVal(T key) {
		assert(ContainsKey(key) != 0);
		int z = Hashfunction(key);
		for(int i=0;i<length;i++)
			for(int j=0;j<length_collisions[i];j++)
				if (key == keys[i].Get(j)) {
					cout << "\nKey" << key << " Data" << data[i].Get(j) << "\n";
					return data[i].Get(j);
				}

	};
	bool ContainsKey(T key) {
		if (count == 0)
			return 0;
		for (int i = 0; i < keys.size(); i++)
			for (int j = 0; j < keys[i].GetLength(); j++)
				if (keys[i].Get(j) == key)
					return 1;
		return 0;

	};
	void Print() {
		cout << "Reserved Length\n" << reserved_length << "\n";
		cout << "Real Length\n" << length << "\n";
		cout << "Reserved memory\n";
		for (int i = 0; i < reserved_length; i++) {
			//cout << reserved_length_collisions.size();
			for (int j = 0; j < reserved_length_collisions[i]; j++)
				cout << "Key " << keys[i].Get(j) << " Data " << data[i].Get(j) << " | ";
			cout << "\n================\n";
		}
		cout << "\nUsed memory\n";
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length_collisions[i]; j++)
				cout << "Key " << keys[i].Get(j) << " Data " << data[i].Get(j) << " | ";
			cout << "\n================\n";
		}
		int reserved_cells = 0;
		for (int i = 0; i < reserved_length; i++) {
			reserved_cells += reserved_length_collisions[i];
		}
		double cur = (count + 0.0) / reserved_cells;
		cout<<"Reserved cells "<<reserved_cells<<" Current load "<< cur;
	}
};