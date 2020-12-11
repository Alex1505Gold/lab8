#include <iostream>
#include <string>

struct SCP
{
    std::string name = "SCP_000";
    std::string klass = "not_stated";
    int scp_number = -1;
};

std::ostream& operator<< (std::ostream& out, const SCP& scp)
{
    out << std::endl;
    out << "SCP_" << scp.scp_number << " \"" << scp.name << "\"" << std::endl;
    out << "Class of the object: " << scp.klass << std::endl;
    return out;
}

bool operator!=(const SCP& left, const SCP& right) {
    return left.scp_number != right.scp_number;
}

template <typename T>
struct Ring_list_element
{
    T value;
    Ring_list_element* rle_prev = nullptr;
    Ring_list_element* rle_next = nullptr;
};

template <typename T>
struct Ring_list_struct
{
    Ring_list_element<T>* rl_begin;
    Ring_list_element<T>* rl_end;
};

template <typename T>
void constructor_rl(Ring_list_struct<T>& rl)
{
    rl.rl_begin = nullptr;
    rl.rl_end = nullptr;
}

template <typename T>
unsigned int size_of_rl(Ring_list_struct<T>& rl)
{
    Ring_list_element<T>* current = new Ring_list_element<T>;
    current = rl.rl_begin;
    if (current == nullptr) return 0;
    else {
        unsigned int counter = 1;
        while (current != rl.rl_end) {
            counter++;
            current = current->rle_next;
        }
        return counter;
    }
}

template <typename T>
void push_begin(Ring_list_struct<T>& rl, T n)
{

    Ring_list_element<T>* newRl_e = new Ring_list_element<T>;
    newRl_e->value = n;
    if (rl.rl_begin == nullptr) {
        rl.rl_begin = newRl_e;
        rl.rl_end = newRl_e;
        newRl_e->rle_next = newRl_e;
        newRl_e->rle_prev = newRl_e;
    }
    else {
        rl.rl_begin->rle_prev = newRl_e;
        newRl_e->rle_next = rl.rl_begin;
        rl.rl_begin = newRl_e;
        rl.rl_begin->rle_prev = rl.rl_end;
    }
}

template <typename T>
void push_end(Ring_list_struct<T>& rl, T n)
{

    Ring_list_element<T>* newRl_e = new Ring_list_element<T>;
    newRl_e->value = n;
    if (rl.rl_begin == nullptr) {
        rl.rl_begin = newRl_e;
        rl.rl_end = newRl_e;
        newRl_e->rle_next = newRl_e;
        newRl_e->rle_prev = newRl_e;
    }
    else {
        rl.rl_end->rle_next = newRl_e;
        newRl_e->rle_prev = rl.rl_end;
        rl.rl_end = newRl_e;
        rl.rl_end->rle_next = rl.rl_begin;
    }
}

template <typename T>
void insert_index(Ring_list_struct<T>& rl, T n, unsigned int i)
{
    unsigned int counter = 0;
    Ring_list_element<T>* current;
    current = rl.rl_begin;
    while (counter != i)
    {
        current = current->rle_next;
        ++counter;
    }
    Ring_list_element<T>* newRl_e = new Ring_list_element<T>;
    newRl_e->value = n;
    newRl_e->rle_prev = current->rle_prev;
    current->rle_prev->rle_next = newRl_e;
    current->rle_prev = newRl_e;
    newRl_e->rle_next = current;
}

template <typename T>
void insert_pointer(Ring_list_struct<T>& rl, T n, Ring_list_element<T>* i)
{
    Ring_list_element<T>* current;
    current = rl.rl_begin;
    while (current != i) current = current->rle_next;
    current = current->rle_next;
    Ring_list_element<T>* newRl_e = new Ring_list_element<T>;
    newRl_e->value = n;
    newRl_e->rle_prev = current->rle_prev;
    current->rle_prev->rle_next = newRl_e;
    current->rle_prev = newRl_e;
    newRl_e->rle_next = current;
}

template <typename T>
T pop_begin(Ring_list_struct<T>& rl)
{
    rl.rl_end->rle_next = rl.rl_begin->rle_next;
    rl.rl_begin->rle_next->rle_prev = rl.rl_end;
    T rez = rl.rl_begin->value;
    Ring_list_element<T>* tmp;
    tmp = rl.rl_begin->rle_next;
    delete rl.rl_begin;
    rl.rl_begin = tmp;
    return rez;
}

template <typename T>
T pop_end(Ring_list_struct<T>& rl)
{
    rl.rl_end->rle_prev->rle_next = rl.rl_begin;
    rl.rl_begin->rle_prev = rl.rl_end->rle_prev;
    T rez = rl.rl_end->value;
    Ring_list_element<T>* tmp;
    tmp = rl.rl_end->rle_prev;
    delete rl.rl_end;
    rl.rl_end = tmp;
    return rez;
}

