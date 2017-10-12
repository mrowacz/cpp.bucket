#include <array>
#include <memory>
#include <utility>
#include <iostream>
#include <initializer_list>

using namespace std;

template <typename T>
struct ListEntry {
	ListEntry() = delete;
	ListEntry(T v) {
		std::cout << "ctor() "  << v << std::endl;
		value = v;
	}
	~ListEntry() {
		std::cout << "dtor() " << value << std::endl;
	}

	T value;
	std::shared_ptr<ListEntry<T>> next;
};

template <typename T>
struct List {

	List& insert(T value)
	{
		if (head == nullptr) {
			std::cout << "Creating head!" << std::endl;
			head = std::make_shared<ListEntry<T>>(value);
			tail = head;
		} else {
			auto s_ptr = tail.lock();
			s_ptr->next = std::make_shared<ListEntry<T>>(value);
			tail = s_ptr->next;
		}
		return *this;
	}

	ListEntry<T>&& find(T value)
	{
		auto ptr = head;
		while(ptr->value != value && ptr->next != nullptr) {
			ptr = ptr->next;
		}

		if (ptr->value == value)
			return std::forward<ListEntry<T>>(*ptr);
	}

	std::shared_ptr<ListEntry<T>> head;
	std::weak_ptr<ListEntry<T>> tail;
};

int main()
{
	List<int> list;
	list
		.insert(1)
		.insert(2)
		.insert(3);

	auto&& entry = list.find(2);
	std::cout << "entry val " << entry.value << std::endl;

	return EXIT_SUCCESS;
}
