#pragma once

template <typename T> class Container
{
private:
	struct Entry
	{
		T data;
		Entry* next;
	};

	Entry* head;

	Container(Container& other) {}
	Container& operator =(Container& other) {}

public:
	Container(void)
	{
		head = NULL;
	}

	void insert_begin(T new_data)
	{
		Entry* new_entry;
		new_entry = new Entry;
		new_entry->data = new_data;
		new_entry->next = head;
		head = new_entry;
	}

	void insert_end(T new_data)
	{
		Entry* new_entry;
		new_entry = new Entry;
		new_entry->data = new_data;
		new_entry->next = NULL;
		if (head == NULL)
		{
			head = new_entry;
		}
		else
		{
			Entry* l;
			for (l = head; l->next != NULL; l = l->next);
			l->next = new_entry;
		}

	}

	void delete_begin(void)
	{
		if (head != NULL)
		{
			Entry* second;
			second = head->next;
			delete head;
			head = second;
		}
	}

	void delete_end(void)
	{
		if (head != NULL)
		{
			if (head->next == NULL)
			{
				delete_begin();
			}
			else
			{
				Entry* l;
				for (l = head; l->next->next != NULL; l = l->next);
				delete l->next;
				l->next = NULL;
			}
		}
	}

	~Container(void)
	{
		while (head != NULL)
			delete_begin();
	}

	bool IsItEmpty(void) const
	{
		return (head == NULL);
	}

	T GetHead(void) const
	{
		if (head != NULL)
			return head->data;
	}

	T GetEnd(void) const
	{
		if (head != NULL)
		{
			Entry* l;
			for (l = head; l->next != NULL; l = l->next);
			return l->data;
		}
	}

	int GetCountContainer(void) const
	{
		if (head != NULL)
		{
			Entry* l;
			int i = 0;
			for (l = head; l != NULL; l = l->next)
				i++;
			return i;
		}
		else
			return 0;
	}

	void print(void) const
	{
		if (head == NULL)
			std::cout << "Empty\n";
		else
		{
			for (Entry* l = head; l != NULL; l = l->next)
				std::cout << l->data << "\n";
			std::cout << "\n";
		}
	}

	class iterator
	{
	private:
		Entry* place;

	public:
		iterator(void)
		{
			place = NULL;
		}

		iterator(iterator& other)
		{
			place = other.place;
		}

		iterator(Entry* e)
		{
			place = e;
		}

		~iterator(void) {}

		bool operator==(iterator& other) const
		{
			if (place == other.place)
				return true;
			else
				return false;
		}

		bool operator!=(iterator& other) const
		{
			if (place == other.place)
				return false;
			else
				return true;
		}

		iterator operator ++ (void)
		{
			if (place != NULL)
				place = place->next;
			return *this;
		}

		T operator * (void) const
		{
			if (place != NULL)
				return place->data;
		}

		T* operator -> (void) const
		{
			if (place != NULL)
				return &(place->data);
		}
	};
	iterator begin(void) const
	{
		iterator i(head);
		return i;
	}
	iterator end(void) const
	{
		iterator i;
		return i;
	}
};