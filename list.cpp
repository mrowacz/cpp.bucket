#include <array>
#include <memory>
#include <iostream>
#include <initializer_list>

using namespace std;

struct ListEntry {
	ListEntry() = delete;
	ListEntry(int v) {
		std::cout << "ctor() "  << v << std::endl;
		value = v;
	}
	~ListEntry() {
		std::cout << "dtor() " << value << std::endl;
	}

	int value;
	std::shared_ptr<ListEntry> next;
};

struct List {

	static int counter;

	List& insert()
	{
		if (head == nullptr) {
			std::cout << "Creating head!" << std::endl;
			head = std::make_shared<ListEntry>(counter++);
			tail = head;
		} else {
			auto s_ptr = tail.lock();
			s_ptr->next = std::make_shared<ListEntry>(counter++);
			tail = s_ptr->next;
		}
		return *this;
	}

	std::shared_ptr<ListEntry> head;
	std::weak_ptr<ListEntry> tail;
};
int List::counter = 0;

int main()
{
	List list;
	list
		.insert()
		.insert()
		.insert();

	return EXIT_SUCCESS;
}