template <typename T>
T pop_index(Ring_list_struct<T>& rl, unsigned int i)
{
    unsigned int counter = 0;
    Ring_list_element<T>* current = new Ring_list_element<T>;
    current = rl.rl_begin;
    //std::cout << i << std::endl;
    while (counter != i)
    {
        current = current->rle_next;
        //std::cout << counter << "-";
        ++counter;
    }
    T rez = current->value;
    current->rle_prev->rle_next = current->rle_next;
    current->rle_next->rle_prev = current->rle_prev;
    delete current;
    return rez;
}

template <typename T>
T pop_index_pointer(Ring_list_struct<T>& rl, Ring_list_element<T>* i)
{
    Ring_list_element<T>* current = new Ring_list_element<T>;
    current = rl.rl_begin;
    while (current != i) current = current->rle_next;
    T rez = current->value;
    current->rle_prev->rle_next = current->rle_next;
    current->rle_next->rle_prev = current->rle_prev;
    delete current;
    return rez;
}

template <typename T>
T find_value(Ring_list_struct<T>& rl, unsigned int i)
{
    unsigned int counter = 0;
    Ring_list_element<T>* current;
    current = rl.rl_begin;
    while (counter != i)
    {
        current = current->rle_next;
        counter++;
    }
    return current->value;
}

template <typename T>
unsigned int find_pos(Ring_list_struct<T>& rl, T n)
{
    Ring_list_element<T>* current;
    current = rl.rl_begin;
    unsigned int i = 0;
    while (current->value != n) {
        ++i;
        current = current->rle_next;
    }
    return i;
}

template <typename T>
void show_list(Ring_list_struct<T>& rl)
{
    if (rl.rl_begin == nullptr)
    {
        std::cout << "List is empty" << std::endl;
    }
    else
    {
        Ring_list_element<T>* current;
        current = rl.rl_begin;
        unsigned int i = 0;
        std::cout << "--------------" << std::endl;
        std::cout << i << ": " << current->value << std::endl;
        ++i;
        while (current != rl.rl_end) {
            current = current->rle_next;
            std::cout << i << ": " << current->value << std::endl;
            ++i;
        }
        std::cout << "--------------" << std::endl;
    }
}

template <typename T>
void destructor_rl(Ring_list_struct<T>& rl)
{
    Ring_list_element<T>* current;
    current = rl.rl_begin;
    while (current != rl.rl_end)
    {
        current = current->rle_next;
        delete rl.rl_begin;
        rl.rl_begin = current;
    }
    delete current;
}

int main()
{
    //проверка для int
    Ring_list_struct<int> rl0;
    constructor_rl(rl0);
    show_list(rl0);
    push_end(rl0, 3);
    push_begin(rl0, 10);
    push_begin(rl0, 4);
    push_end(rl0, 9);
    show_list(rl0);
    std::cout << find_pos(rl0, 3) << std::endl;
    std::cout << find_value(rl0, 2) << std::endl;
    std::cout << size_of_rl(rl0) << std::endl;
    insert_index(rl0, 23, 3);
    push_end(rl0, 88);
    show_list(rl0);
    std::cout << pop_end(rl0) << std::endl;
    std::cout << pop_begin(rl0) << std::endl;
    show_list(rl0);
    push_end(rl0, 90);
    push_end(rl0, 56);
    show_list(rl0);
    std::cout << size_of_rl(rl0) << std::endl;
    std::cout << pop_index(rl0, 2) << std::endl;
    show_list(rl0);
    destructor_rl(rl0);
    //проверка для пользовательского типа
    SCP scp0, scp1, scp2, scp3;
    scp0.scp_number = 35;
    scp0.name = "Possessive Mask";
    scp0.klass = "Keter";
    scp1.scp_number = 96;
    scp1.name = "Shy guy";
    scp1.klass = "Keter";
    scp2.scp_number = 131;
    scp2.name = "Eye pods";
    scp2.klass = "Safe";
    scp3.scp_number = 343;
    scp3.name = "God";
    scp3.klass = "Safe";
    Ring_list_struct<SCP> rl1;
    constructor_rl(rl1);
    push_begin(rl1, scp0);
    push_end(rl1, scp1);
    push_begin(rl1, scp2);
    show_list(rl1);
    std::cout << find_pos(rl1, scp0) << std::endl;
    std::cout << find_value(rl1, 2) << std::endl;
    std::cout << size_of_rl(rl1) << std::endl;
    insert_index(rl1, scp3, 2);
    show_list(rl1);
    std::cout << pop_end(rl1);
    std::cout << pop_begin(rl1);
    show_list(rl1);
    destructor_rl(rl1);
    return 0;
}


