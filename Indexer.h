#pragma once
#include "Dictionary.h"
#include "..\..\Lab1\Lab1\Sequence.h"
template <typename T, typename R> class Indexer {
private:
	Dictionary<T, R> dict;

public:
	Indexer() {};
	Indexer(Sequence<R>* a, T(*indexer)(R)) {
		for (int i = 0; i < a->GetLength(); i++) {
			T index = indexer(a->Get(i));
			dict.Add(index, a->Get(i));
		}
	}
	Indexer(Sequence<R>* a, bool (*cmp)(R)) {
		for (int i = 0; i < a->GetLength(); i++) {
			bool index = cmp(a->Get(i));
			dict.Add(index, a->Get(i));
		}
	}
	Dictionary <T, R> ReturnIndexed() {
		return dict;
	}
};